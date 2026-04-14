#ifndef ALUNO_H
#define ALUNO_H
#include "../util.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNO 50

typedef struct Aluno {
    int matricula;
    char nome[50];
    char sexo;
    Data data_nascimento;
    char cpf[20];
    int qtdDisciplinasMatriculado;
    int ativo;
} Aluno;

void limparBuffer();
void imprimirAluno(Aluno aluno);
int cadastrarAluno(Aluno lista[], int qtd);
void listarAlunos(Aluno lista[], int qtd);
void atualizarAluno(Aluno lista[], int qtd);
void excluirAluno(Aluno lista[], int qtd);

#endif