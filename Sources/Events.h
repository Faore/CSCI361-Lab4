/* ###################################################################
**     Filename    : Events.h
**     Project     : Lab 3
**     Processor   : MKL46Z256VMC4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-03, 16:22, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "LED_RED.h"
#include "LED_GREEN.h"
#include "SegLCD1.h"
#include "TI1.h"
#include "TU1.h"
#include "PTC.h"
#include "GPIO1.h"
#include "TSS1.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL46Z256MC4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt_LDD]
*/
/*!
**     @brief
**         Called if periodic event occur. Component and OnInterrupt
**         event must be enabled. See [SetEventMask] and [GetEventMask]
**         methods. This event is available only if a [Interrupt
**         service/event] is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
*/
/* ===================================================================*/
void TI1_OnInterrupt(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  GPIO1_OnPortEvent (module Events)
**
**     Component   :  GPIO1 [GPIO_LDD]
*/
/*!
**     @brief
**         Called if defined event on any pin of the port occured.
**         OnPortEvent event and GPIO interrupt must be enabled. See
**         SetEventMask() and GetEventMask() methods. This event is
**         enabled if [Interrupt service/event] is Enabled and disabled
**         if [Interrupt service/event] is Disabled.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/
void GPIO1_OnPortEvent(LDD_TUserData *UserDataPtr);

void TSS1_fOnFault(byte u8FaultElecNum);
/*
** ===================================================================
**     Event       :  TSS1_fOnFault (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is called by TSS after Fault
**         occurence. This event is enabled always and depends on
**         selection 'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**         Option is available from TSS3.0 version.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8FaultElecNum  - The value defines
**                           electrode number on which measurement fault
**                           occured.
**     Returns     : Nothing
** ===================================================================
*/

void TSS1_fOnInit(void);
/*
** ===================================================================
**     Event       :  TSS1_fOnInit (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is automatically called during the
**         TSS Init function execution. The function is intended for
**         implementation of peripherals initialization. TSS Component
**         automatically enables clock for all used TSS peripherals in
**         the internal function TSS_InitDevices which is called by
**         this callback.
**         This event is enabled always and depends on selection
**         'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TSS1_fCallBack0(TSS_CONTROL_ID u8ControlId);
/*
** ===================================================================
**     Event       :  TSS1_fCallBack0 (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         Callback definition for Control 0. This event is enabled
**         only if Control 0 is enabled.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8ControlId     - Valid unique Identifier of
**                           the Control which generated the CallBack
**                           function. This Id can be used for finding
**                           of Callback's source Control.
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
