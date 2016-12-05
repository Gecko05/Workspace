#include <16F877A.h>
#device ADC=10
#USE standard_io (B)

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES XT                       //Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT    
#use delay(crystal=4MHz)
//#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

#define espera 300     // Constante para delay espera
#define pinLed PIN_B0  // Sirve para activar un LED, RELE....
#define CONTROL 800    // Constante para ajustar seg�n la iluminaci�n de la habitaci�n
                       // con iluminaci�n de la lampara Vout medido es de 4voltios (+/-)
                       // 4V corresponden con binSensor = 818
                       
void main(){
   setup_adc_ports(AN0);            //  Configuramos RA0 como pin Anal�gico
   setup_adc(ADC_CLOCK_INTERNAL);   // Reloj R-C

}
