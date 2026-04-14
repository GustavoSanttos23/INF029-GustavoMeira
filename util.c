#include "util.h"
#include "fsa/aluno.h"
#include "fsp/professor.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Data lerDataValida() {
    Data d;
    do {
        printf("Digite o dia (1-31): ");
        scanf("%d", &d.dia);
    } while(d.dia < 1 || d.dia > 31);

    do {
        printf("Digite o mes (1-12): ");
        scanf("%d", &d.mes);
    } while(d.mes < 1 || d.mes > 12);

    do {
        printf("Digite o ano (1900-2026): ");
        scanf("%d", &d.ano);
    } while(d.ano < 1900 || d.ano > 2026);

    return d;
}

void listarAniversariantesDoMes(Aluno listaA[], int qtdA, Professor listaP[], int qtdP) {
    int mesBusca;
    int encontrou = 0;

    printf("\n--- BUSCA DE ANIVERSARIANTES ---\n");
    printf("Digite o numero do mes (1-12): ");
    scanf("%d", &mesBusca);

    if (mesBusca < 1 || mesBusca > 12) {
        printf("Mes invalido!\n");
        return;
    }

    printf("\n=== ANIVERSARIANTES DO MES %02d ===\n", mesBusca);

    printf("\n[ALUNOS]\n");
    for (int i = 0; i < qtdA; i++) {
        if (listaA[i].ativo == 1 && listaA[i].data_nascimento.mes == mesBusca) {
            printf("Dia %02d - %s\n", listaA[i].data_nascimento.dia, listaA[i].nome);
            encontrou = 1;
        }
    }

    printf("\n[PROFESSORES]\n");
    for (int i = 0; i < qtdP; i++) {
        if (listaP[i].ativo == 1 && listaP[i].data_nascimento.mes == mesBusca) {
            printf("Dia %02d - %s\n", listaP[i].data_nascimento.dia, listaP[i].nome);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("\nNenhum aniversariante encontrado neste mes.\n");
    }
    printf("==================================\n");
}

void buscarPessoaPorNome(Aluno listaA[], int qtdA, Professor listaP[], int qtdP) {
    char busca[50];
    int encontrou = 0;

    printf("\n--- BUSCA POR NOME ---\n");
    printf("Digite pelo menos 3 letras para pesquisar: ");
    scanf(" %s", busca);
    limparBuffer();

    if (strlen(busca) < 3) {
        printf("Erro: Digite no minimo 3 caracteres para a busca.\n");
        return;
    }

    printf("\nResultados da busca por: \"%s\"\n", busca);

    printf("\n[ALUNOS ENCONTRADOS]\n");
    for (int i = 0; i < qtdA; i++) {
        if (listaA[i].ativo == 1) {
            // strstr retorna um ponteiro se achar a string, ou NULL se não achar
            if (strstr(listaA[i].nome, busca) != NULL) {
                printf("- %s (Mat: %d)\n", listaA[i].nome, listaA[i].matricula);
                encontrou = 1;
            }
        }
    }

    printf("\n[PROFESSORES ENCONTRADOS]\n");
    for (int i = 0; i < qtdP; i++) {
        if (listaP[i].ativo == 1) {
            if (strstr(listaP[i].nome, busca) != NULL) {
                printf("- %s (Mat: %d)\n", listaP[i].nome, listaP[i].matricula);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("\nNenhuma pessoa encontrada com o termo \"%s\".\n", busca);
    }
    printf("------------------------------------\n");
}

void delay(int ms) {
    usleep(ms * 1000);
}

void gatoPiscando() {
    for (int i = 0; i < 10; i++) { // número de piscadas
        // Limpa a tela
        printf("\033[2J\033[H");

        // Olhos abertos
        printf("   /\\_/\\\n");
        printf("  ( o.o )\n");
        printf("   > ^ <\n");

        delay(500);

        // Limpa a tela
        printf("\033[2J\033[H");

        // Olhos fechados
        printf("   /\\_/\\\n");
        printf("  ( -.- )\n");
        printf("   > ^ <\n");

        delay(200);
    }
}