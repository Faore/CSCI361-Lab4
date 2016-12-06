/* ###################################################################
**     Filename    : main.c
**     Project     : Lab 3
**     Processor   : MKL46Z256VMC4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-03, 16:22, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LED_RED.h"
#include "LED_GREEN.h"
#include "SegLCD1.h"
#include "TI1.h"
#include "TU1.h"
#include "PTC.h"
#include "GPIO1.h"
#include "TSS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
int main(void);
void respondToTimerInterrupt(void);
extern int timerUpdate(int);
extern int timerDoneCheck(int);
void writeToLCD(int);
void handleButtonPress();

int mode = 2; //0: Counting Down, 1: Paused, 2: Setup, 3: Finish

int TouchPosition = 0;
int interruptCount = 0;
int TimerTime = 10;
int CurrentTime = 10;

LDD_TDeviceData *MySegLCDPtr , *RED, *GREEN;

char seg[]={7,8,10,11,17,37,38,53}; // seven segment connection
char col[]={0,1,2,3}; // column of lcd

char sLCDBuffer[16];
int main_counter,i,j,m;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

void respondToTimerInterrupt(void){
	//Counting Down
	if(mode == 0) {
		interruptCount++;
		if(timerUpdate(interruptCount) == 1) {
			CurrentTime--;
			writeToLCD(CurrentTime);
			interruptCount = 0;
		}

		if(timerDoneCheck(CurrentTime)) {
			mode = 3; //Finish the timer
			LED_GREEN_NegVal(GREEN);
		}
	}
	//In setup
	else if (mode == 2) {
		LED_RED_ClrVal(RED);
		LED_GREEN_ClrVal(GREEN);
		TimerTime = TouchPosition;
		CurrentTime = TouchPosition;
		writeToLCD(CurrentTime);
	}
	//Just Finished, Flashing Lights
	else if(mode == 3) {
		LED_GREEN_NegVal(GREEN);
		LED_RED_NegVal(RED);
	}
}

void handleButtonPress() {
	//In setup, change to count down
	if(mode == 2) {
		mode = 0;
	}
	if(mode == 3) {
		mode = 2;
	}
}

void writeToLCD(int content) {
	sprintf(sLCDBuffer, "%04i", content);
	vfnLCD_Write_Msg((uint8 *) sLCDBuffer);
}

int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  //Setup Touch Sensor
  TSS1_Configure();
  TSS1_InitDevices();
  //Setup LCD
  MySegLCDPtr = SegLCD1_Init(NULL);
  //Setup LEDs
  RED = LED_RED_Init(NULL);
  GREEN = LED_GREEN_Init(NULL);
  //Turn off all LCD segments
  vfnLCD_All_Segments_OFF();
  //Set timer to the current time
  sprintf(sLCDBuffer, "%04i", CurrentTime);
  vfnLCD_Write_Msg((uint8 *) sLCDBuffer);
  //Negate the LEDs
  //LED_GREEN_NegVal(GREEN);
  //LED_RED_NegVal(RED);

  for(;;) {
	  TSS_Task();
  }
  //vfnLCD_All_Segments_OFF();
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
