/*******************************/
/*** Created by Ovidiu Sabau ***/
/***  29th December 2022	 ***/
/*******************************/

#include "PowerManagement.h"
#include "interruptConfig.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>


void blink_LED_PORTD(uint8_t, uint8_t);


int main(void)
{
	/* Initialization */
	interruptConfig();
	
	while(1)
	{
		/* Some sequence */
		blink_LED_PORTD(PIND7, 3);
		_delay_ms(3000);
	
		/* Power management */
		enable_interrupts();
		enterSleep();
	}
	return 0;
}


/* *****************************************************************
Name:		Interrupt service routine 0
Inputs:		none
Outputs:	none
Description:wakes up MCU when an external interrupt on pin PIND2 occurs
******************************************************************** */
ISR(INT0_vect)
{
	cli();
	_delay_ms(50);	// prevent pin toggling due to imperfect switching
}

/* *****************************************************************
Name:		blink_LED_PORTD()
Inputs:		pin number of the LED and how many times LED should blink
Outputs:	none
Description:blinks a LED a defined number of times
******************************************************************** */
void blink_LED_PORTD(uint8_t pinNumber, uint8_t times)
{
	DDRD |= (1 << pinNumber);
	for (uint8_t i = 0; i < times; i++)
	{
		PORTD |= ( 1 << pinNumber );
		_delay_ms(100);
		PORTD &= ~( 1 << pinNumber );
		_delay_ms(100);
	}
}