#include <Arduino.h>
#include <avr/io.h>
#include "ALU_function.h"
#include <stdio.h>
#include <LiquidCrystal.h>

// LCD pin configuration
LiquidCrystal lcd(8, 9 ,10, 11, 12, 13);

// Button pins
#define BUTTON_INCREMENT 2
#define BUTTON_CONFIRM 3
#define BUTTON_RESET 7

// State machine ( the state the program is in. ex. num1 -> value num2 -> operation -> result)
enum State {ENTER_A, ENTER_B, SELECT_OPERATION, DISPLAY_RESULT};
State currentState = ENTER_A;

// ALU input variables
uint16_t A = 0; // First number
uint16_t B = 0; // Second number
uint16_t operation = 0; // Operation to perform (0=SUM, 1=SUB, 2=MULT, 3=DIV)
ALUResult result; // Result of the ALU operation

// Function to apply the ALU result to the output pins
const char* operationNames[] = {"+", "-", "*", "/"};

// Button debouncing variables
bool lastIncrementState = HIGH;
bool lastConfirmState = HIGH;
bool lastResetState = HIGH;

// Only makes changes to the LCD display when the state 
// changes or when a new number is entered. 
void updateDisplay(){
    lcd.clear();
    switch (currentState) {
        case ENTER_A:
            lcd.setCursor(0, 0);
            lcd.print("Enter Number 1:");
            lcd.setCursor(0, 1);
            lcd.print(A);
            break;
        case ENTER_B:
            lcd.setCursor(0, 0);
            lcd.print("Enter Number 2:");
            lcd.setCursor(0, 1);
            lcd.print(B);
            break;
        case SELECT_OPERATION:
            lcd.setCursor(0, 0);
            lcd.print("Operation:");
            lcd.setCursor(0, 1);
            lcd.print(operationNames[operation]);
            break;
        case DISPLAY_RESULT:
            lcd.setCursor(0, 0);
            lcd.print(A);
            lcd.print(" ");
            lcd.print(operationNames[operation]);
            lcd.print(" ");
            lcd.print(B);
            lcd.setCursor(0, 1);
            lcd.print("= ");
            lcd.print(result.result);
            if (result.carry) lcd.print(" C");
            if (result.zero)  lcd.print(" Z");
            break;
    }
}

void setup() {

    // LCD Set up
    lcd.begin(16, 2);
    Serial.begin(9600);
    // ignore lcd.setCursor(0, 0);
    // ignore lcd.setCursor(0, 1);

    // Setting the actual pins for the buttons
    pinMode(BUTTON_INCREMENT, INPUT_PULLUP);
    pinMode(BUTTON_CONFIRM, INPUT_PULLUP);
    pinMode(BUTTON_RESET, INPUT_PULLUP);

    // push the update to the display
    updateDisplay();
}

void loop() {

    // Variables
    bool incrementPressed = (digitalRead(BUTTON_INCREMENT) == LOW);
    bool confirmPressed = (digitalRead(BUTTON_CONFIRM) == LOW);
    bool resetPressed = (digitalRead(BUTTON_RESET) == LOW);

    // 1st button is pressed increment (first state)
    if (incrementPressed == LOW && lastIncrementState == HIGH) {
        switch (currentState) {
            case ENTER_A:    A = (A + 1) & 0xFF; break;
            case ENTER_B:    B = (B + 1) & 0xFF; break;
            case SELECT_OPERATION:  operation = (operation + 1) % 4; break;
            default: break;
        }
        updateDisplay();
    }

    // second state confirm button is pressed
    if (confirmPressed == LOW && lastConfirmState == HIGH) {
        switch (currentState) {
            case ENTER_A:   currentState = ENTER_B; break;
            case ENTER_B:   currentState = SELECT_OPERATION; break;
            case SELECT_OPERATION:
                switch (operation) {
                    case 0: result = computeSUM(A, B);  break;
                    case 1: result = computeSUB(A, B);  break;
                    case 2: result = computeMULT(A, B); break;
                    case 3: result = computeDIV(A, B);  break;
                }
                currentState = DISPLAY_RESULT;
                break;
            case DISPLAY_RESULT:
                A = 0; B = 0; operation = 0;
                currentState = ENTER_A;
                break;
        }
        updateDisplay();
    }

    // Reset button is pressed
    if (resetPressed == LOW && lastResetState == HIGH) {
        A = 0; B = 0; operation = 0;
        currentState = ENTER_A;
        updateDisplay();
    }

    lastIncrementState = incrementPressed;
    lastConfirmState   = confirmPressed;
    lastResetState     = resetPressed;

    delay(50);
    /* old code
    // Ask for user input 
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Enter 1st Num:");

    // Get user input

   // note to self: if i comment the code below it makes the lcd display the text in weird half pixels
    delay(500);
    */
}