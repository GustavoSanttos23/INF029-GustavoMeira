#include <stdio.h>
#include <stdlib.h>

int main(){

    int opcao, sair = 0; // sair 0 = falso
    printf("Projeto escola\n\n");

    while(sair != 1){
        printf("1- Aluno\n");
        printf("2- Professor\n");
        printf("3- Disciplina\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("---Modulo Aluno---\n");
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
