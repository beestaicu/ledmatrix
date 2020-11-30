/*
 * ledmatrix.c
 *
 * Created: 24/05/2020 20:17:47
 * Author : bee
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define delay _delay_ms(1);


int main(void)
{
	
	
	DDRB = 0b00111111;			// Set B0,1,2,3,4,5 as output for positive LED
	DDRC = 0b00011111;			// Set C0,1,2,3,4 as output for negative LED
	PORTB = 0x00;				// clear port b
	PORTC = 0x00;				// clear port c
	
	
	uint8_t  portC[5] = {0b11111110,0b11111101,0b11111011,0b11110111,0b11101111}; // port c 01234low
	uint8_t  portB[5] = {0b00000100,0b00100010,0b00111111,0b00100000,0b00000000};
	uint8_t j;
	
	while (1)
	{
		for (j = 0;j <5;j++){
			PORTB = portB[j];
			PORTC = portC[j];
			delay;
		}
	}
	
	
	
	}
