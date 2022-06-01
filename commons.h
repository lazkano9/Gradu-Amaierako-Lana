#define Nop() __builtin_nop()

extern unsigned char byte_helb, byte_erreg, byte_idaztekoa;
extern unsigned int idatzi;         //eten bakoitzean idatzi edo iraurri egingo den kontrolatuko duen aldagaia.

extern unsigned int I2C_Libre;

 //LCD-ko scrolla egiteko.
extern  unsigned int egoera;

//LCD-an idazteko testuak
extern const unsigned char Testua_LCD_1[16],Testua_LCD_2[16],Testua_LCD_3[16],Testua_LCD_4[16],Testua_LCD_5[16],Testua_LCD_6[16],Testua_LCD_7[16],Testua_LCD_8[16],Testua_LCD_9[16];
//LCD-ko espazioa
extern unsigned char Leihoa_LCD[2][16];

//Milisegundoro eteten dues timerraren kontagailua
extern unsigned int ms_kop;

extern unsigned char aldagaia[14]; 