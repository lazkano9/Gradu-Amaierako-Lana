/*
Komentarioak!!!
Egileak eta data!!!
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
unsigned char TAULAHEX [16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ,'A', 'B', 'C', 'D', 'E', 'F'};

// Bi digituko balio baten karaktereak lortzeko funtzioa.
// Parametroak:
// bal, ASCII kodera itzuli behar den balioa adierazten du
// d1, helbide bat non pisu handieneko digituaren ASCII kodea itzuliko duen
// d0, helbide bat non pisu handieneko digituaren ASCII kodea itzuliko duen

void denbora_bihurketa (unsigned char * d1, unsigned char *d0, 
												unsigned int bal)
{
    *d1 = (bal/10);
	*d1 |= 0x30;
    
    *d0 = (bal%10);
    *d0 |= 0x30;
}

void sentsore_bihurketa (unsigned char bek[], int * a, int * b, int * c, int * d, int * e, int * f){
   * a = bek[0]<<8;
   * a = * a | bek[1];
   * b = bek[2]<<8;
   * b = * b | bek[3];
   * c = bek[4]<<8;
   * c = * c | bek[5];
   * d = bek[8]<<8;
   * d = * d | bek[7];
   * e = bek[10]<<8;
   * e = * e | bek[9];
   * f = bek[12]<<8;
   * f = * f | bek[11];
}


void BiByteLCD (unsigned char * kar1, unsigned char * kar2, unsigned char * kar3, unsigned char * kar4, unsigned char * kar5, unsigned int bal){
    unsigned int x0, x1, x2, x3, x4;
    
    x0 = bal / 10000;
    *kar1 = TAULAHEX[x0];
    
    x1 = bal %10000;
    x1= x1 /1000;
    *kar2 = TAULAHEX[x1];
    
    
    x2 = (bal%10000) % 1000;
    x2= x2 /100;
    *kar3 = TAULAHEX[x2];
    
    x3 = ((bal%10000) % 1000) % 100;
    x3= x3 / 10;
    *kar4 = TAULAHEX[x3];
    
    x4 = (((bal%10000) % 1000) % 100)%10;
    *kar5 = TAULAHEX[x4];
    
    
    
}


void hamar_bihurketa (unsigned char * kar1, unsigned char * kar2, unsigned char * kar3, unsigned char * kar4, unsigned int bal){
    unsigned int x1, x2, x3, x0;
    
    x0 = bal / 1000;
    *kar1 = TAULAHEX[x0];
    
    x1 = bal %1000;
    x1= x1 /100;
    *kar2 = TAULAHEX[x1];
    
    
    x2 = (bal%1000) % 100;
    x2= x2 /10;
    *kar3 = TAULAHEX[x2];
    
    x3 = ((bal%1000) % 100) % 10;
    *kar4 = TAULAHEX[x3];
}
	



