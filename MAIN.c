/*
 Egilea: Julen Lazkano
 Data: 2022/03/04
*/

#include "p24HJ256GP610A.h"
#include "oscilator.h"
#include "timer_denbora.h"
#include "memoria.h"
#include "kalk_bihurketak.h"
#include "LCD.h"
#include "i2c_funtzioak.h"
#include "mpu9250.h"
#include "commons.h"
#include "CN.h"
#include "math.h"

int main()
{
   int azel_X, azel_Y, azel_Z, gyro_X, gyro_Y, gyro_Z;
   //unsigned char aldagaia[12];
    unsigned int I2C_Libre;         //Hau ez badet jartzen ez du ondo iten
   
   TRISA = 0xff00;
   
   Inic_Oscilator(); // Erlojuaren aukeraketa eta hasieraketa (80 MHz-etan)
   
   konfiguratu_CN(); //Etenak konfiguratu
   
   Init_LCD();       // LCDaren hasieraketa
      
   prestatu_Timer_1(); //Milisegunduro eteten du ms_kop geituz

   prestatu_Timer_2();   //LCD-a freskatzen du eten bakoitzean (2ms-ro)

  ////////////////////////////////////////////////////////////////////
  //RAM memoriara ekarri testua (agurra: Testua_LCD_1 // Testua_LCD_2)
  Kopiatu_FLASH_RAM(Testua_LCD_1,0);
  Kopiatu_FLASH_RAM(Testua_LCD_2,1);
   
  //S3 pultsadorea sakatu arte, ez atera proiektuaren mezua
  while (PORTDbits.RD6);
  
  Kopiatu_FLASH_RAM(Testua_LCD_9,1);
  
   //I2C busa konfiguratu
   InitI2C_1();
   I2C_etena_gaitu();
   I2C_Libre=1;
   
   //MPU9250 Sentsorea konfiguratu (Giroskopio eta Azelerometroa)
   konfigurazioa_MPU();
   //if (I2C_Libre) I2C_Eten_Idatzi(0xd0, 0x1B, 0x10);        //Giroskopio konfigurazioa
   //while(!I2C_Libre);
   //if (I2C_Libre) I2C_Eten_Idatzi(0xd0, 0x1C, 0x10);        //Azelerometro konfigurazioa
   //while(!I2C_Libre);
   if(I2C_Libre) I2C_Eten_Irakurri(0xd0, 0x3B);             //Datuen irakurketa
   while(I2C_Libre==0);
   if(ms_kop > 600) sentsore_bihurketa(aldagaia, &azel_X, &azel_Y, &azel_Z, &gyro_X, &gyro_Y, &gyro_Z);
   
   Kopiatu_FLASH_RAM(Testua_LCD_6,0);
   BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], azel_X);
   
  //BEGIZTA NAGUSIA
  while(1){
     /* if (ms_kop > 200) {
          //Balioak sentsoretik irakurri eta aldagaietan gorde
          
          irakurriBalioak(aldagaia);
          sentsore_bihurketa(aldagaia, &azel_X, &azel_Y, &azel_Z, &gyro_X, &gyro_Y, &gyro_Z);
          
          switch (egoera){
              case 0:
                  Kopiatu_FLASH_RAM(Testua_LCD_6,0);
                  BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], azel_X);
                  break;
              case 1:
                  Kopiatu_FLASH_RAM(Testua_LCD_7,0);
                  BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], azel_Y);
                  break;
              case 2:
                  Kopiatu_FLASH_RAM(Testua_LCD_8,0);
                  BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], azel_Z);
                  break;
              case 3:
                  Kopiatu_FLASH_RAM(Testua_LCD_3,0);
                  BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], gyro_X);
                  break;
              case 4:
                  Kopiatu_FLASH_RAM(Testua_LCD_4,0);
                  BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], gyro_Y);
                  break;
              case 5:
                  Kopiatu_FLASH_RAM(Testua_LCD_5,0);
                  BiByteLCD(&Leihoa_LCD[1][4], &Leihoa_LCD[1][5], &Leihoa_LCD[1][6], &Leihoa_LCD[1][7], &Leihoa_LCD[1][8], gyro_Z);
                  break;
          }
          ms_kop = 0;
          
      
        
}*/
  }  
}		


