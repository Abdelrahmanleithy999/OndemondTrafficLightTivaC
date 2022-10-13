#include "tm4c123gh6pm.h" 
#include "DIO.h" 
#include "keypad.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include "systickk.h" 
#include "Timer0.h"  
#include "std_types.h" 
#include "LEDS_TRAFFIC_INIT.h" 
#define INTERRUPTSW2        1 
#define INTERRUPTSW1        3  
#define SYSTICKSW2          2  
#define SYSTICKSW1          4   
/******************************* PROJECT TEAM 14 ************************************************************************/ 
/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")
/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("CPSID I") 
/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")     
/* Global variable indicates interrupt triggered/not */
volatile unsigned char interrupt_flag = 0; 
 void GPIOPortF_Handler(void)
{ 
  if(GPIO_PORTF_MIS_R & 0x01 ) {
    interrupt_flag = INTERRUPTSW2 ; /* set the variable to indicate that the interrupt is triggered */
    GPIO_PORTF_ICR_R   |= (1<<0);       /* Clear Trigger flag for PF0 (Interupt Flag) */  
  } 
  else if (GPIO_PORTF_MIS_R & 0x10 )  {
    interrupt_flag = INTERRUPTSW1  ;  /* set the variable to indicate that the interrupt is triggered */
    GPIO_PORTF_ICR_R   |= (1<<4);        /*  Clear Trigger flag for PF4 (Interupt Flag) */ 
  
}
} 
uint16 RESERVE_VALUE = 0 ;   // GLOBAL VARIABLE TO SAVE VALUE OF TICKS BEFORE DISABLE TIMER0
uint16 gtick = 0 ;          // GLOBAL GTICK VARIABLE TO COUNT NUMBERS OF SECONDS OF TIMER 0 
uint16 sys_gtick = 0 ;   // GLOBAL SYS_GTICK VARIABLE TO COUNT NUMBERS OF SECONDS OF SYSTICK 
 int main()
{  
  Wait_For_Interrupt() ;   
  TRAFFIC_ONE_INIT ();  // INIT THE TRAFFIC LIGHT 1 
  TRAFFIC_TWO_INIT () ;  // INIT THE TRAFFIC LIGHT  2 
  PEDESTRIAN_TWO_INIT () ; // INIT THE PEDESTRIAN LIGHT  1
  PEDESTRIAN_ONE_INIT () ; // INIT THE PEDESTRIAN LIGHT LIGHT  2 
  SysTick_Init() ;     // INIT OF SYSTICK 
  TIMER0_INIT () ;   // INIT OF TIEMR0 
  WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_HIGH )  ;  // INITIALIZE GREEN LIGHT OF TRAFFIC 1 
  WRITE_PIN (PORT_E ,PIN_1 ,LOGIC_HIGH )  ;   // INITIALIZE RED LIGHT OF PEDESTRIAN 1 
  WRITE_PIN (PORT_A ,PIN_6 ,LOGIC_HIGH )  ; // INITIALIZE RED LIGHT OF  PEDESTRIAN 2 
  SW2_Init()  ;       //INITIALIZE SWITCH  2   
  SW1_Init();         //INITIALIZE SWITCH   1 
 while(1)
   {   
Enable_Exceptions() ;       // ENABLE INTERRUPTS 
     if( interrupt_flag == INTERRUPTSW2  ) { 
         RESERVE_VALUE = gtick  ;  
          DISABLE_TIMER0();      
         sys_gtick = TIME_OUT () ;   
       WRITE_PIN (PORT_E ,PIN_1 ,LOGIC_LOW )  ;
       WRITE_PIN (PORT_E ,PIN_2 ,LOGIC_HIGH )  ;   
         if (sys_gtick == 2 )  {  
        interrupt_flag = SYSTICKSW2 ;    
      
       }   
     } 
     else if ( interrupt_flag == INTERRUPTSW1 ) {
        RESERVE_VALUE = gtick  ;  
         DISABLE_TIMER0(); 
        sys_gtick = TIME_OUT () ;   
       WRITE_PIN (PORT_A ,PIN_6 ,LOGIC_LOW )  ;
       WRITE_PIN (PORT_A ,PIN_5 ,LOGIC_HIGH )  ;   
       if (sys_gtick == 2 )  {  
        interrupt_flag = SYSTICKSW1 ;    
      
       }  
     }
     if(interrupt_flag == SYSTICKSW2){
       WRITE_PIN (PORT_E ,PIN_1 ,LOGIC_HIGH )  ;
       WRITE_PIN (PORT_E ,PIN_2 ,LOGIC_LOW )  ; 
      systick_counter =  0 ;  
      interrupt_flag  = 0 ;  
      counter = RESERVE_VALUE ;
      TIMER0_INIT () ;  
     } 
     else if (interrupt_flag == SYSTICKSW1) {
       WRITE_PIN (PORT_A ,PIN_6 ,LOGIC_HIGH )  ;
       WRITE_PIN (PORT_A ,PIN_5 ,LOGIC_LOW )  ; 
      systick_counter =  0 ; 
     interrupt_flag  = 0 ; 
     counter = RESERVE_VALUE ;
       TIMER0_INIT () ;   
      
     }
       
      gtick = CHECK_FLAG()  ;
     if(gtick == 0 ) {
     WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_HIGH )  ; 
     WRITE_PIN (PORT_B ,PIN_2 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_B ,PIN_3 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_D,PIN_1 , LOGIC_LOW)  ; 
     WRITE_PIN (PORT_D ,PIN_2 , LOGIC_LOW ) ; 
     WRITE_PIN (PORT_D ,PIN_3 , LOGIC_LOW  ) ; 
     
     }
     if(gtick == 5 ) {
      WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_LOW )  ; 
     WRITE_PIN (PORT_B ,PIN_2 , LOGIC_HIGH ) ; 
     WRITE_PIN (PORT_B ,PIN_3 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_D,PIN_1 , LOGIC_LOW)  ; 
     WRITE_PIN (PORT_D ,PIN_2 , LOGIC_LOW ) ; 
     WRITE_PIN (PORT_D ,PIN_3 , LOGIC_LOW  ) ; 
      }  
       if(gtick == 7) {
       WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_LOW )  ; 
     WRITE_PIN (PORT_B ,PIN_2 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_B ,PIN_3 , LOGIC_HIGH  ) ; 
     WRITE_PIN (PORT_D,PIN_1 , LOGIC_LOW)  ; 
     WRITE_PIN (PORT_D ,PIN_2 , LOGIC_LOW ) ; 
     WRITE_PIN (PORT_D ,PIN_3 , LOGIC_LOW  ) ;  
       WRITE_PIN (PORT_E ,PIN_2 , LOGIC_HIGH  ) ;  
       WRITE_PIN (PORT_E ,PIN_1 , LOGIC_LOW ) ; 
      }   
       if(gtick == 8) {
         WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_LOW )  ; 
     WRITE_PIN (PORT_B ,PIN_2 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_B ,PIN_3 , LOGIC_LOW   ) ; 
     WRITE_PIN (PORT_D,PIN_1 , LOGIC_HIGH)  ; 
     WRITE_PIN (PORT_D ,PIN_2 , LOGIC_LOW ) ; 
     WRITE_PIN (PORT_D ,PIN_3 , LOGIC_LOW  ) ; 
      WRITE_PIN (PORT_B ,PIN_3 , LOGIC_HIGH  ) ;
      }   
       if(gtick == 13 ) {
       WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_LOW )  ; 
     WRITE_PIN (PORT_B ,PIN_2 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_B ,PIN_3 , LOGIC_LOW   ) ; 
     WRITE_PIN (PORT_D,PIN_1 , LOGIC_LOW )  ; 
     WRITE_PIN (PORT_D ,PIN_2 , LOGIC_HIGH ) ; 
     WRITE_PIN (PORT_D ,PIN_3 , LOGIC_LOW  ) ; 
      WRITE_PIN (PORT_B ,PIN_3 , LOGIC_HIGH  ) ;
      }   
         if(gtick == 14 ) {  // RED LIGHT OF TRAFFIC 2 
       WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_LOW )  ; 
     WRITE_PIN (PORT_B ,PIN_2 , LOGIC_LOW  ) ; 
     WRITE_PIN (PORT_B ,PIN_3 , LOGIC_LOW   ) ; 
     WRITE_PIN (PORT_D,PIN_1 , LOGIC_LOW )  ; 
     WRITE_PIN (PORT_D ,PIN_2 ,  LOGIC_LOW) ; 
     WRITE_PIN (PORT_D,PIN_3 , LOGIC_HIGH  ) ; 
      WRITE_PIN (PORT_B ,PIN_3 , LOGIC_HIGH  ) ; 
      WRITE_PIN (PORT_A ,PIN_5 ,LOGIC_HIGH )  ;  
      WRITE_PIN (PORT_A ,PIN_6 ,LOGIC_LOW )  ;  
      
      }   
     if(gtick == 15 ) {    // wait one second all leds off 
        WRITE_PIN (PORT_B ,PIN_1 ,LOGIC_LOW )  ; 
      WRITE_PIN (PORT_B ,PIN_2 , LOGIC_LOW ) ; 
      WRITE_PIN (PORT_B ,PIN_3 , LOGIC_LOW  ) ; 
      WRITE_PIN (PORT_D,PIN_1 , LOGIC_LOW)  ; 
      WRITE_PIN (PORT_D ,PIN_2 , LOGIC_LOW ) ; 
      WRITE_PIN (PORT_D ,PIN_3 , LOGIC_LOW  ) ; 
      WRITE_PIN (PORT_E ,PIN_1 ,LOGIC_HIGH )  ;
      WRITE_PIN (PORT_A ,PIN_6 ,LOGIC_HIGH )  ;   
      WRITE_PIN (PORT_E ,PIN_2 ,LOGIC_LOW )  ;
      WRITE_PIN (PORT_A ,PIN_5 ,LOGIC_LOW )  ;  
      
     }
     if(gtick == 16 ) { 
     counter = 0 ; // extern value of counter in another file 
     } 
}
}