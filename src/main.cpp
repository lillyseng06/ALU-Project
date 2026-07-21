#include <Arduino.h>
#include <avr/io.h>
#include "ALU_function.h"
#include <stdio.h>
#include <LiquidCrystal.h>

// LCD pin configuration
LiquidCrystal lcd(8, 9 ,10, 11, 12, 13);


static void printResult(const char* name, uint8_t a, uint8_t b, const ALUResult& r) {
    /*
    Serial.print(name);
    Serial.print("("); Serial.print(a);
    Serial.print(", "); Serial.print(b);
    Serial.print(") = "); Serial.print(r.result);
    Serial.print("  carry="); Serial.print(r.carry);
    Serial.print("  zero="); Serial.println(r.zero);
    */
}

void setup() {

    // LCD Set up (test trial)
    lcd.begin(16, 2);

    lcd.setCursor(0, 0);
    // lcd.print("Andy,");

    lcd.setCursor(0, 1);
    // lcd.print("I love you!");
    
    // Serial set up
    Serial.begin(9600);

    // Set output pins for carry, zero, and result LSB

    // OUTPUT_BIT2 = carry indicator, RESULT_BIT0 = zero flag, RESULT_BIT1 = result LSB
    /* DDRD |=  (1 << OUTPUT_BIT2) | (1 << RESULT_BIT0) | (1 << RESULT_BIT1);

    // INPUT_BIT0 and INPUT_BIT1 select the operation (00=SUM, 01=SUB, 10=MULT, 11=DIV)
    DDRD &= ~((1 << INPUT_BIT0) | (1 << INPUT_BIT1));
    */
}

void loop() {

    // Variables
    // int currentNum = 0;

    // Ask for user input 
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Enter 1st Num:");

    // Get user input

    
    // Read 2-bit op select from input pins
    /* uint8_t op = 0;
    if (PIND & (1 << INPUT_BIT0)) op |= 0x01;
    if (PIND & (1 << INPUT_BIT1)) op |= 0x02;

    ALUResult r;
    switch (op) {
        case 0: r = computeSUM(A, B);  printResult("SUM",  A, B, r); break;
        case 1: r = computeSUB(A, B);  printResult("SUB",  A, B, r); break;
        case 2: r = computeMULT(A, B); printResult("MULT", A, B, r); break;
        case 3: r = computeDIV(A, B);  printResult("DIV",  A, B, r); break;
        default: return;
    }

    applyResult(r);
    */
   // note to self: if i comment the code below it makes the lcd display the text in weird half pixels
    delay(500);
}