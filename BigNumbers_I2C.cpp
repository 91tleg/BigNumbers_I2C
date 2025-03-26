#include "BigNumbers_I2C.h"

BigNumbers_I2C::BigNumbers_I2C(LiquidCrystal_I2C *lcd)
    : _lcd(lcd),
      _currIndex(0),
      _decimalPoint(DEFAULT_DECIMAL_PRECISION) {};

void BigNumbers_I2C::begin(void)
{
    if (!_lcd)
        return;
    // Load custom characters into CGRAM
    _lcd->createChar(0, leftSide);
    _lcd->createChar(1, upperBar);
    _lcd->createChar(2, rightSide);
    _lcd->createChar(3, leftEnd);
    _lcd->createChar(4, lowerBar);
    _lcd->createChar(5, rightEnd);
    _lcd->createChar(6, middleBar);
    _lcd->createChar(7, lowerEnd);
}

void BigNumbers_I2C::clearDigit(uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    _lcd->setCursor(startX, startY);
    _lcd->print("   ");
    _lcd->setCursor(startX, startY + 1);
    _lcd->print("   ");
    _currIndex -= 3;
}

void BigNumbers_I2C::printDigit(uint8_t digit, uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    switch (digit)
    {
    case 0:
        _lcd->setCursor(startX, startY);
        _lcd->write(0);
        _lcd->write(1);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0);
        _lcd->write(4);
        _lcd->write(2);
        break;
    case 1:
        _lcd->setCursor(startX, startY);
        _lcd->write(0XFE);
        _lcd->write(0XFE);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0XFE);
        _lcd->write(0XFE);
        _lcd->write(2);
        break;
    case 2:
        _lcd->setCursor(startX, startY);
        _lcd->write(3);
        _lcd->write(6);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0);
        _lcd->write(4);
        _lcd->write(4);
        break;
    case 3:
        _lcd->setCursor(startX, startY);
        _lcd->write(3);
        _lcd->write(6);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(7);
        _lcd->write(4);
        _lcd->write(2);
        break;
    case 4:
        _lcd->setCursor(startX, startY);
        _lcd->write(0);
        _lcd->write(4);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0xFE);
        _lcd->write(0xFE);
        _lcd->write(2);
        break;
    case 5:
        _lcd->setCursor(startX, startY);
        _lcd->write(0);
        _lcd->write(6);
        _lcd->write(5);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(7);
        _lcd->write(4);
        _lcd->write(2);
        break;
    case 6:
        _lcd->setCursor(startX, startY);
        _lcd->write(0);
        _lcd->write(6);
        _lcd->write(5);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0);
        _lcd->write(4);
        _lcd->write(2);
        break;
    case 7:
        _lcd->setCursor(startX, startY);
        _lcd->write(1);
        _lcd->write(1);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0XFE);
        _lcd->write(0XFE);
        _lcd->write(2);
        break;
    case 8:
        _lcd->setCursor(startX, startY);
        _lcd->write(0);
        _lcd->write(6);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(0);
        _lcd->write(4);
        _lcd->write(2);
        break;
    case 9:
        _lcd->setCursor(startX, startY);
        _lcd->write(0);
        _lcd->write(6);
        _lcd->write(2);
        _lcd->setCursor(startX, startY + 1);
        _lcd->write(7);
        _lcd->write(4);
        _lcd->write(2);
        break;
    }
    _currIndex += 3;
}

void BigNumbers_I2C::printNegativeSign(uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    _lcd->setCursor(_currIndex, startY);
    _lcd->write(4);
    _lcd->setCursor(_currIndex, startY + 1);
    _lcd->write(' ');
    ++_currIndex;
}

void BigNumbers_I2C::printDot(uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    _lcd->setCursor(_currIndex, startY);
    _lcd->write(' ');
    _lcd->setCursor(_currIndex, startY + 1);
    _lcd->print('.');
    ++_currIndex;
}

void BigNumbers_I2C::printColon(uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    _lcd->setCursor(_currIndex, startY);
    _lcd->write('.');
    _lcd->setCursor(_currIndex, startY + 1);
    _lcd->print('.');
    ++_currIndex;
}

void BigNumbers_I2C::printInt(int value, uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    if (value < 0)
    {
        printNegativeSign(_currIndex, startY);
        value = -value;
    }
    uint8_t digits[5] = {0};
    uint8_t length = (value == 0) ? 1 : static_cast<uint8_t>(log10(value) + 1);
    if (length > 5)
        return;
    for (int8_t i = length - 1; i > 0; --i)
    {
        digits[i] = value % 10;
        value /= 10;
    }
    digits[0] = value % 10;
    // Print
    for (uint8_t j = 0; j < length; ++j)
    {
        printDigit(digits[j], _currIndex, startY);
    }
    // Clear if value is shorter than previous
    if (_prevLength > length)
    {
        while (_prevLength != length)
        {
            clearDigit(_currIndex, startY);
            --_prevLength;
        }
    }
    _prevLength = length;
}

void BigNumbers_I2C::printInt(int value)
{
    printInt(value, DEFAULT_START_X, DEFAULT_START_Y);
}

void BigNumbers_I2C::printFloat(float value, uint8_t startX, uint8_t startY)
{
    _currIndex = startX;
    if (value < 0)
    {
        printNegativeSign(startX, startY);
        value = -value;
    }
    // Extract integer and fractional parts
    uint8_t arrInt[3] = {0};
    uint8_t arrFrac[2] = {0};
    uint16_t intPart = static_cast<uint16_t>(value);
    uint8_t fracPart = static_cast<uint8_t>((value - static_cast<float>(intPart)) * 100);
    uint8_t intLength = (intPart == 0) ? 1 : static_cast<uint8_t>(log10(intPart) + 1);
    uint8_t fracLength = 2;
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
        printDigit(arrInt[i], _currIndex, startY);
    }
    // Print decimal point
    printDot(_currIndex, startY);
    // Print fractional part
    for (int8_t i = 0; i < fracLength; ++i)
    {
        printDigit(arrFrac[i], _currIndex, startY);
    }
    if (_prevLength > intLength + fracLength)
    {
        while (_prevLength != intLength + fracLength)
        {
            clearDigit(_currIndex, startY);
            --_prevLength;
        }
    }
    _prevLength = intLength + fracLength;
}

void BigNumbers_I2C::printFloat(float value)
{
    printFloat(value, DEFAULT_START_X, DEFAULT_START_Y);
}

void BigNumbers_I2C::printDouble(double value, uint8_t startX, uint8_t startY)
{
    printFloat(static_cast<float>(value), startX, startY);
}

void BigNumbers_I2C::printDouble(double value)
{
    printDouble(value, DEFAULT_START_X, DEFAULT_START_Y);
}

void BigNumbers_I2C::printTime(uint8_t hour, uint8_t minute, uint8_t startX, uint8_t startY)
{
    _currIndex = startX;

    // Print leading zero if hour is single digit
    if (hour < 10)
        printDigit(0, _currIndex, startY);

    printInt(hour, _currIndex, startY);

    // Print ':'
    printColon(_currIndex, startY);

    // Print leading zero if minute is single digit
    if (minute < 10)
        printDigit(0, _currIndex, startY);
    
    printInt(minute, _currIndex, startY);
}

void BigNumbers_I2C::printTime(uint8_t hour, uint8_t minute)
{
    _printTime(hour, minute, DEFAULT_START_X, DEFAULT_START_Y);
}

void BigNumbers_I2C::clearAll(uint8_t startX, uint8_t startY)
{
    for (int i = startX; i <= _currIndex; ++i)
    {
        _lcd->setCursor(startX, startY);
        _lcd->print(" "); 
        _lcd->setCursor(startX, startY + 1);
        _lcd->print(" ");
    }
}