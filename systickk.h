#include "tm4c123gh6pm.h" 
#include "std_types.h" 
/*******************************REFISTERS DEFINITIONS ************************/ 
#define   CURRENT_REGISTER   NVIC_ST_CURRENT_R  
#define   SYSTICK_CONTROL_REG    NVIC_ST_CTRL_R  
#define   RELOAD_REG              NVIC_ST_RELOAD_R  
#define   RELOAD_FLAG              (SYSTICK_CONTROL_REG & 1<<16)  
extern uint16 systick_counter ; 
/*************************FUNCTIONS PROTOTYPES ******************************/ 
void SysTick_Init(void) ;
uint16  TIME_OUT (void) ;  
void DISABLE_SYSTICK () ;
/***********************************************************/