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
     * @brief Clears a digit at the specified starting position on the LCD.
     *
     * @param startX The column position where the digit should be cleared.
     * @param startY The row position where the digit should be cleared.
     */
    void clearDigit(uint8_t startX, uint8_t startY);

    /**
     * @brief Prints an integer number starting from the specified digit position.
     *
     * @param value The integer number to be displayed.
     * @param startX The column position where the digit should be displayed.
     * @param startY The row position where the digit should be displayed.
     */
    void printInt(int value, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints an integer number at the default position.
     *
     * @param value The integer number to be displayed.
     */
    void printInt(int value);

    /**
     * @brief Prints a floating-point number starting from the specified digit position.
     *
     * @param value The floating-point number to be displayed.
     * @param startX The column position where the digit should be displayed.
     * @param startY The row position where the digit should be displayed.
     */
    void printFloat(float value, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a floating-point number at the default position.
     *
     * @param value The floating-point number to be displayed.
     */
    void printFloat(float value);

    /**
     * @brief Prints a floating-point number starting from the specified digit position.
     *
     * @param value The floating-point number to be displayed.
     * @param startX The column position where the digit should be displayed.
     * @param startY The row position where the digit should be displayed.
     */
    void printDouble(double value, uint8_t startX, uint8_t startY);

    /**
     * @brief Prints a floating-point number at the default position.
     *
     * @param value The floating-point number to be displayed.
     */
    void printDouble(double value);

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