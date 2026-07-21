#pragma once
#ifndef ALU_FUNCTIONS_H
#define ALU_FUNCTIONS_H

#include <Arduino.h>
#include <avr/io.h>

#define INPUT_BIT0  2
#define INPUT_BIT1  3
#define OUTPUT_BIT2 4
#define RESULT_BIT0 5
#define RESULT_BIT1 6

struct ALUResult {
    uint16_t result;
    bool zero;
    bool carry;
};

ALUResult computeSUM(uint16_t a, uint16_t b);
ALUResult computeSUB(uint16_t a, uint16_t b);
ALUResult computeDIV(uint16_t a, uint16_t b);
ALUResult computeMULT(uint16_t a, uint16_t b);

#endif