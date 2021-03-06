/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DA1.h
**     Project     : ProcessorExpert
**     Processor   : MKL46Z256VMC4
**     Component   : DAC_LDD
**     Version     : Component 01.081, Driver 01.08, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-16, 15:22, # CodeGen: 23
**     Abstract    :
**         This component implements an internal D/A converter of the MCU.
**         It contains settings for converting various format of a values
**         to supported format of the D/A converter.
**
**     Settings    :
**          Component name                                 : DA1
**          D/A converter                                  : DAC0
**          Interrupt service/event                        : Disabled
**          Output pin                                     : yes
**            D/A channel (pin)                            : DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1
**            D/A channel (pin) signal                     : 
**          Init value                                     : 0
**          D/A resolution                                 : 12 bits
**          Data mode                                      : unsigned 16 bits, right justified
**          Low power mode                                 : Disabled
**          Voltage reference source                       : internal
**          Data buffer                                    : Disabled
**          DMA                                            : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBufferEnd                                : Disabled
**              OnBufferStart                              : Disabled
**              OnComplete                                 : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init     - LDD_TDeviceData* DA1_Init(LDD_TUserData *UserDataPtr);
**         SetValue - LDD_TError DA1_SetValue(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TData Data);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file DA1.h
** @version 01.08
** @brief
**         This component implements an internal D/A converter of the MCU.
**         It contains settings for converting various format of a values
**         to supported format of the D/A converter.
**
*/         
/*!
**  @addtogroup DA1_module DA1 module documentation
**  @{
*/         

#ifndef __DA1_H
#define __DA1_H

/* MODULE DA1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Cpu.h"

#include "DAC_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define DA1_PRPH_BASE_ADDRESS  0x4003F000U
  
/*  This constant contains mask of all events generated by Processor Expert */
#define DA1_AVAILABLE_EVENTS_MASK 0x00U
/* This constant contains minimal buffer size available on selected device. */
#define DA1_BUFFER_MIN_SIZE 0x01U
/* This constant contains maximal buffer size available on selected device. */
#define DA1_BUFFER_MAX_SIZE 0x02U

/*
** ===================================================================
**     Method      :  DA1_Init (component DAC_LDD)
*/
/*!
**     @brief
**         Initializes the device according to design-time
**         configuration properties. Allocates memory for the device
**         data structure. 
**         If the [Enable in init. code] is set to "yes" then the
**         device is also enabled (see the description of the Enable
**         method).
**         This method can be called only once. Before the second call
**         of Init the Deinit method must be called first. If DMA
**         service is enabled this method also initializes inherited
**         DMA Transfer component.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an events or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* DA1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  DA1_SetValue (component DAC_LDD)
*/
/*!
**     @brief
**         Sets DAC output voltage according to specified value.
**         Input data format is specified by [Data mode] property
**         settings. If selected formatting is not native for DAC
**         device which is used then any necessary transformations (e.g.
**         shifting) are done._/Note: This method is available only if
**         Data buffer is disabled./_
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure.
**     @param
**         Data            - User data.
**     @return
**                         - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
*/
/* ===================================================================*/
LDD_TError DA1_SetValue(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TData Data);

/* END DA1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __DA1_H */
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
