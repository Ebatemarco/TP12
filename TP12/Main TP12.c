/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main TP12.c
 * Author: ebatemarco
 *
 * Created on 6 de noviembre de 2020, 15:39
 */

#include <stdio.h>
#include <stdlib.h>
#include "emuladordepuertos.h"

int switchcase (char bit, char puerto);
//cambia el estado del bit al opuesto


int main(int argc, char** argv) 
{
    char pines[8]={17,4,18,23,24,25,22,27};
    int error;
    char c; 
    char* pinesvalue[]={"/sys/class/gpio/gpio17/value","/sys/class/gpio/gpio4/value",
                        "/sys/class/gpio/gpio18/value","/sys/class/gpio/gpio23/value",
                        "/sys/class/gpio/gpio24/value","/sys/class/gpio/gpio25/value",
                        "/sys/class/gpio/gpio22/value","/sys/class/gpio/gpio27/value"};
    int pinactual;
    while (((c=getchar())!='q')||(error==-1)) 
    {
     switch (c) //me fijo que ingreso el usuario
     {
         case 't': //cambio los bits al estado opuesto
             maskToggle(PORTA, 0xFF); 
             led_state (PORTA);
             for(pinactual=7; pinactual>=0;pinactual--)//Vemos cada bit
                    {
                        switch(bitGet(PORTA, pinactual))//En base a el estado del bit
                        {        
                            case 0: //Si esta apagado lo encendemos
                                error = ValuePinLow(pinesvalue[pinactual]);
                                break;
                            case 1://Si esta encendido lo apagamos
                                error = ValuePinUp(pinesvalue[pinactual]);
                                break;
                            default: break;        
                        }   
                    }
             break;
         case 'c': //apago todos los bits
             maskOff (PORTA, 0xFF);
             led_state (PORTA);
             for(pinactual=7; pinactual>=0;pinactual--)//Apagamos todo
             {
                error = ValuePinLow(pinesvalue[pinactual]);
             } 
             break;
         case 's': //prendo todos los bits
             maskOn (PORTA, 0xFF);
             led_state (PORTA);
             for(pinactual=7; pinactual>=0;pinactual--)//Apagamos todo
             {
                error = ValuePinUp(pinesvalue[pinactual]);
             } 
             break;
         case '0': //prendo el bit 0
             switchcase (0, PORTA);
             led_state (PORTA);
             
             break;
         case '1': //prendo el bit 1
            switchcase (1, PORTA);
             led_state (PORTA);
             break;
         case '2': 
             switchcase (2, PORTA);
             led_state (PORTA);
             break;
         case '3': 
             switchcase (3, PORTA);
             led_state (PORTA);
             break;
         case '4':
             switchcase (4, PORTA);
             led_state (PORTA);
             break;
         case '5': 
             switchcase (5,PORTA);
             led_state (PORTA);
             break;
         case '6': 
             switchcase (6, PORTA);
             led_state (PORTA);
             break;
         case '7':
             switchcase (7, PORTA);
             led_state (PORTA);
             break;
         default: break;
     }
     if(error==-1)
     {
        printf("FATAL ERROR ABORT RUN");
     }
         
    }
    return (EXIT_SUCCESS); 
}

int switchcase (char bit , char puerto)
{
     if (bitGet(puerto, bit))
        bitClr (puerto, bit); //lo apago
     else 
        bitSet (puerto, bit); //lo prendo
}

