#include "systickk.h"  
#include "tm4c123gh6pm.h"
#include "std_types.h"  
#include "DIO.h" 
#define TIME_IN_MILIS    50000
#define SYSTEM_FREQ_TH  16000 
uint16  systick_counter = 0 ; 

void SysTick_Init(void)
{
   SYSTICK_CONTROL_REG    = 0;              /* Disable the SysTick Timer by Clear the ENABLE Bit */
    RELOAD_REG  = 15999999;        /* Set the Reload value with 15999999 to count ONE Second */
    CURRENT_REGISTER = 0;              /* Clear the Current Register value */
    /* Configure the SysTick Control Register 
     * Enable the SysTick Timer (ENABLE = 1)
     * Disable SysTick Interrupt (INTEN = 0)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
      SYSTICK_CONTROL_REG |= 0x05;
}
uint16 TIME_OUT (void){
  if(RELOAD_FLAG ==0) {
  } 
  else 
    systick_counter ++ ; 
     return  systick_counter  ;   
  
}
void DISABLE_SYSTICK () { 

 SYSTICK_CONTROL_REG &= 0x00; 

}