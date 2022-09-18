/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio.h
 *       Module:  Gpio
 *
 *  Description:  header file for Gpio Module    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
* \Syntax          : void Gpio_Init(void)                                      
* \Description     : This function is used to initialize the Gpio based
*                    on the configuration table defined in Gpio_Lcfg.c                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpio_Init(void);

/******************************************************************************
* \Syntax          : void Gpio_ChannelWrite(GpioChannel_t Channel, 
GpioState_t State);
* \Description     : This function is used to write the state of a channel 
*                    (pin) as either logic high or low through the use of  
*                    the GpioChannel_t enum to select the channel
*                    and the DioState_t define the desired state                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel  PORTX_N
                     State    GPIO_STATE_LOW
                              GPIO_STATE_HIGH                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpio_ChannelWrite(GpioChannel_t Channel, GpioState_t State);

/******************************************************************************
* \Syntax          : void Gpio_SetChannelDirection(GpioChannel_t Channel, 
GpioDirection_t Direction);                                     
* \Description     : This function is used to set the direction of a channel.                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel     PXN
*                    Direction   GPIO_DIR_INPUT
*                                GPIO_DIR_OUTPUT           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpio_SetChannelDirection(GpioChannel_t Channel, GpioDirection_t Direction);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio.h
 *********************************************************************************************************************/
