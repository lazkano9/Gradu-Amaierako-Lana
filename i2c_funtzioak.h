// I2C Funtzioen prototipoak
void InitI2C_1();
unsigned int LDByteReadI2C_1(unsigned char, unsigned int, unsigned char*, int);
unsigned int LDByteWriteI2C_1(unsigned char, unsigned char, unsigned char);
void I2C_Idatzi(unsigned char helbidea, unsigned char erregistroa, unsigned char datua);
void I2C_etena_gaitu();
void I2C_Eten_Irakurri(unsigned char helbidea, unsigned char erregistroa);
void I2C_Eten_Idatzi(unsigned char helbidea, unsigned char erregistroa, unsigned char konf);

