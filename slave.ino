#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Wire.begin();  
  Serial.begin(9600); 
  lcd.begin(16, 2);
  lcd.print("Razdalja: ");
}

void loop() {
  lcd.setCursor(0, 1);
  
  Wire.requestFrom(8, 6);   

  while (Wire.available()) {
    int c = Wire.read();
    if (c < 150) {
    	lcd.print(c);
    }
    else {
    	lcd.print(" ");  
    }
  }
  delay(500);
}
 