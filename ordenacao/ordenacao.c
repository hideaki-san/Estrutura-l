#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"



void swap(int *p, int *q)
  {
  int aux = *p;
  *p = *q;
  *q = aux;
  }


void bubble(int *vetor, int size)
  {
  int troca = 0, varredura = 0, comparacao = 0;

//POSICAO DE COMPARACAO COM O VETOR
  for(int n = 0; n < size - 1; n++)
    {
//PERCORRE O VETOR PARA COMPARAR POSICAO ADJACENTE
    for(int m = 0; m < (size - (1 + n)); m++)
      {
//CASO SEJA MAIOR VALOR TROCA COM O PROXIMO
//NA ULTIMO ESPACO FICARA O MAIOR NUMERO
      if(vetor[m] > vetor[m + 1])
        {
        swap(&vetor[m], &vetor[m + 1]);
        troca++;
        }
      comparacao++;
      }
    varredura++;
    }
  printf("\n\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]\n", troca, comparacao, varredura);
  }


void selection(int *vetor, int size)
  {
  int troca = 0, varredura = 0, comparacao = 0;

  for(int n = 0; n < size; n++)
    {
//ARMAZENA A POSICAO QUE VAI SER COMPARADA COM O VETOR
    int menor = n;
    for(int m = menor; m < size; m++)
      {
//FAZ COMPARACAO COM A POSICAO ARMAZENADA ANTERIOR
//CASO O VALOR DO VETOR QUE PERCORRE SEJA MENOR QUE O ARMAZENADO ANTERIOR
//A MENOR POSICAO(ARMAZENADA) ATUALIZA COM A POSICAO NOVA DE MENOR VALOR
      if(vetor[m] < vetor[menor])
        {
        menor = m;
        troca++; 
        }
      comparacao++;
      }
//FAZ A TROCA NOS VALORES QUE ESTAO NA POSICAO DA MEMORIA
//TROCA DA PRIMEIRA POSICAO QUE NAO FOI TROCADA AINDA  
    swap((vetor + n), (vetor + menor));
     varredura++;
    }
  printf("\n\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]\n", troca, comparacao, varredura);
  }


void printVetor(const int *vetor, int size)
  {
  for(int n = 0; n < size; n++)
    {
    printf("[%d] ", *(vetor + n));
    }
  }
