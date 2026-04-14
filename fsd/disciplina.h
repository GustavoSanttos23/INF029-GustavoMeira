#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "../util.h" 
#include "../fsa/aluno.h"     
#include "../fsp/professor.h"  

#define TAM_DISCIPLINA 10
#define TAM_ALUNOS_POR_DISCIPLINA 50

typedef struct Disciplina {
    char nome[50];
    int codigo;
    int semestre;
    int matriculaProfessor; 
    int listaMatriculasAlunos[TAM_ALUNOS_POR_DISCIPLINA]; 
    int qtdAlunosMatriculados; 
    int ativo;
} Disciplina;

int cadastrarDisciplina(Disciplina lista[], int qtd);
void listarDisciplinas(Disciplina lista[], int qtd, Professor listaProf[], int qtdProf, Aluno listaAlunos[], int qtdAlunos);
void atualizarDisciplina(Disciplina lista[], int qtd);
void excluirDisciplina(Disciplina lista[], int qtd);
int atribuirProfessor(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP);
void atribuirAluno(Disciplina listaD[], int qtdD, Aluno listaA[], int qtdA);
void buscarDisciplinaCompleta(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP, Aluno listaA[], int qtdA);
void listarDisciplinasLotadas(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP);

#endif