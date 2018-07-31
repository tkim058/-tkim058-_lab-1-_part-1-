/*
 * [tkim058]_lab[1]_part[1].c
 *	Partner(s) Name & E-mail: No partner yet
 *	Lab Section: B01
 *	Assignment: Lab #1  Exercise #1
 *	Exercise Description: [Return 1 if PA1PA0 is 01 else return 0 on PB0]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,
	// initialize to 0s
	unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpA1 = 0x00;
	while(1)
	{
		// (1) Read input
		tmpA = PINA & 0x02;
		tmpA1 = PINA & 0x01;
		// (2) Perform computation
		// if PA1PA0 is 01, set PB0=1, else=0
		if (tmpA1 == 0x01 && tmpA == 0x00) { // True if PA1PA0 is 01
			tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
			// (clear rightmost 2 bits, then set to 01)
		}
		else {
			tmpB = (tmpB & 0xFC) | 0x00; // Sets tmpB to bbbbbb10
			// (clear rightmost 2 bits, then set to 10)
		}
		// (3) Write output
		PORTB = tmpB;
	}
	return 0;
}
