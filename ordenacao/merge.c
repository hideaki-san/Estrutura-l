#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
time_t merg_init, merg_end;
float merg_tempo;

int size = 10000000; 
int inicio = 0, fim = (size - 1);
vetor *vet = vetorCriar(size);

for(int c = 0; c < size; c++)
  {
  float valor = rand() % size;
  vetorInserir(vet, valor);
  }

dados *merge_inf;
merge_inf = dadosCriar();

merg_init = clock();
mergesort(vet, inicio, fim, merge_inf);
merg_end = clock();
merg_tempo = ((float)(merg_end - merg_init) / CLOCKS_PER_SEC);

dadosPrint(merge_inf, merg_tempo, size);

vetorExcluir(vet);
dadosLiberar(merge_inf);

return 0;
}