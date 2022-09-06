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
 
    //printf("\n\nTAMANHO(max): %d\nQUANTIDADE(atual): %d\n", vet->vetsize, vet->vetqnt);
    } 
  }

int vetorSize(vetor *vet)
  {
  return vet->vetsize;
  }

int vetorQuantidade(vetor *vet)
  {
  return vet->vetqnt;
  }

float vetorValor(const vetor *vet, int indice)
  {
  if(indice <= 0 || indice > vet->vetqnt)
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

void dadosPrint(dados *dado, FILE *arq, float tempo, int size)
  {
  fprintf(arq," %d ; %f ; %d ; %d ; %d ", size, tempo, dado->troca, dado->comparacao, dado->varredura);
  }

void dadosLiberar(dados *dado)
  {
  free(dado);
  dado=NULL;
  }


//LINHA 111 - end (métodos de ordenacao)
void bubble(vetor *vet, int size, FILE *arq)
  {
  time_t bub_init, bub_end;
  float bub_tempo;
  int troca = 0, varredura = 0, comparacao = 0;
  
  bub_init = clock();

  for(int n = 0; n < size - 1; n++)
    {
    for(int m = 0; m < (size - (1 + n)); m++)
      {
      if(vet->vetdata[m] > vet->vetdata[m + 1])
        {
        swap(&vet->vetdata[m], &vet->vetdata[m + 1]);
        troca++;
        }
      comparacao++; 
      }
    varredura++;
    }
  
  bub_end = clock();
  bub_tempo = ((float)(bub_end - bub_init) / CLOCKS_PER_SEC);

  fprintf(arq,"\nBUBBLE ; %d ; %f ; %d ; %d ; %d ", size, bub_tempo, troca, comparacao, varredura);
  printf("\n(TEMPO DE EXECUCAO): %f[s]\n\n", bub_tempo);
  }

void selection(vetor *vetor, int size, FILE *arq)
  {
  time_t sel_init, sel_end;
  float sel_tempo;
  int c = 0;
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
  
  fprintf(arq,"\nSELECTION ; %d ; %f ; %d ; %d ; %d ", size, sel_tempo, troca, comparacao, varredura);
  printf("\n(TEMPO DE EXECUCAO): %f[s]\n\n", sel_tempo);
  }

void merge(vetor *vetor, int inicio, int meio, int fim, dados *dado)
  {
/*
'm1' e 'm'2' FAZEM PARAMETRO PARA AS METADES DO VETOR
PARAMETRO DE COMPRIMENTO DO VETOR E NAO DA POSICAO
*/
  int m1 = meio - inicio + 1;
  int m2 = fim - meio;

//REFERENCIAS PARA ORDENAR E ATRIBUIR AO VETOR PRINCIPAL
  float *subVet1, *subVet2;

  subVet1 =(float *)calloc(m1, sizeof(float));
  subVet2 =(float *)calloc(m2, sizeof(float));

  for(int n = 0; n < m1; n++)
    *(subVet1 + n) = vetor->vetdata[inicio + n];

  for(int n = 0; n < m2; n++)  
    *(subVet2 + n) = vetor->vetdata[meio+1+n];

/*
VARIAVEIS DE CONTROLE
i(POSICAO DE REFERENCIA PARA A PRIMEIRA METADE)
f(POSICAO DE REFERENCIA PARA A SEGUNDA METADE)
z(POSICAO DE REFERENCIA PARA O VETOR PRINCIPAL)
*/
  
  int i = 0, f = 0, z = inicio;

  while(i < m1 && f < m2)
    {
    dado->comparacao++;
  
  //TROCA REALIZADA PARA MENOR VALOR DA POSICAO DE REFERENCIA

    if(*(subVet1 + i) <= *(subVet2 + f))
      {
      vetor->vetdata[z] = *(subVet1 + i);
      dado->troca++;
      i++;
      }
    else
      {
      vetor->vetdata[z] = *(subVet2 + f);
      dado->troca++;
      f++;
      } 
    z++;
    }

//ATRIBUI OS VALORES DAS POSICOES DO VETOR QUE NAO CHEGOU AO FINAL PARA O VETOR PRINCIPAL
  
  while(f < m2)
    {
    vetor->vetdata[z] = *(subVet2 + f);
    dado->troca++;
    f++;
    z++;
    }

  while(i < m1)
    {
    vetor->vetdata[z] = *(subVet1 + i);
    dado->troca++;
    i++;
    z++;
    }

  dado->varredura++;
  free(subVet1);
  free(subVet2);
  subVet1 = NULL;
  subVet2 = NULL;
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
  int esq = inicio, dir = fim; 
  float pivo = vetor->vetdata[fim];

/*
COMPARACAO COM O PIVO FEITA DA ESQUERDA PARA A DIREITA E DA DIREITA PARA A ESQUERDA
O LADO ESQUERDO RECEBE OS VALORES MENORES OU IGUAIS AO PIVO
O LADO DIREITO VAI RECEBER OS VALORES MAIORES QUE O PIVO
ASSIM A TROCA E FEITA ENTRE AS REFERENCIAS DA ESQUERDA E DA DIREITA
*/
  while(esq < dir)
    {
    while(vetor->vetdata[esq] <= pivo)
    {
    dado->comparacao++;
    esq++;
    }
    
    while(vetor->vetdata[dir] > pivo)
    {
    dado->comparacao++;
    dir--;
    }

    if(esq < dir)
    {
    dado->troca++;
    swap(&vetor->vetdata[dir], &vetor->vetdata[esq]);  
    }
    }

//COLOCA O PIVO ENTRE AS POSICOES DE ESQUERDA E DIREITA, FICANDO ASSIM NA POSICAO CORRETA DO VETOR
//pivo QUE E O INICIO TROCA COM O ULTIMA POSICAO DOS VALORES MENORES QUE ELE('dir')
 
  vetor->vetdata[fim] = vetor->vetdata[esq];
  vetor->vetdata[esq] = pivo;
  
  return esq;
  }

void quicksort(vetor *vetor, int inicio, int fim, dados *dado)
  {
  if(inicio < fim)
    {
    int pospivo = quick(vetor, inicio, fim, dado);
    quicksort(vetor, inicio, pospivo - 1, dado);
    quicksort(vetor, pospivo + 1, fim, dado);
    }
  }
