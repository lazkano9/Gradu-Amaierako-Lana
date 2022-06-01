/*
 *Egileak:Jon Ayuso eta Markel Azpeitia
 * Data: 2020/02/11
 */

#include "p24HJ256GP610A.h"
#include "memoria.h"
#include "kalk_bihurketak.h"
#include "LCD.h"
#include "xc.h"
#include "commons.h"

//Aldagaiak ezagutarazi
unsigned int ms_kop, s, min, cents;
unsigned int dist_prest;
#define LED3 LATAbits.LATA0
#define LED4 LATAbits.LATA1
#define LED5 LATAbits.LATA2
#define LED6 LATAbits.LATA3
#define LED7 LATAbits.LATA4

void prestatu_Timer_5 ()
{
    TMR5 = 0 ; 	//hasieratu timerraren erregistroa, 0tik kontatzen has dadin
    PR5 =  25000 ;	//1ms
    T5CONbits.TCKPS = 0;	// prescalerra	1:1
    T5CONbits.TCS = 0;	// barne-erlojuarekin 
    T5CONbits.TGATE = 0;	// Gate modua desgaitzeko
    T5CONbits.TON = 1;	// timerra martxan jarri
    _T5IE = 1;   //Etena gaitu
}


//LCDa frexkatzeko 2ms ro etena
void prestatu_Timer_2 ()
{
	TMR2 = 0 ; 	//hasieratu timerraren erregistroa, 0tik kontatzen has dadin
	T2CONbits.TCKPS=1; //preescaler 8
 	PR2= 10000-1; //2 ms-ro etena
				//timer_1en kontrol-erregistroan, honako hau idatzi behar dugu:
				//timerraren funtzionamendua gaitzeko (pisu handieneko bita, TON = 1),
				//prescaler delakoan behar den ratioa 1:1 (TCKPS1:TCKPS0 bitak = 00),
				//eta barne-erlojuarekin (TCS bita = 0).
				//Kasu honetan, beste bit guztiek ez dute garrantziarik guretzat.

	//Azken hori, honelaxe ere egin daiteke, bitak banan-banan idatziz:

	T2CONbits.TGATE = 0;			//Gate modua desgaitzeko           
	T2CONbits.TCS = 0;			//barne-erlojua
    T2CONbits.TON = 1;			//barne-erlojua
    _T2IE = 1;
	//etenen bidez egiteko, bit gehiago tratatu behar dira. Zeintzuk?
}

//ms ro eten bat sortzen du kronometroa kalkulatzeko
void prestatu_Timer_1 ()
{
	TMR1 = 0 ; 	//hasieratu timerraren erregistroa, 0tik kontatzen has dadin
	T1CONbits.TCKPS=1;  //prescaler 8
    PR1 = 5000-1;
 	
				//timer_1en kontrol-erregistroan, honako hau idatzi behar dugu:
				//timerraren funtzionamendua gaitzeko (pisu handieneko bita, TON = 1),
				//prescaler delakoan behar den ratioa 1:1 (TCKPS1:TCKPS0 bitak = 00),
				//eta barne-erlojuarekin (TCS bita = 0).
				//Kasu honetan, beste bit guztiek ez dute garrantziarik guretzat.

	//Azken hori, honelaxe ere egin daiteke, bitak banan-banan idatziz:

	T1CONbits.TGATE = 0;			//Gate modua desgaitzeko     
	T1CONbits.TCS = 0;			//barne-erlojua
    T1CONbits.TON = 1;
    _T1IE = 1;
	//etenen bidez egiteko, bit gehiago tratatu behar dira. Zeintzuk?
}	


void Delay_ms (unsigned int mst)		//mst milisegundo pasatu dela detektatzen duen funtzioa.
{
    T4CONbits.TCKPS1 = 1;			//prescalerraren balioa hautatzeko
    T4CONbits.TCKPS0 = 1;           //preescalerra 1:256 moduan jarri TCKPS0 eta TCKPS1 = 1
    TMR4 = 0 ;
    PR4 = (mst*(156))-1;	//finkatu timerraren periodoa. Kasu honetan, mst ms kontatzea nahi dugu.
				//Balio hori honelaxe kalkulatu dugu:
				//Kanpoko osziladorearen maiztasuna 80 MHz denez (oscilator.c funtzioan finkatutako balioa),
				//orduan aginduen exekuzio-abiadura FCY = 80/2=40 MHz da, agindu bakoitzak bi ziklo behar dituelako.
				//Ondorioz, agindu bakoitzaren periodoa hau da: 1 / 40MHz = 25 ns.(preescalerra 256 denez kontaketa bakoitza 25*256=6400ns)
				//Hortaz, 1 ms = 10^6ns lortzeko, 40000/256 (10^6/6400) ziklo kontatu behar dira. Preescalerra 256 denez kalkukoa egiterakoan /256 egin behar dugu.
                //GEHIENEZ 419 ms KONTATU DITZAKEGU (2^16/(40000/256))
    T4CONbits.TON = 1;			//timerra gaitzea
    while (!_T4IF)	//TIMER1 aurresandako baliora iristean...
    {
        Nop();
    }	
    _T4IF = 0 ;	//utzi timerra prest hurrengo kontaketa detektatu ahal izateko, flag-a desaktibatu
    T4CONbits.TON = 0;
}	

void Delay_us (unsigned int ust)		//1 milisegundo pasatu dela detektatzen duen funtzioa.
{
    T4CONbits.TCKPS1 = 0;			//prescalerraren balioa hautatzeko
    T4CONbits.TCKPS0 = 1;           //preescalerra 1:8 moduan jarri TCKPS0=1 eta TCKPS1 = 0
    TMR4 = 0 ;
    PR4 =  (ust*5) -1 ;	//finkatu timerraren periodoa. Kasu honetan, ust micro segundu kontatzea nahi dugu.
				//Balio hori honelaxe kalkulatu dugu:
				//Kanpoko osziladorearen maiztasuna 80 MHz denez (oscilator.c funtzioan finkatutako balioa),
				//orduan aginduen exekuzio-abiadura FCY = 80/2=40 MHz da, agindu bakoitzak bi ziklo behar dituelako.
				//Ondorioz, agindu bakoitzaren periodoa hau da: 1 / 40MHz = 25 ns.(preescalerra 8 denez kontaketa bakoitza 25*8=200ns)
				//Hortaz, 1us = 10^3ns lortzeko, 10^3/200 = 5 ziklo kontatu behar dira.
    T4CONbits.TON = 1;			//timerra gaitzea
    while (!_T4IF)	//TIMER1 aurresandako baliora iristean...
    {
    Nop();
    }	
    _T4IF = 0 ;	//utzi timerra prest hurrengo kontaketa detektatu ahal izateko, flag-a desaktibatu
    T4CONbits.TON = 0;
}

void _ISR __attribute__((no_auto_psv)) _T1Interrupt (void)   //ms bakoitzero
{
    ms_kop++;
    _T1IF = 0;
}




//lcd eguneratu
void _ISR __attribute__((no_auto_psv)) _T2Interrupt (void)   //ms bakoitzero
{
    static unsigned int indize=0;
    static unsigned int egoera=0; 
    switch(egoera){
        case 0:
            lcd_cmd(0x80);
            egoera++;
            indize=0;
        break;
        case 1:
            lcd_data(Leihoa_LCD[0][indize]);
            if(indize==15){
                egoera++;
            }
            indize++;
        break;
        case 2:
            lcd_cmd(0xC0);
            egoera++;
            indize=0;
        break;      
        case 3:
            lcd_data(Leihoa_LCD[1][indize]);
            if(indize==15){
                egoera=0;
            }
            indize++;
        break;
    }
    
    _T2IF = 0;
}




