#include "tm4c123gh6pm.h" 
#include "DIO.h"
#include "Timer0.h"
#include "common_macros.h"
#include "std_types.h" 
uint16 counter = 0 ; 
void TIMER0_INIT (void) {
 SET_BIT(SYSCTL_RCGCTIMER_R ,0) ;  //START THE CLOCK OF TIMER 0 
 CLEAR_BIT(TIMER0_CTL_R, 0) ;         // DISABLE TIMER BEFORE CONFIGURATION 
 TIMER0_CFG_R    =  TIMER_CFG_32_BIT_TIMER   ; //32_BIT TIMER 
 TIMER0_TAMR_R  |= (0X2<<0) ;   // PERIODIC COUNTER 
  CLEAR_BIT(TIMER0_TAMR_R  , 4 ) ;     // DOWN COUNTER
  TIMER0_TAILR_R  = 0X00F42400 ;  //16000000 COUNTSA TO COUNT ONE SECOND 
  SET_BIT(TIMER0_CTL_R, 0) ;  // ENABLE TIMER0 
}  

uint16 CHECK_FLAG(){ 
  if(TIMER0_RIS_R & 0x00000001 ) {
    SET_BIT(TIMER0_ICR_R, 0); // CLEAR FLAG 
    counter ++ ;  // INCREASES THE COUNTER EVERY ENTIRY FOR THE FUNCTION 
  } 
return counter ; 
}
void DISABLE_TIMER0(){
CLEAR_BIT(TIMER0_CTL_R, 0) ;         // DISABLE TIMER BEFORE CONFIGURATION 
} 
void ENABLE_TIMER0(){ 
SET_BIT(TIMER0_CTL_R, 0) ;  // ENABLE TIMER0 
}