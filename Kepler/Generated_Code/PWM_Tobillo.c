/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWM_Tobillo.c
**     Project     : ProcessorExpert
**     Processor   : MKL46Z256VMC4
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-22, 05:42, # CodeGen: 32
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       19            |  LCD_P59/ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX
**             ----------------------------------------------------
**
**         Timer name                  : TPM1_CNT [16-bit]
**         Counter                     : TPM1_CNT  [0x40039004]
**         Mode register               : TPM1_SC   [0x40039000]
**         Run register                : TPM1_SC   [0x40039000]
**         Prescaler                   : TPM1_SC   [0x40039000]
**         Compare register            : TPM1_C0V  [0x40039010]
**         Flip-flop register          : TPM1_C0SC [0x4003900C]
**
**         Interrupt name              : INT_TPM1
**         Interrupt enable reg.       : TPM1_C1SC [0x40039014]
**         Priority                    : 2
**         User handling procedure     : PWM_Tobillo_OnEnd
**         This event is called when the 1 of cycles is generated
**
**         Port name                   : PTE
**         Bit number (in port)        : 20
**         Bit mask of the port        : 0x00100000
**         Port data register          : GPIOE_PDOR [0x400FF100]
**         Port control register       : GPIOE_PDDR [0x400FF114]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-[driven by slave component]
**             Clock                   : [driven by slave component] Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : ---        ---
**             microseconds            : ---        ---
**             milliseconds            : 20         1
**             seconds                 : ---        ---
**             seconds (real)          : 20         1
**
**     Contents    :
**         Enable     - byte PWM_Tobillo_Enable(void);
**         Disable    - byte PWM_Tobillo_Disable(void);
**         SetRatio16 - byte PWM_Tobillo_SetRatio16(word Ratio);
**         SetDutyUS  - byte PWM_Tobillo_SetDutyUS(word Time);
**         SetDutyMS  - byte PWM_Tobillo_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PWM_Tobillo.c
** @version 01.01
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup PWM_Tobillo_module PWM_Tobillo module documentation
**  @{
*/         

/* MODULE PWM_Tobillo. */

#include "Events.h"
#include "PWM_Tobillo.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Method      :  PWM_Tobillo_OnEnd (component PWM)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PwmLdd4_OnEnd(LDD_TUserData *UserDataPtr)
{
  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  PWM_Tobillo_OnEnd();                 /* Invoke OnEnd event */
}

/*
** ===================================================================
**     Method      :  PWM_Tobillo_Enable (component PWM)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte PWM_Tobillo_Enable(void)
**  This method is implemented as a macro. See PWM_Tobillo.h file.  **
*/

/*
** ===================================================================
**     Method      :  PWM_Tobillo_Disable (component PWM)
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte PWM_Tobillo_Disable(void)
**  This method is implemented as a macro. See PWM_Tobillo.h file.  **
*/

/*
** ===================================================================
**     Method      :  PWM_Tobillo_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte PWM_Tobillo_SetRatio16(word Ratio)
**  This method is implemented as a macro. See PWM_Tobillo.h file.  **
*/

/*
** ===================================================================
**     Method      :  PWM_Tobillo_SetDutyUS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to --- us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
/*
byte PWM_Tobillo_SetDutyUS(word Time)
**  This method is implemented as a macro. See PWM_Tobillo.h file.  **
*/

/*
** ===================================================================
**     Method      :  PWM_Tobillo_SetDutyMS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to 20 ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
/*
byte PWM_Tobillo_SetDutyMS(word Time)
**  This method is implemented as a macro. See PWM_Tobillo.h file.  **
*/

/* END PWM_Tobillo. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
