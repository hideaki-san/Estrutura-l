#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {
  FILE *arq;
  
  arq = fopen("dados_tempo_execucao.txt", "a");

//SIZE DEFINE O TAMANHO DO VETOR A SER ALOCADO
  int size = 1000000, c = 0;
  int *vetor =(int *) malloc(size * sizeof(int));

  while(c < size)
    {
    *(vetor + c) = rand() % 10;
    c++;
    }

  selection(vetor, size, arq);

  free(vetor);
  vetor = NULL;

  return 0;
  }