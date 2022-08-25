#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
int size = 10;
int inicio = 0, fim = (size - 1);

int *vet =(int *)malloc(size * sizeof(int));

for(int n = 0; n < size; n++)
  *(vet + n) = rand() % 100;

printVetor(vet, size);
quicksort(vet, inicio, fim);
printf("\n");
printVetor(vet, size);

free(vet);
vet = NULL;
return 0;
}