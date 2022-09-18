/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  Gpt
 *
 *  Description:  header file for Gpt Module    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"

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
* \Syntax          : void Gpt_Init(void)                                   
* \Description     : This function is used to initialize timers.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Config  GptConfig_t* the configuration structure.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(void);

/******************************************************************************
* \Syntax          : void Gpt_StartTimer(GptChannel_t Channel)
* \Description     : This function starts a timer.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel  GptChannel_t the Channel Id.                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer(GptChannel_t Channel);

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(GptChannel_t Channel)
* \Description     : This function stops a timer.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel  GptChannel_t the Channel Id.                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer(GptChannel_t Channel);

/******************************************************************************
* \Syntax          : void Gpt_LoadSet(GptChannel_t Channel, uint32 Value)                                 
* \Description     : This function sets load value for a timer.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel  GptChannel_t the Channel Id.
                     Value  uint32 the load value.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_LoadSet(GptChannel_t Channel, uint32 Value);

/******************************************************************************
* \Syntax          : void Gpt_SetCallback(GptChannel_t Channel, 
void (*Callback)(void))
* \Description     : This function register a callback function for a timer.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel  GptChannel_t the Channel Id. 
                     Callback void (*)(void) the callback function            
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_SetCallback(GptChannel_t Channel, void (*Callback)(void));

#ifdef __cplusplus
} // extern "C"
#endif

#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/
