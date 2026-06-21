#include <iostream>
#pragma once

// define the pins on the board with bit/hex code ATmega328P
#define INPUT_BIT0 2 // pin D2
#define INPUT_BIT1 3 // pin D3
#define OUTPUT_BIT2 4 // pin D4

// define as input and output
DDRD |= (1<< OUTPUT_BIT2);
DDRD &= ~(1 << RESULT_BIT0);
DDRD &= ~(1 << RESULT_BIT1);

// define functions of the arithmetic operators
#ifndef ALU_pin.h
#define ALU_pin.h
#include <Arduino.h>

// Create a struct for the result
struct ALUResult(){
    uint8_t result;
    bool zero;
    bool carry;
}

ALUResult computeSUM(uint8_t a, uint8_t b);
ALUResult computeSUB(uint8_t a, uint8_t b);
ALUResult computeDIV(uint8_t a, uint8_t b);
ALUResult computeMULT(uint8_t a, uint8_t b);
ALUResult computeEXP(uint8_t a, uint8_t b);

#endif