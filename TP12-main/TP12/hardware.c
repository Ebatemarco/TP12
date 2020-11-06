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

int DirectionOutPin(char pin)
{
    FILE * handle_direction;
    int nWritten;
    switch(pin)
    {        
        case 27:
            if((handle_direction= fopen("/sys/class/gpio/gpio27/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(1);
            }// Set pin Direction
            break;
        case 22:
            if((handle_direction= fopen("/sys/class/gpio/gpio22/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(1);
            }// Set pin Direction
            break;
        case 25:
            if((handle_direction= fopen("/sys/class/gpio/gpio25/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(1);
            }// Set pin Direction
            break;
        case 24:
            if((handle_direction= fopen("/sys/class/gpio/gpio24/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(1);
            }// Set pin Direction
            break;
        case 23:
            if((handle_direction= fopen("/sys/class/gpio/gpio23/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(1);
            }// Set pin Direction
            break;
        case 18:
            if((handle_direction= fopen("/sys/class/gpio/gpio18/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(1);
            }// Set pin Direction
            break;
        case 4:
            if((handle_direction= fopen("/sys/class/gpio/gpio4/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(-1);
            }// Set pin Direction
            break;
        case 17:
            if((handle_direction= fopen("/sys/class/gpio/gpio17/direction","w")) == NULL)
            {
                printf("Cannot open DIRECTION File");
                exit(-1);
            }// Set pin Direction
            break;
        default:
            printf("Cannot find DIRECTION File");
            exit(-1);
            break;    
    }    
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

int ValuePinLow(char* pin)
{
    FILE * handle;
    int nWritten;
    
    if ((handle = fopen(pin,"w")) == NULL)
    {
        printf("Cannot open device. Try again later.\n");
        exit(-1);
    }
    else
    {
        printf("Device successfully opened\n");
    }
    if(fputc('0' ,handle)==-1) // Set pin low
    {
        printf("Clr_Pin: Cannot write to file. Try again later.\n");
        exit(-1);
    }
    else
        printf("Write to file %s successfully done.\n",pin);
    fclose(handle);
}

int ValuePinUp(char* pin)
{
    FILE * handle;
    int nWritten;
    
    if ((handle = fopen(pin,"w")) == NULL)
    {
        printf("Cannot open device. Try again later.\n");
        exit(-1);
    }
    else
    {
        printf("Device successfully opened\n");
    }
    if(fputc('1' ,handle)==-1) // Set pin up
    {
        printf("Clr_Pin: Cannot write to file. Try again later.\n");
        exit(-1);
    }
    else
        printf("Write to file %s successfully done.\n",pin);
    fclose(handle);
}

