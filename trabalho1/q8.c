#include <stdio.h>
#include "trabalho1.h"

void mostrarTabuleiro(char tabuleiro[3][3])
{
    printf("\n");
    printf("    1   2   3\n");

    printf("A   %c | %c | %c\n",
           tabuleiro[0][0],
           tabuleiro[0][1],
           tabuleiro[0][2]);

    printf("   ---|---|---\n");

    printf("B   %c | %c | %c\n",
           tabuleiro[1][0],
           tabuleiro[1][1],
           tabuleiro[1][2]);

    printf("   ---|---|---\n");

    printf("C   %c | %c | %c\n",
           tabuleiro[2][0],
           tabuleiro[2][1],
           tabuleiro[2][2]);

    printf("\n");
}

int verificarVencedor(char tabuleiro[3][3], char simbolo)
{
    int i;

    for(i = 0; i < 3; i++){
        if(tabuleiro[i][0] == simbolo &&
           tabuleiro[i][1] == simbolo &&
           tabuleiro[i][2] == simbolo){

            return 1;
        }
    }

    for(i = 0; i < 3; i++){
        if(tabuleiro[0][i] == simbolo &&
           tabuleiro[1][i] == simbolo &&
           tabuleiro[2][i] == simbolo){

            return 1;
        }
    }

    if(tabuleiro[0][0] == simbolo &&
       tabuleiro[1][1] == simbolo &&
       tabuleiro[2][2] == simbolo){

        return 1;
    }

    if(tabuleiro[0][2] == simbolo &&
       tabuleiro[1][1] == simbolo &&
       tabuleiro[2][0] == simbolo){

        return 1;
    }

    return 0;
}

void jogoDaVelha()
{
    char tabuleiro[3][3];

    int i;
    int j;

    char jogadorAtual = 'X';

    char linha;
    int coluna;

    int linhaIndice;
    int colunaIndice;

    int jogadas = 0;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }

    while(1){

        mostrarTabuleiro(tabuleiro);

        if(jogadorAtual == 'X'){
            printf("Jogador 1 (X), informe sua jogada: ");
        }else{
            printf("Jogador 2 (O), informe sua jogada: ");
        }

        scanf(" %c%d", &linha, &coluna);

        if(linha == 'A' || linha == 'a'){
            linhaIndice = 0;
        }else if(linha == 'B' || linha == 'b'){
            linhaIndice = 1;
        }else if(linha == 'C' || linha == 'c'){
            linhaIndice = 2;
        }else{
            printf("Jogada invalida!\n");
            continue;
        }

        colunaIndice = coluna - 1;

        if(colunaIndice < 0 || colunaIndice > 2){
            printf("Jogada invalida!\n");
            continue;
        }

        if(tabuleiro[linhaIndice][colunaIndice] != ' '){
            printf("Posicao ocupada!\n");
            continue;
        }

        tabuleiro[linhaIndice][colunaIndice] = jogadorAtual;

        jogadas++;

        if(verificarVencedor(tabuleiro, jogadorAtual)){

            mostrarTabuleiro(tabuleiro);

            if(jogadorAtual == 'X'){
                printf("Jogador 1 venceu!\n");
            }else{
                printf("Jogador 2 venceu!\n");
            }

            break;
        }

        if(jogadas == 9){

            mostrarTabuleiro(tabuleiro);

            printf("Empate!\n");

            break;
        }

        if(jogadorAtual == 'X'){
            jogadorAtual = 'O';
        }else{
            jogadorAtual = 'X';
        }
    }
}