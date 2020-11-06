/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include "hardware.h"


int ExportPin(char* pin)
{
    FILE *handle_export;
    int nWritten;
    if((handle_export=  fopen("/sys/class/gpio/export","w")) == NULL)
    {
        printf("Cannot open EXPORT File. Try again later.\n");
        exit(1);
    }
    nWritten=fputs(pin,handle_export);
    if(nWritten==-1)
    {
        printf("Cannot EXPORT PIN . Try again later.\n");
        exit(1);
    }
    else
        printf("EXPORT File opened succesfully\n");
    fclose(handle_export);  // Be carefulldo this for EACH pin !!!
}

int DirectionOutPin(const char* pin)
{
    FILE * handle_direction;
    int nWritten;
    if(pin==NULL)
    {
        printf("Invalid pointer");
        exit(1);
    }
    handle_direction= fopen(pin,"w");
    if(handle_direction== NULL)
    {
        printf("Cannot open DIRECTION File");
        exit(1);
    }// Set pin Direction
    
                
        
    if ((nWritten=fputs("out",handle_direction))==-1)
    {
        printf("Cannot open DIRECTION pin. Try again later.\n");
        exit(-1);
    }
    else
    {
        printf("DIRECTION File for PIN opened succesfully\n");
    }
    fclose(handle_direction); // Be carefulldo this for EACH pin !!!
}

int ValuePinLow(const char* pin)
{
    FILE * handle;
    int fputstatus=0;
    int nWritten;
    handle = fopen(pin,"w");
    if ( handle == NULL)
    {
        printf("Cannot open device. Try again later.\n");
        exit(-1);
    }
    else
    {
        printf("Device successfully opened\n");
    }
    fputstatus=fputc('0' ,handle);
    if(fputstatus==-1) // Set pin low
    {
        printf("Clr_Pin: Cannot write to file. Try again later.\n");
        exit(-1);
    }
    else
        printf("Write to file %s successfully done.\n",pin);
    fclose(handle);
}

int ValuePinUp(const char* pin)
{
    FILE * handle;
    int fputstatus=0;
    int nWritten;
    
    handle = fopen(pin,"w");
    if ( handle == NULL)
    {
        printf("Cannot open device. Try again later.\n");
        exit(-1);
    }
    else
    {
        printf("Device successfully opened\n");
    }
    fputstatus=fputc('1' ,handle);
    if(fputstatus==-1) // Set pin up
    {
        printf("Clr_Pin: Cannot write to file. Try again later.\n");
        exit(-1);
    }
    else
        printf("Write to file %s successfully done.\n",pin);
    fclose(handle);
}

