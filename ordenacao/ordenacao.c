#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"

void swap(int *p, int *q)
  {
  int aux = *p;
  *p = *q;
  *q = aux;
  }

void bubble(int *vetor, int size)
  {
  for(int n = 0; n < size - 1; n++)
    {
    for(int m = 0; m < size - 1; m++)
      {
      if(vetor[m] > vetor[m + 1])
        {
        swap(&vetor[m], &vetor[m + 1]);
        }
      }
    }
  }

void selection(int *vetor, int size)
  {
  for(int n = 0; n < size; n++)
    {
    int menor = n;
    for(int m = menor; m < size; m++)
      {
      if(vetor[m] < vetor[menor])
        {
        menor = m;  
        }
      }
    swap((vetor + n), (vetor + menor));
    }
  }

void printVetor(const int *vetor, int size)
  {
  for(int n = 0; n < size; n++)
    {
    printf("[%d] ", *(vetor + n));
    }
  }
