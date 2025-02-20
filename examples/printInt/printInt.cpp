#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <BigNumbers_I2C.h>

#define POT_PIN A0

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
BigNumbers_I2C bn(&lcd);

void setup()
{
  lcd.init();
  lcd.backlight();
  bn.begin();
  pinMode(POT_PIN, INPUT);
}

void loop()
{
  int pot = analogRead(POT_PIN);
  bn.printInt(pot, 0);
  delay(100);
}