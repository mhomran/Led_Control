/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  General purpose input/output Driver
 *
 *      \details  The Driver Configures MCU General purpose timers.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt.h"
#include "Gpt_Memmap.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
static uint32 gBaseAddresses[] = { TIM0_BASE };

#define ARR_SIZE(x) (sizeof(x)/sizeof(x[0]))
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static void (*Callbacks[6])(void);
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const GptConfig_t gGptConfig[];
extern const uint8 gGptConfigSize;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static void Gpt_IntClear(GptChannel_t Channel);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void TIMER0A_Handler(void);

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
void 
Gpt_Init(void)
{
  uint8 i, j;
  uint8 baseIdx;

  for(i = 0; i < gGptConfigSize; i++) 
    {
      baseIdx = gGptConfig[i].Channel;
      
      /* disable the timer. */
      GPT_CTL(gBaseAddresses[baseIdx], GPT_CTL_TAEN) = 0;
      GPT_CTL(gBaseAddresses[baseIdx], GPT_CTL_TBEN) = 0;

      /* 32 bit concatenated timer. */
      for(j = 0; j < 4; j++) 
        {
          GPT_CFG(gBaseAddresses[baseIdx], j) = 0; 
        }
      
      /* One-shot or periodic */
      GPT_TAMR(gBaseAddresses[baseIdx], GPT_TAMR_TAMR_0) = gGptConfig[i].Mode & 1;
      GPT_TAMR(gBaseAddresses[baseIdx], GPT_TAMR_TAMR_1) = (gGptConfig[i].Mode >> 1);

      /* Enable Time-out interrupt */
      GPT_IMR(gBaseAddresses[baseIdx], GPT_IMR_TATOIM) = 1;

      /* Count up */
      GPT_TAMR(gBaseAddresses[baseIdx], GPT_TAMR_TACDIR) = 1;
    }
}


void 
Gpt_LoadSet(GptChannel_t Channel, uint32 Value)
{
  GPT_TAILR(gBaseAddresses[Channel]) = Value << 4;
}

void 
Gpt_StartTimer(GptChannel_t Channel)
{
  /* disable the timer. */
  GPT_CTL(gBaseAddresses[Channel], GPT_CTL_TAEN) = 1;
  GPT_CTL(gBaseAddresses[Channel], GPT_CTL_TBEN) = 1;
}

void 
Gpt_SetCallback(GptChannel_t Channel, void (*Callback)(void))
{
  Callbacks[Channel] = Callback;
}

static void 
Gpt_IntClear(GptChannel_t Channel)
{
  GPT_ICR(gBaseAddresses[Channel]) = 0xFFFF;
}

void 
TIMER0A_Handler(void) 
{
  Gpt_IntClear(TIMER_0);
	if(Callbacks[0]) Callbacks[0]();
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
