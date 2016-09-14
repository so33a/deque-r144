#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next, link prev) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->ultimo = f->primeiro = NULL;
  return f;
}
void insereDepois(FILA f, int e) {
  if(f->primeiro == NULL) {
    f->primeiro = f->ultimo = novoNo(e, NULL, NULL);
  } else {
    f->ultimo->next = novoNo(e, NULL, f->ultimo);
    f->ultimo = f->ultimo->next;
  }
}
void insereAntes(FILA f, int e) {
  if(f->ultimo == NULL) {
    f->ultimo = f->primeiro = novoNo(e, NULL, NULL);
  } else {
    f->primeiro->prev = novoNo(e, NULL, f->primeiro);
    f->primeiro = f->primeiro->prev;
  }
}

int removeDepois(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->ultimo->item;
  t = f->ultimo;
  f->ultimo = f->ultimo->prev;

  if(f->ultimo == NULL)
    f->primeiro = NULL;

  free(t);
  return x;
}
int removeAntes(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->primeiro->item;
  t = f->primeiro;
  f->primeiro = f->primeiro->next;

  if(f->primeiro == NULL)
    f->ultimo = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->ultimo == NULL) || (f->primeiro == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->primeiro; t != NULL; t = t->next)
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    removeAntes(f);
  free(f);
}
