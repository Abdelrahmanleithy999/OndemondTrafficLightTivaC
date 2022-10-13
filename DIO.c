#include "tm4c123gh6pm.h" 
#include "DIO.h"
#include "common_macros.h"
int DIO_ReadPort (char Port_num)
{
  volatile unsigned int val;
  switch(Port_num)
  {
  case 0:
    val= GPIO_PORTA_DATA_R;
    break;
    
  case 1:
    val= GPIO_PORTB_DATA_R;
    break;
    
  case 2:
    val= GPIO_PORTC_DATA_R;
    break;
    
  case 3:
    val= GPIO_PORTD_DATA_R;
    break;
    
  case 4:
    val= GPIO_PORTE_DATA_R;
    break;
    
  case 5:
    val= GPIO_PORTF_DATA_R;
    break;
    
  }
  return val; 
}
char DIO_ReadPin(char Port_num, char Pin_num)
{
    unsigned int val;
  switch(Port_num)
  {
     case  0 :
   switch(Pin_num)
   {
   case 0:
     val = GET_BIT (GPIO_PORTA_DATA_R, 0);
     break;
   case 1:
     val = GET_BIT(GPIO_PORTA_DATA_R, 1);
     break;
   case 2:
     val = GET_BIT(GPIO_PORTA_DATA_R, 2);
     break;
   case 3:
     val = GET_BIT(GPIO_PORTA_DATA_R, 3);
     break;
    case 4:
     val = GET_BIT(GPIO_PORTA_DATA_R, 4);
     break;
     case 5:
     val = GET_BIT(GPIO_PORTA_DATA_R, 5); 
     break;
     case 6:
     val = GET_BIT(GPIO_PORTA_DATA_R, 6);
     break;
     case 7:
     val = GET_BIT(GPIO_PORTA_DATA_R, 7);
     break;
   }
   break;
     case  1 :
   switch(Pin_num)
   {
   case 0:
     val = GET_BIT(GPIO_PORTB_DATA_R, 0);
     break;
   case 1:
     val = GET_BIT(GPIO_PORTB_DATA_R, 1);
     break;
   case 2:
     val = GET_BIT(GPIO_PORTB_DATA_R, 2);
     break;
   case 3:
     val = GET_BIT(GPIO_PORTB_DATA_R, 3);
     break;
    case 4:
     val = GET_BIT(GPIO_PORTB_DATA_R, 4);
     break;
     case 5:
     val = GET_BIT(GPIO_PORTB_DATA_R, 5); 
     break;
     case 6:
     val = GET_BIT(GPIO_PORTB_DATA_R, 6);
     break;
     case 7:
     val = GET_BIT(GPIO_PORTB_DATA_R, 7);
     break;
   }
   break;
     case  2 :
   switch(Pin_num)
   {
   case 0:
     val = GET_BIT(GPIO_PORTC_DATA_R, 0);
     break;
   case 1:
     val = GET_BIT(GPIO_PORTC_DATA_R, 1);
     break;
   case 2:
     val = GET_BIT(GPIO_PORTC_DATA_R, 2);
     break;
   case 3:
     val = GET_BIT(GPIO_PORTC_DATA_R, 3);
     break;
    case 4:
     val = GET_BIT(GPIO_PORTC_DATA_R, 4);
     break;
     case 5:
     val = GET_BIT(GPIO_PORTC_DATA_R, 5); 
     break;
     case 6:
     val = GET_BIT(GPIO_PORTC_DATA_R, 6);
     break;
     case 7:
     val = GET_BIT(GPIO_PORTC_DATA_R, 7);
     break;
   }
   break;
    case  3 :
   switch(Pin_num)
   {
   case 0:
     val = GET_BIT(GPIO_PORTD_DATA_R, 0);
     break;
   case 1:
     val = GET_BIT(GPIO_PORTD_DATA_R, 1);
     break;
   case 2:
     val = GET_BIT(GPIO_PORTD_DATA_R, 2);
     break;
   case 3:
     val = GET_BIT(GPIO_PORTD_DATA_R, 3);
     break;
    case 4:
       break;
     case 5:
     val = GET_BIT(GPIO_PORTD_DATA_R, 5); 
     break;
     case 6:
     val = GET_BIT(GPIO_PORTD_DATA_R, 6);
     break;
     case 7:
     val = GET_BIT(GPIO_PORTD_DATA_R, 7);
     break;
   }
   break;
    case  4 :
    
   switch(Pin_num)
   {
   case 0:
     val = GET_BIT (GPIO_PORTE_DATA_R, 0);
     break;
   case 1:
     val = GET_BIT(GPIO_PORTE_DATA_R, 1);
     break;
   case 2:
     val = GET_BIT(GPIO_PORTE_DATA_R, 2);
     break;
   case 3:
     val = GET_BIT(GPIO_PORTE_DATA_R, 3);
     break;
    case 4:
     val = GET_BIT(GPIO_PORTE_DATA_R, 4);
     break;
   }
   break;
  case  5 :
    
   switch(Pin_num)
   {
   case 0:
     val = GET_BIT(GPIO_PORTF_DATA_R, 0);
     break;
   case 1:
     val = GET_BIT(GPIO_PORTF_DATA_R, 1);
     break;
   case 2:
     val = GET_BIT(GPIO_PORTF_DATA_R, 2);
     break;
   case 3:
     val = GET_BIT(GPIO_PORTF_DATA_R, 3);
     break;
    case 4:
     val = GET_BIT(GPIO_PORTF_DATA_R, 4);
     break;
   }
   break;
  }
  return val;
}
void DIO_init ( char port_num,char pin_num ,PIN_DIRECTION direction )
{
  switch( port_num  )
  {
  case 0 : 
    SYSCTL_RCGCGPIO_R |= 0x00000001;
    switch (direction)
    {
    case 0 :
      CLEAR_BIT(GPIO_PORTA_DIR_R,pin_num); 
      SET_BIT(GPIO_PORTA_PUR_R,pin_num); 
      break;
      case 1 :
      SET_BIT(GPIO_PORTA_DIR_R,pin_num);
      break;
    }
  case 1 :
    SYSCTL_RCGCGPIO_R |= 0x00000002;
    switch (direction)
    {
     case 0 :
      CLEAR_BIT(GPIO_PORTB_DIR_R,pin_num);
      SET_BIT(GPIO_PORTB_PUR_R,pin_num); 
      break;
      case 1 :
      SET_BIT(GPIO_PORTB_DIR_R,pin_num);
      break;
    }
  case 2 : 
    SYSCTL_RCGCGPIO_R |= 0x00000004;
    switch (direction)
    {
    case 0 :
      CLEAR_BIT(GPIO_PORTC_DIR_R,pin_num);
      SET_BIT(GPIO_PORTC_PUR_R,pin_num); 
      break;
      case 1 :
      SET_BIT(GPIO_PORTC_DIR_R,pin_num);
      break;
    }
  case 3 :
    SYSCTL_RCGCGPIO_R |= 0x00000008;
    switch (direction)
    {
    case 0 :
      CLEAR_BIT(GPIO_PORTD_DIR_R,pin_num);
      SET_BIT(GPIO_PORTD_PUR_R,pin_num); 
      break;
      case 1 :
      SET_BIT(GPIO_PORTD_DIR_R,pin_num);
      break;
    }
  case 4 : 
    SYSCTL_RCGCGPIO_R |= 0x00000010;
     GPIO_PORTE_LOCK_R = 0x4C4F434B;
    switch (direction)
    {
     case 0 :
      CLEAR_BIT(GPIO_PORTE_DIR_R,pin_num);
      SET_BIT(GPIO_PORTE_PUR_R,pin_num); 
      break;
      case 1 :
      SET_BIT(GPIO_PORTE_DIR_R,pin_num);
      break;
    }
  case 5 :
    SYSCTL_RCGCGPIO_R |= 0x00000020;
     GPIO_PORTF_LOCK_R = 0x4C4F434B;
      GPIO_PORTF_DEN_R = ENABLE_DIGITAL;
    switch (direction)
    {
    case 0 :
      CLEAR_BIT(GPIO_PORTF_DIR_R,pin_num);  
      SET_BIT(GPIO_PORTF_PUR_R,pin_num); 
      break;
      case 1 :
      SET_BIT(GPIO_PORTF_DIR_R,pin_num);
      break;
    }
  }
}  
void WRITE_PIN (char port_num,char pin_num , VALUE_PIN  value  ){ 
  switch( port_num  ) {
     case 0 : 
    switch (value) {
    case 0 :   
    CLEAR_BIT(GPIO_PORTA_DATA_R ,pin_num); 
    break;   
    case 1 : 
      SET_BIT(GPIO_PORTA_DATA_R ,pin_num); 
      break; 
  }
  break; 
     case 1 : 
    switch (value) {
    case 0 :   
    CLEAR_BIT(GPIO_PORTB_DATA_R ,pin_num); 
    break;   
    case 1 : 
      SET_BIT(GPIO_PORTB_DATA_R ,pin_num); 
      break; 
  }
  break; 
     case 2 : 
    switch (value) {
    case 0 :   
    CLEAR_BIT(GPIO_PORTC_DATA_R ,pin_num); 
    break;   
    case 1 : 
      SET_BIT(GPIO_PORTC_DATA_R ,pin_num); 
      break; 
  }
  break; 
  case 3 : 
    switch (value) {
    case 0 :   
    CLEAR_BIT(GPIO_PORTD_DATA_R ,pin_num); 
    break;   
    case 1 : 
      SET_BIT(GPIO_PORTD_DATA_R ,pin_num); 
      break; 
  }
  break;  
   case 4 : 
    switch (value) {
    case 0 :   
    CLEAR_BIT(GPIO_PORTE_DATA_R ,pin_num); 
    break;   
    case 1 : 
      SET_BIT(GPIO_PORTE_DATA_R ,pin_num); 
      break; 
  }
  break; 
   case 5 : 
    switch (value) {
    case 0 :   
    CLEAR_BIT(GPIO_PORTF_DATA_R ,pin_num); 
    break;   
    case 1 : 
      SET_BIT(GPIO_PORTF_DATA_R ,pin_num); 
      break; 
  }
  break; 
  }
} 
void DIO_WritePort ( char port_num , char value ){
     switch( port_num)
  {
  case 0 : 
    SYSCTL_RCGCGPIO_R |= 0x00000001;
    GPIO_PORTA_DATA_R  = value ; 
    break;
     case 1 : 
    SYSCTL_RCGCGPIO_R |= 0x00000002;
    GPIO_PORTB_DATA_R = value ; 
    break;
     case 2 : 
    SYSCTL_RCGCGPIO_R |= 0x00000004;
    GPIO_PORTC_DATA_R = value ; 
    break;
     case 3 : 
    SYSCTL_RCGCGPIO_R |= 0x00000008;
    GPIO_PORTD_DATA_R = value ; 
    break;
     case 4 : 
    SYSCTL_RCGCGPIO_R |= 0x000000010;
    GPIO_PORTE_DATA_R = value ; 
    break;
     case 5 : 
    SYSCTL_RCGCGPIO_R |= 0x00000020;
    GPIO_PORTF_DATA_R = value ;  
    break;
  }
} 
