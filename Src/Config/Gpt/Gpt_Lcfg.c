/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

const uint8 gGptConfigSize = 1;
const GptConfig_t gGptConfig[] = {
  { TIMER_0, GPT_PREDEF_TIMER_1US_28BIT, GPT_MODE_ONESHOT }
};

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Lcfg.c
 *********************************************************************************************************************/
