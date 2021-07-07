int razdalja = 0;

int gumb = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

#include <Wire.h>

void setup()
{
  pinMode(7, INPUT);
  Serial.begin(9600);
  Wire.begin(8);                
  Wire.onRequest(requestEvent); 
  pinMode(9, OUTPUT);
}

void loop()
{
  while (true) {
    razdalja = 0.01723 * readUltrasonicDistance(4, 4);
    gumb = digitalRead(7);
    if (razdalja < 150 || gumb == 1) {
      requestEvent();
      digitalWrite(9, HIGH);
      delay(2000);
      digitalWrite(9, LOW);
      delay(5000); 
    }
    
  }
}

void requestEvent() {
  	Wire.write(razdalja);
}
