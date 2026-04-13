// Codigo antes da modularização

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_AlUNO 5


typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Aluno{
    int matricula;
    char nome[50];
    char sexo;
    Data data_nascimento;
    char cpf[20];
    int ativo;
}Aluno;

void imprimirAluno(Aluno aluno) {
    printf("---------- Dados do Aluno ----------\n");
    printf("1- Nome: %s\n", aluno.nome);
    printf("2- Matrícula: %d\n", aluno.matricula);
    printf("3- Data de Nascimento: %02d/%02d/%04d\n", 
            aluno.data_nascimento.dia, 
            aluno.data_nascimento.mes, 
            aluno.data_nascimento.ano);
    printf("4- CPF: %s\n", aluno.cpf);
    printf("5- Sexo: %c\n", aluno.sexo);
    printf("------------------------------------\n\n");
}

int main(){

    Aluno listaAluno[TAM_AlUNO];
    int opcao, sair = 0;
    int qtdAluno = 0;

    printf("\t---Projeto escola---\n\n");

    while(sair != 1){
        printf("1- Aluno\n");
        printf("2- Professor\n");
        printf("3- Disciplina\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("\t---Modulo Aluno---\n\n");
            int opcaoAluno, sairAluno = 0;
            while(sairAluno != 1){
                printf("1- Cadastrar Aluno\n");
                printf("2- Listar Alunos\n");
                printf("3- Atualizar Aluno\n");
                printf("4- Excluir Aluno\n");
                printf("5- Sair\n");
                scanf("%d", &opcaoAluno);
                printf("\n");
                
                switch(opcaoAluno){
                    case 1:
                    if (qtdAluno == TAM_AlUNO) {
                        printf("Limite de alunos alcançado!\n");
                    } else {
                        printf("Digite a matricula: ");
                        int matricula;
                        scanf("%d", &matricula);
                        printf("\n");

                        if (matricula < 0) {
                            printf("Matricula invalida!\n");
                        } else {
                            listaAluno[qtdAluno].matricula = matricula;
                            listaAluno[qtdAluno].ativo = 1;
                            // FIM DO NUMERO DE MATRICULA

                            // INICIO DO CPF
                            printf("Digite o Cpf do Aluno: ");
                            char cpf[20];
                            scanf("%s", cpf);
                            // LIMPEZA DO BUFFER
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            // FIM LIMPEZA
                            printf("\n");
                            int tamcpf = strlen(cpf);
                            if (tamcpf != 11) {
                                printf("Cpf Invalido!\n");
                            } else {
                                strcpy(listaAluno[qtdAluno].cpf, cpf);
                                // FIM DO CPF

                                // INICIO DO NOME
                                printf("Digite o Nome do Aluno: ");
                                char nome[50];
                                fgets(nome, 50, stdin);
                                printf("\n");
                                nome[strcspn(nome, "\n")] = 0;
                                strcpy(listaAluno[qtdAluno].nome, nome);
                                // FIM DO NOME

                                // INICIO DO SEXO
                                printf("Defina o Sexo do Aluno\n Selecione M para masculino e F para feminino: ");
                                char entrada;
                                scanf("%c", &entrada);
                                int c2;
                                while ((c2 = getchar()) != '\n' && c2 != EOF);
                                printf("\n");

                                if (toupper(entrada) == 'M' || toupper(entrada) == 'F') {
                                    listaAluno[qtdAluno].sexo = toupper(entrada);
                                } else {
                                    printf("Invalido!\n");
                                }
                                // FIM DO SEXO

                                // INICIO DATA NASCIMENTO
                                printf("Insira a Data de nascimento, seguindo as instruções a seguir:\n");

                                printf("Digite a data do mês:(DATA/XX/XXXX): ");
                                int dia;
                                scanf("%d", &dia);
                                if (dia < 1 || dia > 31) {
                                    printf("Data invalida!\n");
                                } else {
                                    listaAluno[qtdAluno].data_nascimento.dia = dia;

                                    printf("Digite o mês(XX/MÊS/XXXX): ");
                                    int mes;
                                    scanf("%d", &mes);
                                    if (mes < 1 || mes > 12) {
                                        printf("Mês invalido!\n");
                                    } else {
                                        listaAluno[qtdAluno].data_nascimento.mes = mes;

                                        printf("Digite o Ano(XX/XX/ANO): ");
                                        int ano;
                                        scanf("%d", &ano);
                                        if (ano < 1900 || ano > 2024) {
                                            printf("Ano invalido!\n");
                                        } else {
                                            listaAluno[qtdAluno].data_nascimento.ano = ano;
                                            printf("Cadastro de aluno concluido, REF 0%d\n\n", qtdAluno);
                                        }
                                    }
                                }
                                // FIM DA DATA DE NASCIMENTO
                            }
                            qtdAluno++;
                        }
                    }
                    break;

                    case 2:
                        if(qtdAluno == 0){
                            printf("Lista Vazia!\n");
                        }else{
                            for(int i=0; i < qtdAluno; i++){
                                if(listaAluno[i].ativo != 1){
                                    i++;
                                }else{
                                    imprimirAluno(listaAluno[i]);
                                }
                            }
                        }
                        break;

                    case 3:
                        printf("Digite a matricula: ");
                        int matriculaAt;
                        scanf("%d", &matriculaAt);
                        printf("\n");
                        int achouAt = 0;
                        int opcaoAt;
                        for(int i = 0; i < qtdAluno; i++){
                            if(listaAluno[i].matricula == matriculaAt && listaAluno[i].ativo == 1){
                                achouAt = 1;
                                imprimirAluno(listaAluno[i]);
                                printf("Escolha o dado que deseja alterar: ");
                                scanf("%d", &opcaoAt);
                                printf("\n");
                                switch(opcaoAt){

                                    case 1:
                                        printf("Digite o Nome Atualizado do Aluno: ");
                                        char nomeAt[50];
                                        fgets(nomeAt, 50, stdin);
                                        printf("\n");
                                        nomeAt[strcspn(nomeAt, "\n")] = 0;
                                        strcpy(listaAluno[i].nome, nomeAt);
                                        printf("Atualização concluida com sucesso, REF 0%d\n\n", qtdAluno);
                                    break;

                                    case 2:
                                        printf("Digite a matricula Atualizada: ");
                                        int matriculaAt;
                                        scanf("%d", &matriculaAt);
                                        printf("\n");

                                        if (matriculaAt < 0) {
                                            printf("Matricula invalida!\n");
                                        } else {
                                            listaAluno[i].matricula = matriculaAt;
                                            printf("Atualização concluida com sucesso, REF 0%d\n\n", qtdAluno);
                                        }
                                    break;

                                    case 3:
                                        printf("Insira a Data de nascimento atualizada, seguindo as instruções a seguir:\n");

                                        printf("Digite a data do mês:(DATA/XX/XXXX): ");
                                        int diaAt;
                                        scanf("%d", &diaAt);
                                        if (diaAt < 1 || diaAt > 31) {
                                            printf("Data invalida!\n");
                                        } else {
                                            listaAluno[i].data_nascimento.dia = diaAt;

                                            printf("Digite o mês(XX/MÊS/XXXX): ");
                                            int mesAt;
                                            scanf("%d", &mesAt);
                                            if (mesAt < 1 || mesAt > 12) {
                                                printf("Mês invalido!\n");
                                            } else {
                                                listaAluno[i].data_nascimento.mes = mesAt;

                                                printf("Digite o Ano(XX/XX/ANO): ");
                                                int anoAt;
                                                scanf("%d", &anoAt);
                                                if (anoAt < 1900 || anoAt > 2024) {
                                                    printf("Ano invalido!\n");
                                                } else {
                                                    listaAluno[i].data_nascimento.ano = anoAt;
                                                    printf("Atualização concluida com sucesso, REF 0%d\n\n", qtdAluno);
                                                }
                                            }
                                        }
                                    break;
                                    
                                    case 4:
                                        printf("Digite o Cpf atualizado do Aluno: ");
                                        char cpfAt[20];
                                        scanf("%s", cpfAt);
                                        // LIMPEZA DO BUFFER
                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);
                                        // FIM LIMPEZA
                                        printf("\n");
                                        int tamcpf = strlen(cpfAt);
                                        if (tamcpf != 11) {
                                            printf("Cpf Invalido!\n");
                                        } else {
                                            strcpy(listaAluno[i].cpf, cpfAt);
                                        }
                                    break;
                                    
                                    case 5:
                                        printf("Defina o Sexo atualizado do Aluno\n Selecione M para masculino e F para feminino: ");
                                        char entrada;
                                        scanf("%c", &entrada);
                                        int c2;
                                        while ((c2 = getchar()) != '\n' && c2 != EOF);
                                        printf("\n");

                                        if (toupper(entrada) == 'M' || toupper(entrada) == 'F') {
                                            listaAluno[i].sexo = toupper(entrada);
                                        } else {
                                            printf("Invalido!\n");
                                        }
                                    break;

                                    default:
                                        printf("Opção invalida!\n");
                                    break;
                                        
                                }
                            }
                        }
                        break;

                    case 4:
                        printf("Digite a matricula: ");
                        int matricula;
                        scanf("%d", &matricula);
                        printf("\n");
                        int achou = 0;

                        for(int i = 0; i < qtdAluno; i++){
                            if(listaAluno[i].matricula == matricula){
                                achou = 1;
                                imprimirAluno(listaAluno[i]);
                                printf("Digite S para confirmar exclusão e N para abortar exclusão\n --> ");
                                char entrada;
                                scanf(" %c", &entrada);
                                int c;
                                while ((c = getchar()) != '\n' && c != EOF);
                                printf("\n");

                                if (toupper(entrada) == 'S') {
                                    listaAluno[i].ativo = 0;
                                    printf("Cadastro excluido com sucesso!\n");
                                } else if(toupper(entrada) == 'N') {
                                    printf("Operação abortada!\n");
                                } else{
                                    printf("Resposta invalida!\n");
                                }

                            }
                        }
                        if(achou = 0){
                            printf("Matricula não encontrada!\n");
                        }

                        break;

                    case 5:
                        sairAluno = 1;
                        break;

                    default:
                        printf("Opção invalida!");
                        break;
                    }
                }

            break;
        case 2:
            printf("---Modulo Professor---\n");
            break;
        case 3:
            printf("---Modulo Disciplina---\n");
            break;
        case 4:
            sair = 1;
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }
    }
}
