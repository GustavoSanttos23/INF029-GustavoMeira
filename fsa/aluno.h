#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_ALUNO 5

// Definição das Structs
typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Aluno {
    int matricula;
    char nome[50];
    char sexo;
    Data data_nascimento;
    char cpf[20];
    int ativo;
} Aluno;

// Protótipos das Funções (Assinaturas)
void limparBuffer();
Data lerDataValida();
void imprimirAluno(Aluno aluno);
int cadastrarAluno(Aluno lista[], int qtd);
void listarAlunos(Aluno lista[], int qtd);
void atualizarAluno(Aluno lista[], int qtd);
void excluirAluno(Aluno lista[], int qtd);
void listarAniversariantesDoMes(Aluno listaA[], int qtdA, Professor listaP[], int qtdP);

#endif