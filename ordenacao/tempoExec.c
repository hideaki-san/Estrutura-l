#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"

int main()
{
int size = 10000; 
    
int *bub_vetor =(int *)malloc(size * sizeof(int));
int *sel_vetor =(int *)malloc(size * sizeof(int));

bubble(bub_vetor, size);
selection(sel_vetor, size);

free(bub_vetor);
free(sel_vetor);

bub_vetor = NULL;
sel_vetor = NULL;

return 0;
}