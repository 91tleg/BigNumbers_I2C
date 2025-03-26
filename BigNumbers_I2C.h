#ifndef BIGNUMBERS_I2C_H
#define BIGNUMBERS_I2C_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <stdint.h>

#define DEFAULT_START_X 0
#define DEFAULT_START_Y 0
#define DEFAULT_DECIMAL_PRECISION 2

class BigNumbers_I2C
{
public:
    /**
     * @brief Constructs a BigNumbers_I2C object.
     *
     * @param lcd Pointer to a LiquidCrystal_I2C object.
     */
    BigNumbers_I2C(LiquidCrystal_I2C *lcd);

    /**
     * @brief Initializes the custom characters.
     */
    void begin(void);

    /**
     * @brief Clears a digit at the specified starting position.
     *
     * @param startX The column position where the digit should be cleared.
     * @param startY The row position where the digit should be cleared.
     */
    void clearDigit(uint8_t startX, uint8_t startY);

    /**
     * @brief Prints an integer value starting from the specified position.
     *
     * @param value The integer value to be displayed.
     * @param startX The column position where the value should be displayed.
     * @param startY The row position where the value should be displayed.
     */
    void printInt(int value, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints an integer value at the default position.
     *
     * @param value The integer value to be displayed.
     */
    void printInt(int value);

    /**
     * @brief Prints a floating-point value starting from the specified position.
     *
     * @param value The floating-point value to be displayed.
     * @param startX The column position where the value should be displayed.
     * @param startY The row position where the value should be displayed.
     */
    void printFloat(float value, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a floating-point value at the default position.
     *
     * @param value The floating-point value to be displayed.
     */
    void printFloat(float value);

    /**
     * @brief Prints a floating-point value starting from the specified position.
     *
     * @param value The floating-point value to be displayed.
     * @param startX The column position where the digit should be displayed.
     * @param startY The row position where the digit should be displayed.
     */
    void printDouble(double value, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a floating-point value at the default position.
     *
     * @param value The floating-point value to be displayed.
     */
    void printDouble(double value);

    /**
     * @brief Prints a time in HH:MM format at the specified position.
     *
     * @param hour The hour value (0-23 or 0-12).
     * @param minute The minute value (0-59).
     * @param startX The column position where the time should be displayed.
     * @param startY The row position where the time should be displayed.
     */
    void printTime(uint8_t hour, uint8_t minute, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a time in HH:MM format at the default position.
     *
     * @param hour The hour value (0-23 or 0-12).
     * @param minute The minute value (0-59).
     */
    void printTime(uint8_t hour, uint8_t minute);

    /**
     * @brief Clears the value from the specified position to the last known index.
     *
     * @param startX The column position where the time should be cleared.
     * @param startY The row position where the time should be cleared.
     */
    void clearAll(uint8_t startX, uint8_t startY);

private:
    LiquidCrystal_I2C *_lcd;
    uint8_t _currIndex;
    uint8_t _prevLength;
    uint8_t _decimalPoint;

    /**
     * @brief Prints a single-digit number (0-9) at the specified position on the LCD.
     *
     * @param digit The digit to be displayed (0-9).
     * @param startX The column position where the digit should be displayed.
     * @param startY The row position where the digit should be displayed.
     */
    void printDigit(uint8_t digit, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a negative sign at the specified position on the LCD.
     *
     * @param startX The column position where the sign should be displayed.
     * @param startY The row position where the sign should be displayed.
     */
    void printNegativeSign(uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a dot for floating point numbers at the specified position on the LCD..
     *
     * @param startX The column position where the dot should be displayed.
     * @param startY The row position where the dot should be displayed.
     */
    void printDot(uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a colon  at the specified position on the LCD.
     *
     * @param startX The column position where the colon should be displayed.
     * @param startY The row position where the colon should be displayed.
     */
    void printColon(uint8_t startX, uint8_t startY);

    
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