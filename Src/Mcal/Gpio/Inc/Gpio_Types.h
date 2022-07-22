/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  Gpio
 *
 *  Description:  Data types for Gpio Module.    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
  GPIO_STATE_LOW, /**< Defines digital state ground */
  GPIO_STATE_HIGH, /**< Defines digital state power */
  GPIO_STATE_MAX /**< the maximum number of states */
} GpioState_t;

/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
  PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
  PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, 
  PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, 
  PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7, 
  PE0, PE1, PE2, PE3, PE4, PE5, PE6, PE7, 
  PF0, PF1, PF2, PF3, PF4, PF5, PF6, PF7, 
  GPIO_CHANNEL_MAX
} GpioChannel_t;

/**
 * Defines the possible directions of the pin
 */
typedef enum 
{
  GPIO_DIR_INPUT, 
  GPIO_DIR_OUTPUT,
  GPIO_DIR_MAX
} GpioDirection_t;

#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
