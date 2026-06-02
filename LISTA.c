#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Nodo* iniciarLista() {
    return NULL;
}

int estaVazia(Nodo* sequencia) {
    return (sequencia == NULL);
}

void adicionarInicio(Nodo** sequencia, int numero) {
    Nodo* novoElemento = (Nodo*)malloc(sizeof(Nodo));

    novoElemento->valor = numero;
    novoElemento->prox = *sequencia;

    *sequencia = novoElemento;
}

void adicionarFinal(Nodo** sequencia, int numero) {
    Nodo* novoElemento = (Nodo*)malloc(sizeof(Nodo));

    novoElemento->valor = numero;
    novoElemento->prox = NULL;

    if (*sequencia == NULL) {
        *sequencia = novoElemento;
        return;
    }

    Nodo* cursor = *sequencia;

    while (cursor->prox != NULL) {
        cursor = cursor->prox;
    }

    cursor->prox = novoElemento;
}

void exibirLista(Nodo* sequencia) {
    if (estaVazia(sequencia)) {
        return;
    }

    Nodo* cursor = sequencia;


    while (cursor != NULL) {
        cursor = cursor->prox;
    }

}

void destruirLista(Nodo** sequencia) {
    Nodo* cursor = *sequencia;

    while (cursor != NULL) {
        Nodo* proximoItem = cursor;

        cursor = cursor->prox;

        free(proximoItem);
    }

    *sequencia = NULL;
}

int obterMenor(Nodo* sequencia) {
    if (estaVazia(sequencia)) {
        return -1;
    }

    int menorValor = sequencia->valor;

    Nodo* cursor = sequencia->prox;

    while (cursor != NULL) {
        if (cursor->valor < menorValor) {
            menorValor = cursor->valor;
        }

        cursor = cursor->prox;
    }

    return menorValor;
}

int obterMaior(Nodo* sequencia) {
    if (estaVazia(sequencia)) {
        return -1;
    }

    int maiorValor = sequencia->valor;

    Nodo* cursor = sequencia->prox;

    while (cursor != NULL) {
        if (cursor->valor > maiorValor) {
            maiorValor = cursor->valor;
        }

        cursor = cursor->prox;
    }

    return maiorValor;
}

int calcularMedia(Nodo* sequencia) {
    if (estaVazia(sequencia)) {
        return 0;
    }

    int acumulador = 0;
    int quantidadeItens = 0;

    Nodo* cursor = sequencia;

    while (cursor != NULL) {
        acumulador += cursor->valor;
        quantidadeItens++;

        cursor = cursor->prox;
    }

    return acumulador / quantidadeItens;
}

int quantidadeElementos(Nodo* sequencia) {
    int contador = 0;

    Nodo* cursor = sequencia;

    while (cursor != NULL) {
        contador++;
        cursor = cursor->prox;
    }

    return contador;
}

Nodo* concatenarListas(Nodo* listaA, Nodo* listaB) {
    Nodo* listaResultado = NULL;

    Nodo* cursor = listaA;

    while (cursor != NULL) {
        adicionarFinal(&listaResultado, cursor->valor);
        cursor = cursor->prox;
    }

    cursor = listaB;

    while (cursor != NULL) {
        adicionarFinal(&listaResultado, cursor->valor);
        cursor = cursor->prox;
    }

    return listaResultado;
}


Nodo* inverterLista(Nodo* sequencia) {
    Nodo* listaInvertida = NULL;

    Nodo* cursor = sequencia;

    while (cursor != NULL) {
        adicionarInicio(&listaInvertida, cursor->valor);
        cursor = cursor->prox;
    }

    return listaInvertida;
}

int compararInicio(Nodo* listaPrincipal, Nodo* listaComparacao) {
    Nodo* cursorPrincipal = listaPrincipal;
    Nodo* cursorComparacao = listaComparacao;

    while (cursorComparacao != NULL) {

        if (cursorPrincipal == NULL) {
            return 0;
        }

        if (cursorPrincipal->valor != cursorComparacao->valor) {
            return 0;
        }

        cursorPrincipal = cursorPrincipal->prox;
        cursorComparacao = cursorComparacao->prox;
    }

    return 1;
}

int verificarSubLista(Nodo* listaPrincipal, Nodo* listaComparacao) {

    if (listaComparacao == NULL) {
        return 1;
    }

    if (listaPrincipal == NULL) {
        return 0;
    }

    Nodo* cursor = listaPrincipal;

    while (cursor != NULL) {

        if (compararInicio(cursor, listaComparacao)) {
            return 1;
        }

        cursor = cursor->prox;
    }

    return 0;
}
