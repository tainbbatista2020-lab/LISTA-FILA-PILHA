#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main() {

    Pilha pilhaPrincipal;
    Pilha pilhaAuxiliar;
    int retornoBusca;

    criarPilha(&pilhaPrincipal);


    empilhar(&pilhaPrincipal, 10);
    empilhar(&pilhaPrincipal, 20);
    empilhar(&pilhaPrincipal, 30);
    empilhar(&pilhaPrincipal, 40);
    empilhar(&pilhaPrincipal, 50);

    mostrarPilha(&pilhaPrincipal);

    retornoBusca = buscarElemento(&pilhaPrincipal, 30);
    printf("Buscar 30: posicao %d\n", retornoBusca);

    retornoBusca = buscarElemento(&pilhaPrincipal, 99);
    printf("Buscar 99: posicao %d\n", retornoBusca);

    mostrarPilha(&pilhaPrincipal);

    retornoBusca = buscarERemover(&pilhaPrincipal, 30);


    mostrarPilha(&pilhaPrincipal);

    criarPilha(&pilhaAuxiliar);

    empilhar(&pilhaAuxiliar, 1);
    empilhar(&pilhaAuxiliar, 2);
    empilhar(&pilhaAuxiliar, 3);
    empilhar(&pilhaAuxiliar, 4);
    empilhar(&pilhaAuxiliar, 5);
    empilhar(&pilhaAuxiliar, 6);

    mostrarPilha(&pilhaAuxiliar);

    removerPares(&pilhaAuxiliar);

    mostrarPilha(&pilhaAuxiliar);

    criarPilha(&pilhaAuxiliar);

    empilhar(&pilhaAuxiliar, 10);
    empilhar(&pilhaAuxiliar, 20);
    empilhar(&pilhaAuxiliar, 10);
    empilhar(&pilhaAuxiliar, 30);
    empilhar(&pilhaAuxiliar, 20);
    empilhar(&pilhaAuxiliar, 40);

    mostrarPilha(&pilhaAuxiliar);

    removerRepetidos(&pilhaAuxiliar);

    mostrarPilha(&pilhaAuxiliar);

    liberarPilha(&pilhaPrincipal);
    liberarPilha(&pilhaAuxiliar);


    return 0;
}
