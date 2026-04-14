#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "../util.h"

int cadastrarDisciplina(Disciplina lista[], int qtd) {
    if (qtd >= TAM_DISCIPLINA) {
        printf("Limite de disciplinas atingido!\n");
        return qtd;
    }

    printf("Codigo da Disciplina: ");
    scanf("%d", &lista[qtd].codigo);
    limparBuffer();

    printf("Nome da Disciplina: ");
    fgets(lista[qtd].nome, 50, stdin);
    lista[qtd].nome[strcspn(lista[qtd].nome, "\n")] = 0;

    printf("Semestre (1-10): ");
    scanf("%d", &lista[qtd].semestre);

    lista[qtd].matriculaProfessor = -1;
    lista[qtd].qtdAlunosMatriculados = 0;
    lista[qtd].ativo = 1;

    printf("Disciplina cadastrada com sucesso!\n");
    return qtd + 1;
}

void listarDisciplinas(Disciplina lista[], int qtd, Professor listaProf[], int qtdProf, Aluno listaAlunos[], int qtdAlunos) {
    int encontrou = 0;
    for (int i = 0; i < qtd; i++) {
        if (lista[i].ativo == 1) {
            printf("\n========================================\n");
            printf("DISCIPLINA: %s (Cod: %d)\n", lista[i].nome, lista[i].codigo);
            printf("Semestre: %d\n", lista[i].semestre);
            
            if (lista[i].matriculaProfessor == -1) {
                printf("Professor: [NAO ATRIBUIDO]\n");
            } else {
                for(int j = 0; j < qtdProf; j++) {
                    if(listaProf[j].matricula == lista[i].matriculaProfessor) {
                        printf("Professor: %s\n", listaProf[j].nome);
                        break;
                    }
                }
            }

            //printf("Alunos Matriculados (%d/%d):\n", lista[i].qtdAlunosMatriculados, TAM_ALUNOS_POR_DISCIPLINA);
            
            if (lista[i].qtdAlunosMatriculados == 0) {
                //printf("  -> Nenhum aluno matriculado nesta disciplina.\n");
            } else {
                for (int j = 0; j < lista[i].qtdAlunosMatriculados; j++) {
                    int matBusca = lista[i].listaMatriculasAlunos[j];
                    
                    for (int k = 0; k < qtdAlunos; k++) {
                        if (listaAlunos[k].matricula == matBusca) {
                            //printf("  - [%d] %s\n", listaAlunos[k].matricula, listaAlunos[k].nome);
                            break;
                        }
                    }
                }
            }
            printf("========================================\n");
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhuma disciplina ativa cadastrada.\n");
}

int atribuirProfessor(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP) {
    int cod, mat, acheiD = -1, acheiP = -1;

    printf("Codigo da Disciplina: ");
    scanf("%d", &cod);
    printf("Matricula do Professor: ");
    scanf("%d", &mat);

    for(int i = 0; i < qtdD; i++) {
        if(listaD[i].codigo == cod && listaD[i].ativo == 1) {
            acheiD = i;
            break;
        }
    }

    for(int i = 0; i < qtdP; i++) {
        if(listaP[i].matricula == mat && listaP[i].ativo == 1) {
            acheiP = i;
            break;
        }
    }

    if(acheiD != -1 && acheiP != -1) {
        listaD[acheiD].matriculaProfessor = mat;
        printf("Professor %s atribuido com sucesso!\n", listaP[acheiP].nome);
    } else {
        printf("Erro: Disciplina ou Professor nao encontrados!\n");
    }
}

void atualizarDisciplina(Disciplina lista[], int qtd) {
    int cod, achou = 0;
    printf("Digite o codigo da disciplina para atualizar: ");
    scanf("%d", &cod);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo == cod && lista[i].ativo == 1) {
            achou = 1;
            int opcaoAt;
            printf("\nDisciplina encontrada: %s\n", lista[i].nome);
            printf("O que deseja alterar?\n1-Nome\n2-Codigo\n3-Semestre\nOpcao: ");
            scanf("%d", &opcaoAt);
            limparBuffer();

            switch (opcaoAt) {
                case 1:
                    printf("Novo Nome: ");
                    fgets(lista[i].nome, 50, stdin);
                    lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
                    break;
                case 2:
                    printf("Novo Codigo: ");
                    scanf("%d", &lista[i].codigo);
                    break;
                case 3:
                    printf("Novo Semestre: ");
                    scanf("%d", &lista[i].semestre);
                    break;
                default:
                    printf("Opção Invalida!\n");
                    return;
            }
            printf("Dados da disciplina atualizados com sucesso!\n");
            return;
        }
    }
    if (!achou) printf("Disciplina com codigo %d nao encontrada.\n", cod);
}

void excluirDisciplina(Disciplina lista[], int qtd) {
    int cod;
    printf("Digite o codigo da disciplina para excluir: ");
    scanf("%d", &cod);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo == cod && lista[i].ativo == 1) {
            char confirma;
            printf("Confirmar exclusão da disciplina %s? (S/N): ", lista[i].nome);
            scanf(" %c", &confirma);
            
            if (toupper(confirma) == 'S') {
                lista[i].ativo = 0;
                printf("Disciplina excluida com sucesso!\n");
            } else {
                printf("Operação cancelada.\n");
            }
            return;
        }
    }
    printf("Disciplina não encontrada ou já inativa.\n");
}

void atribuirAluno(Disciplina listaD[], int qtdD, Aluno listaA[], int qtdA) {
    int cod, mat, acheiD = -1, acheiA = -1;

    printf("Codigo da Disciplina: ");
    scanf("%d", &cod);
    printf("Matricula do Aluno: ");
    scanf("%d", &mat);

    for(int i = 0; i < qtdD; i++) {
        if(listaD[i].codigo == cod && listaD[i].ativo == 1) {
            acheiD = i;
            break;
        }
    }

    for(int i = 0; i < qtdA; i++) {
        if(listaA[i].matricula == mat && listaA[i].ativo == 1) {
            acheiA = i;
            break;
        }
    }

    if(acheiD != -1 && acheiA != -1) {
        if (listaD[acheiD].qtdAlunosMatriculados < TAM_ALUNOS_POR_DISCIPLINA) {
            int pos = listaD[acheiD].qtdAlunosMatriculados;
            listaD[acheiD].listaMatriculasAlunos[pos] = mat;
            listaD[acheiD].qtdAlunosMatriculados++;
            listaA[acheiA].qtdDisciplinasMatriculado++;
            printf("Aluno %s matriculado na disciplina %s!\n", listaA[acheiA].nome, listaD[acheiD].nome);
        } else {
            printf("Erro: Disciplina lotada!\n");
        }
    } else {
        printf("Erro: Disciplina ou Aluno nao encontrados!\n");
    }
}

void buscarDisciplinaCompleta(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP, Aluno listaA[], int qtdA) {
    int cod, achei = -1;

    printf("Digite o codigo da disciplina para busca detalhada: ");
    scanf("%d", &cod);

    for (int i = 0; i < qtdD; i++) {
        if (listaD[i].codigo == cod && listaD[i].ativo == 1) {
            achei = i;
            break;
        }
    }

    if (achei != -1) {
        printf("\n==============================================\n");
        printf("       DETALHES DA DISCIPLINA %d\n", listaD[achei].codigo);
        printf("==============================================\n");
        printf("NOME: %s\n", listaD[achei].nome);
        printf("SEMESTRE: %d\n", listaD[achei].semestre);

        if (listaD[achei].matriculaProfessor == -1) {
            printf("PROFESSOR: [NAO ATRIBUIDO]\n");
        } else {
            for (int j = 0; j < qtdP; j++) {
                if (listaP[j].matricula == listaD[achei].matriculaProfessor) {
                    printf("PROFESSOR: %s (Mat: %d)\n", listaP[j].nome, listaP[j].matricula);
                    break;
                }
            }
        }

        printf("----------------------------------------------\n");
        printf("LISTA DE ALUNOS MATRICULADOS (%d):\n", listaD[achei].qtdAlunosMatriculados);

        if (listaD[achei].qtdAlunosMatriculados == 0) {
            printf("-> Nao ha alunos matriculados nesta disciplina.\n");
        } else {
            for (int j = 0; j < listaD[achei].qtdAlunosMatriculados; j++) {
                int matAluno = listaD[achei].listaMatriculasAlunos[j];
                
                for (int k = 0; k < qtdA; k++) {
                    if (listaA[k].matricula == matAluno) {
                        printf("   [%d] - %s\n", listaA[k].matricula, listaA[k].nome);
                        break;
                    }
                }
            }
        }
        printf("==============================================\n");
    } else {
        printf("\nErro: Disciplina com codigo %d nao encontrada.\n", cod);
    }
}

void listarDisciplinasLotadas(Disciplina listaD[], int qtdD, Professor listaP[], int qtdP) {
    int encontrou = 0;
    const int LIMITE = 40;

    printf("\n--- DISCIPLINAS COM MAIS DE %d ALUNOS ---\n", LIMITE);

    for (int i = 0; i < qtdD; i++) {
        if (listaD[i].ativo == 1 && 
            listaD[i].qtdAlunosMatriculados > LIMITE) {

            printf("\nDisciplina: %s (Cod: %d)\n", 
                   listaD[i].nome, listaD[i].codigo);

            if (listaD[i].matriculaProfessor == -1) {
                printf("Professor: [NAO ATRIBUIDO]\n");
            } else {
                int achouProf = 0;
                for (int j = 0; j < qtdP; j++) {
                    if (listaP[j].matricula == listaD[i].matriculaProfessor &&
                        listaP[j].ativo == 1) {
                        printf("Professor: %s\n", listaP[j].nome);
                        achouProf = 1;
                        break;
                    }
                }
                if (!achouProf) {
                    printf("Professor: [NAO ENCONTRADO]\n");
                }
            }

            printf("Total de alunos: %d\n", 
                   listaD[i].qtdAlunosMatriculados);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma disciplina excede %d alunos.\n", LIMITE);
    }

    printf("----------------------------------------\n");
}