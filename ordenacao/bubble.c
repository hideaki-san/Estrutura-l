#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {
  FILE *arq;
  
  arq = fopen("dados_tempo_execucao.txt", "a");
  
  int size = 1000000, c = 0;
  int *vetor =(int *) malloc(size * sizeof(int));
  
  fprintf(arq,"\n[TAMANHO DO VETOR: %d]\n", size);

  while(c < size)
    {
    *(vetor + c) = rand() % 10;
    c++;
    }

  bubble(vetor, size, arq); 

  free(vetor);
  vetor = NULL;

  return 0;
  }