#ifndef BIGNUMBERS_I2C_H
#define BIGNUMBERS_I2C_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <stdint.h>

class BigNumbers_I2C
{
public:
    /**
     * @brief Constructor for BigNumbers_I2C class.
     *
     * @param lcd Pointer to a LiquidCrystal_I2C object for LCD interaction.
     */
    BigNumbers_I2C(LiquidCrystal_I2C *lcd);

    /**
     * @brief Initializes the LCD with custom characters.
     */
    void begin(void);

    /**
     * @brief Clears a digit at the specified starting position on the LCD.
     *
     * @param startX The column position where the digit should be cleared.
     */
    void clearDigit(uint8_t startX);

    /**
     * @brief Prints an integer number starting from the specified digit position.
     *
     * @param value The integer number to be displayed.
     * @param startX The column position where the number should start displaying.
     */
    void printInt(int, uint8_t startX);

    /**
     * @brief Prints a floating-point number starting from the specified digit position.
     *
     * @param value The floating-point number to be displayed.
     * @param startX The column position where the number should start displaying.
     */
    void printFloat(float, uint8_t startX);

private:
    LiquidCrystal_I2C *_lcd;
    uint8_t _currIndex;
    uint8_t _prevLength;

    /**
     * @brief Prints a single-digit number (0-9) at the specified position on the LCD.
     *
     * @param digit The digit to be displayed (0-9).
     * @param startX The column position where the digit should be displayed.
     */
    void printDigit(uint8_t digit, uint8_t startX);

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