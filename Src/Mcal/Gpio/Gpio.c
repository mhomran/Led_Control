/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpio.c
 *        \brief  General purpose input/output Driver
 *
 *      \details  The Driver Configures MCU GPIO pins.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpio.h"
#include "Gpio_Memmap.h"
#include "Gpio_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define PORT_PINS_NUM         8

#define ARR_SIZE(x) (sizeof(x)/sizeof(x[0]))
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 gBaseAddresses[] = { 
  GPIOA_BASE, 
  GPIOB_BASE,
  GPIOC_BASE,
  GPIOD_BASE,
  GPIOE_BASE,
  GPIOF_BASE
  };
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const GpioConfig_t gGpioConfig[];
extern const uint8 gGpioConfigSize;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


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
void Gpio_Init(void)
{
  uint8 i, j;
  uint8 baseIdx;
  uint8 bit;

  for(i = 0; i < gGpioConfigSize; i++) 
    {
      baseIdx = gGpioConfig[i].Channel / PORT_PINS_NUM;
      bit = gGpioConfig[i].Channel % PORT_PINS_NUM; 

      GPIO_DIR(gBaseAddresses[baseIdx], bit) = gGpioConfig[i].Direction;
      GPIO_AFSEL(gBaseAddresses[baseIdx], bit) = 0;
      GPIO_EN(gBaseAddresses[baseIdx], bit) = 1;
      for(j = 0; j < 4; j++) 
        {
          GPIO_CTL(gBaseAddresses[baseIdx], j+bit*4) = 0;
        }
      GPIO_DATA(gBaseAddresses[baseIdx], bit) = gGpioConfig[i].Data;
    }
}


/******************************************************************************
* \Syntax          : void Gpio_Init(void)                                      
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
void Gpio_ChannelWrite(GpioChannel_t Channel, GpioState_t State)
{
  uint8 baseIdx;
  uint8 bit;
  baseIdx = Channel / PORT_PINS_NUM;
  bit = Channel % PORT_PINS_NUM; 

  GPIO_DATA(gBaseAddresses[baseIdx], bit) = State;
}

/******************************************************************************
* \Syntax          : void Gpio_Init(void)                                      
* \Description     : This function is used to set the direction of a channel.                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel     PORTX_N
*                    Direction   GPIO_DIR_INPUT
*                                GPIO_DIR_OUTPUT           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpio_SetChannelDirection(GpioChannel_t Channel, GpioDirection_t Direction)
{
  uint8 baseIdx;
  uint8 bit;
  baseIdx = Channel / PORT_PINS_NUM;
  bit = Channel % PORT_PINS_NUM; 

  GPIO_DIR(gBaseAddresses[baseIdx], bit) = Direction;
}

/**********************************************************************************************************************
 *  END OF FILE: Gpio.c
 *********************************************************************************************************************/
