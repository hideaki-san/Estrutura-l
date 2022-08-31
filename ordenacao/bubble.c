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

  FILE *arq;
  arq = fopen("dados_execucao.csv", "a");

  bubble(vet, size, arq); 

  vetorExcluir(vet);
  fclose(arq);

  return 0;
  }