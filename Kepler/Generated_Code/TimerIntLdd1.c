/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TimerIntLdd1.c
**     Project     : ProcessorExpert
**     Processor   : MKL46Z256VMC4
**     Component   : TimerInt_LDD
**     Version     : Component 01.018, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-14, 17:56, # CodeGen: 8
**     Abstract    :
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : TimerIntLdd1
**          Periodic interrupt source                      : TPM2_C0V
**          Counter                                        : TPM2_CNT
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_TPM2
**            Interrupt priority                           : medium priority
**          Interrupt period                               : 26.8 �s
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked TimerUnit                             : TU3
**     Contents    :
**         Init - LDD_TDeviceData* TimerIntLdd1_Init(LDD_TUserData *UserDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TimerIntLdd1.c
** @version 01.01
** @brief
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup TimerIntLdd1_module TimerIntLdd1 module documentation
**  @{
*/         

/* MODULE TimerIntLdd1. */

#include "TI1.h"
#include "TimerIntLdd1.h"
/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TDeviceData *LinkedDeviceDataPtr;
  bool EnUser;                         /* Enable/Disable device */
  LDD_TEventMask EnEvents;             /* Enable/Disable events mask */
  uint16_t CmpVal;                     /* Value periodically addded to compare register */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} TimerIntLdd1_TDeviceData;

typedef TimerIntLdd1_TDeviceData *TimerIntLdd1_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static TimerIntLdd1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define CHANNEL 0x00U
#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERINT_ON_INTERRUPT)
/* Internal method prototypes */
/*
** ===================================================================
**     Method      :  TimerIntLdd1_Init (component TimerInt_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* TimerIntLdd1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  TimerIntLdd1_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  DeviceDataPrv->EnEvents = 0x01u;     /* Initial event mask */
  DeviceDataPrv->EnUser = TRUE;        /* Set the flag "device enabled" */
  DeviceDataPrv->CmpVal = 0x0232U;     /* Initial value periodically addded to compare register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_TimerIntLdd1_ID,DeviceDataPrv);
  DeviceDataPrv->LinkedDeviceDataPtr = TU3_Init((LDD_TUserData *)NULL);
  if (DeviceDataPrv->LinkedDeviceDataPtr == NULL) { /* Is initialization of TimerUnit unsuccessful? */
    /* Unregistration of the device structure */
    PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_TimerIntLdd1_ID);
    /* Deallocation of the device structure */
    /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
    return NULL;                       /* If so, then the TimerInt initialization is also unsuccessful */
  }
  (void)TU3_SetEventMask(DeviceDataPrv->LinkedDeviceDataPtr, TU3_GetEventMask(DeviceDataPrv->LinkedDeviceDataPtr) | LDD_TIMERUNIT_ON_CHANNEL_0); /* Enable TimerUnit event */
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  TU3_OnChannel0 (component TimerInt_LDD)
**
**     Description :
**         The method services the event of the linked component TU3 and 
**         eventually invokes event TimerIntLdd1_OnInterrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU3_OnChannel0(LDD_TUserData *UserDataPtr)
{
  TimerIntLdd1_TDeviceData *DeviceDataPrv = PE_LDD_DeviceDataList[PE_LDD_COMPONENT_TimerIntLdd1_ID];
  uint16_t Ticks;

  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  (void)TU3_GetOffsetTicks(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, &Ticks);
  Ticks += DeviceDataPrv->CmpVal;
  (void)TU3_SetOffsetTicks(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, Ticks);
  if (DeviceDataPrv->EnEvents & LDD_TIMERINT_ON_INTERRUPT) { /* Is the event enabled? */
    TimerIntLdd1_OnInterrupt(DeviceDataPrv->UserDataPtr); /* Invoke OnInterrupt event */
  }
}

/* END TimerIntLdd1. */

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