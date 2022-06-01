
/*
 *Egileak:Jon Ayuso eta Markel Azpeitia
 * Data: 2020/02/11
 */

#include "p24HJ256GP610A.h"
#include "commons.h"

// Oscilator moduluaren hasieraketa
// Konfigurazioa ikusteko:
//      Barra herramientas: Windows -> PIC Memory Views -> Configuration Bits


// Oscilator moduluaren konfigurazioa
# pragma config FNOSC=PRIPLL   //Primary oscillator (XT, HS, EC) w/PLL
# pragma config FCKSM=CSECMD   //Enable Clok switching
# pragma config OSCIOFNC=OFF   //OSC2 is clock
# pragma config POSCMD=XT      //XT oscillator
# pragma config FWDTEN=OFF     //Watchdog Timer: Disabled


void Inic_Oscilator ()
{
// Configure Oscillator to operate the device at 40MHz 
// (erlojua 80 MHz-etan, aginduen exekuzio-abiadura 40 MHz izan dadin).
// Fosc= Fin*M(N1*N2),  Fcy=Fosc/2
// Fosc= 8M*40/(2*2)= 80MHz for 8MHz input clock
// M=40 --> 80 MHz Instruction 25ns
// M=20 --> 40 MHz Instruction 50ns
// M=10 --> 20 MHz Instruction 100ns

	PLLFBD = 40-2;						// M=4
	CLKDIVbits.PLLPOST = 0;		// N2=2
	CLKDIVbits.PLLPRE = 0;		// N1=2
	RCONbits.SWDTEN = 0;			// Disable Watch Dog Timer

// Aldez aurretik konpilatutako funtzioak: MPLAB C30 -DS51284G- B eranskinean
// Clock switch to incorporate PLL

	__builtin_write_OSCCONH(0x03);	// Initiate Clock Switch to Primary
																	// Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01);	// Start clock switching
	while (OSCCONbits.COSC != 0b011);// Wait fot Clock switch to occur

// Wait for PLL to lock
	while(OSCCONbits.LOCK !=1) {}
}