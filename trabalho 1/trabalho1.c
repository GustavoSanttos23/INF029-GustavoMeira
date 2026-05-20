// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h"
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
 # *# função utilizada para testes  ##

 somar = somar dois valores
 @objetivo
 Somar dois valores x e y e retonar o resultado da soma
 @entrada
 dois inteiros x e y
 @saida
 resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
 # *# função utilizada para testes  ##

 fatorial = fatorial de um número
 @objetivo
 calcular o fatorial de um número
 @entrada
 um inteiro x
 @saida
 fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int i, fat = 1;

    for (i = x; i > 1; i--)
        fat = fat * i;

    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

int q1(char data[])
{
    DataQuebrada dq;
    int anoBissexto = 0;
    int diasNoMes;

    dq = quebraData(data);

    if (dq.valido == 0){
        return 0;
    }

    if (dq.iMes < 1 || dq.iMes > 12){
        return 0;
    }

    if (dq.iDia < 1){
        return 0;
    }

    if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || (dq.iAno % 400 == 0)){
        anoBissexto = 1;
    }

    if (dq.iMes == 1 || dq.iMes == 3 || dq.iMes == 5 ||
        dq.iMes == 7 || dq.iMes == 8 || dq.iMes == 10 ||
        dq.iMes == 12){

        diasNoMes = 31;

    }else if (dq.iMes == 4 || dq.iMes == 6 ||
              dq.iMes == 9 || dq.iMes == 11){

        diasNoMes = 30;

    }else{

        // fevereiro
        if (anoBissexto == 1){
            diasNoMes = 29;
        }else{
            diasNoMes = 28;
        }
    }

    if (dq.iDia > diasNoMes){
        return 0;
    }

    return 1;
}



DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma;

    DataQuebrada dataInicial;
    DataQuebrada dataFinal;

    int diasMes;

    dataInicial = quebraData(datainicial);
    dataFinal = quebraData(datafinal);

    if (q1(datainicial) == 0){
        dma.retorno = 2;
        return dma;
    }

    if (q1(datafinal) == 0){
        dma.retorno = 3;
        return dma;
    }

    if (dataInicial.iAno > dataFinal.iAno ||
       (dataInicial.iAno == dataFinal.iAno &&
        dataInicial.iMes > dataFinal.iMes) ||
       (dataInicial.iAno == dataFinal.iAno &&
        dataInicial.iMes == dataFinal.iMes &&
        dataInicial.iDia > dataFinal.iDia)){

        dma.retorno = 4;
        return dma;
    }

    dma.qtdDias = dataFinal.iDia;
    dma.qtdMeses = dataFinal.iMes;
    dma.qtdAnos = dataFinal.iAno;

    if (dma.qtdDias < dataInicial.iDia){

        dma.qtdMeses--;

        if (dataFinal.iMes == 1 || dataFinal.iMes == 3 ||
            dataFinal.iMes == 5 || dataFinal.iMes == 7 ||
            dataFinal.iMes == 8 || dataFinal.iMes == 10 ||
            dataFinal.iMes == 12){

            diasMes = 31;

        }else if (dataFinal.iMes == 4 || dataFinal.iMes == 6 ||
                  dataFinal.iMes == 9 || dataFinal.iMes == 11){

            diasMes = 30;

        }else{

            if ((dataFinal.iAno % 4 == 0 && dataFinal.iAno % 100 != 0) ||
                (dataFinal.iAno % 400 == 0)){

                diasMes = 29;

            }else{

                diasMes = 28;
            }
        }

        dma.qtdDias = dma.qtdDias + diasMes - dataInicial.iDia;

    }else{

        dma.qtdDias = dma.qtdDias - dataInicial.iDia;
    }

    if (dma.qtdMeses < dataInicial.iMes){

        dma.qtdAnos--;

        dma.qtdMeses = dma.qtdMeses + 12 - dataInicial.iMes;

    }else{

        dma.qtdMeses = dma.qtdMeses - dataInicial.iMes;
    }

    dma.qtdAnos = dma.qtdAnos - dataInicial.iAno;

    dma.retorno = 1;

    return dma;
}

int q3(char *texto, char c, int isCaseSensitive)
{
    int i;
    int qtdOcorrencias = 0;
    char caractereTexto;
    char caractereBusca;

    for(i = 0; texto[i] != '\0'; i++){

        caractereTexto = texto[i];
        caractereBusca = c;

        if(isCaseSensitive != 1){

            if(caractereTexto >= 'A' && caractereTexto <= 'Z'){
                caractereTexto = caractereTexto + 32;
            }

            if(caractereBusca >= 'A' && caractereBusca <= 'Z'){
                caractereBusca = caractereBusca + 32;
            }
        }

        if(caractereTexto == caractereBusca){
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int i, j;
    int encontrou;
    int qtdOcorrencias = 0;
    int tamanhoBusca = 0;

    while(strBusca[tamanhoBusca] != '\0'){
        tamanhoBusca++;
    }

    for(i = 0; strTexto[i] != '\0'; i++){

        encontrou = 1;

        for(j = 0; j < tamanhoBusca; j++){

            if(strTexto[i + j] != strBusca[j]){
                encontrou = 0;
                break;
            }
        }

        if(encontrou == 1){

            posicoes[qtdOcorrencias * 2] = i + 1;

            posicoes[(qtdOcorrencias * 2) + 1] = i + tamanhoBusca;

            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

int q5(int num)
{
    int numeroInvertido = 0;
    int ultimoDigito;

    while(num > 0){

        ultimoDigito = num % 10;

        numeroInvertido = (numeroInvertido * 10) + ultimoDigito;

        num = num / 10;
    }

    return numeroInvertido;
}

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;

    int baseTemp = numerobase;
    int buscaTemp = numerobusca;

    int tamanhoBusca = 0;
    int divisor = 1;

    while(buscaTemp > 0){
        tamanhoBusca++;
        buscaTemp = buscaTemp / 10;
    }

    for(int i = 0; i < tamanhoBusca; i++){
        divisor = divisor * 10;
    }

    while(baseTemp > 0){

        if(baseTemp % divisor == numerobusca){
            qtdOcorrencias++;
        }

        baseTemp = baseTemp / 10;
    }

    return qtdOcorrencias;
}

int q7(char matriz[8][10], char palavra[5])
{
    int i, j, k;

    int direcaoLinha[8] = {-1,-1,-1,0,0,1,1,1};
    int direcaoColuna[8] = {-1,0,1,-1,1,-1,0,1};

    int novaLinha;
    int novaColuna;

    int encontrou;

    // percorre toda matriz
    for(i = 0; i < 8; i++){

        for(j = 0; j < 10; j++){

            // verifica todas as direções
            for(int d = 0; d < 8; d++){

                encontrou = 1;

                // verifica letra por letra
                for(k = 0; palavra[k] != '\0'; k++){

                    novaLinha = i + (direcaoLinha[d] * k);
                    novaColuna = j + (direcaoColuna[d] * k);

                    // verifica limites da matriz
                    if(novaLinha < 0 || novaLinha >= 8 ||
                       novaColuna < 0 || novaColuna >= 10){

                        encontrou = 0;
                        break;
                    }

                    // compara caractere
                    if(matriz[novaLinha][novaColuna] != palavra[k]){

                        encontrou = 0;
                        break;
                    }
                }

                // se encontrou a palavra
                if(encontrou == 1){
                    return 1;
                }
            }
        }
    }

    return 0;
}

DataQuebrada quebraData(char data[]){
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;

    for (i = 0; data[i] != '/'; i++){
        sDia[i] = data[i];
    }
    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
        sDia[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
        return dq;
    }


    int j = i + 1; //anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++){
        sMes[i] = data[j];
        i++;
    }

    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
        sMes[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
        return dq;
    }


    j = j + 1; //anda 1 cada para pular a barra
    i = 0;

    for(; data[j] != '\0'; j++){
        sAno[i] = data[j];
        i++;
    }

    if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
        sAno[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

    dq.valido = 1;

    return dq;
}
