
# BigNumbers_I2C Arduino Library

## Description
The BigNumbers_I2C library provides functions to display large numbers on a LiquidCrystal display using I2C communication. 
It supports printing positive and negative integers and floating-point numbers with customizable digit positions.

## Installation
Download: Download the BigNumbers_I2C library.

Import to Arduino IDE: In the Arduino IDE, navigate to Sketch -> Include Library -> Add .ZIP Library and select the downloaded ZIP file.

Include in Sketch: Include the library in your sketch by adding #include <BigNumbers_I2C.h>.

## Features
Display Control: Clear specific digits or print numbers at specified positions.

Integer and Floating-Point Support: Print both integers and floating-point numbers.

Supports negative integer and float.

## Dependencies
This library depends on the LiquidCrystal_I2C library for communication with the LCD display. Make sure it is installed and correctly configured.

## Usage

### Constructor
BigNumbers_I2C(LiquidCrystal_I2C *lcd);

Parameters: lcd - Pointer to a LiquidCrystal_I2C object.

## Methods
begin()

Initializes the library and the connected display.


clearDigit(uint8_t startX)

Clears the digit at the specified position.


printDigit(uint8_t digit, uint8_t startX)

Prints a single-digit number (0-9) at the specified position.


printInt(int value, uint8_t startX)

Prints an integer number starting from the specified digit position.


printFloat(float value, uint8_t startX)

Prints a floating-point number starting from the specified digit position.