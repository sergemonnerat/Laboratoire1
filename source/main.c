/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include <MKL46Z4.h>

// Pointeur permettant d'accéder aux registres de configuration des pattes du up
unsigned long *gPinCtrlAddr;

// Pointeur permettant d'accéder aux registres de direction de chaque port
unsigned long *gPDDRAdr;

// Pointeur permettant d'accéder aux registres de données des ports IO
unsigned long *gGPIOB_PDIR = (unsigned long*) 0x400FF050;
unsigned long *gGPIOC_PDIR = (unsigned long*) 0x400FF090;
unsigned long *gGPIOD_PDIR = (unsigned long*) 0x400FF0D0;

unsigned long *gGPIOA_PDOR = (unsigned long*) 0x400FF000;
unsigned long *gGPIOC_PDOR = (unsigned long*) 0x400FF080;
unsigned long *gGPIOD_PDOR = (unsigned long*) 0x400FF0C0;

// Pointeur permettant d'accéder aux registres d'enable des clocks des port IO
unsigned long *gSIMSCGC5Addr = (unsigned long*) 0x40048038;

//-----------------------------------------------------------------------------
// Programme principal
//-----------------------------------------------------------------------------
int main(void)
	{

		// ------------------------------------------------------------
		// Enable du clock des ports IO
		// ------------------------------------------------------------
		*gSIMSCGC5Addr = (0 | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12)
				| (1 << 13));

		// ------------------------------------------------------------
		// Configuration de la fonction des pattes du microcontrôleur
		// ------------------------------------------------------------
		// --> 8 LEDS de la carte fille
		// PORTD_PCR2 - LED1
		gPinCtrlAddr = (unsigned long*) 0x4004C008;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTA_PCR13 - LED2
		gPinCtrlAddr = (unsigned long*) 0x40049034;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR9 - LED3
		gPinCtrlAddr = (unsigned long*) 0x4004B024;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR8 - LED4
		gPinCtrlAddr = (unsigned long*) 0x4004B020;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTA_PCR5 - LED5
		gPinCtrlAddr = (unsigned long*) 0x40049014;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTA_PCR4 - LED6
		gPinCtrlAddr = (unsigned long*) 0x40049010;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTA_PCR12 - LED7
		gPinCtrlAddr = (unsigned long*) 0x40049030;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTD_PCR3 - LED8
		gPinCtrlAddr = (unsigned long*) 0x4004C00C;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;

		// --> 8 interrupteurs de la carte mère
		// PORTB_PCR18 - SWITCH1
		gPinCtrlAddr = (unsigned long*) 0x4004A048;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTB_PCR19 - SWITCH2
		gPinCtrlAddr = (unsigned long*) 0x4004A04C;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR0 - SWITCH3
		gPinCtrlAddr = (unsigned long*) 0x4004B000;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR4 - SWITCH4
		gPinCtrlAddr = (unsigned long*) 0x4004B010;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR6 - SWITCH5
		gPinCtrlAddr = (unsigned long*) 0x4004B018;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR7 - SWITCH6
		gPinCtrlAddr = (unsigned long*) 0x4004B01C;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR10 - SWITCH7
		gPinCtrlAddr = (unsigned long*) 0x4004B028;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTC_PCR11 - SWITCH8
		gPinCtrlAddr = (unsigned long*) 0x4004B02C;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;

		// --> 4 boutons poussoir de la carte mère
		// PORTD_PCR5 - PUSHBUT1
		gPinCtrlAddr = (unsigned long*) 0x4004C014;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTD_PCR7 - PUSHBUT2
		gPinCtrlAddr = (unsigned long*) 0x4004C01C;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTD_PCR6 - PUSHBUT3
		gPinCtrlAddr = (unsigned long*) 0x4004C018;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;
		// PORTD_PCR4 - PUSHBUT4
		gPinCtrlAddr = (unsigned long*) 0x4004C010;
		// Reset du champ
		*gPinCtrlAddr &= 0xFFFFF8FF;
		// Alternative 1 (GPIO)
		*gPinCtrlAddr |= 0x00000100;

		// ------------------------------------------------------------
		// Configuration des ports en entrée ou sortie
		// ------------------------------------------------------------
		// Port A
		gPDDRAdr = (unsigned long*) 0x400FF014;
		*gPDDRAdr = (0 | (1 << 4) | (1 << 5) | (1 << 12) | (1 << 13));
		// Port B
		gPDDRAdr = (unsigned long*) 0x400FF054;
		*gPDDRAdr = 0;
		// Port C
		gPDDRAdr = (unsigned long*) 0x400FF094;
		*gPDDRAdr = (0 | (1 << 8) | (1 << 9));
		// Port D
		gPDDRAdr = (unsigned long*) 0x400FF0D4;
		*gPDDRAdr = (0 | (1 << 2) | (1 << 3));

		// Boucle infinie
		for (;;)
			{
				// Contrôle si le bouton PUSHBUT1 est "ON"
				if ((*gGPIOD_PDIR & (1 << 5)) == (1 << 5))
					{
						// On éteint toutes les LEDS
						*gGPIOA_PDOR &= (~((1 << 4) | (1 << 5) | (1 << 12) | (1 << 13)));
						*gGPIOC_PDOR &= (~((1 << 8) | (1 << 9)));
						*gGPIOD_PDOR &= (~((1 << 2) | (1 << 3)));
					}
				// Contrôle si le bouton PUSHBUT2 est "ON"
				else if ((*gGPIOD_PDIR & (1 << 7)) == (1 << 7))
					{
						// On allume toutes les LEDS
						*gGPIOA_PDOR |= ((1 << 4) | (1 << 5) | (1 << 12) | (1 << 13));
						*gGPIOC_PDOR |= ((1 << 8) | (1 << 9));
						*gGPIOD_PDOR |= ((1 << 2) | (1 << 3));
					}
				else
					{
						// Contrôle si l'interrupteur 1 est "ON"
						if ((*gGPIOB_PDIR & (1 << 18)) == (1 << 18))
							{
								// On allume la LED 5
								*gGPIOA_PDOR |= (0 | (1 << 5));
							}
						else
							{
								// On éteint la LED 5
								*gGPIOA_PDOR &= (~(0 | (1 << 5)));
							}

						// Contrôle si l'interrupteur 2 est "ON"
						if ((*gGPIOB_PDIR & (1 << 19)) == (1 << 19))
							{
								// On allume la LED 6
								*gGPIOA_PDOR |= (0 | (1 << 4));
							}
						else
							{
								// On éteint la LED 6
								*gGPIOA_PDOR &= (~(0 | (1 << 4)));
							}

						// Contrôle si l'interrupteur 3 est "ON"
						if ((*gGPIOC_PDIR & (1 << 0)) == (1 << 0))
							{
								// On allume la LED 7
								*gGPIOA_PDOR |= (0 | (1 << 12));
							}
						else
							{
								// On éteint la LED 7
								*gGPIOA_PDOR &= (~(0 | (1 << 12)));
							}

						// Contrôle si l'interrupteur 4 est "ON"
						if ((*gGPIOC_PDIR & (1 << 4)) == (1 << 4))
							{
								// On allume la LED 8
								*gGPIOD_PDOR |= (0 | (1 << 3));
							}
						else
							{
								// On éteint la LED 8
								*gGPIOD_PDOR &= (~(0 | (1 << 3)));
							}

						// Contrôle si l'interrupteur 5 est "ON"
						if ((*gGPIOC_PDIR & (1 << 6)) == (1 << 6))
							{
								// On allume la LED 1
								*gGPIOD_PDOR |= (0 | (1 << 2));
							}
						else
							{
								// On éteint la LED 1
								*gGPIOD_PDOR &= (~(0 | (1 << 2)));
							}

						// Contrôle si l'interrupteur 6 est "ON"
						if ((*gGPIOC_PDIR & (1 << 7)) == (1 << 7))
							{
								// On allume la LED 2
								*gGPIOA_PDOR |= (0 | (1 << 13));
							}
						else
							{
								// On éteint la LED 2
								*gGPIOA_PDOR &= (~(0 | (1 << 13)));
							}

						// Contrôle si l'interrupteur 7 est "ON"
						if ((*gGPIOC_PDIR & (1 << 10)) == (1 << 10))
							{
								// On allume la LED 3
								*gGPIOC_PDOR |= (0 | (1 << 9));
							}
						else
							{
								// On éteint la LED 3
								*gGPIOC_PDOR &= (~(0 | (1 << 9)));
							}

						// Contrôle si l'interrupteur 8 est "ON"
						if ((*gGPIOC_PDIR & (1 << 11)) == (1 << 11))
							{
								// On allume la LED 4
								*gGPIOC_PDOR |= (0 | (1 << 8));
							}
						else
							{
								// On éteint la LED 4
								*gGPIOC_PDOR &= (~(0 | (1 << 8)));
							}

					}

			} /* wait forever */
	}

