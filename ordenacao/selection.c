#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {
  float tempo;
  time_t inicio, fim;

  inicio = clock();

//SIZE DEFINE O TAMANHO DO VETOR A SER ALOCADO

  int size = 10, c = 0;
  int *vetor =(int *) malloc(size * sizeof(int));
  
  printf("SEM ORDENACAO: ");
  while(c < size)
    {
    *(vetor + c) = rand() % 10;
    printf("[%d] ", *(vetor + c));
    c++;
    }
  
  selection(vetor, size);
  printf("\nCOM ORDENACAO: ");
  printVetor(vetor, size);

  fim = clock();
  tempo = ((float)(fim - inicio) / CLOCKS_PER_SEC);

  printf("\n\nTEMPO DE EXECUCAO: %f(s)", tempo);

  free(vetor);
  vetor = NULL;

  return 0;
  }