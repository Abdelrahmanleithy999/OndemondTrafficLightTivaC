#include "tm4c123gh6pm.h" 
#include "DIO.h"   
#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2
#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 762
void TRAFFIC_ONE_INIT (){
DIO_init ( PORT_B ,PIN_1 ,PIN_OUTPUT ) ; // LED GREEN TRAFFIC 1 
 DIO_init ( PORT_B ,PIN_2 ,PIN_OUTPUT ) ;  // LED YELLOW TRAFFIC 1 
 DIO_init ( PORT_B ,PIN_3 ,PIN_OUTPUT ) ;  // LED TRAFFIC 1 
    GPIO_PORTB_AMSEL_R &= 0xF1;         /* Disable Analog on PB1, PB2 and PB3 */
    GPIO_PORTB_PCTL_R  &= 0xFFFF000F;   /* Clear PMCx bits for PB1, PB2 and PB3 to use it as GPIO pin */
    GPIO_PORTB_DIR_R   |= 0x0E;         /* Configure PB1, PB2 and PB3 as output pin */
    GPIO_PORTB_AFSEL_R &= 0xF1;         /* Disable alternative function on PB1, PB2 and PB3 */
    GPIO_PORTB_DEN_R   |= 0x0E;         /* Enable Digital I/O on PB1, PB2 and PB3 */
    GPIO_PORTB_DATA_R  &=  0xF1;         /* Clear bit 3 , 1 and 2 in Data regsiter to turn off the leds */  
}  
void TRAFFIC_TWO_INIT (){ 

DIO_init ( PORT_D ,PIN_1 ,PIN_OUTPUT ) ; // LED GREEN TRAFFIC 2 
 DIO_init ( PORT_D ,PIN_2 ,PIN_OUTPUT ) ;  // LED YELLOW TRAFFIC 2
 DIO_init ( PORT_D ,PIN_3 ,PIN_OUTPUT ) ;  // LED TRAFFIC 2 
    GPIO_PORTD_AMSEL_R &= 0xF1;         /* Disable Analog on PD1, PD2 and PD3 */
    GPIO_PORTD_PCTL_R  &= 0xFFFF000F;   /* Clear PMCx bits for PD1, PD2 and PE3 to use it as GPIO pin */
    GPIO_PORTD_DIR_R   |= 0x0E;         /* Configure PD1, PD2 and PD3 as output pin */
    GPIO_PORTD_AFSEL_R &= 0xF1;         /* Disable alternative function on PD1, PD2 and PD3 */
    GPIO_PORTD_DEN_R   |= 0x0E;         /* Enable Digital I/O on PD1, PD2 and PD3 */
    GPIO_PORTD_DATA_R  &=  0xF1;         /* Clear bit 3 , 1 and 2 in Data regsiter to turn off the leds */
}
void PEDESTRIAN_ONE_INIT (){ 

DIO_init ( PORT_E ,PIN_1 ,PIN_OUTPUT ) ; // LED red PEDESTRIAN 1 
 DIO_init ( PORT_E ,PIN_2 ,PIN_OUTPUT ) ;  // LED green PEDESTRIAN 1
   GPIO_PORTD_AMSEL_R &= 0xF9;         /* Disable Analog on PD1, PD2 and PD3 */
    GPIO_PORTE_PCTL_R  &= 0xFFFFF00F;   /* Clear PMCx bits for PD1, PD2 and PE3 to use it as GPIO pin */
    GPIO_PORTE_DIR_R   |= 0x06;         /* Configure PD1, PD2 and PD3 as output pin */
    GPIO_PORTE_AFSEL_R &= 0xF9;         /* Disable alternative function on PD1, PD2 and PD3 */
    GPIO_PORTE_DEN_R   |= 0x06;         /* Enable Digital I/O on PD1, PD2 and PD3 */
    GPIO_PORTE_DATA_R  &=  0xF9;         /* Clear bit 3 , 1 and 2 in Data regsiter to turn off the leds */  
}

void PEDESTRIAN_TWO_INIT (){ 

DIO_init ( PORT_A ,PIN_6 ,PIN_OUTPUT ) ; // LED red PEDESTRIAN 1 
DIO_init ( PORT_A ,PIN_5 ,PIN_OUTPUT ) ;  // LED green PEDESTRIAN 1
    GPIO_PORTA_AMSEL_R &= 0x9F;         /* Disable Analog on PD1, PD2 and PD3 */
    GPIO_PORTA_PCTL_R  &= 0xF00FFFFF;   /* Clear PMCx bits for PD1, PD2 and PE3 to use it as GPIO pin */
    GPIO_PORTA_DIR_R   |= 0x60;         /* Configure PD1, PD2 and PD3 as output pin */
    GPIO_PORTA_AFSEL_R &= 0x9F;         /* Disable alternative function on PD1, PD2 and PD3 */
    GPIO_PORTA_DEN_R   |= 0x60;          /* Enable Digital I/O on PD1, PD2 and PD3 */
    GPIO_PORTA_DATA_R  &=  0x9F;         /* Clear bit 3 , 1 and 2 in Data regsiter to turn off the leds */  
} 
void SW2_Init(void)
{
    GPIO_PORTF_LOCK_R  = 0x4C4F434B;   /* Unlock the GPIO_PORTF_CR_REG */
    GPIO_PORTF_CR_R    |= (1<<0);       /* Enable changes on PF0 */
    GPIO_PORTF_AMSEL_R &= ~(1<<0);      /* Disable Analog on PF0 */
    GPIO_PORTF_PCTL_R  &= 0xFFFFFFF0;   /* Clear PMCx bits for PF0 to use it as GPIO pin */
    GPIO_PORTF_DIR_R   &= ~(1<<0);      /* Configure PF0 as input pin */
    GPIO_PORTF_AFSEL_R &= ~(1<<0);      /* Disable alternative function on PF0 */
    GPIO_PORTF_PUR_R   |= (1<<0);       /* Enable pull-up on PF0 */
    GPIO_PORTF_DEN_R   |= (1<<0);       /* Enable Digital I/O on PF0 */
    GPIO_PORTF_IS_R    &= ~(1<<0);      /* PF0 detect edges */
    GPIO_PORTF_IBE_R   &= ~(1<<0);      /* PF0 will detect a certain edge */
    GPIO_PORTF_IEV_R   &= ~(1<<0);      /* PF0 will detect a falling edge */
    GPIO_PORTF_ICR_R   |= (1<<0);       /* Clear Trigger flag for PF0 (Interupt Flag) */
    GPIO_PORTF_IM_R    |= (1<<0);       /* Enable Interrupt on PF0 pin */
    /* Set GPIO PORTF priotiy as 2 by set Bit number 21, 22 and 23 with value 2 */
    NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_R        |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}
 void SW1_Init(void)
{
    GPIO_PORTF_AMSEL_R &= ~(1<<4);      /* Disable Analog on PF4 */
    GPIO_PORTF_PCTL_R  &= 0xFFF0FFFF;   /* Clear PMCx bits for PF4 to use it as GPIO pin */
    GPIO_PORTF_DIR_R   &= ~(1<<4);      /* Configure PF4 as input pin */
    GPIO_PORTF_AFSEL_R &= ~(1<<4);      /* Disable alternative function on PF4 */
    GPIO_PORTF_PUR_R   |= (1<<4);       /* Enable pull-up on PF4 */
    GPIO_PORTF_DEN_R   |= (1<<4);       /* Enable Digital I/O on PF4 */
    GPIO_PORTF_IS_R    &= ~(1<<4);      /* PF4 detect edges */
    GPIO_PORTF_IBE_R   &= ~(1<<4);      /* PF4 will detect a certain edge */
    GPIO_PORTF_IEV_R   &= ~(1<<4);      /* PF4 will detect a falling edge */
    GPIO_PORTF_ICR_R   |= (1<<4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
    GPIO_PORTF_IM_R    |= (1<<4);       /* Enable Interrupt on PF4 pin */
    /* Set GPIO PORTF priotiy as 2 by set Bit number 21, 22 and 23 with value 2 */
    NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_R         |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}