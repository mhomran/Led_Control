/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  main.c
 *        \brief  Control blinking of an LED for a user-defined ON and OFF periods
 *
 *      \details  Users can input a specific ON time and OFF time in seconds, 
 *                lights a LED for the given ON time, and dim itfor the given OFF
 *                time. 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpio.h"
#include "IntCtrl.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 gOnTime, gOffTime, gOnVal, gOffVal;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void App_Callback(void);
void App_Blink(uint32 OnTime, uint32 OffTime);
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : int main(void)        
* \Description     : The entry point of the program                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None            
* \Parameters (out): None                                                      
* \Return value:   : int             SUCCESS
*                                    FAILURE                                  
*******************************************************************************/
int main(void)
{
	/*enable PORT F CLK*/
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	while(!(SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R5));
	/*enable Timer0 CLK*/
	SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;
	while(!(SYSCTL_PRTIMER_R & SYSCTL_RCGCTIMER_R0));

	IntCtrl_EnableIRQ(TIM0A_IRQn);

	Gpio_Init();
	Gpio_ChannelWrite(PF0, GPIO_STATE_HIGH);
	
	Gpt_Init();
	Gpt_LoadSet(TIMER_0, 1000000);
	Gpt_SetCallback(TIMER_0, App_Callback);
	
	App_Blink(1, 3);
	while(1) 
    {
      /* STUP */
    }
}

void 
App_Callback(void)
{
	static uint8 turn = 1;

	if (turn)
		{
			Gpio_ChannelWrite(PF0, GPIO_STATE_HIGH);
			/* The load value can't be covered by the timer */
			if ((gOnVal * (1000000ul)) > (0x0FFFFFFFul))
				{
					Gpt_LoadSet(TIMER_0, (1000000ul));
					gOnVal--; /* Decrease number of ON seconds. */
				}
			else
				{
					Gpt_LoadSet(TIMER_0, (gOnVal * (1000000ul)));
					turn = 1-turn;
					gOffVal = gOffTime;
				}
		}
	else 
		{
			Gpio_ChannelWrite(PF0, GPIO_STATE_LOW);
			/* The load value can't be covered by the timer */
			if ((gOffVal * (1000000ul)) > (0x0FFFFFFFul))
				{
					Gpt_LoadSet(TIMER_0, (1000000ul));
					gOffVal--; /* Decrease number of OFF seconds. */
				}
			else
				{
					Gpt_LoadSet(TIMER_0, (gOffVal * (1000000ul)));
					turn = 1-turn;
					gOnVal = gOnTime;
				}
		}

	Gpt_StartTimer(TIMER_0);
}

void 
App_Blink(uint32 OnTime, uint32 OffTime)
{
	Gpt_StopTimer(TIMER_0);
	gOnTime = OnTime;
	gOnVal = OnTime;
	gOffTime = OffTime;
	gOffVal = OffTime;
	App_Callback();
}

/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/
