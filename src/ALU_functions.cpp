#include <iostream>
#include ALU_pin.h
#include Math.h

#pragma once

// Create the functions
ALURESULT computeSUM(uint8_t a, uint8_t b){
    ALUResult {};
    uint8_t sum = a + b;
    r.result = sum & 0xf;
    r.carry = sum > 0xF;
    r.zero = (r.result == 0);
    return r;
}



