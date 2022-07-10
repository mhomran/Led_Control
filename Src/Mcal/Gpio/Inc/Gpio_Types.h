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
  /* TODO: Populate this list based on available MCU pins */
  PORTA_0,
  PORTA_1,
  GPIO_CHANNEL_MAX
} GpioChannel_t;

/**
 * Defines the possible directions of the pin
 */
typedef enum 
{
  GPIO_DIR_INPUT, 
  GPIO_DIR_OUTPUT
} GpioDirection_t;

#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
