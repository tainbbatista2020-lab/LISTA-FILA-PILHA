#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializarFila(ListaFila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int estaVazia(ListaFila *fila)
{
    return (fila->primeiro == NULL);
}

void inserirElemento(ListaFila *fila, int numero)
{
    Celula *novoNo = (Celula *)malloc(sizeof(Celula));

    if (novoNo == NULL)
    {
        printf("Falha na alocacao de memoria.\n");
        return;
    }

    novoNo->dado = numero;
    novoNo->proximo = NULL;

    if (estaVazia(fila))
    {
        fila->primeiro = novoNo;
    }
    else
    {
        fila->ultimo->proximo = novoNo;
    }

    fila->ultimo = novoNo;
}

int retirarElemento(ListaFila *fila)
{
    if (estaVazia(fila))
    {
        printf("Estrutura vazia.\n");
        return -1;
    }

    Celula *temporario = fila->primeiro;
    int conteudo = temporario->dado;

    fila->primeiro = temporario->proximo;

    if (fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }

    free(temporario);

    return conteudo;
}
void exibirFila(ListaFila *fila)
{
    if (estaVazia(fila))
    {
        printf("Nenhum elemento encontrado.\n");
        return;
    }

    Celula *atual = fila->primeiro;

    printf("Conteudo da fila: ");

    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }

    printf("\n");
}

void destruirFila(ListaFila *fila)
{
    while (!estaVazia(fila))
    {
        retirarElemento(fila);
    }
}

void localizarEAlterar(ListaFila *fila, int valorProcurado, int novoValor)
{
    Celula *cursor = fila->primeiro;
    int encontrado = 0;

    while (cursor != NULL)
    {
        if (cursor->dado == valorProcurado)
        {
            cursor->dado = novoValor;
            encontrado = 1;
        }

        cursor = cursor->proximo;
    }

    if (encontrado)
    {
        printf("Valor atualizado com sucesso.\n");
    }
    else
    {
        printf("Valor nao localizado.\n");
    }
}

int localizarERemover(ListaFila *fila, int numeroDesejado)
{
    ListaFila auxiliar;
    inicializarFila(&auxiliar);

    int removido = 0;

    while (!estaVazia(fila))
    {
        int itemAtual = retirarElemento(fila);

        if (itemAtual == numeroDesejado && !removido)
        {
            removido = 1;
        }
        else
        {
            inserirElemento(&auxiliar, itemAtual);
        }
    }

    while (!estaVazia(&auxiliar))
    {
        inserirElemento(fila, retirarElemento(&auxiliar));
    }

    destruirFila(&auxiliar);

    return removido;
}
void eliminarDuplicados(ListaFila *fila)
{
    ListaFila apoio;
    inicializarFila(&apoio);

    while (!estaVazia(fila))
    {
        int valorAtual = retirarElemento(fila);

        int existe = 0;

        Celula *verificador = apoio.primeiro;

        while (verificador != NULL)
        {
            if (verificador->dado == valorAtual)
            {
                existe = 1;
                break;
            }

            verificador = verificador->proximo;
        }

        if (!existe)
        {
            inserirElemento(&apoio, valorAtual);
        }
    }

    while (!estaVazia(&apoio))
    {
        inserirElemento(fila, retirarElemento(&apoio));
    }

    destruirFila(&apoio);
}

void removerNumerosPares(ListaFila *fila)
{
    ListaFila apoio;
    inicializarFila(&apoio);

    while (!estaVazia(fila))
    {
        int valorAtual = retirarElemento(fila);

        if (valorAtual % 2 != 0)
        {
            inserirElemento(&apoio, valorAtual);
        }
    }

    while (!estaVazia(&apoio))
    {
        inserirElemento(fila, retirarElemento(&apoio));
    }

    destruirFila(&apoio);
}
