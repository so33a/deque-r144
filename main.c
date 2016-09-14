#include <stdio.h>
#include "fila.h"
#include "fila.c"

int main () {
  FILA alunos = novaFila();
  insereDepois(alunos, 9);
  insereDepois(alunos, 8);
  insereDepois(alunos, 3);
  insereDepois(alunos, 10);

  imprimirFila(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", removeAntes(alunos));

  printf ("---------------------\n\n");
  insereAntes(alunos, 10);
  insereAntes(alunos, 32);

  imprimirFila(alunos);

   while(!filaVazia(alunos))
    printf ("removido: %d \n", removeDepois(alunos));

  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
