#ifndef BIGNUMBERS_I2C_H
#define BIGNUMBERS_I2C_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <stdint.h>

class BigNumbers_I2C
{
public:
  BigNumbers_I2C(LiquidCrystal_I2C *);
  void begin();
  void clearDigit(uint8_t);
  void printDigit(uint8_t, uint8_t);
  void printInt(int, uint8_t);
  void printFloat(float, uint8_t);

private:
  LiquidCrystal_I2C *_lcd;
  uint8_t _currIndex;
  uint8_t _prevLength;
  
  uint8_t leftSide[8] =
      {
          B00111,
          B01111,
          B01111,
          B01111,
          B01111,
          B01111,
          B01111,
          B00111};
  uint8_t upperBar[8] =
      {
          B11111,
          B11111,
          B11111,
          B00000,
          B00000,
          B00000,
          B00000,
          B00000};
  uint8_t rightSide[8] =
      {
          B11100,
          B11110,
          B11110,
          B11110,
          B11110,
          B11110,
          B11110,
          B11100};
  uint8_t leftEnd[8] =
      {
          B01111,
          B00111,
          B00000,
          B00000,
          B00000,
          B00000,
          B00011,
          B00111};
  uint8_t lowerBar[8] =
      {
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B11111,
          B11111,
          B11111};
  uint8_t rightEnd[8] =
      {
          B11110,
          B11100,
          B00000,
          B00000,
          B00000,
          B00000,
          B11000,
          B11100};
  uint8_t middleBar[8] =
      {
          B11111,
          B11111,
          B11111,
          B00000,
          B00000,
          B00000,
          B11111,
          B11111};
  uint8_t lowerEnd[8] =
      {
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B00111,
          B01111};
};

#endif