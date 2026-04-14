#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "../util.h"
#define TAM_PROFESSOR 10

typedef struct Professor {
    int matricula;
    char nome[50];
    char sexo;
    Data data_nascimento;
    char cpf[20];
    int ativo;
} Professor;

int cadastrarProfessor(Professor lista[], int qtd);
void listarProfessores(Professor lista[], int qtd);
void atualizarProfessor(Professor lista[], int qtd);
void excluirProfessor(Professor lista[], int qtd);
void imprimirProfessor(Professor prof);

#endif