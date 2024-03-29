/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  Data types for IntCtrl Module.    
 *  
 *********************************************************************************************************************/
#ifndef INT_CTRL_TYPES_H
#define INT_CTRL_TYPES_H

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
* Defines the IRQs in the target.
*/
typedef enum
{
  TIM0A_IRQn = 19
} IRQn_t;



#endif  /* INT_CTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
