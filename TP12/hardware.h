/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hardware.h
 * Author: ebatemarco
 *
 * Created on 6 de noviembre de 2020, 15:41
 */

int ExportPin(char* pin);

int DirectionOutPin(const char* pin);

int ValuePinLow(const char* pin);

int ValuePinUp(const char* pin);

int UnExportPin(char* pin);