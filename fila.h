#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
  link prev;
};

typedef struct {
  link primeiro;
  link ultimo;
} * FILA;

link novoNo(int item, link next, link prev);
FILA novaFila();

void insereDepois(FILA f, int e);
int removeDepois(FILA f);

void insereAntes(FILA f, int e);
int removeAntes(FILA f);

void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f);

#endif
