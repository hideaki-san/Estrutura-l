#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {
  int size = 1000, c = 0;
  vetor *vet = vetorCriar(size);

  for(c; c < size; c++)
    {
    float valor = rand() % size;
    vetorInserir(vet, valor);
    }
  
  selection(vet, size);
  vetorImprimir(vet);
  vetorExcluir(vet);


  return 0;
  }