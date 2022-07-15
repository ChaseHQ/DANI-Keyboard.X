/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1509
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

typedef char BYTE;

BYTE keyboardBuffer[11] = {};
BYTE keyboardBufferCounter = 0;
bool keyInBuffer = false;

#define SC_BREAK 0xF0
#define SC_EXTEN 0xE0

void kbdInterrupt(void) {
    while (keyboardBufferCounter < 11) {
        while (KB_CLK_GetValue()); // wait until goes low

        if (keyboardBufferCounter < 11) {
            keyboardBuffer[keyboardBufferCounter++] = KB_DATA_PORT;
        }

        while (!KB_CLK_GetValue()); // wait until value goes high
    }
    
    keyboardBufferCounter = 0;
    keyInBuffer = true;
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    IOCBF4_SetInterruptHandler(kbdInterrupt);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    bool keyboardBreak = false;
    bool keyboardExten = false;
    bool inShift       = false;
    bool inCtrl        = false;
    bool inAlt         = false;
    bool inCaps        = false;
    
    while (1)
    {
        if (keyInBuffer) {
            INTERRUPT_GlobalInterruptDisable();
            // Check to see that this is valid keyboard entry
            if (keyboardBuffer[0] == 0 && keyboardBuffer[10] == 1) {
                char keyboardByte = 0;
                bool preserveLast = false;
                char sendCharBuffer = 0;
                bool sendChar = false;
                // The Keyboard Buffer is Valid - do something with it
                for (int x = 1; x < 9; ++x) {
                    keyboardByte |= keyboardBuffer[x] << (x-1);
                }
                switch (keyboardByte) {
                    case SC_BREAK:
                        keyboardBreak = true;
                        preserveLast = true;
                        break;
                    case SC_EXTEN:
                        keyboardExten = true;
                        preserveLast = true;
                        break;
                    case 0x12: // LShift
                    case 0x59: // RShift
                        if (keyboardBreak)
                            inShift = false;
                        else 
                            inShift = true;
                        break;
                    case 0x14: // LCtrl & RCtrl
                        if (keyboardBreak)
                            inCtrl = false;
                        else 
                            inCtrl = true;
                        break;
                    case 0x11: // LAlt & RAlt
                        if (keyboardBreak)
                            inAlt = false;
                        else 
                            inAlt = true;
                        break;
                    case 0x58: // CapsLock
                        if (!keyboardBreak) {
                            inCaps = !inCaps; // Toggle Caps lock
                        }
                        break;
                }
                if (!keyboardBreak) { // If not in keyboard break
                    sendChar = true;
                    switch (keyboardByte) {
                        case 0x1C: // A
                            if (inShift || inCaps)
                                sendCharBuffer = 'A';
                            else 
                                sendCharBuffer = 'a';
                            break;
                        case 0x32: // B
                            if (inShift || inCaps)
                                sendCharBuffer = 'B';
                            else 
                                sendCharBuffer = 'b';
                            break;
                        case 0x21: // C
                            if (inShift || inCaps)
                                sendCharBuffer = 'C';
                            else 
                                sendCharBuffer = 'c';
                            break;
                        case 0x23: // D
                            if (inShift || inCaps)
                                sendCharBuffer = 'D';
                            else 
                                sendCharBuffer = 'd';
                            break;
                        case 0x24: // E
                            if (inShift || inCaps)
                                sendCharBuffer = 'E';
                            else 
                                sendCharBuffer = 'e';
                            break;
                        case 0x2B: // F
                            if (inShift || inCaps)
                                sendCharBuffer = 'F';
                            else 
                                sendCharBuffer = 'f';
                            break; 
                        case 0x34: // G
                            if (inShift || inCaps)
                                sendCharBuffer = 'G';
                            else 
                                sendCharBuffer = 'g';
                            break;
                        case 0x33: // H
                            if (inShift || inCaps)
                                sendCharBuffer = 'H';
                            else 
                                sendCharBuffer = 'h';
                            break; 
                        case 0x43: // I
                            if (inShift || inCaps)
                                sendCharBuffer = 'I';
                            else 
                                sendCharBuffer = 'i';
                            break;
                        case 0x3B: // J
                            if (inShift || inCaps)
                                sendCharBuffer = 'J';
                            else 
                                sendCharBuffer = 'j';
                            break;
                        case 0x42: // K
                            if (inShift || inCaps)
                                sendCharBuffer = 'K';
                            else 
                                sendCharBuffer = 'k';
                            break;
                        case 0x4B: // L
                            if (inShift || inCaps)
                                sendCharBuffer = 'L';
                            else 
                                sendCharBuffer = 'l';
                            break;
                        case 0x3A: // M
                            if (inShift || inCaps)
                                sendCharBuffer = 'M';
                            else 
                                sendCharBuffer = 'm';
                            break;
                        case 0x31: // N
                            if (inShift || inCaps)
                                sendCharBuffer = 'N';
                            else 
                                sendCharBuffer = 'n';
                            break;
                        case 0x44: // O
                            if (inShift || inCaps)
                                sendCharBuffer = 'O';
                            else 
                                sendCharBuffer = 'o';
                            break;
                        case 0x4D: // P
                            if (inShift || inCaps)
                                sendCharBuffer = 'P';
                            else 
                                sendCharBuffer = 'p';
                            break;
                        case 0x15: // Q
                            if (inShift || inCaps)
                                sendCharBuffer = 'Q';
                            else 
                                sendCharBuffer = 'q';
                            break;
                        case 0x2D: // R
                            if (inShift || inCaps)
                                sendCharBuffer = 'R';
                            else 
                                sendCharBuffer = 'r';
                            break;
                        case 0x1B: // S
                            if (inShift || inCaps)
                                sendCharBuffer = 'S';
                            else 
                                sendCharBuffer = 's';
                            break;
                        case 0x2C: // T
                            if (inShift || inCaps)
                                sendCharBuffer = 'T';
                            else 
                                sendCharBuffer = 't';
                            break;
                        case 0x3C: // U
                            if (inShift || inCaps)
                                sendCharBuffer = 'U';
                            else 
                                sendCharBuffer = 'u';
                            break;
                        case 0x2A: // V
                            if (inShift || inCaps)
                                sendCharBuffer = 'V';
                            else 
                                sendCharBuffer = 'v';
                            break;
                        case 0x1D: // W
                            if (inShift || inCaps)
                                sendCharBuffer = 'W';
                            else 
                                sendCharBuffer = 'w';
                            break;
                        case 0x22: // X
                            if (inShift || inCaps)
                                sendCharBuffer = 'X';
                            else 
                                sendCharBuffer = 'x';
                            break;
                        case 0x35: // Y
                            if (inShift || inCaps)
                                sendCharBuffer = 'Y';
                            else 
                                sendCharBuffer = 'y';
                            break;
                        case 0x1A: // Z
                            if (inShift || inCaps)
                                sendCharBuffer = 'Z';
                            else 
                                sendCharBuffer = 'z';
                            break;
                        case 0x45: // 0
                            if (inShift)
                                sendCharBuffer = ')';
                            else
                                sendCharBuffer = '0';
                            break;
                        case 0x16: // 1
                            if (inShift)
                                sendCharBuffer = '!';
                            else
                                sendCharBuffer = '1';
                            break;
                        case 0x1E: // 2
                            if (inShift)
                                sendCharBuffer = '@';
                            else
                                sendCharBuffer = '2';
                            break;
                        case 0x26: // 3
                            if (inShift)
                                sendCharBuffer = '#';
                            else
                                sendCharBuffer = '3';
                            break;
                        case 0x25: // 4
                            if (inShift)
                                sendCharBuffer = '$';
                            else
                                sendCharBuffer = '4';
                            break;
                        case 0x2E: // 5
                            if (inShift)
                                sendCharBuffer = '%';
                            else
                                sendCharBuffer = '5';
                            break;
                        case 0x36: // 6
                            if (inShift)
                                sendCharBuffer = '^';
                            else
                                sendCharBuffer = '6';
                            break;
                        case 0x3D: // 7
                            if (inShift)
                                sendCharBuffer = '&';
                            else
                                sendCharBuffer = '7';
                            break;
                        case 0x3E: // 8
                            if (inShift)
                                sendCharBuffer = '*';
                            else
                                sendCharBuffer = '8';
                            break;
                        case 0x46: // 9
                            if (inShift)
                                sendCharBuffer = '(';
                            else
                                sendCharBuffer = '9';
                            break;
                        case 0x4A: // /
                            if (inShift)
                                sendCharBuffer = '?';
                            else
                                sendCharBuffer = '/';
                            break;
                        case 0x5B: // ]
                            if (inShift)
                                sendCharBuffer = '}';
                            else
                                sendCharBuffer = ']';
                            break;
                        case 0x54: // [
                            if (inShift)
                                sendCharBuffer = '{';
                            else
                                sendCharBuffer = '[';
                            break;
                        case 0x5D: // '\'
                            if (inShift)
                                sendCharBuffer = '|';
                            else
                                sendCharBuffer = '\\';
                            break;
                        case 0x41: // ,
                            if (inShift)
                                sendCharBuffer = '<';
                            else
                                sendCharBuffer = ',';
                            break;
                        case 0x49: // .
                            if (inShift)
                                sendCharBuffer = '>';
                            else
                                sendCharBuffer = '.';
                            break;
                        case 0x4E: // -
                            if (inShift)
                                sendCharBuffer = '_';
                            else
                                sendCharBuffer = '-';
                            break;
                        case 0x55: // =
                            if (inShift)
                                sendCharBuffer = '+';
                            else
                                sendCharBuffer = '=';
                            break;
                        case 0x0E: // `
                            if (inShift)
                                sendCharBuffer = '~';
                            else
                                sendCharBuffer = '`';
                            break;
                        case 0x4C: // ;
                            if (inShift)
                                sendCharBuffer = ':';
                            else
                                sendCharBuffer = ';';
                            break;
                        case 0x52: // '
                            if (inShift)
                                sendCharBuffer = '"';
                            else
                                sendCharBuffer = '\'';
                            break;
                        case 0x29: // [SPACE]
                            sendCharBuffer = ' ';
                            break;
                        case 0x5A: // [ENTER]
                            sendCharBuffer = 0x0D;
                            break;
                        case 0x66: // [BKSP]
                            sendCharBuffer = 0x08;
                            break;
                        case 0x71: // [DELETE]
                            if (keyboardExten) 
                                sendCharBuffer = 0x7F;
                            break;
                        case 0x75: // U ARROW
                            if (keyboardExten) 
                                sendCharBuffer = 0x80;
                            break;
                        case 0x6B: // L ARROW
                            if (keyboardExten) 
                                sendCharBuffer = 0x82;
                            break;
                        case 0x72: // D ARROW
                            if (keyboardExten) 
                                sendCharBuffer = 0x81;
                            break;
                        case 0x74: // R ARROW
                            if (keyboardExten) 
                                sendCharBuffer = 0x83;
                            break;
                        case 0x76: // Backspace
                            sendCharBuffer = 0x1B;
                            break;
                        default:
                            sendChar = false;
                            break;
                    }
                }
                // Check results of everything here and act on it
                if (sendChar) {
                    PORTC = sendCharBuffer;
                    LATCH_SetLow();
                    LATCH_SetHigh();
                }
                // Clear Breaks and Extends if needed
                if (!preserveLast && keyboardBreak) {
                    keyboardBreak = false;
                }
                if (!preserveLast && keyboardExten) {
                    keyboardExten = false;
                }
            }            
            keyInBuffer = false;
            INTERRUPT_GlobalInterruptEnable();
        }
    }
}