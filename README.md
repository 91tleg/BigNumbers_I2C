
# BigNumbers_I2C

modified from seanauff's BigNumbers: https://github.com/seanauff/BigNumbers

## Description
An Arduino library for displaying large numbers on I2C HD44780-based LCD Displays
* Supports integer, float, & double.
* Supports positive & negative numbers.

## Installation

#### Arduino IDE
1. Download the BigNumbers_I2C library.
2. Import to Arduino IDE: In the Arduino IDE, navigate to Sketch -> Include Library -> Add .ZIP Library and select the downloaded ZIP file.
3. Include the library in your project by adding ```#include <BigNumbers_I2C.h>```

#### PlatformIO
1. Open terminal and change the directory to the lib folder of your PlatformIO project. Assuming you're in the root directory of your PlatformIO project:
```
cd lib
```
2. Clone the repository.
```
git clone https://github.com/91tleg/BigNumbers_I2C
```
3. Include the library in your project by adding ```#include <BigNumbers_I2C.h>```

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
void clearAll(uint8_t startX, uint8_t startY);
```
Clears all the digits starting from the specified position to the last known position.


```cpp
void printInt(int value);
```
Prints an integer number starting from the default position.


```cpp
void printInt(int value, uint8_t startX, uint8_t startY);
```
Prints an integer number starting from the specified position.


```cpp
void printFloat(float value);
```
Prints a floating-point number starting from the default position.


```cpp
void printFloat(float value, uint8_t startX, uint8_t startY);
```
Prints a floating-point number starting from the specified position.


```cpp
void printDouble(double value);
```
Prints a floating-point number starting from the default position.


```cpp
void printDouble(double value, uint8_t startX, uint8_t startY);
```
Prints a floating-point number starting from the specified position.


```cpp
void printTime(uint8_t hour, uint8_t minute);
```
Prints a time in HH:MM format starting from the default position.


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

## Troubleshooting
* This library depends on the LiquidCrystal_I2C library for communication with the LCD display. Make sure it is installed and correctly configured.
* Make sure custom characters are initialized in setup.