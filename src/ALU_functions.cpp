#include "ALU_function.h"
#include <avr/io.h>
#include <math.h>

ALUResult computeSUM(uint16_t a, uint16_t b) {
    ALUResult r {};
    uint16_t sum = a + b;
    r.result = sum & 0xFF;
    r.carry  = sum > 0xFF;
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeSUB(uint16_t a, uint16_t b) {
    ALUResult r {};
    uint16_t diff = a - b;
    r.result = diff & 0xFF;
    r.carry  = (b > a);
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeMULT(uint16_t a, uint16_t b) {
    ALUResult r {};
    uint32_t product = (uint32_t)a * b;
    r.result = product & 0xFF;
    r.carry  = (product > 0xFF);
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeDIV(uint16_t a, uint16_t b) {
    ALUResult r {};
    if (b == 0) {
        r.result = 0xF;
        r.carry  = true;
        r.zero   = false;
        return r;
    }
    r.result = (a / b) & 0xF;
    r.carry  = false;
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeEXP(uint16_t a, uint16_t b) {
    ALUResult r {};
    uint16_t val = (uint16_t)pow((double)a, (double)b);
    r.result = val & 0xFF;
    r.carry  = (val > 0xFF);
    r.zero   = (r.result == 0);
    return r;
}