#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
time_t quick_init, quick_end;
float quick_tempo;

int size = 1000000;
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

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", quick_tempo);

FILE *arq;
arq = fopen("dados_execucao.csv", "a");

fprintf(arq,"\nQUICK ;");
dadosPrint(quick_info, arq, quick_tempo, size);

vetorExcluir(vet);
dadosLiberar(quick_info);
fclose(arq);

return 0;
}