#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "../fsp/professor.h" // Para termos acesso aos limites e tipos do professor

#define TAM_DISCIPLINA 10
#define TAM_ALUNOS_POR_DISCIPLINA 10

typedef struct Disciplina {
    char nome[50];
    int codigo;
    int semestre;
    int matriculaProfessor; // Armazena a matrícula do professor vinculado
    int listaMatriculasAlunos[TAM_ALUNOS_POR_DISCIPLINA]; // Novo campo
    int qtdAlunosMatriculados; // Contador de alunos na matéria
    int ativo;
} Disciplina;

// Protótipos
int cadastrarDisciplina(Disciplina lista[], int qtd);
void listarDisciplinas(Disciplina lista[], int qtd, Professor listaProf[], int qtdProf, Aluno listaAlunos[], int qtdAlunos);
void atualizarDisciplina(Disciplina lista[], int qtd);
void excluirDisciplina(Disciplina lista[], int qtd);
int atribuirProfessor(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP);
void atribuirAluno(Disciplina listaD[], int qtdD, Aluno listaA[], int qtdA);
void buscarDisciplinaCompleta(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP, Aluno listaA[], int qtdA);

#endif