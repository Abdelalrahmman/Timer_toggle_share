/*
 * main.c
 *
 *  Created on: 26.07.2024
 *      Author: abeda
 */

//#include <inttypes.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <avr/sleep.h>
//#include <util/delay.h>
#include <stdio.h>

#define set(x,y)  (x|=(1<<y))
#define reset(x,y)  (x&=~(1<<y))
#define SREG   *((uint8_t*)0x5fUL)//INT
#define TCCR0	*((uint8_t*)0x53UL)
#define DDRD   *((uint8_t*)0x31UL)
#define TCNT0	*((uint8_t*)0x52UL)
#define DDRA   *((uint8_t*)0x3aUL)
#define PORTA  *((uint8_t*)0x3bUL)
#define PORTD  *((uint8_t*)0x32UL)
#define TIMSK	*((uint8_t*)0x59UL)

__attribute__((signal)) void __vector_11();

void __vector_11()
{  static int i=0;
i++;
if(i==245u)
{
	PORTA^=(1<<0);
	i=0;
}
}



int main(){
	TCCR0=0b00000100;
	set(DDRA,0); //OUT
	set(SREG,7); //INT
	TCNT0=220u;  //either Preload or Timer0 Value
	set(TIMSK,0);
 while(1); //why does it only with while work?


	return 0;
}

