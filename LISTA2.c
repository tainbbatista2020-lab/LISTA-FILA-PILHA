#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {

    Nodo* listaPrincipal = criarLista();
    Nodo* listaSecundaria = criarLista();
    Nodo* listaTesteA = NULL;
    Nodo* listaTesteB = NULL;
    Nodo* listaUnificada = NULL;
    Nodo* listaInvertida = NULL;

    int retornoVerificacao;


    inserirFim(&listaPrincipal, 10);
    inserirFim(&listaPrincipal, 5);
    inserirFim(&listaPrincipal, 30);
    inserirFim(&listaPrincipal, 20);
    inserirFim(&listaPrincipal, 15);

    mostrarLista(listaPrincipal);

    inserirFim(&listaSecundaria, 100);
    inserirFim(&listaSecundaria, 200);

    mostrarLista(listaPrincipal);

    mostrarLista(listaSecundaria);

    listaUnificada = appendLista(listaPrincipal, listaSecundaria);

    mostrarLista(listaUnificada);

    listaInvertida = reverseLista(listaPrincipal);

    mostrarLista(listaPrincipal);

    mostrarLista(listaInvertida);


    inserirFim(&listaTesteA, 5);
    inserirFim(&listaTesteA, 30);
    inserirFim(&listaTesteA, 20);

    inserirFim(&listaTesteB, 30);
    inserirFim(&listaTesteB, 20);
    inserirFim(&listaTesteB, 15);

    mostrarLista(listaPrincipal);

    mostrarLista(listaTesteA);

    mostrarLista(listaTesteB);

    retornoVerificacao = isSubLista(listaPrincipal, listaTesteA);

    retornoVerificacao = isSubLista(listaPrincipal, listaTesteB);


    liberarLista(&listaPrincipal);
    liberarLista(&listaSecundaria);
    liberarLista(&listaTesteA);
    liberarLista(&listaTesteB);
    liberarLista(&listaUnificada);
    liberarLista(&listaInvertida);


    return 0;
}
