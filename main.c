#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	lcdInit();
	lcdShowStr("jhbzs",0);
	lcdShowStr("jhbzs",17);

	return 0;
}
