#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

int vetorPrincipal[TAM];

typedef struct {
    int *vetor;
    int tamanho;
    int qtd;
} EstruturaAuxiliar;

EstruturaAuxiliar estruturas[TAM];

int ehPosicaoValida(int posicao);
void ordenarVetor(int vetor[], int tamanho);

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    if (tamanho < 1)
        return TAMANHO_INVALIDO;

    if (estruturas[posicao - 1].vetor != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    estruturas[posicao - 1].vetor = (int *)malloc(sizeof(int) * tamanho);

    if (estruturas[posicao - 1].vetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    estruturas[posicao - 1].tamanho = tamanho;
    estruturas[posicao - 1].qtd = 0;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *aux = &estruturas[posicao - 1];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (aux->qtd >= aux->tamanho)
        return SEM_ESPACO;

    aux->vetor[aux->qtd] = valor;
    aux->qtd++;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *aux = &estruturas[posicao - 1];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (aux->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    aux->qtd--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *aux = &estruturas[posicao - 1];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (aux->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int indice = -1;

    for (int i = 0; i < aux->qtd; i++)
    {
        if (aux->vetor[i] == valor)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
        return NUMERO_INEXISTENTE;

    for (int i = indice; i < aux->qtd - 1; i++)
    {
        aux->vetor[i] = aux->vetor[i + 1];
    }

    aux->qtd--;

    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

void ordenarVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *aux = &estruturas[posicao - 1];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < aux->qtd; i++)
        vetorAux[i] = aux->vetor[i];

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

    if (retorno != SUCESSO)
        return retorno;

    ordenarVetor(vetorAux, estruturas[posicao - 1].qtd);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int indice = 0;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < estruturas[i].qtd; j++)
        {
            vetorAux[indice++] = estruturas[i].vetor[j];
        }
    }

    if (indice == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if (retorno != SUCESSO)
        return retorno;

    int total = 0;

    for (int i = 0; i < TAM; i++)
        total += estruturas[i].qtd;

    ordenarVetor(vetorAux, total);

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *aux = &estruturas[posicao - 1];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int novoTam = aux->tamanho + novoTamanho;

    if (novoTam < 1)
        return NOVO_TAMANHO_INVALIDO;

    if (aux->qtd > novoTam)
        aux->qtd = novoTam;

    int *novo = realloc(aux->vetor, sizeof(int) * novoTam);

    if (novo == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    aux->vetor = novo;
    aux->tamanho = novoTam;

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *aux = &estruturas[posicao - 1];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (aux->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return aux->qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cabeca = (No *)malloc(sizeof(No));

    if (cabeca == NULL)
        return NULL;

    cabeca->prox = NULL;

    No *fim = cabeca;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < estruturas[i].qtd; j++)
        {
            No *novo = (No *)malloc(sizeof(No));

            if (novo == NULL)
            {
                destruirListaEncadeadaComCabecote(&cabeca);
                return NULL;
            }

            novo->conteudo = estruturas[i].vetor[j];
            novo->prox = NULL;

            fim->prox = novo;
            fim = novo;
        }
    }

    if (cabeca->prox == NULL)
    {
        free(cabeca);
        return NULL;
    }

    return cabeca;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    if (inicio == NULL)
        return;

    No *aux = inicio->prox;

    int i = 0;

    while (aux != NULL)
    {
        vetorAux[i++] = aux->conteudo;
        aux = aux->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (inicio == NULL || *inicio == NULL)
        return;

    No *aux = *inicio;

    while (aux != NULL)
    {
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    *inicio = NULL;
}

void dobrar(int *x)
{
    *x *= 2;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i] = 0;
        estruturas[i].vetor = NULL;
        estruturas[i].tamanho = 0;
        estruturas[i].qtd = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 0; i < TAM; i++)
    {
        if (estruturas[i].vetor != NULL)
        {
            free(estruturas[i].vetor);
            estruturas[i].vetor = NULL;
        }

        estruturas[i].tamanho = 0;
        estruturas[i].qtd = 0;
    }
}