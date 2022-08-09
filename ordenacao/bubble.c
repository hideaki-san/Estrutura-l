#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {
  float tempo;
  time_t inicio, fim;

  inicio = clock();

  //size define o tamanho do vetor

  int size = 100000, c = 0;
  int *vetor =(int *) malloc(size * sizeof(int));
  
  //printf("SEM ORDENACAO: ");
  while(c < size)
    {
    *(vetor + c) = rand() % 100000;
    //printf("[%d] ", *(vetor + c));
    c++;
    }
  
  //printf("\nCOM ORDENACAO: ");
  bubble(vetor, size);
  //printVetor(vetor, size);

  fim = clock();
  tempo = ((float)(fim - inicio) / CLOCKS_PER_SEC);

  printf("\n\nTEMPO DE EXECUCAO: %f(s)", tempo);

  free(vetor);
  vetor = NULL;

  return 0;
  }