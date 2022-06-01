//Sentsorearen helbidea AD0 (9. pina) ikututa hau aldatzeko aukera dago
#define MPU9250_HELB 0x68

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
// Funtzioen prototipoak

unsigned int Neurketa_berria_hasi(unsigned char sents);
unsigned int Irakurri_neurria (unsigned char sents, unsigned char *dis) ;
void Aldatu_helbidea (unsigned char sents, unsigned char sentsberr);
unsigned int Helbide_zehaztu (unsigned char *helbide);
void konfigurazioa_MPU();
void irakurriBalioak(unsigned char *gyro_Z);
