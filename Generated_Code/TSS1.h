/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TSS1.h
**     Project     : Lab 3
**     Processor   : MKL46Z256VMC4
**     Component   : TSS_Library
**     Version     : Component 03.001, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-05, 21:27, # CodeGen: 15
**     Contents    :
**         Configure - byte TSS1_Configure(void);
**
**     (c) Copyright Freescale Semiconductor, Inc. 2013
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TSS1.h
** @version 01.00
*/         
/*!
**  @addtogroup TSS1_module TSS1 module documentation
**  @{
*/         

#ifndef __TSS1_H
#define __TSS1_H

/* MODULE TSS1. */


/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE TSS1. */

#include "Cpu.h"

/* Include inherited components */
#include "TSS_API.h"

/* List of macros for calling methods without "TSS1_" prefix */
#define Configure TSS1_Configure

void TSS1_InitDevices(void);
/*
** ===================================================================
**     Function    :  TSS1_InitDevices
**     Description :
**         The function is intended for implementation of peripherals
**         initialization. TSS Component automatically enables clock
**         for all used TSS peripherals, setup pin multiplexors,
**         installs RTOS interrupt service routines etc.
**         This function is generated always and depends on user if
**         it is used.
**         This function is automatically called during the
**         TSS1_fOnInit callback execution.
**     Parameters  : None
**     Returns     : None
** ===================================================================
*/

byte TSS1_Configure(void);
/*
** ===================================================================
**     Method      :  TSS1_Configure (component TSS_Library)
**     This method can be used also under name "Configure"
**
**     Description :
**         Whole TSS initialization and configuration of registers.
**         Contains main TSS_Init() function, TSS System Config
**         registers and all Control Config registers initialization
**         according to setting of Component properties. The user have
**         to place this function into the proper location in the
**         source code.
**     Parameters  : None
**     Returns     :
**         ---             - Error status code of Configure method. If
**                           the configuration is successful the
**                           TSS_STATUS_OK is reported, otherwise is
**                           reported one of error status codes
**                           described in TSSAPIRM document.
** ===================================================================
*/


/* END TSS1. */
#endif
/* ifndef __TSS1_H */
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
