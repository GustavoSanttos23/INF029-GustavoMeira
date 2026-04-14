#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_AlUNO 5
#define TAM_PROF 5

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
}Aluno;

typedef struct Professor{
    int matricula;
    char nome[50];
    char sexo;
    Data data_nascimento;
    char cpf[20];
}Professor;//Ainda sem uso


int main(){

    Aluno listaAluno[TAM_AlUNO];
    Professor listaProf[TAM_PROF];
    int opcao, sair = 0;
    int qtdAluno = 0;
    int qtdProf = 0;//Ainda sem uso


    printf("Projeto escola\n\n");

    while(sair != 1){
        printf("1- Aluno\n");
        printf("2- Professor\n");
        printf("3- Disciplina\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("---Modulo Aluno---\n\n");
            int opcaoAluno, sairAluno = 0;
            while(sairAluno != 1){
                printf("1- Cadastrar Aluno\n");
                printf("2- Listar Aluno\n");
                printf("3- Atualizar Aluno\n");
                printf("4- Excluir Aluno\n");
                printf("5- Sair\n");
                scanf("%d", &opcaoAluno);
                printf("\n");
                
                switch(opcaoAluno){
                    case 1:
                        printf("Digite a matricula: ");
                        int matricula;
                        scanf("%d", &matricula);
                        printf("\n");

                        if(matricula < 0){
                            printf("Matricula invalida!\n");
                        } else{ 
                            if(qtdAluno == TAM_AlUNO){
                                printf("Limite de alunos alcançado!\n");
                            } else{
                                listaAluno[qtdAluno].matricula = matricula;
                                //FIM DO NUMERO DE MATRICULA
                                
                                //INICIO DO CPF
                                printf("Digite o Cpf do Aluno: ");
                                char cpf[20];
                                scanf("%s", cpf);
                                // LIMPEZA DO BUFFER
                                int c;
                                while ((c = getchar()) != '\n' && c != EOF);
                                //FIM LIMPEZA
                                printf("\n");
                                int tamcpf = strlen(cpf);
                                if(tamcpf != 11){
                                    printf("Cpf Invalido!\n");
                                }else{
                                    strcpy(listaAluno[qtdAluno].cpf, cpf);
                                    // FIM DO CPF

                                    // INICIO DO NOME
                                    printf("Digite o Nome do Aluno: ");
                                    char nome[50];
                                    fgets(nome, 50, stdin);
                                    printf("\n");
                                    nome[strcspn(nome, "\n")] = 0;
                                    strcpy(listaAluno[qtdAluno].nome, nome);
                                    //FIM DO NOME

                                    //INICIO DO SEXO
                                    printf("Defina o Sexo do Aluno\n Selecione M para masculino e F para feminino: ");
                                    char entrada;
                                    scanf("%c", &entrada);
                                    int c;
                                    while ((c = getchar()) != '\n' && c != EOF);
                                    printf("\n");
                                    char MF[4] = "MmFf";
                                    if(toupper(entrada) == 'M' || toupper(entrada) == 'F'){
                                        listaAluno[qtdAluno].sexo = toupper(entrada);
                                    } else {
                                        printf("Invalido!\n");
                                    }
                                    //FIM DO SEXO
                                    
                                    //INICIO DATA NASCIMENTO
                                    printf("Insira a Data de nascimento, seguindo as instruções a seguir:\n");
                                    
                                    printf("Digite a data do mês:(DATA/XX/XXXX): ");
                                    int dia;
                                    scanf("%d", &dia);
                                    if(dia < 1 || dia > 31){
                                        printf("Data invalida!\n");
                                    } else{
                                        listaAluno[qtdAluno].data_nascimento.dia = dia;

                                        printf("Digite o mês(XX/MÊS/XXXX): ");
                                        int mes;
                                        scanf("%d", &mes);
                                        if(mes < 1 || mes > 12){
                                            printf("Mês invalido!\n");
                                        }else{
                                            listaAluno[qtdAluno].data_nascimento.mes = mes;

                                            printf("Digite o Ano(XX/XX/ANO): ");
                                            int ano;
                                            scanf("%d", &ano);
                                            if(ano < 1900 || ano > 2024){
                                                printf("Ano invalido!\n");
                                            } else{
                                                listaAluno[qtdAluno].data_nascimento.ano = ano;
                                                printf("Cadastro de aluno concluido, REF %d", qtdAluno);
                                            }
                                        }
                                    }
                                    //FIM DA DATA DE NASCIMENTO
                                }
                                qtdAluno++;
                            }
                        }
                        break;

                    case 2:
                        printf("Listagem de alunos");
                        break;

                    case 3:
                        printf("Atualização de aluno");
                        break;

                    case 4:
                        printf("Excluir aluno");
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
            printf("Saida automatica a seguir\n");
            sair = 1;
            break;
        }
    }
}
