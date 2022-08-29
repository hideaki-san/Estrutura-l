#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
time_t quick_inicio, quick_final;
float quick_tempo;

dados *quick_info;
quick_info = dadosCriar();

int size = 699999;
int inicio = 0, fim = (size - 1);

int *vet =(int *)malloc(size * sizeof(int));

for(int n = 0; n < size; n++)
  *(vet + n) = rand() % size;

quick_inicio = clock();
quicksort(vet, inicio, fim, quick_info);
quick_final = clock();
quick_tempo = ((float)(quick_final - quick_inicio) / CLOCKS_PER_SEC);

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", quick_tempo);

//FILE *arq;
//arq = fopen("dados_execucao.csv", "a");

//fprintf(arq,"QUICK ;");
//dadosPrint(quick_info, arq, quick_tempo, size);

free(vet);
dadosLiberar(quick_info);
//fclose(arq);

vet = NULL;
return 0;
}