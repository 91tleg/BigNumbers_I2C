#include "BigNumbers_I2C.h"

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

BigNumbers_I2C::BigNumbers_I2C(LiquidCrystal_I2C *lcd)
{
  _lcd = lcd;
}

void BigNumbers_I2C::begin()
{
  _lcd->createChar(0, leftSide);
  _lcd->createChar(1, upperBar);
  _lcd->createChar(2, rightSide);
  _lcd->createChar(3, leftEnd);
  _lcd->createChar(4, lowerBar);
  _lcd->createChar(5, rightEnd);
  _lcd->createChar(6, middleBar);
  _lcd->createChar(7, lowerEnd);
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
    _lcd->write(char(254));
    _lcd->write(char(254));
    _lcd->write(uint8_t(2));
    _lcd->setCursor(startX, 1);
    _lcd->write(char(254));
    _lcd->write(char(254));
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
    _lcd->write(char(254));
    _lcd->write(char(254));
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
    _lcd->write(char(254));
    _lcd->write(char(254));
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

void BigNumbers_I2C::printInt(int number, uint8_t startX)
{
  bool isNegative = false;
  // Print negative sign
  if (number < 0)
  {
    isNegative = true;
    _lcd->setCursor(startX, 0);
    _lcd->write(uint8_t(4));
    _lcd->setCursor(startX, 1);
    _lcd->print("   ");
    ++startX;
    number = -number;
  }
  uint8_t length = (number == 0) ? 1 : static_cast<uint8_t>(log10(number) + 1);
  uint8_t digits[5] = {0};

  if (length > 5)
  {
    return;
  }

  // Load the digits into array
  for (int8_t i = length - 1; i > 0; --i)
  {
    digits[i] = number % 10;
    number /= 10;
  }
  digits[0] = number % 10;

  // Print
  for (uint8_t j = 0; j < length; ++j)
  {
    printDigit(digits[j], startX + (j * 3));
  }
  clearDigit(startX + (length * 3));
  if (length == 1 && !isNegative)
  {
    clearDigit(startX + 6);
  }
  if (length == 5 && !isNegative && startX == 0)
  {
    clearDigit(length * 3);
  }
}

void BigNumbers_I2C::clearDigit(uint8_t startX)
{
  _lcd->setCursor(startX, 0);
  _lcd->print("   ");
  _lcd->setCursor(startX, 1);
  _lcd->print("   ");
}

void BigNumbers_I2C::printFloat(float number, uint8_t startX)
{
  uint8_t index = startX;
  bool isNegative = false;
  if (number < 0)
  {
    isNegative = true;
    _lcd->setCursor(index, 0);
    _lcd->write(uint8_t(4));
    _lcd->setCursor(index, 1);
    _lcd->print("   ");
    ++index;
    number = -number;
  }

  // Extract integer and fractional parts
  int8_t intPart = static_cast<int>(number);
  int8_t fracPart = static_cast<int>((number - static_cast<float>(intPart)) * 100);

  uint8_t intLength = (intPart == 0) ? 1 : static_cast<uint8_t>(log10(intPart) + 1);
  uint8_t fracLength = 2;

  if ((!isNegative && intLength + fracLength > 5) || (isNegative && intLength + fracLength > 4))
  {
    return;
  }

  uint8_t arrInt[3] = {0};
  uint8_t arrFrac[2] = {0};

  for (int8_t i = intLength - 1; i > 0; --i)
  {
    arrInt[i] = intPart % 10;
    intPart /= 10;
  }
  arrInt[0] = intPart % 10;

  for (int8_t i = fracLength - 1; i > 0; --i)
  {
    arrFrac[i] = fracPart % 10;
    fracPart /= 10;
  }
  arrFrac[0] = fracPart % 10;

  // Print integer part
  for (int8_t i = 0; i < intLength; ++i)
  {
    printDigit(arrInt[i], index);
    index += 3;
  }

  // Print decimal point
  _lcd->setCursor(index, 0);
  _lcd->print("     ");
  _lcd->setCursor(index, 1);
  _lcd->print('.');
  ++index;

  // Print fractional part
  for (int8_t i = 0; i < fracLength; ++i)
  {
    printDigit(arrFrac[i], index);
    index += 3;
  }

  if (isNegative && intLength == 1)
  {
    clearDigit(startX + (intLength + fracLength) * 3 + 2);
  }
  if (!isNegative && intLength == 1)
  {
    clearDigit(startX + (intLength + fracLength) * 3 + 1);
  }
  if (!isNegative && intLength == 2)
  {
    clearDigit(startX + (intLength + fracLength) * 3 + 3);
  }
}
