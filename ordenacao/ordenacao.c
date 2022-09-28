#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

struct VETOR
  {
  int vetsize;
  int vetqnt;
  float *vetdata;
  }VETOR;

struct DADOS
  {
  int troca;
  int varredura;
  int comparacao;
  }DADOS;


//LINHA 22 - 88 (manipulacao do vetor)
vetor *vetorCriar(int size)
  {
  vetor *vet =(vetor *)malloc(sizeof(vetor));
  vet->vetdata =(float *)calloc(size, sizeof(float));
  vet->vetsize = size;
  vet->vetqnt = 0;

  return vet;
  }

void vetorExcluir(vetor *vet)
  {
  free(vet->vetdata);
  vet->vetdata = NULL;
  free(vet);
  vet = NULL;
  }

void vetorImprimir(vetor *vet)
  {
  if(vet != NULL)
    {
    for(int c = 0; c < vet->vetqnt;  c++)
      printf("[%.3f] ", *(vet->vetdata + c));
 
    printf("\n\nTAMANHO(max): %d\nQUANTIDADE(atual): %d\n", vet->vetsize, vet->vetqnt);
    } 
  }

int vetorSize(vetor *vet)
  {
  return vet->vetsize;
  }

int vetorQnt(vetor *vet)
  {
  return vet->vetqnt;
  }

float vetorValor(const vetor *vet, int indice)
  {
  while(indice <= 0 || indice > vet->vetqnt)
    {
    printf("Indice definido NAO COMPATIVEL com tamanho do vetor.\nInsira posicao valida: ");
    fflush(stdin);
    scanf("%d", &indice);
    }
  return vet->vetdata[indice-1];
  }

void vetorInserir(vetor *vet, float valor)
  {
  if(vet->vetqnt == vet->vetsize)
    {
    fprintf(stderr, "ERRO: VETOR CHEIO!");
    exit(EXIT_FAILURE);
    }
  vet->vetdata[vet->vetqnt] = valor;
  vet->vetqnt++;
  }

void swap(float *p, float *q)
  {
  int aux = *p;
  *p = *q;
  *q = aux;
  }


// LINHA 92 - 107 (manipulação do dados)
dados *dadosCriar()
  {
  dados *inf = (dados *)calloc(1, sizeof(dados));
  return inf;
  }

void dadosPrint(dados *dado, float tempo, int size)
  {
  printf("TAMANHO> %d\nTEMPO(s)> %f\nTROCAS> %d\nCOMPARACAO> %d\nVARREDURAS> %d\n", size, tempo, dado->troca, dado->comparacao, dado->varredura);
  }

void dadosLiberar(dados *dado)
  {
  free(dado);
  dado=NULL;
  }


//LINHA 111 - end (métodos de ordenacao)
void bubble(vetor *vet, int size)
  {
  time_t bub_init, bub_end;
  float bub_tempo;
  int troca = 0, varredura = 0, comparacao = 0, ref = 0;
  
  bub_init = clock();

  for(int n = 0; n < size - 1; n++)
    {
    for(int m = 0; m < (size - (1 + n)); m++)
      {
      if(vet->vetdata[m] > vet->vetdata[m + 1])
        {
        swap(&vet->vetdata[m], &vet->vetdata[m + 1]);
        troca++;
        ref++;
        }
      comparacao++; 
      }
    if(ref == 0)
      {
      bub_end = clock();
      bub_tempo = ((float)(bub_end - bub_init) / CLOCKS_PER_SEC);
      printf("\n(TEMPO DE EXECUCAO)> %f[s]\nTROCAS> %d\nCOMPARACOES> %d\nVARREDURAS> %d\n", bub_tempo, troca, comparacao, varredura);  
      return;
      }
    varredura++;
    ref = 0;
    }
  
  bub_end = clock();
  bub_tempo = ((float)(bub_end - bub_init) / CLOCKS_PER_SEC);

  printf("\n(TEMPO DE EXECUCAO)> %f[s]\nTROCAS> %d\nCOMPARACOES> %d\nVARREDURAS> %d\n", bub_tempo, troca, comparacao, varredura);
  }


void selection(vetor *vetor, int size)
  {
  time_t sel_init, sel_end;
  float sel_tempo;
  
  int troca = 0, varredura = 0, comparacao = 0;
  
  sel_init = clock();

  for(int n = 0; n < size; n++)
    {
    int menor = n;
    
    for(int m = (menor + 1); m < size; m++)
      {
      if(vetor->vetdata[menor] > vetor->vetdata[m])
        menor = m;
      
      comparacao++;
      }

    if(n != menor)
      {
      swap(&vetor->vetdata[n], &vetor->vetdata[menor]);
      troca++; 
      }
    varredura++;
    }
  
  sel_end = clock();
  sel_tempo = ((float)(sel_end - sel_init) / CLOCKS_PER_SEC);
  
  printf("\n(TEMPO DE EXECUCAO)> %f[s]\nTROCAS> %d\nCOMPARACOES> %d\nVARREDURAS> %d\n", sel_tempo, troca, comparacao, varredura);
  }


void merge(vetor *vetor, int inicio, int meio, int fim, dados *dado)
{
    //comprimento das metade
int m1 = meio - inicio + 1;
int m2 = fim - meio;
    //referencias de posicao no vetor
int refm1=0, refm2=0, refvet=inicio;

int *vetm1 =(int *)malloc(m1 * sizeof(int));
int *vetm2 =(int *)malloc(m2 * sizeof(int));

for(int n=0; n < m1; n++)
    vetm1[n] = vetor->vetdata[inicio + n];

for(int n=0; n < m2; n++)
    vetm2[n] = vetor->vetdata[meio + n + 1];

while(refm1 < m1 && refm2 < m2)
  {
  if(vetm1[refm1] < vetm2[refm2])
    {
    vetor->vetdata[refvet] = vetm1[refm1];
    refm1++;
    refvet++;
    dado->comparacao++;
    dado->troca++;
    }
  else
    {
    vetor->vetdata[refvet] = vetm2[refm2];
    refm2++;
    refvet++;
    dado->comparacao++;
    dado->troca++;
    }
  }

  while(refm1 < m1)
    {
    vetor->vetdata[refvet] = vetm1[refm1];
    refm1++;
    refvet++;
    dado->troca++;
    }

  while(refm2 < m2)
    {
    vetor->vetdata[refvet] = vetm2[refm2];
    refm2++;
    refvet++;
    dado->troca++;
    }

dado->varredura++;
free(vetm1);
vetm1=NULL;
free(vetm2);
vetm2=NULL;
}


int mergesort(vetor *vetor, int inicio, int fim, dados *dado)
  {
int meio;

  if(inicio < fim)
    {
    meio = inicio + (fim - inicio)/2;
    
    mergesort(vetor, inicio, meio, dado);
    mergesort(vetor, meio+1, fim, dado);

    merge(vetor, inicio, meio, fim, dado);
    }
  }


int quick(vetor *vetor, int inicio, int fim, dados *dado)
{
int pivo = vetor->vetdata[fim], esq = inicio, dir = fim;

if(esq>dir) return 0;

while(dir > esq)
  {

  while(vetor->vetdata[esq] < pivo)
    {
    dado->comparacao++;
    esq++;
    }
  while(vetor->vetdata[dir] >= pivo)
    {
    dado->comparacao++;
    dir--;
    }

  if(dir > esq)
    {
    swap(&vetor->vetdata[dir], &vetor->vetdata[esq]);
    dado->troca++;
    } 
  }

if(vetor->vetdata[esq] > pivo)
  {
  swap(&vetor->vetdata[esq], &vetor->vetdata[fim]);
  dado->troca++;
  dado->varredura++;
  return esq;
  }

dado->varredura++;
return esq;
}


void quicksort(vetor *vetor, int inicio, int fim, dados *dado)
{
if(inicio < fim)
  {
  int posicaoPivo = quick(vetor, inicio, fim, dado);
  quicksort(vetor, inicio, posicaoPivo-1, dado);
  quicksort(vetor, posicaoPivo+1, fim, dado);
  }
}