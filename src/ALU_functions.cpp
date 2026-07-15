/*#include "ALU_pin.h"
#include <avr/io.h>
#include <math.h>

ALUResult computeSUM(uint8_t a, uint8_t b) {
    ALUResult r {};
    uint8_t sum = a + b;
    r.result = sum & 0xF;
    r.carry  = sum > 0xF;
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeSUB(uint8_t a, uint8_t b) {
    ALUResult r {};
    uint8_t diff = a - b;
    r.result = diff & 0xF;
    r.carry  = (b > a);
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeMULT(uint8_t a, uint8_t b) {
    ALUResult r {};
    uint16_t product = (uint16_t)a * b;
    r.result = product & 0xF;
    r.carry  = (product > 0xF);
    r.zero   = (r.result == 0);
    return r;
}

ALUResult computeDIV(uint8_t a, uint8_t b) {
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

ALUResult computeEXP(uint8_t a, uint8_t b) {
    ALUResult r {};
    uint8_t val = (uint8_t)pow((double)a, (double)b);
    r.result = val & 0xF;
    r.carry  = (val > 0xF);
    r.zero   = (r.result == 0);
    return r;
}
*/