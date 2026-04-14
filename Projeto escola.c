#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"
#include "fsa/aluno.h"
#include "fsp/professor.h"
#include "fsd/disciplina.h"

void listarAniversariantesDoMes(Aluno listaA[], int qtdA, Professor listaP[], int qtdP);
void buscarPessoaPorNome(Aluno listaA[], int qtdA, Professor listaP[], int qtdP);
void listarAlunosMuitasDisciplinas(Aluno listaA[], int qtdA);

int main() {
    Aluno listaAluno[TAM_ALUNO];
    int qtdAluno = 0;
    Professor listaProf[TAM_PROFESSOR];
    int qtdProf = 0;
    Disciplina listaDisc[TAM_DISCIPLINA];
    int qtdDisciplina = 0;
    int opcao, sair = 0;

    while (sair != 1) {
        printf("\n\t--- PROJETO ESCOLA ---\n\n");
        printf("1- Modulo Aluno\n");
        printf("2- Modulo Professor\n");
        printf("3- Modulo Disciplina\n");
        printf("4- Bônus\n");
        printf("5- Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            continue;
        }

        switch (opcao) {
            case 1: {
                int opcaoAluno, sairAluno = 0;
                while (sairAluno != 1) {
                    printf("\n\t--- MENU ALUNO ---\n\n");
                    printf("1- Cadastrar Aluno\n");
                    printf("2- Listar Alunos\n");
                    printf("3- Atualizar Aluno\n");
                    printf("4- Excluir Aluno\n");
                    printf("5- Voltar ao Menu Principal\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoAluno);
                    
                    switch (opcaoAluno) {
                        case 1: qtdAluno = cadastrarAluno(listaAluno, qtdAluno); break;
                        case 2: listarAlunos(listaAluno, qtdAluno); break;
                        case 3: atualizarAluno(listaAluno, qtdAluno); break;
                        case 4: excluirAluno(listaAluno, qtdAluno); break;
                        case 5: sairAluno = 1; break;
                        default: printf("Opcao invalida no modulo Aluno!\n"); break;
                    }
                }
                break;
            }

            case 2:
                int opcaoProf, sairProf = 0;
                while (sairProf != 1) {
                    printf("\n\t--- MENU PROFESSOR ---\n\n");
                    printf("1- Cadastrar Professor\n");
                    printf("2- Listar Professor\n");
                    printf("3- Atualizar Professor\n");
                    printf("4- Excluir Professor\n");
                    printf("5- Voltar ao Menu Principal\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoProf);
                    
                    switch (opcaoProf) {
                        case 1: qtdProf = cadastrarProfessor(listaProf, qtdProf); break;
                        case 2: listarProfessores(listaProf, qtdProf); break;
                        case 3: atualizarProfessor(listaProf, qtdProf); break;
                        case 4: excluirProfessor(listaProf, qtdProf); break;
                        case 5: sairProf = 1; break;
                        default: printf("Opcao invalida!\n"); break;
                    }
                }
                break;

            case 3:
                int opD, sairD = 0;
                while (!sairD) {
                    printf("\n\t--- MENU DISCIPLINA ---\n");
                    printf("1- Cadastrar Disciplina\n");
                    printf("2- Listar Disciplinas\n");
                    printf("3- Atualizar Disciplina\n");
                    printf("4- Excluir Disciplina\n");
                    printf("5- Atribuir Professor\n");
                    printf("6- Atribuir Aluno\n"); 
                    printf("7- Busca detalhada por disciplina\n");
                    printf("8- Voltar\n");
                    printf("Opcao: ");
                    scanf("%d", &opD);

                    switch (opD) {
                        case 1: qtdDisciplina = cadastrarDisciplina(listaDisc, qtdDisciplina); break;
                        case 2: listarDisciplinas(listaDisc, qtdDisciplina, listaProf, qtdProf, listaAluno, qtdAluno); break;
                        case 3: atualizarDisciplina(listaDisc, qtdDisciplina); break;
                        case 4: excluirDisciplina(listaDisc, qtdDisciplina); break;
                        case 5: atribuirProfessor(listaDisc, qtdDisciplina, listaProf, qtdProf); break;
                        case 6: atribuirAluno(listaDisc, qtdDisciplina, listaAluno, qtdAluno); break;
                        case 7: buscarDisciplinaCompleta(listaDisc, qtdDisciplina, listaProf, qtdProf, listaAluno, qtdAluno); break;
                        case 8: sairD = 1; break;
                        default: printf("Opcao invalida!\n"); break;
                    }
                }
                break;

            case 4:
                int sairBo = 0, opBo;
                while(!sairBo){
                    printf("\n\t--- Aba Bônus ---\n"); 
                    printf("1- Aniversariantes do Mês\n");
                    printf("2- Buscar pessoa por nome\n");
                    printf("3- Listar alunos matriculados em pelo menos três disciplinas\n");
                    printf("4- Lista de disciplinas com mais de 40 alunos\n");
                    printf("5- Atribuir Professor\n");
                    printf("6- Voltar\n");
                    scanf("%d", &opBo);

                    switch(opBo){
                        case 1: listarAniversariantesDoMes(listaAluno, qtdAluno, listaProf, qtdProf); break;
                        case 2: buscarPessoaPorNome(listaAluno, qtdAluno, listaProf, qtdProf); break;
                        case 3: listarAlunosMuitasDisciplinas(listaAluno, qtdAluno); break;
                        case 4: listarDisciplinasLotadas(listaDisc, qtdDisciplina, listaProf, qtdProf); break;
                        case 6: sairBo=1; break;
                    }
                }
            
                break;
            case 5:
                printf("Saindo do sistema... Ate logo!\n"); sair = 1; break;
            default:
                printf("Opcao invalida! Tente novamente.\n"); break;
        }
    }

    return 0;
}
void listarAlunosMuitasDisciplinas(Aluno listaA[], int qtdA) {
    int encontrou = 0;
    const int MINIMO_DISCIPLINAS = 3;

    printf("\n--- ALUNOS MATRICULADOS EM %d OU MAIS DISCIPLINAS ---\n", MINIMO_DISCIPLINAS);

    for (int i = 0; i < qtdA; i++) {
        if (listaA[i].ativo == 1 && listaA[i].qtdDisciplinasMatriculado >= MINIMO_DISCIPLINAS) {
            printf("- Nome: %s (Mat: %d) | Disciplinas: %d\n", 
                    listaA[i].nome, 
                    listaA[i].matricula, 
                    listaA[i].qtdDisciplinasMatriculado);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno encontrado com matricula em pelo menos %d disciplinas.\n", MINIMO_DISCIPLINAS);
    }
    printf("----------------------------------------------------\n");
}

