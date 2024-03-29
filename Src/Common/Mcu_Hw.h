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

/* GPIO Port F Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32 *)0x400FE608))
#define SYSCTL_RCGCGPIO_R5      0x00000020 
#define SYSCTL_PRGPIO_R         (*((volatile uint32 *)0x400FEA08))
#define SYSCTL_PRGPIO_R5        0x00000020  
#define SYSCTL_RCGCTIMER_R      (*((volatile uint32 *)0x400FE604))
#define SYSCTL_RCGCTIMER_R0     0x00000001  /* 16/32-Bit General-Purpose Timer
                                               0 Run Mode Clock Gating Control */
#define SYSCTL_PRTIMER_R        (*((volatile uint32 *)0x400FEA04))
#define SYSCTL_PRTIMER_R0       0x00000001  /* 16/32-Bit General-Purpose Timer
																							 0 Peripheral Ready */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
