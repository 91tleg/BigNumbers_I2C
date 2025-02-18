#include "BigNumbers_I2C.h"

BigNumbers_I2C::BigNumbers_I2C(LiquidCrystal_I2C *lcd)
{
  _lcd = lcd;
  _currIndex = 0;
}

// Initialize the custom characters
void BigNumbers_I2C::begin()
{
  if (!_lcd)
    return;

  _lcd->createChar(0, leftSide);
  _lcd->createChar(1, upperBar);
  _lcd->createChar(2, rightSide);
  _lcd->createChar(3, leftEnd);
  _lcd->createChar(4, lowerBar);
  _lcd->createChar(5, rightEnd);
  _lcd->createChar(6, middleBar);
  _lcd->createChar(7, lowerEnd);
}

void BigNumbers_I2C::clearDigit(uint8_t startX)
{
  _lcd->setCursor(startX, 0);
  _lcd->print("   ");
  _lcd->setCursor(startX, 1);
  _lcd->print("   ");
}

// 0-9, and the starting x position
void BigNumbers_I2C::printDigit(uint8_t digit, uint8_t startX)
{
  switch (digit)
  {
  case 0:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(1));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    break;
  case 1:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0XFE));
    _lcd->write(uint8_t(0XFE));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0XFE));
    _lcd->write(uint8_t(0XFE));
    _lcd->write(uint8_t(2));
    break;
  case 2:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(3));
    _lcd->write(uint8_t(6));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(4));
    break;
  case 3:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(3));
    _lcd->write(uint8_t(6));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(7));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    break;
  case 4:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0xFE));
    _lcd->write(uint8_t(0xFE));
    _lcd->write(uint8_t(2));
    break;
  case 5:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(6));
    _lcd->write(uint8_t(5));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(7));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    break;
  case 6:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(6));
    _lcd->write(uint8_t(5));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    break;
  case 7:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(1));
    _lcd->write(uint8_t(1));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0XFE));
    _lcd->write(uint8_t(0XFE));
    _lcd->write(uint8_t(2));
    break;
  case 8:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(6));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    break;
  case 9:
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(0));
    _lcd->write(uint8_t(6));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(uint8_t(7));
    _lcd->write(uint8_t(4));
    _lcd->write(uint8_t(2));
    break;

  default:
    break;
  }
}

void BigNumbers_I2C::printInt(int value, uint8_t startX)
{
  _currIndex = startX;
  if (value < 0)
  {
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(4)); // Print negative sign
    _lcd->setCursor(startX, 1);
    _lcd->print("   ");
    ++_currIndex;
    value = -value;
  }
  uint8_t digits[5] = {0};
  uint8_t length = (value == 0) ? 1 : static_cast<uint8_t>(log10(value) + 1);
  if (length > 5)
    return;
  // Load the digits into array
  for (int8_t i = length - 1; i > 0; --i)
  {
    digits[i] = value % 10;
    value /= 10;
  }
  digits[0] = value % 10;
  // Print 
  for (uint8_t j = 0; j < length; ++j)
  {
    printDigit(digits[j], _currIndex);
    _currIndex += 3;
  }
  clearDigit(_currIndex);
}

void BigNumbers_I2C::printFloat(float value, uint8_t startX)
{
  _currIndex = startX;
  if (value < 0)
  {
    _lcd->setCursor(_currIndex, 0);
    _lcd->write(uint8_t(4));
    _lcd->setCursor(_currIndex, 1);
    _lcd->print("   ");
    ++_currIndex;
    value = -value;
  }
  // Extract integer and fractional parts
  uint16_t intPart = static_cast<uint16_t>(value);
  uint8_t fracPart = static_cast<uint8_t>((value - static_cast<float>(intPart)) * 100);
  uint8_t intLength = (intPart == 0) ? 1 : static_cast<uint8_t>(log10(intPart) + 1);
  uint8_t fracLength = 2;
  uint8_t arrInt[3] = {0};
  uint8_t arrFrac[2] = {0};
  for (int8_t i = intLength - 1; i > 0; --i)
  {
    arrInt[i] = static_cast<uint8_t>(intPart % 10);
    intPart /= 10;
  }
  arrInt[0] = static_cast<uint8_t>(intPart % 10);
  for (int8_t i = fracLength - 1; i > 0; --i)
  {
    arrFrac[i] = fracPart % 10;
    fracPart /= 10;
  }
  arrFrac[0] = fracPart % 10;
  // Print integer part
  for (int8_t i = 0; i < intLength; ++i)
  {
    printDigit(arrInt[i], _currIndex);
    _currIndex += 3;
  }
  // Print decimal point
  _lcd->setCursor(_currIndex, 0);
  _lcd->print("     ");
  _lcd->setCursor(_currIndex, 1);
  _lcd->print('.');
  ++_currIndex;
  // Print fractional part
  for (int8_t i = 0; i < fracLength; ++i)
  {
    printDigit(arrFrac[i], _currIndex);
    _currIndex += 3;
  }
  clearDigit(_currIndex);
}
