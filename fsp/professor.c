#include "professor.h"

void imprimirProfessor(Professor prof) {
    printf("---------- Dados do Professor ----------\n");
    printf("Nome: %s\n", prof.nome);
    printf("Matrícula: %d\n", prof.matricula);
    printf("Data de Nascimento: %02d/%02d/%04d\n", 
            prof.data_nascimento.dia, 
            prof.data_nascimento.mes, 
            prof.data_nascimento.ano);
    printf("CPF: %s\n", prof.cpf);
    printf("Sexo: %c\n", prof.sexo);
    printf("----------------------------------------\n\n");
}

int cadastrarProfessor(Professor lista[], int qtd) {
    if (qtd >= TAM_PROFESSOR) {
        printf("Erro: Limite de professores alcançado!\n");
        return qtd;
    }

    printf("Digite a matricula do professor: ");
    scanf("%d", &lista[qtd].matricula);
    
    if (lista[qtd].matricula < 0) {
        printf("Matricula invalida!\n");
        return qtd;
    }

    printf("Digite o CPF (apenas numeros): ");
    scanf("%s", lista[qtd].cpf);
    limparBuffer();

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
    printf("Professor cadastrado com sucesso!\n\n");
    
    return qtd + 1;
}

void listarProfessores(Professor lista[], int qtd) {
    int encontrou = 0;
    for (int i = 0; i < qtd; i++) {
        if (lista[i].ativo == 1) {
            imprimirProfessor(lista[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum professor ativo cadastrado.\n");
}

void atualizarProfessor(Professor lista[], int qtd) {
    int mat;
    printf("Digite a matricula para atualizar: ");
    scanf("%d", &mat);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].matricula == mat && lista[i].ativo == 1) {
            int opcaoAt;
            imprimirProfessor(lista[i]);
            printf("O que deseja alterar?\n1-Nome\n2-Matricula\n3-Data\n4-CPF\n5-Sexo\nOpcao: ");
            scanf("%d", &opcaoAt);
            limparBuffer();

            switch (opcaoAt) {
                case 1:
                    printf("Novo Nome: ");
                    fgets(lista[i].nome, 50, stdin);
                    lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
                    break;
                case 2:
                    printf("Nova Matricula: ");
                    scanf("%d", &lista[i].matricula);
                    break;
                case 3:
                    printf("Nova Data de Nascimento:\n");
                    lista[i].data_nascimento = lerDataValida();
                    break;
                case 4:
                    printf("Novo CPF: ");
                    scanf("%s", lista[i].cpf);
                    break;
                case 5:
                    printf("Novo Sexo (M/F): ");
                    char s;
                    scanf(" %c", &s);
                    lista[i].sexo = toupper(s);
                    break;
                default:
                    printf("Opção Invalida!\n");
                    return;
            }
            printf("Dados atualizados!\n");
            return;
        }
    }
    printf("Professor não encontrado.\n");
}

void excluirProfessor(Professor lista[], int qtd) {
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
    printf("Professor não encontrado.\n");
}