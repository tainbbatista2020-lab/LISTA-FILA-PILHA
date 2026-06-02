#ifndef FILA_H
#define FILA_H

typedef struct Elemento {
    int numero;
    struct Elemento* proximo;
} Elemento;

typedef struct {
    Elemento* primeiro;
    Elemento* ultimo;
} EstruturaFila;

void criarFila(EstruturaFila* fila);
int filaVazia(EstruturaFila* fila);
void enfileirar(EstruturaFila* fila, int numero);
int desenfileirar(EstruturaFila* fila);
void mostrarFila(EstruturaFila* fila);
void liberarFila(EstruturaFila* fila);

void buscarEEditar(EstruturaFila* fila, int numeroAntigo, int numeroNovo);
int buscarERemoverFila(EstruturaFila* fila, int numero);

void removerRepeticoes(EstruturaFila* fila);
void removerParesFila(EstruturaFila* fila);

#endif
