/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CM4_PERI_BASE_ADDRESS            0xE000E000
#define APINT                            *((volatile uint32*)(CM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                          *((volatile INTCTRL_Tag*)(CM4_PERI_BASE_ADDRESS+0xD04))

#define BITBAND_PERI_REF                 0x40000000
#define BITBAND_PERI_BASE                0x42000000
#define BITBAND(address, bit)            *(volatile uint32*)(BITBAND_PERI_BASE + \
                                          (address - BITBAND_PERI_REF) * 32 + (bit) * 4) 
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
