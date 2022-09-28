#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
time_t quick_init, quick_end;
float quick_tempo;

int size = 10000;
int inicio = 0, fim = (size - 1);
vetor *vet = vetorCriar(size);

for(int c = 0; c < size; c++)
  {
  float valor = rand() % size;
  vetorInserir(vet, valor);
  }

dados *quick_info;
quick_info = dadosCriar();

quick_init = clock();
quicksort(vet, inicio, fim, quick_info);
quick_end = clock();
quick_tempo = ((float)(quick_end - quick_init) / CLOCKS_PER_SEC);

dadosPrint(quick_info, quick_tempo, size);

vetorExcluir(vet);
dadosLiberar(quick_info);

return 0;
}