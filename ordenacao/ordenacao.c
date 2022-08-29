#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>
#include<math.h>

struct DADOS
  {
  int troca;
  int varredura;
  int comparacao;
  }DADOS;

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

  fprintf(arq,"\nBUBBLE ; %d ; %f ; %d ; %d ; %d ", size, bub_tempo, troca, comparacao, varredura);
  printf("\n(TEMPO DE EXECUCAO): %f[s]\n\n", bub_tempo);
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
  
  fprintf(arq,"\nSELECTION ; %d ; %f ; %d ; %d ; %d ", size, sel_tempo, troca, comparacao, varredura);
  printf("\n(TEMPO DE EXECUCAO): %f[s]\n\n", sel_tempo);
  }

//PARAMETROS REFERENTES A POSICAO DO VETOR
void merge(int *vetor, int inicio, int meio, int fim, dados *dado)
  {
/*
'm1' e 'm'2' FAZEM PARAMETRO PARA AS METADES DO VETOR
PARAMETRO DE COMPRIMENTO DO VETOR E NAO DA POSICAO
*/
  int m1 = meio - inicio + 1;
  int m2 = fim - meio;

//REFERENCIAS PARA ORDENAR E ATRIBUIR AO VETOR PRINCIPAL
  int *subVet1, *subVet2;

  subVet1 =(int *)calloc(m1, sizeof(int));
  subVet2 =(int *)calloc(m2, sizeof(int));

  for(int n = 0; n < m1; n++)
    *(subVet1 + n) = *(vetor + (inicio + n));

  for(int n = 0; n < m2; n++)  
    *(subVet2 + n) = *(vetor + ((meio + 1) + n));

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
      *(vetor + z) = *(subVet1 + i);
      dado->troca++;
      i++;
      }
    else
      {
      *(vetor + z) = *(subVet2 + f);
      dado->troca++;
      f++;
      } 
    z++;
    }

//ATRIBUI OS VALORES DAS POSICOES DO VETOR QUE NAO CHEGOU AO FINAL PARA O VETOR PRINCIPAL
  
  while(f < m2)
    {
    *(vetor + z) = *(subVet2 + f);
    dado->troca++;
    f++;
    z++;
    }

  while(i < m1)
    {
    *(vetor + z) = *(subVet1 + i);
    dado->troca++;
    i++;
    z++;
    }

  dado->varredura++;
  free(subVet1);
  free(subVet2);
  }

//O 'inicio' E 'fim' REFERENTE A POSICAO NO VETOR
int mergesort(int *vetor, int inicio, int fim, dados *dado)
  {
int meio;

  if(inicio < fim)
    {

//PARA TODA VEZ QUE UMA INSTANCIA DESSA FUNCAO E CHAMDA
//GERA UM NOVO 'meio' E INICIA NOVAMENTE A RECURSIVIDADE
    meio = inicio + (fim - inicio)/2;
    mergesort(vetor, inicio, meio, dado);
    mergesort(vetor, meio+1, fim, dado);
/*
QUANDO 'inicio = fim' A FUNCAO TERMINA SUA INSTANCIA E RETORNA PARA INSTANCIA ANTERIOR
NESSE RETORNO O SEGUNDO 'mergesort' E CHAMADO REALIZANDO O MESMO CAMINHO DA LINHA ACIMA  
TERMINANDO AS DUAS METADES O 'merge' E CHAMADO REALIZANDO ASSIM A ORDENACAO ENTRE AS DUAS 'mergesort' DESSA INSTANCIA
O PROCESSO SE REPETE ATE TODAS AS INSTANCIAS SEREM REALIZADAS E TERMINAR O PRIMEIRO 'mergesort' CHAMADO, COM O VETOR ORDENADO
*/
    merge(vetor, inicio, meio, fim, dado);
    }
  }


int quick(int *vetor, int inicio, int fim, dados *dado)
  {
  int esq = inicio, dir = fim, pivo = *(vetor + inicio);

//VERIFICACAO DE VETOR JA ORDENADO 
  int c = 0;
  while(*(vetor + c) < *(vetor + c + 1))
    {
    c++;
    if(c == fim)
      return 0;
    }
/*
COMPARACAO COM O PIVO FEITA DA ESQUERDA PARA A DIREITA E DA DIREITA PARA A ESQUERDA
O LADO ESQUERDO RECEBE OS VALORES MENORES OU IGUAIS AO PIVO
O LADO DIREITO VAI RECEBER OS VALORES MAIORES QUE O PIVO
ASSIM A TROCA E FEITA ENTRE AS REFERENCIAS DA ESQUERDA E DA DIREITA
*/
  while(esq < dir)
    {
    while(*(vetor + esq) <= pivo)
    {
    dado->comparacao++;
    esq++;
    }
    
    while(*(vetor + dir) > pivo)
    {
    dado->comparacao++;
    dir--;
    }

    if(esq < dir)
    {
    dado->troca++;
    swap((vetor + dir), (vetor + esq));  
    }
    }

//COLOCA O PIVO ENTRE AS POSICOES DE ESQUERDA E DIREITA, FICANDO ASSIM NA POSICAO CORRETA DO VETOR
//pivo QUE E O INICIO TROCA COM O ULTIMA POSICAO DOS VALORES MENORES QUE ELE('dir')
  *(vetor + inicio) = *(vetor + dir);
  *(vetor + dir) = pivo;
  return dir;
  }

void quicksort(int *vetor, int inicio, int fim, dados *dado)
  {
  if(inicio < fim)
    {
    int pivo = quick(vetor, inicio, fim, dado);
    quicksort(vetor, inicio, pivo - 1, dado);
    quicksort(vetor, pivo + 1, fim, dado);
    }
  }

dados *dadosCriar()
  {
  dados *inf = (dados *)calloc(1, sizeof(dados));
  return inf;
  }

void dadosPrint(dados *dado, FILE *arq, float tempo, int size)
  {
  fprintf(arq,"\n %d ; %f ; %d ; %d ; %d ", size, tempo, dado->troca, dado->comparacao, dado->varredura);
  }

void dadosLiberar(dados *dado)
  {
  free(dado);
  dado=NULL;
  }
  
void printVetor(const int *vetor, int size)
  {
  for(int n = 0; n < size; n++)
    printf("[%d] ", *(vetor + n));
  }
