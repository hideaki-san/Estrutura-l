#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {
  FILE *arq;
  
  arq = fopen("dados_execucao.csv", "a");

  int size = 100, c = 0;
  int *vetor =(int *) malloc(size * sizeof(int));

  while(c < size)
    {
    *(vetor + c) = rand() % 1000;
    c++;
    }

  bubble(vetor, size, arq); 

  free(vetor);
  vetor = NULL;

  return 0;
  }