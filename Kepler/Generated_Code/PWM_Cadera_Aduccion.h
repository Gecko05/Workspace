/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWM_Cadera_Aduccion.h
**     Project     : ProcessorExpert
**     Processor   : MKL46Z256VMC4
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-22, 01:01, # CodeGen: 30
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       84            |  LCD_P24/PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3/I2S0_MCLK
**             ----------------------------------------------------
**
**         Timer name                  : TPM0_CNT [16-bit]
**         Counter                     : TPM0_CNT  [0x40038004]
**         Mode register               : TPM0_SC   [0x40038000]
**         Run register                : TPM0_SC   [0x40038000]
**         Prescaler                   : TPM0_SC   [0x40038000]
**         Compare register            : TPM0_C3V  [0x40038028]
**         Flip-flop register          : TPM0_C3SC [0x40038024]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTC
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**         Port data register          : GPIOC_PDOR [0x400FF080]
**         Port control register       : GPIOC_PDDR [0x400FF094]
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
**             milliseconds            : 20         2
**             seconds                 : ---        ---
**             seconds (real)          : 20         2
**
**     Contents    :
**         Enable     - byte PWM_Cadera_Aduccion_Enable(void);
**         Disable    - byte PWM_Cadera_Aduccion_Disable(void);
**         SetRatio16 - byte PWM_Cadera_Aduccion_SetRatio16(word Ratio);
**         SetDutyUS  - byte PWM_Cadera_Aduccion_SetDutyUS(word Time);
**         SetDutyMS  - byte PWM_Cadera_Aduccion_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PWM_Cadera_Aduccion.h
** @version 01.01
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup PWM_Cadera_Aduccion_module PWM_Cadera_Aduccion module documentation
**  @{
*/         

#ifndef __PWM_Cadera_Aduccion_H
#define __PWM_Cadera_Aduccion_H

/* MODULE PWM_Cadera_Aduccion. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PwmLdd3.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define PWM_Cadera_Aduccion_PERIOD_VALUE PwmLdd3_PERIOD_VALUE /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define PWM_Cadera_Aduccion_PERIOD_VALUE_HIGH PwmLdd3_PERIOD_VALUE_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  PWM_Cadera_Aduccion_Enable (component PWM)
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
#define PWM_Cadera_Aduccion_Enable() (PwmLdd3_Enable(PwmLdd3_DeviceData))

/*
** ===================================================================
**     Method      :  PWM_Cadera_Aduccion_Disable (component PWM)
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
#define PWM_Cadera_Aduccion_Disable() (PwmLdd3_Disable(PwmLdd3_DeviceData))

/*
** ===================================================================
**     Method      :  PWM_Cadera_Aduccion_SetRatio16 (component PWM)
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
#define PWM_Cadera_Aduccion_SetRatio16(Ratio) (PwmLdd3_SetRatio16(PwmLdd3_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  PWM_Cadera_Aduccion_SetDutyUS (component PWM)
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
#define PWM_Cadera_Aduccion_SetDutyUS(Time) (PwmLdd3_SetDutyUS(PwmLdd3_DeviceData, Time))

/*
** ===================================================================
**     Method      :  PWM_Cadera_Aduccion_SetDutyMS (component PWM)
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
#define PWM_Cadera_Aduccion_SetDutyMS(Time) (PwmLdd3_SetDutyMS(PwmLdd3_DeviceData, Time))

/* END PWM_Cadera_Aduccion. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __PWM_Cadera_Aduccion_H */
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
