#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNO 5

// --- Estruturas ---
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

// --- Funções Auxiliares e de Validação ---

Data lerDataValida() {
    Data d;
    
    do {
        printf("Digite o dia (1-31): ");
        scanf("%d", &d.dia);
        if(d.dia < 1 || d.dia > 31) printf("Dia invalido!\n");
    } while(d.dia < 1 || d.dia > 31);

    do {
        printf("Digite o mes (1-12): ");
        scanf("%d", &d.mes);
        if(d.mes < 1 || d.mes > 12) printf("Mes invalido!\n");
    } while(d.mes < 1 || d.mes > 12);

    do {
        printf("Digite o ano (1900-2026): ");
        scanf("%d", &d.ano);
        if(d.ano < 1900 || d.ano > 2026) printf("Ano invalido (1900-2026)!\n");
    } while(d.ano < 1900 || d.ano > 2026);

    return d;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimirAluno(Aluno aluno) {
    printf("---------- Dados do Aluno ----------\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matrícula: %d\n", aluno.matricula);
    printf("Data de Nascimento: %02d/%02d/%04d\n", 
            aluno.data_nascimento.dia, 
            aluno.data_nascimento.mes, 
            aluno.data_nascimento.ano);
    printf("CPF: %s\n", aluno.cpf);
    printf("Sexo: %c\n", aluno.sexo);
    printf("------------------------------------\n\n");
}

// --- Funções de Operação ---

int cadastrarAluno(Aluno lista[], int qtd) {
    if (qtd >= TAM_ALUNO) {
        printf("Erro: Limite de alunos alcançado!\n");
        return qtd;
    }

    printf("Digite a matricula: ");
    scanf("%d", &lista[qtd].matricula);
    if (lista[qtd].matricula < 0) {
        printf("Matricula invalida!\n");
        return qtd;
    }

    printf("Digite o CPF (apenas numeros): ");
    scanf("%s", lista[qtd].cpf);
    limparBuffer();
    if (strlen(lista[qtd].cpf) != 11) {
        printf("CPF Invalido!\n");
        return qtd;
    }

    printf("Digite o Nome: ");
    fgets(lista[qtd].nome, 50, stdin);
    lista[qtd].nome[strcspn(lista[qtd].nome, "\n")] = 0;

    printf("Sexo (M/F): ");
    char s;
    scanf(" %c", &s);
    lista[qtd].sexo = toupper(s);

    printf("Data de Nascimento:\n");
    lista[qtd].data_nascimento = lerDataValida();
    lista[qtd].ativo = 1;
    printf("Cadastro concluido com sucesso! [REF %d]\n\n", qtd);
    
    return qtd + 1;
}

void listarAlunos(Aluno lista[], int qtd) {
    int encontrou = 0;
    for (int i = 0; i < qtd; i++) {
        if (lista[i].ativo == 1) {
            imprimirAluno(lista[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum aluno ativo cadastrado.\n");
}

void atualizarAluno(Aluno lista[], int qtd) {
    int mat;
    printf("Digite a matricula para atualizar: ");
    scanf("%d", &mat);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].matricula == mat && lista[i].ativo == 1) {
            int opcaoAt;
            imprimirAluno(lista[i]);
            printf("O que deseja alterar?\n1-Nome\n2-Matricula\n3-Data\n4-CPF\n5-Sexo\nOpcao: ");
            scanf("%d", &opcaoAt);
            limparBuffer();

            switch (opcaoAt) {
                case 1:
                    printf("Novo Nome: ");
                    fgets(lista[i].nome, 50, stdin);
                    lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
                    printf("Dados atualizados!\n");
                    break;
                case 2:
                    printf("Nova Matricula: ");
                    scanf("%d", &lista[i].matricula);
                    printf("Dados atualizados!\n");
                    break;
                case 3:
                    printf("Nova Data de Nascimento:\n");
                    lista[i].data_nascimento = lerDataValida();
                    printf("Dados atualizados!\n");
                    break;
                case 4:
                    printf("Novo CPF: ");
                    scanf("%s", lista[i].cpf);
                    printf("Dados atualizados!\n");
                    break;
                case 5:
                    printf("Novo Sexo (M/F): ");
                    char s;
                    scanf(" %c", &s);
                    lista[i].sexo = toupper(s);
                    printf("Dados atualizados!\n");
                    break;
                default:
                    printf("Opção Invalido!\n;");
                    break;
            }
            return;
        }
    }
    printf("Matricula não encontrada.\n");
}

void excluirAluno(Aluno lista[], int qtd) {
    int mat;
    printf("Digite a matricula para excluir: ");
    scanf("%d", &mat);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].matricula == mat && lista[i].ativo == 1) {
            char confirma;
            printf("Confirmar exclusão de %s? (S/N): ", lista[i].nome);
            scanf(" %c", &confirma);
            if (toupper(confirma) == 'S') {
                lista[i].ativo = 0;
                printf("Excluido com sucesso!\n");
            } else {
                printf("Operação cancelada.\n");
            }
            return;
        }
    }
    printf("Matricula não encontrada.\n");
}

int main() {
    Aluno listaAluno[TAM_ALUNO];
    int qtdAluno = 0;
    int opcao, sair = 0;

    while (sair != 1) {
        printf("\n\t--- PROJETO ESCOLA ---\n\n");
        printf("1- Modulo Aluno\n");
        printf("2- Modulo Professor\n");
        printf("3- Modulo Disciplina\n");
        printf("4- Sair\n");
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
                printf("\n[AVISO] Modulo Professor em desenvolvimento...\n");
                // Aqui voce chamaria funcoes como: qtdProf = cadastrarProfessor(listaProf, qtdProf);
                break;

            case 3:
                printf("\n[AVISO] Modulo Disciplina em desenvolvimento...\n");
                // Aqui voce chamaria funcoes como: cadastrarDisciplina(listaDisc, &qtdDisc);
                break;

            case 4:
                printf("Saindo do sistema... Ate logo!\n");
                sair = 1;
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
