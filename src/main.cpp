/* #include <Arduino.h>
#include <avr/io.h>
#include "ALU_pin.h"
#include <stdio.h>

// Test operands — change these to try different values
static const uint8_t A = 12;
static const uint8_t B = 3;

// Drive carry, zero, and LSB of result onto output pins
static void applyResult(const ALUResult& r) {
    if (r.carry)    PORTD |=  (1 << OUTPUT_BIT2);
    else            PORTD &= ~(1 << OUTPUT_BIT2);

    if (r.zero)     PORTD |=  (1 << RESULT_BIT0);
    else            PORTD &= ~(1 << RESULT_BIT0);

    if (r.result & 1) PORTD |=  (1 << RESULT_BIT1);
    else              PORTD &= ~(1 << RESULT_BIT1);
}

static void printResult(const char* name, uint8_t a, uint8_t b, const ALUResult& r) {
    Serial.print(name);
    Serial.print("("); Serial.print(a);
    Serial.print(", "); Serial.print(b);
    Serial.print(") = "); Serial.print(r.result);
    Serial.print("  carry="); Serial.print(r.carry);
    Serial.print("  zero="); Serial.println(r.zero);
}

void setup() {
    Serial.begin(9600);

    // OUTPUT_BIT2 = carry indicator, RESULT_BIT0 = zero flag, RESULT_BIT1 = result LSB
    DDRD |=  (1 << OUTPUT_BIT2) | (1 << RESULT_BIT0) | (1 << RESULT_BIT1);

    // INPUT_BIT0 and INPUT_BIT1 select the operation (00=SUM, 01=SUB, 10=MULT, 11=DIV)
    DDRD &= ~((1 << INPUT_BIT0) | (1 << INPUT_BIT1));
}

void loop() {

    // Variables
    int currentNum = 0;

    // Ask for user input 
    printf("What is the first number? ");
    
    // Read 2-bit op select from input pins
    uint8_t op = 0;
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
    delay(500);
}
*/
#include <Arduino.h>
#include <LiquidCrystal.h>

// RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("I am so cool");

  lcd.setCursor(0, 1);
  lcd.print("-Lilly");
}

void loop() {}