#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

void limparBuffer();
Data lerDataValida(); 
void gatoPiscando();
#endif