/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
extern int TouchPosition;
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
void Cpu_OnNMIINT(void)
{

}

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
void TI1_OnInterrupt(LDD_TUserData *UserDataPtr)
//calls the increment function every second when the timer triggers an interrupt
{
  respondToTimerInterrupt();
}

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
void GPIO1_OnPortEvent(LDD_TUserData *UserDataPtr)
//calls the increment function every time button is pressed
{
	handleButtonPress();
}

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
void TSS1_fOnFault(byte u8FaultElecNum)
{
  #if TSS_USE_PE_COMPONENT
  /* If large or small capacitor fault  */
  if(tss_CSSys.Faults.ChargeTimeout || tss_CSSys.Faults.SmallCapacitor)
  {
    /* Write your code here ... */
  }
  /* If data corruption fault  */
  if(tss_CSSys.Faults.DataCorruption)
  {
    /* Write your code here ... */
  }
  /* If small trigger period fault  */
  if(tss_CSSys.Faults.SmallTriggerPeriod)
  {
    /* Write your code here ... */
  }
  /* Clear the fault flags */
  (void) TSS_SetSystemConfig(System_Faults_Register, 0x00);

  (void) u8FaultElecNum;
  return;
  #endif
}

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
void TSS1_fOnInit(void)
{
  #if TSS_USE_PE_COMPONENT
    TSS1_InitDevices();
  #endif

  /* Write your code here ... */

}

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
void TSS1_fCallBack0(TSS_CONTROL_ID u8ControlId)
{
  if (AnalogSlider.DynamicStatus.Movement)
  {
    if (AnalogSlider.Events.Touch)
    {
      if (!(AnalogSlider.Events.InvalidPos))
      {
        TouchPosition = AnalogSlider.Position;

        /* Write your code here ... */
      }
    }
    else
    {
      /* Write your code here ... */
    }
  }


  (void) u8ControlId;
  return;
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
