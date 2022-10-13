#include "tm4c123gh6pm.h" 
#ifndef DIO_H
#define DIO_H
#define NUM_TIMERS 762 
#define ENABLE_DIGITAL 0XFF      
# define PORT_A 0
# define PORT_B 1
# define PORT_C 2
# define PORT_D 3
# define PORT_E 4
# define PORT_F 5
# define PIN_0 0
# define PIN_1 1
# define PIN_2 2
# define PIN_3 3
# define PIN_4 4
# define PIN_5 5
# define PIN_6 6
# define PIN_7 7
# define PIN_8 8
# define DIR_LOW  0
# define DIR_HIGH 1  
#define PORT_LOW  0X00 
#define PORT_HIGH 0XFF 
typedef enum {
PIN_INPUT , PIN_OUTPUT
} PIN_DIRECTION ; 
typedef enum {
 LOGIC_LOW , LOGIC_HIGH 
} VALUE_PIN  ;
int DIO_ReadPort (char Port_num) ;
 char DIO_ReadPin(char Port_num, char Pin_num);
void DIO_init ( char port_num , char pin_num , PIN_DIRECTION direction );
void WRITE_PIN (char port_num,char pin_num , VALUE_PIN  value  ) ; 
void DIO_WritePort ( char port_num  , char value ) ; 


#endif