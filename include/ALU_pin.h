#pragma once
#ifndef ALU_PIN_h
#define ALU_PIN_h

#include <Arduino.h>
#include <avr/io.h>

// define the pins on the board with bit/hex code ATmega328P
#define INPUT_BIT0  2 // pin D2
#define INPUT_BIT1  3 // pin D3
#define OUTPUT_BIT2 4 // pin D4
#define RESULT_BIT0 5 // pin D5
#define RESULT_BIT1 6 // pin D6

// Create a struct for the result
struct ALUResult {
    uint8_t result;
    bool zero;
    bool carry;
};

ALUResult computeSUM(uint8_t a, uint8_t b);
ALUResult computeSUB(uint8_t a, uint8_t b);
ALUResult computeDIV(uint8_t a, uint8_t b);
ALUResult computeMULT(uint8_t a, uint8_t b);
ALUResult computeEXP(uint8_t a, uint8_t b);

#endif