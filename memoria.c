/*
Komentarioak!!!
Egileak eta data!!!
*/

#include "p24HJ256GP610A.h"
#include "commons.h"

const unsigned char Testua_LCD_1[]={" Gradu Amaierako"};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_2[]={" Lana, s3 sakatu"};  // 2.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_3[]={"Giroskopio   X  "};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_4[]={"Giroskopio   Y  "};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_5[]={"Giroskopio   Z  "};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_6[]={"Azeleromet   X  "};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_7[]={"Azeleromet   Y  "};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_8[]={"Azeleromet   Z  "};  // 1.1 lerroa, 16 karaktere
const unsigned char Testua_LCD_9[]={"                "};  // 1.1 lerroa, 16 karaktere

unsigned char Leihoa_LCD[2][16];


void Kopiatu_FLASH_RAM (const unsigned char *testua, unsigned int i)
{
  unsigned int j;
  for (j=0;j<16;j++) Leihoa_LCD[i][j]=testua[j];
}

