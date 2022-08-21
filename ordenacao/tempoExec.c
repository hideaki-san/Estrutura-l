#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"

int main()
{
//FILE *arq;
int size = 10; 
int inicio = 0, fim = (size - 1);

//arq = fopen("dados_tempo_execucao.txt", "a"); 

//int *bub_vetor =(int *)malloc(size * sizeof(int));
//int *sel_vetor =(int *)malloc(size * sizeof(int));
int *merge_vetor =(int *)malloc(size * sizeof(int));

for(int g=0; g < size; g++)
  *(merge_vetor + g) = rand() % 20;

printVetor(merge_vetor, size);
  
//bubble(bub_vetor, size, arq);
//selection(sel_vetor, size, arq);
mergesort(merge_vetor, inicio, fim);


//free(bub_vetor);
//free(sel_vetor);
free(merge_vetor);

//bub_vetor = NULL;
//sel_vetor = NULL;
merge_vetor = NULL;

return 0;
}