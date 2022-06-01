/**********************************************************************
LCD erabiltzeko funtzioak:
	Hasieraketa
	Komando bat bidali
	Datu bat bistaratu
	Testu bat bistaratu
	Funtzio bereziak: 1. lerroan kokatu // 2. lerroan kokatu
**********************************************************************/

#include "p24HJ256GP610A.h"
#include "timer_denbora.h"
#include "xc.h"
#include "commons.h"
	
/* 
   For Explorer 16 board, here are the data and control signal definitions
   RS -> RB15
   E  -> RD4
   RW -> RD5
   DATA -> RE0 - RE7   
*/

// Control signal data pins 
#define  RW  LATDbits.LATD5       // LCD R/W signal
#define  RS  LATBbits.LATB15      // LCD RS signal
#define  E   LATDbits.LATD4       // LCD E signal 

// Control signal pin direction 
#define  RW_TRIS	TRISDbits.TRISD5 
#define  RS_TRIS	TRISBbits.TRISB15
#define  E_TRIS		TRISDbits.TRISD4

// Data signals and pin direction
#define  DATA      LATE           // Port for LCD data
#define  DATAPORT  PORTE
#define  TRISDATA  TRISE          // I/O setup for data Port


/*****	LCD SUBROUTINES  *****/ 
void lcd_cmd (char cmd)        // subroutiune for lcd commands
{
  RW = 0;             // RW 0ra jarri, idazketa
  RS = 0;					    // RS 0ra jarri, komando idazteko
  DATA &= 0xFF00;     // Ezabatu datuaren 8 bitak (prepare RD0 - RD7) 
  DATA |= cmd;        // Komandoa (parametroan) kopiatu (command byte to lcd)
  E = 1;              // E aktibatu (toggle E line)
  Nop();				      // 10 NOP. ZERTARAKO??
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  E = 0;						 // E desaktibatu
  RW = 1;						 // Idazketa desaktibatu
}




void lcd_data (char data)      // subroutine for lcd data
{
  RW = 0;       		 // RW 0ra jarri, idazketa
  RS = 1;            // RS 1era jarri, datua idazteko
  DATA &= 0xFF00;    // Ezabatu datuaren 8 bitak (prepare RD0 - RD7)
  DATA |= data;      // Datua (parametroan) kopiatu (data byte to lcd)
  E = 1;             // E aktibatu (toggle E line)
  Nop();             // 10 NOP. ZERTARAKO
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  E = 0;             // E desaktibatu
  RS = 0;            // RS desaktibatu
  RW = 1;						 // Idazketa desaktibatu
}

void Init_LCD ()             // initialize LCD display
{
  // 15mS delay after Vdd reaches nnVdc before proceeding 
  // with LCD initialization
  // not always required and is based on system Vdd rise rate
  Delay_ms (15); // 15 ms delay
			
  /* set initial states for the data and control pins */
  DATA &= 0xFF00;	
  RW = 0;                       // R/W state set low
  RS = 0;                       // RS state set low
  E = 0;                        // E state set low

  /* set data and control pins to outputs */
  TRISDATA &= 0xFF00;
  RW_TRIS = 0;                  // RW pin set as output
  RS_TRIS = 0;                  // RS pin set as output
  E_TRIS = 0;                   // E pin set as output

  /* LCD initialization sequence */ 
  lcd_cmd (0x38);				// function set (3 aldiz)
  Delay_ms (5);         // 5 ms delay
  lcd_cmd (0x38);
  Delay_us (100);       // 100 us delay
  lcd_cmd (0x38);
  Delay_us (40);      // 40us delay (taulan begiratu)
  lcd_cmd (0x38);  
  Delay_us (40);      // 40us delay (taulan begiratu)
  lcd_cmd (0x0C);       // Display on/off control, cursor blink off (0x0C)
  Delay_us (40);      // 40us delay (taulan begiratu)
  lcd_cmd (0x06);			  // Entry mode set (0x06)
  Delay_us (40);      // 40us delay (taulan begiratu)
}





void puts_lcd (unsigned char *data, unsigned char count) 
{
    Nop();
    Nop();
    Nop();
  while (count)
	{
	 lcd_data(*data++);
     Delay_us (40);			// 40us delay (taulan begiratu)
	 count--;
	}	
}

void line_1()
{
    lcd_cmd(0x80);  	// Set DDRAM address (@0)
    Delay_us (40);  // 40us delay (taulan begiratu)
}

void line_2()
{
    lcd_cmd(0xC0);  	// Set DDRAM address (@40)
    Delay_us (40);  // 40us delay (taulan begiratu)
}
