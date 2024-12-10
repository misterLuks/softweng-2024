/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuSTM32HALI2C.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : STM32CubeI2C
**     Version     : Component 01.004, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-08-27, 17:24, # CodeGen: 349
**     Abstract    :
**         Driver for STM32CubMX HAL I2C library
**     Settings    :
**          Component name                                 : McuSTM32HALI2C
**          SDK                                            : McuLib
**          Wait                                           : McuWait
**     Contents    :
**         SendChar          - uint8_t McuSTM32HALI2C_SendChar(uint8_t Chr);
**         RecvChar          - uint8_t McuSTM32HALI2C_RecvChar(uint8_t *Chr);
**         SendBlock         - uint8_t McuSTM32HALI2C_SendBlock(void *Ptr, uint16_t Siz, uint16_t *Snt);
**         SendBlockContinue - uint8_t McuSTM32HALI2C_SendBlockContinue(void *Ptr, uint16_t Siz, uint16_t...
**         RecvBlock         - uint8_t McuSTM32HALI2C_RecvBlock(void *Ptr, uint16_t Siz, uint16_t *Rcv);
**         SendAck           - void McuSTM32HALI2C_SendAck(bool Ack);
**         SendStop          - uint8_t McuSTM32HALI2C_SendStop(void);
**         SelectSlave       - uint8_t McuSTM32HALI2C_SelectSlave(uint8_t Slv);
**         GetSelected       - uint8_t McuSTM32HALI2C_GetSelected(uint8_t *Slv);
**         SetDeviceHandle   - uint8_t McuSTM32HALI2C_SetDeviceHandle(I2C_HandleTypeDef *handle);
**         Deinit            - void McuSTM32HALI2C_Deinit(void);
**         Init              - void McuSTM32HALI2C_Init(void);
**
** * Copyright (c) 2018, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuSTM32HALI2C.h
** @version 01.00
** @brief
**         Driver for STM32CubMX HAL I2C library
*/         
/*!
**  @addtogroup McuSTM32HALI2C_module McuSTM32HALI2C module documentation
**  @{
*/         

#ifndef __McuSTM32HALI2C_H
#define __McuSTM32HALI2C_H

/* MODULE McuSTM32HALI2C. */
#include "McuLib.h" /* SDK and API used */
#if McuLib_CONFIG_CPU_IS_STM32 /* only for STM32 */

#include "McuSTM32HALI2Cconfig.h" /* configuration */


#define McuSTM32HALI2C_RECVBLOCKCUSTOM_AVAILABLE  (0)
  /*!< Define which can be used to check if the function RecvBlockCustom() is available */

typedef enum McuSTM32HALI2C_EnumStartFlags_ {
  McuSTM32HALI2C_SEND_START,        /* Start is sent */
  McuSTM32HALI2C_DO_NOT_SEND_START  /* Start is not sent */
} McuSTM32HALI2C_EnumStartFlags;

typedef enum McuSTM32HALI2C_EnumAckFlags_ {
  McuSTM32HALI2C_SEND_LAST_ACK,   /* Nack after last received byte is sent */
  McuSTM32HALI2C_DO_NOT_LAST_ACK  /* Nack after last received byte is not sent */
} McuSTM32HALI2C_EnumAckFlags;

/* defines to be used for McuSTM32HALI2C_SendAck(); */
#define McuSTM32HALI2C_ACK         0U
#define McuSTM32HALI2C_NOACK       1U

void McuSTM32HALI2C_Init(void);
/*
** ===================================================================
**     Method      :  Init (component STM32CubeI2C)
**
**     Description :
**         Initializes the associated peripheral(s) and the components
**         internal variables.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuSTM32HALI2C_SendChar(uint8_t Chr);
/*
** ===================================================================
**     Method      :  SendChar (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, this method writes 7 bits of slave
**         address plus R/W bit = 0 to the I2C bus and then writes one
**         character (byte) to the bus. The slave address must be
**         specified before by the "SelectSlave" method or in the
**         component initialization section of 'Slave address init'
**         property. When working as the SLAVE, this method writes one
**         character (byte) to the bus. If the ERR_NOTAVAIL error code
**         returned, the char is successfully sent to master but the
**         master device responds by an acknowledgment instead of no
**         acknowledgment at the end of transfer. 'OnError' event is
**         called in this case.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_BUSY - The slave device is busy, it
**                           does not respond by the acknowledgment
**                           (MASTER mode only)
**                           ERR_NOTAVAIL - The master device sends
**                           acknowledgment instead of no acknowledgment
**                           after the last byte transfer (SLAVE mode
**                           only)
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSOFF - Clock timeout elapsed (SLAVE
**                           mode only)
** ===================================================================
*/

uint8_t McuSTM32HALI2C_RecvChar(uint8_t *Chr);
/*
** ===================================================================
**     Method      :  RecvChar (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, this method writes 7 bits of slave
**         address plus R/W bit = 1 to the I2C bus and then reads one
**         character (byte) from the bus. The slave address must be
**         specified before by the "SelectSlave" method or in the
**         component initialization section of 'Slave address init'
**         property. When working as a SLAVE, this method reads one
**         character (byte) from the bus.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_BUSY - The slave device is busy, it
**                           does not respond by the acknowledgment
**                           (MASTER mode only)
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSOFF - Clock timeout elapsed (SLAVE
**                           mode only)
** ===================================================================
*/

uint8_t McuSTM32HALI2C_SendBlock(void *Ptr, uint16_t Siz, uint16_t *Snt);
/*
** ===================================================================
**     Method      :  SendBlock (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, this method writes 7 bits of slave
**         address plus R/W bit = 0 to the I2C bus and then writes the
**         block of characters to the bus. If the component is disabled
**         (by the "Disable" method or initialization), the block is
**         moved to the output buffer if the 'Output buffer size'
**         property is different from zero. The content of the output
**         buffer is sent immediately with the stop condition at the
**         end when the component is enabled by the "Enable" method.
**         After the output buffer transmission, the whole output
**         buffer is cleared. The slave address must be specified
**         before by the "SelectSlave" method or in component
**         initialization section of 'Slave address init' property.
**         When working as a SLAVE, this method writes block of
**         characters to the bus. If the ERR_NOTAVAIL error code is
**         returned, the whole block is successfully sent to a master
**         but the master device responds by an acknowledgment instead
**         of no acknowledgment sent at the end of the last block byte
**         transfer. 'OnError' event is called in this case.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - A pointer to the block of data to send
**         Siz             - The size of the block
**       * Snt             - A pointer to the number of data that are
**                           sent (copied to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_BUSY - The slave device is busy, it
**                           does not respond by the acknowledgment
**                           (MASTER mode only)
**                           ERR_TXFULL - Output buffer is full (MASTER
**                           mode only)
**                           ERR_NOTAVAIL - The master device sends
**                           acknowledgment instead of no acknowledgment
**                           after the last byte transfer (SLAVE mode
**                           only)
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSOFF - Clock timeout elapsed (SLAVE
**                           mode only)
** ===================================================================
*/

uint8_t McuSTM32HALI2C_RecvBlock(void *Ptr, uint16_t Siz, uint16_t *Rcv);
/*
** ===================================================================
**     Method      :  RecvBlock (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, this method writes 7 bits of slave
**         address plus R/W bit = 1 to the I2C bus and then reads the
**         block of characters from the bus. The slave address must be
**         specified before by the "SelectSlave" method or in component
**         initialization section of 'Slave address init' property.
**         When working as a SLAVE, this method reads the block of
**         characters from the bus.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - A pointer to the block space for received
**                           data
**         Siz             - The size of the block
**       * Rcv             - A pointer to the number of actually
**                           received data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_BUSY - The slave device is busy, it
**                           does not respond by the acknowledgment
**                           (MASTER mode only)
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSOFF - Clock timeout elapsed (SLAVE
**                           mode only)
** ===================================================================
*/

uint8_t McuSTM32HALI2C_SendStop(void);
/*
** ===================================================================
**     Method      :  SendStop (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, if the 'Automatic stop condition'
**         property value is 'no', this method sends a valid stop
**         condition to the serial data line of the I2C bus to
**         terminate the communication on the bus after using send
**         methods. This method is enabled only if the component is in
**         MASTER mode and 'Automatic stop condition' property value is
**         'no'
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
** ===================================================================
*/

uint8_t McuSTM32HALI2C_SelectSlave(uint8_t Slv);
/*
** ===================================================================
**     Method      :  SelectSlave (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, this method selects a new slave
**         for communication by its slave address value. Any send or
**         receive method are directed to or from the selected device,
**         until a new slave device is selected by this method. If the
**         selected slave uses 10-bit slave addressing, as the
**         parameter 7 bits must be passed, which involves 10-bit
**         addressing (11110XX), including two MSBs of slave address
**         (XX). The second byte of the 10-bit slave address must be
**         sent to the slave as a general character of send methods.
**         This method is available only if the component is in MASTER
**         mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Slv             - Slave address value
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED -  Device is disabled
** ===================================================================
*/

uint8_t McuSTM32HALI2C_GetSelected(uint8_t *Slv);
/*
** ===================================================================
**     Method      :  GetSelected (component STM32CubeI2C)
**
**     Description :
**         When working as a MASTER, this method returns the
**         identification address value of the slave, which is
**         currently selected for communication with the master. If the
**         current slave uses 10-bit slave addressing, the method
**         returns the first 7 bits only, which involves 10-bit
**         addressing (11110XX), including two MSBs of the slave
**         address (XX). This method is not able to return the rest
**         value of 10-bit slave address. This method is available only
**         if the component is in MASTER mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Slv             - A pointer to the current selected slave
**                           address value
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

uint8_t McuSTM32HALI2C_SendBlockContinue(void *Ptr, uint16_t Siz, uint16_t *Snt);
/*
** ===================================================================
**     Method      :  SendBlockContinue (component STM32CubeI2C)
**
**     Description :
**         Same is SendBlock() but does not send start condition. When
**         working as a MASTER, this method writes 7 bits of slave
**         address plus R/W bit = 0 to the I2C bus and then writes the
**         block of characters to the bus. If the component is disabled
**         (by the "Disable" method or initialization), the block is
**         moved to the output buffer if the 'Output buffer size'
**         property is different from zero. The content of the output
**         buffer is sent immediately with the stop condition at the
**         end when the component is enabled by the "Enable" method.
**         After the output buffer transmission, the whole output
**         buffer is cleared. The slave address must be specified
**         before by the "SelectSlave" method or in component
**         initialization section of 'Slave address init' property.
**         When working as a SLAVE, this method writes block of
**         characters to the bus. If the ERR_NOTAVAIL error code is
**         returned, the whole block is successfully sent to a master
**         but the master device responds by an acknowledgment instead
**         of no acknowledgment sent at the end of the last block byte
**         transfer. 'OnError' event is called in this case.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - A pointer to the block of data to send
**         Siz             - The size of the block
**       * Snt             - A pointer to the number of data that are
**                           sent (copied to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_BUSY - The slave device is busy, it
**                           does not respond by the acknowledgment
**                           (MASTER mode only)
**                           ERR_TXFULL - Output buffer is full (MASTER
**                           mode only)
**                           ERR_NOTAVAIL - The master device sends
**                           acknowledgment instead of no acknowledgment
**                           after the last byte transfer (SLAVE mode
**                           only)
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSOFF - Clock timeout elapsed (SLAVE
**                           mode only)
** ===================================================================
*/

void McuSTM32HALI2C_SendAck(bool Ack);
/*
** ===================================================================
**     Method      :  SendAck (component STM32CubeI2C)
**
**     Description :
**         The method sends ACK to the bus.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ack             - If acknowledge is high or low
**     Returns     : Nothing
** ===================================================================
*/

void McuSTM32HALI2C_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component STM32CubeI2C)
**
**     Description :
**         Driver de-initialization method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuSTM32HALI2C_SetDeviceHandle(I2C_HandleTypeDef *handle);
/*
** ===================================================================
**     Method      :  SetDeviceHandle (component STM32CubeI2C)
**
**     Description :
**         Sets the HAL device handle.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Pointer to I2C_HandleTypeDef
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END McuSTM32HALI2C. */
#endif /* McuLib_CONFIG_CPU_IS_STM32 */ /* only for STM32 */

#endif
/* ifndef __McuSTM32HALI2C_H */
/*!
** @}
*/
