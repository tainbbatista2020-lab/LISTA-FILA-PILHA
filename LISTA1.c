#ifndef LISTA_H
#define LISTA_H

typedef struct Celula {
    int dado;
    struct Celula* proximo;
} Celula;

Celula* criarLista();

int listaVazia(Celula* sequencia);

void inserirInicio(Celula** sequencia, int numero);
void inserirFim(Celula** sequencia, int numero);

void mostrarLista(Celula* sequencia);
void liberarLista(Celula** sequencia);

int maxLista(Celula* sequencia);
int minLista(Celula* sequencia);
int mediaLista(Celula* sequencia);
int lenLista(Celula* sequencia);

Celula* appendLista(Celula* listaPrincipal, Celula* listaAuxiliar);
Celula* reverseLista(Celula* sequencia);
int isSubLista(Celula* listaPrincipal, Celula* listaAuxiliar);

#endif
