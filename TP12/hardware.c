/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>


int ExportBit(char* bit)
{
    FILE *handle_export;
    int nWritten;
    if((handle_export=  fopen("/sys/class/gpio/export","w")) == NULL)
    {
        printf("Cannot open EXPORT File. Try again later.\n");
        exit(1);
    }
    nWritten=fputs(bit,handle_export);
    if(nWritten==-1)
    {
        printf("Cannot EXPORT PIN . Try again later.\n");
        exit(1);
    }
    else
        printf("EXPORT File opened succesfully\n");
    fclose(handle_export);  // Be carefulldo this for EACH pin !!!
}