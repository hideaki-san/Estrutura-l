#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>
#include<math.h>


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


//PARAMETROS REFERENTES A POSICAO DO VETOR
void merge(int *vetor, int inicio, int meio, int fim)
  {
  int m1 = meio - inicio + 1;//obs
  int m2 = fim - meio;

  int *subVet1, *subVet2;

  subVet1 =(int *)calloc(m1, sizeof(int));
  
  subVet2 =(int *)calloc(m2,  sizeof(int));

  
  for(int n = 0; n < m1; n++)
    {
    *(subVet1 + n) = *(vetor + (inicio + n));
    }

  for(int n = 0; n < m2; n++)
    {
    *(subVet2 + n) = *(vetor + (meio + 1));//obs
    }

  int i = 0, f = 0, z = 0;
  
  while(i < m1 && f < m2)
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

  while(f < m2)
    {
    *(vetor + z) = *(subVet2 + f);
    f++;
    z++;
    }

  while(i < m1)
    {
    *(vetor + z) = *(subVet1 + i);
    i++;
    z++;
    }
  free(subVet1);
  free(subVet2);
  }


//O 'inicio' E 'fim' REFERENTE A POSICAO NO VETOR
int mergesort(int *vetor, int inicio, int fim)
  {
int meio;
  if(inicio < fim)
    {
//PARA TODA VEZ QUE UMA INSTANCIA DESSA FUNCAO E CHAMDA
//GERA UM NOVO 'meio' E INICIA NOVAMENTE APENAS A PRIMEIRA FUNCAO
//REPETE ATE VETOR COM VETOR UMA POSICAO('fim' = 'inicio') 
    meio = inicio + (fim - inicio)/2;

    mergesort(vetor, inicio, meio);
//DEPOIS DE CHEGAR NO VETOR DE UMA POSICAO
//EXECUTA merge COMPARANDO AS POSICOES DOS VETORES
    mergesort(vetor, meio+1, fim);
//APOS merge SER EXECUTADO A FUNCAO TERMINA E VOLTAMOS UM mergesort ANTES EXECUTADO
//COM ESSA VOLTA, O SEGUNDO mergesort EXECUTA FAZENDO O PROCESSO PARA A OUTRA METADE
//ASSIM NA VOLTA DO SEGUNDO mergesort A FUNCAO merge E CHAMADA NOVAMENTE
//REALIZANDO A ORDENACAO DO VETOR COM AS DUAS METADES
//E ASSIM VOLTANDO NOVAMENTE PARA UM mergesort DA FUNCAO CHAMADA ANTERIORMENTE 
    merge(vetor, inicio, meio, fim);
//TERMINA QUANDO A CHAMDA VOLTA PARA A PRIMEIRA mergesort QUE FOI CHAMADA
    }
  }


void printVetor(const int *vetor, int size)
  {
  for(int n = 0; n < size; n++)
    {
    printf("[%d] ", *(vetor + n));
    }
  }