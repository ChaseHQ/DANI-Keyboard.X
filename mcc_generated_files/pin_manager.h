/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1509
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set KB_CLK aliases
#define KB_CLK_TRIS                 TRISBbits.TRISB4
#define KB_CLK_LAT                  LATBbits.LATB4
#define KB_CLK_PORT                 PORTBbits.RB4
#define KB_CLK_WPU                  WPUBbits.WPUB4
#define KB_CLK_ANS                  ANSELBbits.ANSB4
#define KB_CLK_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define KB_CLK_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define KB_CLK_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define KB_CLK_GetValue()           PORTBbits.RB4
#define KB_CLK_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define KB_CLK_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define KB_CLK_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define KB_CLK_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define KB_CLK_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define KB_CLK_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set KB_DATA aliases
#define KB_DATA_TRIS                 TRISBbits.TRISB5
#define KB_DATA_LAT                  LATBbits.LATB5
#define KB_DATA_PORT                 PORTBbits.RB5
#define KB_DATA_WPU                  WPUBbits.WPUB5
#define KB_DATA_ANS                  ANSELBbits.ANSB5
#define KB_DATA_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define KB_DATA_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define KB_DATA_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define KB_DATA_GetValue()           PORTBbits.RB5
#define KB_DATA_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define KB_DATA_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define KB_DATA_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define KB_DATA_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define KB_DATA_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define KB_DATA_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LATCH aliases
#define LATCH_TRIS                 TRISBbits.TRISB6
#define LATCH_LAT                  LATBbits.LATB6
#define LATCH_PORT                 PORTBbits.RB6
#define LATCH_WPU                  WPUBbits.WPUB6
#define LATCH_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LATCH_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LATCH_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LATCH_GetValue()           PORTBbits.RB6
#define LATCH_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LATCH_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define LATCH_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define LATCH_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set CA2 aliases
#define CA2_TRIS                 TRISBbits.TRISB7
#define CA2_LAT                  LATBbits.LATB7
#define CA2_PORT                 PORTBbits.RB7
#define CA2_WPU                  WPUBbits.WPUB7
#define CA2_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define CA2_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define CA2_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define CA2_GetValue()           PORTBbits.RB7
#define CA2_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define CA2_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define CA2_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define CA2_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set DATA_0 aliases
#define DATA_0_TRIS                 TRISCbits.TRISC0
#define DATA_0_LAT                  LATCbits.LATC0
#define DATA_0_PORT                 PORTCbits.RC0
#define DATA_0_ANS                  ANSELCbits.ANSC0
#define DATA_0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DATA_0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DATA_0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DATA_0_GetValue()           PORTCbits.RC0
#define DATA_0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DATA_0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DATA_0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define DATA_0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set DATA_1 aliases
#define DATA_1_TRIS                 TRISCbits.TRISC1
#define DATA_1_LAT                  LATCbits.LATC1
#define DATA_1_PORT                 PORTCbits.RC1
#define DATA_1_ANS                  ANSELCbits.ANSC1
#define DATA_1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DATA_1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DATA_1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DATA_1_GetValue()           PORTCbits.RC1
#define DATA_1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DATA_1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DATA_1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define DATA_1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set DATA_2 aliases
#define DATA_2_TRIS                 TRISCbits.TRISC2
#define DATA_2_LAT                  LATCbits.LATC2
#define DATA_2_PORT                 PORTCbits.RC2
#define DATA_2_ANS                  ANSELCbits.ANSC2
#define DATA_2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define DATA_2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define DATA_2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define DATA_2_GetValue()           PORTCbits.RC2
#define DATA_2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define DATA_2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define DATA_2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define DATA_2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set DATA_3 aliases
#define DATA_3_TRIS                 TRISCbits.TRISC3
#define DATA_3_LAT                  LATCbits.LATC3
#define DATA_3_PORT                 PORTCbits.RC3
#define DATA_3_ANS                  ANSELCbits.ANSC3
#define DATA_3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DATA_3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DATA_3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DATA_3_GetValue()           PORTCbits.RC3
#define DATA_3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DATA_3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define DATA_3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define DATA_3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set DATA_4 aliases
#define DATA_4_TRIS                 TRISCbits.TRISC4
#define DATA_4_LAT                  LATCbits.LATC4
#define DATA_4_PORT                 PORTCbits.RC4
#define DATA_4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define DATA_4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define DATA_4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define DATA_4_GetValue()           PORTCbits.RC4
#define DATA_4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define DATA_4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set DATA_5 aliases
#define DATA_5_TRIS                 TRISCbits.TRISC5
#define DATA_5_LAT                  LATCbits.LATC5
#define DATA_5_PORT                 PORTCbits.RC5
#define DATA_5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DATA_5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DATA_5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DATA_5_GetValue()           PORTCbits.RC5
#define DATA_5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DATA_5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set DATA_6 aliases
#define DATA_6_TRIS                 TRISCbits.TRISC6
#define DATA_6_LAT                  LATCbits.LATC6
#define DATA_6_PORT                 PORTCbits.RC6
#define DATA_6_ANS                  ANSELCbits.ANSC6
#define DATA_6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define DATA_6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define DATA_6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define DATA_6_GetValue()           PORTCbits.RC6
#define DATA_6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define DATA_6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define DATA_6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define DATA_6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set DATA_7 aliases
#define DATA_7_TRIS                 TRISCbits.TRISC7
#define DATA_7_LAT                  LATCbits.LATC7
#define DATA_7_PORT                 PORTCbits.RC7
#define DATA_7_ANS                  ANSELCbits.ANSC7
#define DATA_7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define DATA_7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define DATA_7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define DATA_7_GetValue()           PORTCbits.RC7
#define DATA_7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define DATA_7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define DATA_7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define DATA_7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF4 pin functionality
 * @Example
    IOCBF4_ISR();
 */
void IOCBF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_InterruptHandler);

*/
extern void (*IOCBF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);

*/
void IOCBF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/