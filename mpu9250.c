
#include "i2c_funtzioak.h"
#include "kalk_bihurketak.h"
#include <p24HJ256GP610A.h>
#include "commons.h"

//Sentsorearen helbidea AD0 (9. pina) ikututa hau aldatzeko aukera dago
#define MPU9250_HELB 0xd0

#define GYRO_FS_SEL_250  0x00
#define GYRO_FS_SEL_500  0x08
#define GYRO_FS_SEL_1000 0x10
#define GYRO_FS_SEL_2000 0x18

#define ACCEL_FS_SEL_2g  0x00
#define ACCEL_FS_SEL_4g  0x08
#define ACCEL_FS_SEL_8g  0x10
#define ACCEL_FS_SEL_16g 0x18

#define GYRO_KONF_ERREG 0x1B
#define ACEL_KONF_ERREG 0x1C

#define GYRO_X 0x3B
#define GYRO_Y 0x3D
#define GYRO_Z 0x3F

#define AZEL_X 0x43
#define AZEL_Y 0x45
#define AZEL_Z 0x47


void konfigurazioa_MPU (){
    //Giroskopioa konfiguratu
    LDByteWriteI2C_1(MPU9250_HELB, GYRO_KONF_ERREG, 0x10);
    
    //Azelerometroa konfiguratu
    LDByteWriteI2C_1(MPU9250_HELB, ACEL_KONF_ERREG, 0x10);
}

void irakurriBalioak(unsigned char *aldagaia){
    unsigned char p[2];
    LDByteReadI2C_1(MPU9250_HELB, 0x3B, p, 2);
    aldagaia[0]=p[0];
    aldagaia[1]=p[1];
    LDByteReadI2C_1(MPU9250_HELB, 0x3D, p, 2);  
    aldagaia[2]=p[0];
    aldagaia[3]=p[1];
    LDByteReadI2C_1(MPU9250_HELB, 0x3F, p, 2);   
    aldagaia[4]=p[0];
    aldagaia[5]=p[1];
    LDByteReadI2C_1(MPU9250_HELB, 0x43, p, 2);
    aldagaia[6]=p[0];
    aldagaia[7]=p[1];
    LDByteReadI2C_1(MPU9250_HELB, 0x45, p, 2);
    aldagaia[8]=p[0];
    aldagaia[9]=p[1];
    LDByteReadI2C_1(MPU9250_HELB, 0x47, p, 2);
    aldagaia[10]=p[0];
    aldagaia[11]=p[1];    
}

