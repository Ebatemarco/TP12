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
#include "hardware.h" 
#include "termlib.h"

int switchcase (char bit, char puerto);
//cambia el estado del bit al opuesto

int tecla (char caracter, const char* arr); 

int main(int argc, char** argv) 
{
    changemode (BUFFERED_OFF);
    char pines[8]={17,4,18,23,24,25,22,27};
    int error;
    char c; 
    char* pinesvalue[]={"/sys/class/gpio/gpio17/value","/sys/class/gpio/gpio4/value",
                        "/sys/class/gpio/gpio18/value","/sys/class/gpio/gpio23/value",
                        "/sys/class/gpio/gpio24/value","/sys/class/gpio/gpio25/value",
                        "/sys/class/gpio/gpio22/value","/sys/class/gpio/gpio27/value"};
    
    char* pinesdirection[]={"/sys/class/gpio/gpio17/direction","/sys/class/gpio/gpio4/direction",
                        "/sys/class/gpio/gpio18/direction","/sys/class/gpio/gpio23/direction",
                        "/sys/class/gpio/gpio24/direction","/sys/class/gpio/gpio25/direction",
                        "/sys/class/gpio/gpio22/direction","/sys/class/gpio/gpio27/direction"};
    int pinactual;
    
    //inicializacion de pins
    
    ExportPin("17");
    ExportPin("4");
    ExportPin("18");
    ExportPin("23");
    ExportPin("24");
    ExportPin("25");
    ExportPin("22");
    ExportPin("27");
    
    for (int i=0; i<8; i++)
    {
        DirectionOutPin(pinesdirection[i]);
    }
            
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
       
             tecla (0,pinesvalue[0]);
             break;
        case '1': //prendo el bit 0
       
             tecla (1,pinesvalue[1]);
             break;
        case '2': //prendo el bit 0
       
             tecla (2,pinesvalue[2]);
             break;   
        case '3': //prendo el bit 0
       
             tecla (3,pinesvalue[3]);
             break; 
        case '4': //prendo el bit 0
       
             tecla (4,pinesvalue[4]);
             break;
        case '5': //prendo el bit 0
       
             tecla (5,pinesvalue[5]);
             break;
        case '6': //prendo el bit 0
       
             tecla (6,pinesvalue[6]);
             break; 
        case '7': //prendo el bit 0
       
             tecla (7,pinesvalue[7]);
             break;
         default: break;     
     }
     if(error==-1)
     {
        printf("FATAL ERROR ABORT RUN");
     }
         
    }
    changemode (BUFFERED_ON); 
    return (EXIT_SUCCESS); 
}

int switchcase (char bit , char puerto)
{
     if (bitGet(puerto, bit))
        bitClr (puerto, bit); //lo apago
     else 
        bitSet (puerto, bit); //lo prendo
}

int tecla (char caracter, const char* arr)
{
    int error;
      switchcase (caracter, PORTA);
              if(bitGet(PORTA, caracter)==1)
                    {
                        led_state (PORTA);
                        error = ValuePinLow(arr); 
                    }
              else if(bitGet(PORTA, caracter)==0)
                    {
                        led_state (PORTA);
                       error = ValuePinUp(arr);
                    }
                    else
                    {
                        led_state (PORTA);
                    }
      return error;
}
