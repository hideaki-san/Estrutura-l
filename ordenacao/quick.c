#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
FILE *arq;

time_t quick_inicio, quick_final;
float quick_tempo;

arq = fopen("dados_execucao.csv", "a");

dados *quick_info;
quick_info = dadosCriar();

int size = 1000000;
int inicio = 0, fim = (size - 1);

int *vet =(int *)malloc(size * sizeof(int));

for(int n = 0; n < size; n++)
  *(vet + n) = rand() % 10000;

quick_inicio = clock();
quicksort(vet, inicio, fim, quick_info);
quick_final = clock();
quick_tempo = ((float)(quick_final - quick_inicio) / CLOCKS_PER_SEC);

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", quick_tempo);


dadosPrint(quick_info, arq, quick_tempo, size);

free(vet);
dadosLiberar(quick_info);

vet = NULL;
return 0;
}