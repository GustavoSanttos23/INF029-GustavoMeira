#include "aluno.h"
#include "../util.h"

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
    lista[qtd].qtdDisciplinasMatriculado = 0;
    printf("Cadastro concluido com sucesso!\n\n");
    
    return qtd + 1;
}

void listarAlunos(Aluno lista[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int opcao;
    printf("\n--- Opcoes de Listagem ---\n");
    printf("1- Ordem de Cadastro\n");
    printf("2- Ordem Alfabetica (A-Z)\n");
    printf("3- Por Sexo\n");
    printf("4- Por Data de Nascimento (Mais velhos primeiro)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    
    Aluno listaCopia[TAM_ALUNO];
    for(int i = 0; i < qtd; i++) listaCopia[i] = lista[i];

    // Bubble Sort
    if (opcao > 1 && opcao <= 4) {
        for (int i = 0; i < qtd - 1; i++) {
            for (int j = 0; j < qtd - i - 1; j++) {
                int trocar = 0;

                if (opcao == 2) { // Alfabetica
                    if (strcmp(listaCopia[j].nome, listaCopia[j + 1].nome) > 0) trocar = 1;
                } 
                else if (opcao == 3) { // Sexo (F antes de M)
                    if (listaCopia[j].sexo > listaCopia[j + 1].sexo) trocar = 1;
                } 
                else if (opcao == 4) { // Data de Nascimento
                    if (listaCopia[j].data_nascimento.ano > listaCopia[j + 1].data_nascimento.ano) trocar = 1;
                    else if (listaCopia[j].data_nascimento.ano == listaCopia[j + 1].data_nascimento.ano) {
                        if (listaCopia[j].data_nascimento.mes > listaCopia[j + 1].data_nascimento.mes) trocar = 1;
                        else if (listaCopia[j].data_nascimento.mes == listaCopia[j + 1].data_nascimento.mes) {
                            if (listaCopia[j].data_nascimento.dia > listaCopia[j + 1].data_nascimento.dia) trocar = 1;
                        }
                    }
                }

                if (trocar) {
                    Aluno temp = listaCopia[j];
                    listaCopia[j] = listaCopia[j + 1];
                    listaCopia[j + 1] = temp;
                }
            }
        }
    }

    int encontrou = 0;
    for (int i = 0; i < qtd; i++) {
        if (listaCopia[i].ativo == 1) {
            imprimirAluno(listaCopia[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum aluno ativo encontrado.\n");
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
