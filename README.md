
# BigNumbers_I2C Arduino Library

modified from seanauff's BigNumbers: https://github.com/seanauff/BigNumbers

## Description
Library for displaying large numbers on a Liquid Crystal Displays using I2C communication.\
Supports printing positive and negative integers and floating-point numbers with customizable digit positions.

## Installation
* Download the BigNumbers_I2C library.\
* Import to Arduino IDE: In the Arduino IDE, navigate to Sketch -> Include Library -> Add .ZIP Library and select the downloaded ZIP file.\
* Include in Sketch: Include the library in your sketch by adding 
'''cpp
#include <BigNumbers_I2C.h>
'''

## Features
Integer and Floating-Point Support: Print both integers and floating-point numbers.\
Supports positive & negative Integer and floats.\

## Dependencies
This library depends on the LiquidCrystal_I2C library for communication with the LCD display. Make sure it is installed and correctly configured.\

## Usage

### Constructor
'''cpp
BigNumbers_I2C(LiquidCrystal_I2C *lcd);
'''
Parameters: lcd - Pointer to a LiquidCrystal_I2C object.

## Methods
'''cpp
begin()
'''
Initializes the custom characters./

'''cpp
clearDigit(uint8_t startX)/
'''
Clears the digit at the specified position./

'''cpp
printDigit(uint8_t digit, uint8_t startX)
'''
Prints a single-digit number (0-9) at the specified position./

'''cpp
printInt(int value, uint8_t startX)
'''
Prints an integer number starting from the specified digit position./

'''cpp
printFloat(float value, uint8_t startX)
'''
Prints a floating-point number starting from the specified digit position.