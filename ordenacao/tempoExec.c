#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"

int main()
{
FILE *arq;
int size = 10000; 
int merg, i = 0, f = 0;

arq = fopen("dados_tempo_execucao.txt", "a"); 

int *bub_vetor =(int *)malloc(size * sizeof(int));
int *sel_vetor =(int *)malloc(size * sizeof(int));
int *merge_vetor =(int *)malloc(size * sizeof(int));

bubble(bub_vetor, size, arq);
selection(sel_vetor, size, arq);
merg = mergesort(merge_vetor, i, f);


free(bub_vetor);
free(sel_vetor);
free(merge_vetor);

bub_vetor = NULL;
sel_vetor = NULL;
merge_vetor = NULL;

return 0;
}