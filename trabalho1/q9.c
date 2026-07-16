#include <stdio.h>
#include "trabalho1.h"

#define TAM 10
#define QUANTIDADE_NAVIOS 5

void inicializarTabuleiro(char tabuleiro[TAM][TAM])
{
    int i;
    int j;

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrarTabuleiroJogador(char tabuleiro[TAM][TAM])
{
    int i;
    int j;

    printf("\n   ");

    for(i = 0; i < TAM; i++){
        printf("%d ", i);
    }

    printf("\n");

    for(i = 0; i < TAM; i++){

        printf("%d  ", i);

        for(j = 0; j < TAM; j++){

            printf("%c ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void mostrarTabuleiroAdversario(char tabuleiro[TAM][TAM])
{
    int i;
    int j;

    printf("\n   ");

    for(i = 0; i < TAM; i++){
        printf("%d ", i);
    }

    printf("\n");

    for(i = 0; i < TAM; i++){

        printf("%d  ", i);

        for(j = 0; j < TAM; j++){

            if(tabuleiro[i][j] == 'N'){
                printf("  ");
            }else{
                printf("%c ", tabuleiro[i][j]);
            }
        }

        printf("\n");
    }

    printf("\n");
}

int podePosicionar(char tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao)
{
    int i;

    if(direcao == 'H'){

        if(coluna + tamanho > TAM){
            return 0;
        }

        for(i = 0; i < tamanho; i++){

            if(tabuleiro[linha][coluna + i] != ' '){
                return 0;
            }
        }

    }else{

        if(linha + tamanho > TAM){
            return 0;
        }

        for(i = 0; i < tamanho; i++){

            if(tabuleiro[linha + i][coluna] != ' '){
                return 0;
            }
        }
    }

    return 1;
}

void posicionarNavio(char tabuleiro[TAM][TAM], int tamanho)
{
    int linha;
    int coluna;
    int i;

    char direcao;

    while(1){

        mostrarTabuleiroJogador(tabuleiro);

        printf("Posicione um navio de tamanho %d\n", tamanho);

        printf("Linha: ");
        scanf("%d", &linha);

        printf("Coluna: ");
        scanf("%d", &coluna);

        printf("Direcao (H/V): ");
        scanf(" %c", &direcao);

        if(direcao >= 'a' && direcao <= 'z'){
            direcao = direcao - 32;
        }

        if(linha < 0 || linha >= TAM ||
           coluna < 0 || coluna >= TAM){

            printf("Posicao invalida!\n");
            continue;
        }

        if(direcao != 'H' && direcao != 'V'){
            printf("Direcao invalida!\n");
            continue;
        }

        if(podePosicionar(tabuleiro, linha, coluna, tamanho, direcao)){

            if(direcao == 'H'){

                for(i = 0; i < tamanho; i++){
                    tabuleiro[linha][coluna + i] = 'N';
                }

            }else{

                for(i = 0; i < tamanho; i++){
                    tabuleiro[linha + i][coluna] = 'N';
                }
            }

            break;

        }else{

            printf("Nao pode posicionar aqui!\n");
        }
    }
}

void posicionarTodosNavios(char tabuleiro[TAM][TAM])
{
    posicionarNavio(tabuleiro, 4);
    posicionarNavio(tabuleiro, 3);

    posicionarNavio(tabuleiro, 1);
    posicionarNavio(tabuleiro, 1);
    posicionarNavio(tabuleiro, 1);
}

void realizarTiro(char tabuleiro[TAM][TAM])
{
    int linha;
    int coluna;

    printf("Informe linha do tiro: ");
    scanf("%d", &linha);

    printf("Informe coluna do tiro: ");
    scanf("%d", &coluna);

    if(linha < 0 || linha >= TAM ||
       coluna < 0 || coluna >= TAM){

        printf("Tiro invalido!\n");
        return;
    }

    if(tabuleiro[linha][coluna] == 'N'){

        tabuleiro[linha][coluna] = 'O';

        printf("Acertou um navio!\n");

    }else if(tabuleiro[linha][coluna] == ' '){

        tabuleiro[linha][coluna] = 'X';

        printf("Errou!\n");

    }else{

        printf("Posicao ja utilizada!\n");
    }
}

int verificarVitoria(char tabuleiro[TAM][TAM])
{
    int i;
    int j;

    for(i = 0; i < TAM; i++){

        for(j = 0; j < TAM; j++){

            if(tabuleiro[i][j] == 'N'){
                return 0;
            }
        }
    }

    return 1;
}

void batalhaNaval()
{
    char tabuleiroJogador1[TAM][TAM];
    char tabuleiroJogador2[TAM][TAM];

    int jogadorAtual = 1;

    inicializarTabuleiro(tabuleiroJogador1);
    inicializarTabuleiro(tabuleiroJogador2);

    printf("\n=== JOGADOR 1 POSICIONANDO NAVIOS ===\n");

    posicionarTodosNavios(tabuleiroJogador1);

    printf("\n=== JOGADOR 2 POSICIONANDO NAVIOS ===\n");

    posicionarTodosNavios(tabuleiroJogador2);

    while(1){

        if(jogadorAtual == 1){

            printf("\n=== VEZ DO JOGADOR 1 ===\n");

            mostrarTabuleiroAdversario(tabuleiroJogador2);

            realizarTiro(tabuleiroJogador2);

            if(verificarVitoria(tabuleiroJogador2)){

                printf("Jogador 1 venceu!\n");

                break;
            }

            jogadorAtual = 2;

        }else{

            printf("\n=== VEZ DO JOGADOR 2 ===\n");

            mostrarTabuleiroAdversario(tabuleiroJogador1);

            realizarTiro(tabuleiroJogador1);

            if(verificarVitoria(tabuleiroJogador1)){

                printf("Jogador 2 venceu!\n");

                break;
            }

            jogadorAtual = 1;
        }
    }
}