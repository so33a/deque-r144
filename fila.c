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
  t->prev = prev;
  
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->last = f->first = NULL;
  return f;
}

void inserir(FILA f, int e) {
  if(f->first == NULL) {
    f->first = f->last = novoNo(e, NULL, NULL);
  } else {
    f->last->next = novoNo(e, NULL, f->last);
    f->last = f->last->next;
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->first->item;
  t = f->first;
  f->first = f->first->next;
  if(f->first == NULL)
    f->last = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->last == NULL) || (f->first == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->first; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}
int removerBack(FILA f)
{
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  x = f->last->item;
  t = f->last;
  f->last = f->last->prev;
  
  if(f->last == NULL){
    f->last = NULL;
  }
  free(t);
  
}
void InsereFront(FILA f, e)
{
  if(f->last == NULL) {
    f->last = f->first = novoNo(e, NULL, NULL);
  } else {
    f->first->prev = novoNo(e, NULL, f->first);
    f->first = f->first->prev;
  }
}

