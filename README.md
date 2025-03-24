
# BigNumbers_I2C

modified from seanauff's BigNumbers: https://github.com/seanauff/BigNumbers

## Description
An Arduino library for displaying large numbers on I2C HD44780-based LCD Displays
* Supports integer, float, & double.
* Supports positive & negative numbers.

## Installation
Download the BigNumbers_I2C library.\
Import to Arduino IDE: In the Arduino IDE, navigate to Sketch -> Include Library -> Add .ZIP Library and select the downloaded ZIP file.\
Include in Sketch: Include the library in your sketch by adding ```#include <BigNumbers_I2C.h>```

## Usage

#### Constructor
```cpp
BigNumbers_I2C(LiquidCrystal_I2C *lcd);
```
Parameters: lcd - Pointer to a LiquidCrystal_I2C object.

#### Methods
```cpp
void begin(void);
```
Initializes the custom characters.


```cpp
void clearDigit(uint8_t startX, uint8_t startY);
```
Clears the digit at the specified position.


```cpp
void printInt(int value);
```
Prints an integer number at default position.


```cpp
void printInt(int value, uint8_t startX, uint8_t startY);
```
Prints an integer number starting from the specified position.


```cpp
void printFloat(float value);
```
Prints a floating-point number at default position.


```cpp
void printFloat(float value, uint8_t startX, uint8_t startY);
```
Prints a floating-point number starting from the specified position.


```cpp
void printDouble(double value);
```
Prints a floating-point number at default position.


```cpp
void printDouble(double value, uint8_t startX, uint8_t startY);
```
Prints a floating-point number starting from the specified position.


```cpp
void printTime(uint8_t hour, uint8_t minute, uint8_t startX, uint8_t startY);
```
Prints a time in HH:MM format starting from the specified position.

## Example
```cpp
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD object

BigNumbers_I2C bigNum(&lcd);       // Passing the pointer to the address of LCD object

void setup()
{
    lcd.init();
    lcd.backlight();
    bigNum.begin();
}

void loop()
{
  bigNum.printInt(1111);   // Prints 1111 at 0,0
}
```

### Troubleshooting
This library depends on the LiquidCrystal_I2C library for communication with the LCD display. Make sure it is installed and correctly configured.\
Make sure custom characters are initialized in setup.