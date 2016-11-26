/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : I2C1.h
**     Project     : ProcessorExpert
**     Processor   : MKL46Z256VMC4
**     Component   : I2C_LDD
**     Version     : Component 01.016, Driver 01.07, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-22, 23:30, # CodeGen: 43
**     Abstract    :
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
**     Settings    :
**          Component name                                 : I2C1
**          I2C channel                                    : I2C1
**          Interrupt service                              : Enabled
**            Interrupt                                    : INT_I2C1
**            Interrupt priority                           : high priority
**          Settings                                       : 
**            Mode selection                               : MASTER
**            MASTER mode                                  : Enabled
**              Initialization                             : 
**                Address mode                             : 7-bit addressing
**                Target slave address init                : 68
**            SLAVE mode                                   : Disabled
**            Pins                                         : 
**              SDA pin                                    : 
**                SDA pin                                  : LCD_P48/PTE0/SPI1_MISO/UART1_TX/RTC_CLKOUT/CMP0_OUT/I2C1_SDA
**                SDA pin signal                           : 
**              SCL pin                                    : 
**                SCL pin                                  : LCD_P49/PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL
**                SCL pin signal                           : 
**              High drive select                          : Disabled
**              Input Glitch filter                        : 0
**            Internal frequency (multiplier factor)       : 5.24288 MHz
**            Bits 0-2 of Frequency divider register       : 010
**            Bits 3-5 of Frequency divider register       : 010
**            SCL frequency                                : 81.92 kHz
**            SDA Hold                                     : 2.48 us
**            SCL start Hold                               : 4.959 us
**            SCL stop Hold                                : 6.294 us
**            Control acknowledge bit                      : Disabled
**            Low timeout                                  : Disabled
**          Initialization                                 : 
**            Enabled in init code                         : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMasterBlockSent                          : Enabled
**              OnMasterBlockReceived                      : Enabled
**              OnMasterByteReceived                       : Disabled
**              OnSlaveBlockSent                           : Disabled
**              OnSlaveBlockReceived                       : Disabled
**              OnSlaveByteReceived                        : Disabled
**              OnSlaveRxRequest                           : Disabled
**              OnSlaveTxRequest                           : Disabled
**              OnSlaveGeneralCallAddr                     : Disabled
**              OnSlaveSmBusCallAddr                       : Disabled
**              OnSlaveSmBusAlertResponse                  : Disabled
**              OnError                                    : Disabled
**              OnBusStopDetected                          : Disabled
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
**         Init               - LDD_TDeviceData* I2C1_Init(LDD_TUserData *UserDataPtr);
**         Deinit             - void I2C1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         MasterSendBlock    - LDD_TError I2C1_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         MasterReceiveBlock - LDD_TError I2C1_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         SelectSlaveDevice  - LDD_TError I2C1_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr,...
**         GetError           - LDD_TError I2C1_GetError(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TErrorMask...
**         CheckBus           - LDD_TError I2C1_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file I2C1.h
** @version 01.07
** @brief
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
*/         
/*!
**  @addtogroup I2C1_module I2C1 module documentation
**  @{
*/         

#ifndef __I2C1_H
#define __I2C1_H

/* MODULE I2C1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define I2C1_PRPH_BASE_ADDRESS  0x40067000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define I2C1_Init_METHOD_ENABLED       /*!< Init method of the component I2C1 is enabled (generated) */
#define I2C1_Deinit_METHOD_ENABLED     /*!< Deinit method of the component I2C1 is enabled (generated) */
#define I2C1_MasterSendBlock_METHOD_ENABLED /*!< MasterSendBlock method of the component I2C1 is enabled (generated) */
#define I2C1_MasterReceiveBlock_METHOD_ENABLED /*!< MasterReceiveBlock method of the component I2C1 is enabled (generated) */
#define I2C1_SelectSlaveDevice_METHOD_ENABLED /*!< SelectSlaveDevice method of the component I2C1 is enabled (generated) */
#define I2C1_GetError_METHOD_ENABLED   /*!< GetError method of the component I2C1 is enabled (generated) */
#define I2C1_CheckBus_METHOD_ENABLED   /*!< CheckBus method of the component I2C1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define I2C1_OnMasterBlockSent_EVENT_ENABLED /*!< OnMasterBlockSent event of the component I2C1 is enabled (generated) */
#define I2C1_OnMasterBlockReceived_EVENT_ENABLED /*!< OnMasterBlockReceived event of the component I2C1 is enabled (generated) */



/*
** ===================================================================
**     Method      :  I2C1_Init (component I2C_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the device data structure. 
*/
/* ===================================================================*/
LDD_TDeviceData* I2C1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  I2C1_Deinit (component I2C_LDD)
*/
/*!
**     @brief
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void I2C1_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  I2C1_MasterSendBlock (component I2C_LDD)
*/
/*!
**     @brief
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 0 to
**         the I2C bus and then writes the block of characters to the
**         bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that transmission was
**         successful. The state of transmission is detectable by means
**         of events (OnMasterSendComplete or OnError). Data to be sent
**         are not copied to an internal buffer and remains in the
**         original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockSent"can be used to detect the end of
**         the transmission. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Size of the data block.
**     @param
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is now running
*/
/* ===================================================================*/
LDD_TError I2C1_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);

/*
** ===================================================================
**     Method      :  I2C1_MasterReceiveBlock (component I2C_LDD)
*/
/*!
**     @brief
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 1 to
**         the I2C bus and then receives the block of characters from
**         the bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that reception was
**         successful. The state of reception is detectable by means of
**         events (OnMasterSendComplete  or OnError). Data to be
**         received are not copied to an internal buffer and remains in
**         the original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockReceived"can be used to detect the end
**         of the reception. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**     @param
**         Size            - The size of the block.
**     @param
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The master device is busy
**                           ERR_NOTAVAIL - It is not possible to
**                           receive data if general call address is set.
**                           ERR_PARAM_MODE -  Stop condition isn't
**                           possible generated on end transmission.
*/
/* ===================================================================*/
LDD_TError I2C1_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);

/*
** ===================================================================
**     Method      :  I2C1_SelectSlaveDevice (component I2C_LDD)
*/
/*!
**     @brief
**         This method selects a new slave for communication by its
**         7-bit slave, 10-bit address or general call value. Any send
**         or receive method directs to or from selected device, until
**         a new slave device is selected by this method. This method
**         is available for the MASTER mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         AddrType        - Specify type of slave address
**                           (7bit, 10bit or general call address), e.g.
**                           LDD_I2C_ADDRTYPE_7BITS.
**     @param
**         Addr            - 7bit or 10bit slave address value.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_BUSY - The device is busy, wait until
**                           the current operation is finished.
**                           ERR_DISABLED -  The device is disabled.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_ADDRESS_TYPE -  Invalid address
**                           type.
**                           ERR_PARAM_ADDRESS -  Invalid address value.
*/
/* ===================================================================*/
LDD_TError I2C1_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TAddrType AddrType, LDD_I2C_TAddr Addr);

/*
** ===================================================================
**     Method      :  I2C1_GetError (component I2C_LDD)
*/
/*!
**     @brief
**         Returns value of error mask, e.g. LDD_I2C_ARBIT_LOST.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ErrorMaskPtr    - Pointer to a variable
**                           where errors value mask will be stored.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError I2C1_GetError(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TErrorMask *ErrorMaskPtr);

/*
** ===================================================================
**     Method      :  I2C1_CheckBus (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the status of the bus. If the START
**         condition has been detected, the method returns LDD_I2C_BUSY.
**         If the STOP condition has been detected, the method returns
**         LDD_I2C_IDLE.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BusStatePtr     - Pointer to a variable,
**                           where value of status is stored.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError I2C1_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState *BusStatePtr);

/*
** ===================================================================
**     Method      :  I2C1_Interrupt (component I2C_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(I2C1_Interrupt);

/* END I2C1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __I2C1_H */
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
