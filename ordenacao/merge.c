#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
FILE *arq;

time_t merg_init, merg_end;
float merg_tempo;
dados *merge_inf;
merge_inf = dadosCriar();

int size = 10000; 
int inicio = 0, fim = (size - 1);

arq = fopen("dados_execucao.csv", "a");

int *merge_vetor =(int *)malloc(size * sizeof(int));

for(int g=0; g < size; g++)
  *(merge_vetor + g) = rand() % 1000;

merg_init = clock();
mergesort(merge_vetor, inicio, fim, merge_inf);
merg_end = clock();
merg_tempo = ((float)(merg_end - merg_init) / CLOCKS_PER_SEC);

dadosPrint(merge_inf, arq, merg_tempo, size);

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", merg_tempo);

free(merge_vetor);
dadosLiberar(merge_inf);

merge_vetor = NULL;

return 0;
}