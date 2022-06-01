/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;   Programa egokitua: i2c_Func.c  ;February 21, 2007   ;Martin Bowman                                                            
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;	Filename:			    i2c_funtzioak.c            
;	Date:				    2022 Martxoa          
;	File Version:		  	1.1                             
;	Assembled using:		MPLAB IDE 8.83.00.0               
; 	Author:		  	    	Julen Lazkano               		    
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <p24HJ256GP610A.h>
#include "commons.h"

#define PAGESIZE	32

#define Gailu_Helbidea  1
#define Erreg_Helbidea  2
#define Idazketa        3
#define Restart         4
#define Helbidea_Read   5
#define Tartekoa_1      6
#define Irakurketa      7
#define Stop            8
#define Azkena          9


unsigned char byte_helb, byte_erreg, byte_idaztekoa;
unsigned int idatzi, I2C_Libre;
unsigned char aldagaia[14];

/*******************************************************************
* Function: InitI2C_1()
* Overview:	Initializes the I2C(1) peripheral
* Note:     Sets up Master mode, No slew rate control, 400 kHz
* This function will initialize the I2C(1) peripheral.
********************************************************************/
void InitI2C_1()
{	
  //I2CBRG=(Fcy/Fscl)-(Fcy/10000000)-1	--> Fscl Frec clock I2C
  I2C1BRG = 95; 	//400 kHz & Fcy= 40 MHz --> Period = 2,5 us
  //I2C1BRG = 195; 	//200 kHz & Fcy= 40 MHz --> Period = 5 us
    
  //I2C1BRG = 395; 	// 100 kHz & Fcy= 40 MHz //First set the I2C(1) BRG Baud Rate
  I2C1CON = 0x1000;	// Hasieratu nagusi moduan, No Slew Rate, I2C desaktibatuta
  I2C1RCV = 0x0000;	// Datuak jasotzeko erregistroa (hartzaile)
  I2C1TRN = 0x0000;	// Datuak igortzeko erregistroa (igorle)
  I2C1CONbits.I2CEN = 1;	//gaitu I2C 
}

void I2C_etena_gaitu(){
    _MI2C1IE=1;     //Etena gaitu
    _MI2C1IF=0;     //Flaga desaktibatu
}

//Start seinalea sortu
void I2C_Eten_Irakurri(unsigned char helbidea, unsigned char erregistroa){
    byte_helb = helbidea;
    byte_erreg = erregistroa;
    idatzi = 0;
    I2C_Libre = 0;
    I2C1CONbits.SEN = 1;
}
void I2C_Eten_Idatzi(unsigned char helbidea, unsigned char erregistroa, unsigned char konf){
    byte_helb = helbidea;
    byte_erreg = erregistroa;
    byte_idaztekoa = konf;
    idatzi = 1;
    I2C_Libre = 0;
    I2C1CONbits.SEN = 1;
}




void _ISR __attribute__((no_auto_psv)) _MI2C1Interrupt (){  
    static int egoera_eten=1;                   //Hemen 0 edo 1 ekin hasieratu behar det?¿?¿?¿?¿?¿?¿ 
    static int i=0;
            Nop();
            Nop();
            Nop();
            Nop();
        switch(egoera_eten){            
            case Gailu_Helbidea:                //Morroiaren HELBIDEA IDATZI
                I2C1TRN = byte_helb;            //TRSTAT eta TBF erregistroak aztertzen dira inkesta bidez egitean
                egoera_eten=Erreg_Helbidea;     //TBF bufferreko idazketa bukatzean desaktibatu
                break;                          //TRSTAT morroiak ACK bidaltzean desaktibatu. Ondoren hurrengo etena 
                
            case Erreg_Helbidea:
                I2C1TRN = byte_erreg;           //ERREGISTROAREN HELBIDEA IDATZI               
                egoera_eten = Idazketa;
                if (!idatzi) egoera_eten = Restart;
                break;
                
            case Idazketa:                      //ERREGISTROAN IDATZI
                I2C1TRN = 0x10;
                egoera_eten=Stop;
                break;
                
            case Restart:                       //RESTART seinalea bidali
                I2C1CONbits.RSEN = 1;
                egoera_eten=Helbidea_Read;
                break;
                              
            case Helbidea_Read:                 //Helbidea + read bita aktibatu
                I2C1TRN = byte_helb | 0x01;
                egoera_eten=Tartekoa_1;
                break;  
               
            case Tartekoa_1:                    //Helbidea transmititzean eten egingo du baina ez dugu ezer egin behar
                egoera_eten=Irakurketa;         //Ondoren morroiak datua bidaltzean berriro eten eta datua gordeko da hurrengo egoeran
                I2C1CONbits.RCEN = 1;           //Enable Master receive
                break;
                
            case Irakurketa:
                //Wait for receive bufer to be full?¿?¿?¿?¿?¿?¿?¿ 
                aldagaia[i]=I2C1RCV;            //Lehen byte-a gorde
                i++;
                if (i==14){                      //Not_ACK 
                    egoera_eten = Stop;
                    I2C1CONbits.ACKDT = 1;
                    I2C1CONbits.ACKEN = 1;
                    i=0;
                } else {                        //ACK
                    egoera_eten =Tartekoa_1;      //Hau SOBRAN dago?
                    I2C1CONbits.ACKDT = 0;	
                    I2C1CONbits.ACKEN = 1;
                }
                break;
                                               
            case Stop:                          //STOP
                I2C1CONbits.PEN = 1;
                egoera_eten = Azkena;
                break;        
                
            case Azkena:
                I2C_Libre=1;
                egoera_eten = Gailu_Helbidea;
                break;                
        }   
        
    _MI2C1IF=0;
    _LATA2 = 1;
    _LATA3 = 1;
}

/*******************************************************************
* Function: StartI2C_1()
* Overview: Generates an I2C Start Condition
* This function generates an I2C start condition and returns status of the Start.
********************************************************************/
unsigned int StartI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.SEN = 1; //Generate Start Condition
  time_out= 0;
  //Wait for Start Condition
  while (I2C1CONbits.SEN && (time_out<1000))	time_out++;
  if(time_out>=1000) return 1;
  return 0;
  //return(I2C1STATbits.S);	//Optionally return status
}

/*******************************************************************
* Function: RestartI2C_1()
* Overview: Generates a restart condition and optionally returns status
* This function generates an I2C Restart condition and returns status of the Restart.
********************************************************************/
unsigned int RestartI2C_1()
{
 unsigned int time_out;
 I2C1CONbits.RSEN = 1; //Generate Restart
 time_out= 0;
 //Wait for restart
 while (I2C1CONbits.RSEN && (time_out<1000))time_out++;
 if(time_out>=1000) return 2;
 return 0;
 //return(I2C1STATbits.S);	//Optional - return status
}

/*******************************************************************
* Function: StopI2C_1()
* Overview:	Generates a bus stop condition
* This function generates an I2C stop condition and returns status of the Stop.
********************************************************************/
unsigned int StopI2C_1()
{
 unsigned int time_out;
 I2C1CONbits.PEN = 1; //Generate Stop Condition
 time_out= 0;
 //Wait for Stop
 while (I2C1CONbits.PEN && (time_out<1000)) time_out++;
 if(time_out>=1000) return 3;
 return 0;
 //return(I2C1STATbits.P);	//Optional - return status
}

/*********************************************************************
* Function: IdleI2C_1()
* Overview: Waits for bus to become Idle
********************************************************************/
unsigned int IdleI2C_1()
{
  unsigned int time_out;
  time_out= 0;
  //Wait for bus Idle
  while (I2C1STATbits.TRSTAT && (time_out<1000)) time_out++;
  if(time_out>=1000) return 5;
  return 0;
}

/*******************************************************************
* Function:     WriteI2C_1()
* Input:		Byte to write
* Overview:		Writes a byte out to the bus
* This function transmits the byte passed to the function
********************************************************************/
unsigned int WriteI2C_1(unsigned char byte)
{
 unsigned int time_out;
 time_out= 0;
 //Wait for bus to be idle
 while (I2C1STATbits.TRSTAT && (time_out<1000))	time_out++;
 if(time_out>=1000) return 4;
 
 I2C1TRN = byte; //Load byte to I2C1 Transmit buffer
 time_out= 0;
 //wait for data transmission
 while (I2C1STATbits.TBF && (time_out<1000)) time_out++;
 if(time_out>=1000) return 4;
 return 0;
}

/*******************************************************************
* Function: ACKStatus_1()
* Output:	Acknowledge Status
* Overview:	Return the Acknowledge status on the bus
********************************************************************/
unsigned int ACKStatus_1()
{
    return (!I2C1STATbits.ACKSTAT);		//Return Ack Status
}

/*******************************************************************
* Function: NotAckI2C_1()
* Overview:	Generates a NO Acknowledge on the Bus
********************************************************************/
unsigned int NotAckI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.ACKDT = 1; //Set for NotACk
  I2C1CONbits.ACKEN = 1;
  time_out= 0;
  //wait for ACK to complete
  while(I2C1CONbits.ACKEN && (time_out<1000)) time_out++;
  I2C1CONbits.ACKDT = 0;			//Set for NotACk
  if(time_out>=1000) return 7;
  return 0;
}

/*******************************************************************
* Function: AckI2C_1()
* Overview:	Generates an Acknowledge
********************************************************************/
unsigned int AckI2C_1()
{
 unsigned int time_out;
 I2C1CONbits.ACKDT = 0;	//Set for ACk
 I2C1CONbits.ACKEN = 1;
 time_out= 0;
 //wait for ACK to complete
 while(I2C1CONbits.ACKEN && (time_out<1000)) time_out++;
 if(time_out>=1000) return 9;
 return 0;
}

/*******************************************************************
* Function: getI2C_1()
* Output:   contents of I2C1 receive buffer
* Overview:	Read a single byte from Bus
********************************************************************/
unsigned int getI2C_1()
{
 int time_out;
 I2C1CONbits.RCEN = 1; //Enable Master receive
 time_out=0;
 //Wait for receive bufer to be full
 while(!I2C1STATbits.RBF & (time_out<1000)) time_out++;
 //if (time_out>=1000)	Error_I2C_1=9;
 return(I2C1RCV); //Return data in buffer
}

/*******************************************************************
* Function: getsI2C_1()
* Input:	array pointer, Length
* Overview:	read Length number of Bytes into array
********************************************************************/
unsigned int getsI2C_1(unsigned char *rdptr, unsigned char Length)
{
  unsigned int ErrorCode=0;
  while (Length --)
  {
    *rdptr++ = getI2C_1();		//get a single byte
    //if(I2C1STATbits.BCL) return(-1);	//Test for Bus collision
	if(I2C1STATbits.BCL) 
	{
		ErrorCode=8;		//Test for Bus collision
		I2C1STATbits.BCL= 0;
	}
	if(Length) AckI2C_1();		//Acknowledge until all read
  }
  return (ErrorCode);
}

/*******************************************************************
* Function: putstringI2C()_1
* Input:	pointer to array
* Overview:	writes a string of data upto PAGESIZE from array
********************************************************************/
unsigned int putstringI2C_1(unsigned char *wrptr)
{
 unsigned char x;
 for(x = 0; x < PAGESIZE; x++) //Transmit Data Until Pagesize
 {	
    //Write 1 byte
	if(WriteI2C_1(*wrptr)) return(-3); //Return with Write Collision
    IdleI2C_1();  //Wait for Idle bus
	if(I2C1STATbits.ACKSTAT) return(-2); //Bus responded with Not ACK
	wrptr++;
 }
 return(0);
}

/*******************************************************************
* Function: EEAckPolling()_1
* Input:	Control byte
* Output:	error state
* Overview:	polls the bus for an Acknowledge from device
********************************************************************/
unsigned int EEAckPolling_1(unsigned char control)
{
    IdleI2C_1();  //wait for bus Idle
    StartI2C_1(); //Generate Start condition
    if(I2C1STATbits.BCL) return(-1); //Bus collision, return
    else
    {
        if(WriteI2C_1(control)) return(-3);	//error return
        IdleI2C_1(); //wait for bus idle
        if(I2C1STATbits.BCL) return(-1);	//error return
        while(ACKStatus_1())
        {
            RestartI2C_1();	//generate restart
            if(I2C1STATbits.BCL) return(-1);	//error return
            if(WriteI2C_1(control)) return(-3);
            IdleI2C_1();
        }
    }
    StopI2C_1(); //send stop condition
    if(I2C1STATbits.BCL) return(-1);
    return(0);
}

/******************************************************************
* Function: LDByteReadI2C_1()
* Input:	Control Byte, Address, *Data, Length
* Overview:	Performs a low density read of Length bytes and stores in *Data array
*			starting at Address
********************************************************************/
unsigned int LDByteReadI2C_1(unsigned char ControlByte, unsigned char Address, unsigned char *Data, unsigned char Length)
{
    unsigned int ErrorCode=0;
    if (IdleI2C_1()) ErrorCode=5;
    if (StartI2C_1()) ErrorCode=1;
    if (WriteI2C_1(ControlByte)) ErrorCode=4;
    if (IdleI2C_1()) ErrorCode=5;
//	ErrorCode = ACKStatus_1();		//Return ACK Status
    if (WriteI2C_1(Address)) ErrorCode=4;
    if (IdleI2C_1()) ErrorCode=5;
//	ErrorCode = ACKStatus_1();		//Return ACK Status   
    if (RestartI2C_1()) ErrorCode=2;
    //if (StartI2C_1()) ErrorCode=2;
    //Restart egin ondoren berriro MPU9250ren helbidea idatziko dugu baina azken bita aktibatuz
    if (WriteI2C_1(ControlByte | 0x01)) ErrorCode=4;
    if (IdleI2C_1()) ErrorCode=5;
//	ErrorCode = ACKStatus_1();		//Return ACK Status
    if (getsI2C_1(Data, Length)) ErrorCode=9;
    if (NotAckI2C_1()) ErrorCode=7;
    if (StopI2C_1()) ErrorCode=3;
    return (ErrorCode);
}

/*******************************************************************
* Function: LDByteWriteI2C_1()
* Input:    Control Byte, 8 - bit address, data
* Overview:	Write a byte to low density device at address LowAdd
********************************************************************/
unsigned int LDByteWriteI2C_1(unsigned char ControlByte, unsigned char LowAdd, unsigned char data)
{
    int x;
  unsigned int ErrorCode=0;
  if (IdleI2C_1()) ErrorCode=5;
  if (StartI2C_1()) ErrorCode=1;
  if (WriteI2C_1(ControlByte)) ErrorCode=4;
   
  if (IdleI2C_1()) ErrorCode=5;
  x=I2C1STATbits.ACKSTAT;
  //ErrorCode = ACKStatus_1();		//Return ACK Status
  if (WriteI2C_1(LowAdd)) ErrorCode=4;
  if (IdleI2C_1()) ErrorCode=5;
  //ErrorCode = ACKStatus_1();		//Return ACK Status
  if (WriteI2C_1(data)) ErrorCode=4;
  if (IdleI2C_1()) ErrorCode=5;
  if (StopI2C_1()) ErrorCode=3;
  return (ErrorCode);
}


void I2C_Idatzi(unsigned char helbidea, unsigned char erregistroa, unsigned char datua){
    //Data Sheeteko 34 orria
    StartI2C_1();
    WriteI2C_1(helbidea);
    IdleI2C_1();
    WriteI2C_1(erregistroa);
    IdleI2C_1();
    WriteI2C_1(datua);
    IdleI2C_1();    
    StopI2C_1(); 
}


