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
  void printInt(int32_t, uint8_t);

private:
  LiquidCrystal_I2C *_lcd;
};

#endif