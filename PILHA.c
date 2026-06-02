#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


void iniciarPilha(Pilha *estrutura)
{
    estrutura->topo = NULL;
}

int estaVazia(Pilha *estrutura)
{
    return (estrutura->topo == NULL);
}


void inserirTopo(Pilha *estrutura, int numero)
{
    Nodo *novoItem = (Nodo *)malloc(sizeof(Nodo));

    novoItem->valor = numero;
    novoItem->prox = estrutura->topo;

    estrutura->topo = novoItem;
}

int removerTopo(Pilha *estrutura)
{
    if (estaVazia(estrutura))
    {
        return -1;
    }

    Nodo *itemAtual = estrutura->topo;

    int conteudo = itemAtual->valor;

    estrutura->topo = itemAtual->prox;

    free(itemAtual);

    return conteudo;
}


void exibirPilha(Pilha *estrutura)
{
    if (estaVazia(estrutura))
    {
        return;
    }

    Nodo *cursor = estrutura->topo;


    while (cursor != NULL)
    {
        cursor = cursor->prox;
    }

}


void destruirPilha(Pilha *estrutura)
{
    while (!estaVazia(estrutura))
    {
        removerTopo(estrutura);
    }
}

int localizarValor(Pilha *estrutura, int procurado)
{
    Nodo *cursor = estrutura->topo;
    int indice = 0;

    while (cursor != NULL)
    {
        if (cursor->valor == procurado)
        {
            return indice;
        }

        cursor = cursor->prox;
        indice++;
    }

    return -1;
}

int excluirValor(Pilha *estrutura, int procurado)
{
    Pilha pilhaTemporaria;
    iniciarPilha(&pilhaTemporaria);

    int encontrado = 0;

    while (!estaVazia(estrutura))
    {
        int numeroAtual = removerTopo(estrutura);

        if (numeroAtual == procurado && !encontrado)
        {
            encontrado = 1;
        }
        else
        {
            inserirTopo(&pilhaTemporaria, numeroAtual);
        }
    }

    while (!estaVazia(&pilhaTemporaria))
    {
        inserirTopo(estrutura, removerTopo(&pilhaTemporaria));
    }

    destruirPilha(&pilhaTemporaria);

    return encontrado;
}


void excluirPares(Pilha *estrutura)
{
    Pilha pilhaTemporaria;
    iniciarPilha(&pilhaTemporaria);

    while (!estaVazia(estrutura))
    {
        int numeroAtual = removerTopo(estrutura);

        if (numeroAtual % 2 != 0)
        {
            inserirTopo(&pilhaTemporaria, numeroAtual);
        }
    }

    while (!estaVazia(&pilhaTemporaria))
    {
        inserirTopo(estrutura, removerTopo(&pilhaTemporaria));
    }

    destruirPilha(&pilhaTemporaria);
}


void eliminarDuplicados(Pilha *estrutura)
{
    Pilha pilhaTemporaria;
    iniciarPilha(&pilhaTemporaria);

    while (!estaVazia(estrutura))
    {
        int numeroAtual = removerTopo(estrutura);

        int duplicado = 0;

        Nodo *cursor = pilhaTemporaria.topo;

        while (cursor != NULL)
        {
            if (cursor->valor == numeroAtual)
            {
                duplicado = 1;
                break;
            }

            cursor = cursor->prox;
        }

        if (!duplicado)
        {
            inserirTopo(&pilhaTemporaria, numeroAtual);
        }
    }

    while (!estaVazia(&pilhaTemporaria))
    {
        inserirTopo(estrutura, removerTopo(&pilhaTemporaria));
    }

    destruirPilha(&pilhaTemporaria);
}
