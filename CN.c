/*
 Azalpena: CN = Change Notification sarrerak tratatzeko

 1) CN sarreren konfigurazioa, tentsio-aldaketak detektatu ahal izateko
    (pultsadoreak sakatzean, alegia). Horretarako, etenak gaitu behar dira.

 2) CN sarreren zerbitzu-errutina.
        Kasu honetan, S6 (RD7) pultsadorearen tratamendua:
            S6 sakatzean, D7 LEDaren egoera kommutatu behar da:
                                    piztuta baldin bazegoen, itzali,
                          eta itzalita baldin bazegoen, piztu.

Egileak:
Data:
 */

#include "p24HJ256GP610A.h"
#include "timer_denbora.h"
#include "commons.h"


extern unsigned int ms_kop;
unsigned int egoera;

// 1) Konfigurazioa:
//==================

void konfiguratu_CN() {
    //etenen bidez tratatu nahi ditugun pultsadoreen etenak gaitu:
    //gogoan izan: CNEN1 erregistroan CN0 - CN15 sarrerak, CN0IE - CN15IE bitetan
    //gogoan izan: CNEN2 erregistroan CN16 - CN23 sarrerak, CN16IE - CN23IE bitetan

    // S6  pultsadorearen etenen konfig.
    _CN16IE = 1;
   
    // Ezabatu etenen adierazleak
    _CNIF = 0;
    _CNIE = 1;
}


//2) Erlojuaren etenaren zerbitzu-errutina:
//==============================


void _ISR __attribute__((no_auto_psv)) _CNInterrupt() {
    
    if (!_RD7){
        
        egoera++;
        if (egoera==6) egoera=0;
    }
    

    
    _CNIF = 0;
    
   
}