#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main() {
    Fila filaPrincipal;
    Fila filaAuxiliar;
    int retornoBusca;

    criarFila(&filaPrincipal);

    enfileirar(&filaPrincipal, 10);
    enfileirar(&filaPrincipal, 20);
    enfileirar(&filaPrincipal, 30);
    enfileirar(&filaPrincipal, 40);
    enfileirar(&filaPrincipal, 50);

    mostrarFila(&filaPrincipal);

    mostrarFila(&filaPrincipal);

    buscarEEditar(&filaPrincipal, 20, 25);

    mostrarFila(&filaPrincipal);

    mostrarFila(&filaPrincipal);

    retornoBusca = buscarERemoverFila(&filaPrincipal, 30);


    mostrarFila(&filaPrincipal);

    criarFila(&filaAuxiliar);

    enfileirar(&filaAuxiliar, 10);
    enfileirar(&filaAuxiliar, 20);
    enfileirar(&filaAuxiliar, 10);
    enfileirar(&filaAuxiliar, 30);
    enfileirar(&filaAuxiliar, 20);
    enfileirar(&filaAuxiliar, 40);

    mostrarFila(&filaAuxiliar);

    removerRepeticoes(&filaAuxiliar);

    mostrarFila(&filaAuxiliar);

    criarFila(&filaAuxiliar);

    enfileirar(&filaAuxiliar, 1);
    enfileirar(&filaAuxiliar, 2);
    enfileirar(&filaAuxiliar, 3);
    enfileirar(&filaAuxiliar, 4);
    enfileirar(&filaAuxiliar, 5);
    enfileirar(&filaAuxiliar, 6);

    mostrarFila(&filaAuxiliar);

    removerParesFila(&filaAuxiliar);

    mostrarFila(&filaAuxiliar);

    liberarFila(&filaPrincipal);
    liberarFila(&filaAuxiliar);


    return 0;
}
