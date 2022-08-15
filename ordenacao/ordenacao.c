#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>


void swap(int *p, int *q)
  {
  int aux = *p;
  *p = *q;
  *q = aux;
  }


void bubble(int *vetor, int size, FILE *arq)
  {
  time_t bub_init, bub_end;
  float bub_tempo;
  
  int troca = 0, varredura = 0, comparacao = 0;
  
  bub_init = clock();
  
    for(int c = 0; c < size; c++)
      *(vetor + c) = rand() % 10000;

//POSICAO DE COMPARACAO COM O VETOR
  for(int n = 0; n < size - 1; n++)
    {

//PERCORRE O VETOR SEMPRE COM UMA POSICAO A MENOS
//ULTIMA POSICAO DE TROCA JA ESTA COM O MAIOR MAIOR VALOR
    for(int m = 0; m < (size - (1 + n)); m++)
      {

//CASO SEJA MAIOR VALOR TROCA COM O PROXIMO
//NA ULTIMO POSICAO POSSIVEL FICARA O MAIOR NUMERO
      if(vetor[m] > vetor[m + 1])
        {
        swap(&vetor[m], &vetor[m + 1]);
        troca++;
        }
      comparacao++;
      }
    varredura++;
    }
  
  bub_end = clock();
  bub_tempo = ((float)(bub_end - bub_init) / CLOCKS_PER_SEC);

  fprintf(arq,"\n:BUBBLE: ");
  fprintf(arq,"\nTEMPO DE EXECUCAO: %f[s]", bub_tempo);
  fprintf(arq,"\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]\n", troca, comparacao, varredura);
  }


void selection(int *vetor, int size, FILE *arq)
  {
  time_t sel_init, sel_end;
  float sel_tempo;

  int troca = 0, varredura = 0, comparacao = 0;
  
  sel_init = clock();

  for(int c = 0; c < size; c++)
    *(vetor + c) = rand() % 10000;

  for(int n = 0; n < size; n++)
    {

//ARMAZENA A POSICAO QUE VAI SER COMPARADA COM O VETOR
    int menor = n;

//FAZ COMPARACAO DO VETOR COM A POSICAO ARMAZENADA NO MENOR
    for(int m = (menor + 1); m < size; m++)
      {

//CASO O VALOR DO VETOR QUE PERCORRE SEJA MENOR QUE O ARMAZENADO ANTERIOR
//A MENOR POSICAO(ARMAZENADA) ATUALIZA COM A POSICAO NOVA DE MENOR VALOR
      if(vetor[menor] > vetor[m])
        {
        menor = m;
        }
      comparacao++;
      }

//FAZ A TROCA DOS VALORES DE 'MENOR' ATUALIZADO E DA POSICAO(em ordem 'n') QUE SERA TROCADA
//CASO A REFERENCIA('n') SEJA A MESMA QUE O 'MENOR' NAO OCORRE TROCA
    if(n != menor)
      {
      swap((vetor + n), (vetor + menor));
      troca++; 
      }
    varredura++;
    }
  
  sel_end = clock();
  sel_tempo = ((float)(sel_end - sel_init) / CLOCKS_PER_SEC);
  
  fprintf(arq,"\n:SELECTION: ");
  fprintf(arq,"\nTEMPO DE EXECUCAO: %f[s]", sel_tempo);
  fprintf(arq,"\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]\n", troca, comparacao, varredura);
  }


void merge(int *vetor, int inicio, int meio, int fim)
  {
  int metade1 = meio - inicio + 1;//obs
  int metade2 = fim - meio;

  int *subVet1, *subVet2;
  
  for(int n = 0; n < metade1; n++)
    {
    *(subVet1 + n) = *(vetor + (inicio + n));
    }

  for(int n = 0; n < metade2; n++)
    {
    *(subVet2 + n) = *(vetor + (meio + 1));//obs
    }

  int i = 0, f = 0, z = 0;
  
  while(i < metade1 && f < metade2)
    {
    if(*(subVet1 + i) <= *(subVet2 + f))
      {
      *(vetor + z) = *(subVet1 + i);
      i++;
      }
    else
      {
      *(vetor + z) = *(subVet2 + f);
      f++;
      }
    z++;
    }

  while(f < metade2)
    {
    *(vetor + z) = *(subVet2 + f);
    f++;
    z++;
    }

  while(i < metade1)
    {
    *(vetor + z) = *(subVet1 + i);
    i++;
    z++;
    }
  }


int mergesort(int *vetor, int inicio, int fim)
  {
  if(inicio < fim)
    {
    int meio = inicio + (fim - inicio)/2;
    mergesort(vetor, inicio, meio);
    mergesort(vetor, meio+1, fim);
    merge(vetor, inicio, meio, fim);
    }
  }


void printVetor(const int *vetor, int size)
  {
  for(int n = 0; n < size; n++)
    {
    printf("[%d] ", *(vetor + n));
    }
  }