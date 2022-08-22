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
  int divisao;
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

  fprintf(arq,"\n:BUBBLE: ");
  fprintf(arq,"\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]", troca, comparacao, varredura);
  fprintf(arq,"\n(TEMPO DE EXECUCAO): %f[s]\n\n", bub_tempo);
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
  
  fprintf(arq,"\n:SELECTION: ");
  fprintf(arq,"\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]", troca, comparacao, varredura);
  fprintf(arq,"\n(TEMPO DE EXECUCAO): %f[s]\n\n", sel_tempo);
  printf("\n(TEMPO DE EXECUCAO): %f[s]\n\n", sel_tempo);
  }


//PARAMETROS REFERENTES A POSICAO DO VETOR
void merge(int *vetor, int inicio, int meio, int fim, dados *dado)
  {
/*
'm1' FAZ PARAMETRO PARA A PRIMEIRA METADE DO VETOR
PARAMETRO DE COMPRIMENTO DO VETOR E NAO DA POSICAO
POR ISSO +1 E ADICIONADO
POIS EM POSICAO 'inicio' = 0 MAS EM COMPRIMETO ESTE E A PRIMEIRA POSICAO
*/
  int m1 = meio - inicio + 1;

//'m2' FAZ PARAMETRO PARA A OUTRA METADE
  int m2 = fim - meio;

//REFERENCIAS PARA ORDENAR E ATRIBUIR AO VETOR PRINCIPAL
  int *subVet1, *subVet2;

//ALOCA TAMANHO NA MEMORIA REFERENTE AOS PARAMETROS 'm1' e 'm2'
  subVet1 =(int *)calloc(m1, sizeof(int));
  subVet2 =(int *)calloc(m2, sizeof(int));

  //printf("\nvalor m1 = %d, m2 = %d", m1, m2);
//VETOR DE REFERENCIA PARA A PRIMEIRA METADE
//RECEBE OS VALORES DO VETOR PRINCIPAL PELO COMPRIMENTO 'm1'
//NA POSICAO DE 'inicio' + 'n'(DO 0 ATE 'm1 - 1') 
  for(int n = 0; n < m1; n++)
  {
  *(subVet1 + n) = *(vetor + (inicio + n));
  //printf("\nvetor = %d -> subVet1 = %d", *(vetor + (inicio + n)), *(subVet1 + n));
  }
//VETOR DE REFERENCIA PARA A SEGUNDA METADE
//RECEBE OS VALORES DO VETOR PRINCIPAL PELO COMPRIMENTO 'm2'
//NA POSICAO DE 'meio' + 1(POSICAO SEGUINTE AO 'meio' DO OUTRO VETOR) + 'n'(do 0 ATE 'm2 -1')
  for(int n = 0; n < m2; n++)  
  {
  *(subVet2 + n) = *(vetor + ((meio + 1) + n));
  //printf("\nvetor = %d -> subVet2 = %d", *(vetor + ((meio + 1) + n)), *(subVet2 + n));
  }
/*
VARIAVEIS DE CONTROLE
i(POSICAO DE REFERENCIA PARA A PRIMEIRA METADE)
f(POSICAO DE REFERENCIA PARA A SEGUNDA METADE)
z(POSICAO DE REFERENCIA PARA ATRIBUIR VALORES PARA O VETOR PRINCIPAL)
*/

//ERRO ANTERIOR REFERENTE AO 'z = 0', QUANDO A OUTRA METADE ENTRAVA NO MERGE
//A POSICAO ERA DUPLICADA PARA A PRIMEIRA POSICAO[0] EM VEZ DA POSICAO REFERENTE AO INCIO
  int i = 0, f = 0, z = inicio;

//ATE QUE UM DOS VETORES TERMINE(POSICAO DE REFERENCIA = PARAMETRO DE COMPRIMENTO)
  while(i < m1 && f < m2)
    {
    dado->comparacao++;
/*
COMPARACAO FEITA PARA ATRIBUIR O MENOR VALOR AO VETOR PRINCIPAL
ATRIBUICAO PELO 'subVet1' :: POSICAO 'i' FOI ATRIBUIDA logo:
i++(PROXIMA POSICAO DE REFERENCIA DESSA METADE DO VETOR)
ATRIBUICAO PELO 'subVet2' :: POSICAO 'f' FOI ATRIBUIDA logo:
f++(PROXIMA POSICAO DE REFERENCIA DESSA METADE DO VETOR)
*/
    if(*(subVet1 + i) <= *(subVet2 + f))
      {
      *(vetor + z) = *(subVet1 + i);
      dado->troca++;
      //printf("\nsubVet1 = %d | subVet2 = %d", *(subVet1 + i), *(subVet2 + f));
      //printf("\nsubVet1 -> vetor[%d] = %d", z, *(vetor + z));
      i++;
      }
    else
      {
      *(vetor + z) = *(subVet2 + f);
      dado->troca++;
      //printf("\nsubVet1 = %d | subVet2 = %d", *(subVet1 + i), *(subVet2 + f));
      //printf("\nsubVet2 -> vetor[%d] = %d", z, *(vetor + z));
      f++;
      }
//SEMPRE QUE VALOR NA POSICAO 'z' DO VETOR PRINCIPAL FOR ATRIBUIDO
//z++(PROXIMA POSICAO DO VETOR PRINCIPAL) 
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

  //printf("\n\n");
  //printVetor(vetor, (fim+1));
  dado->varredura++;
  free(subVet1);
  free(subVet2);
  }


//O 'inicio' E 'fim' REFERENTE A POSICAO NO VETOR
int mergesort(int *vetor, int inicio, int fim, dados *dado)
  {
int meio;

//REPETE ATE VETOR COM VETOR UMA POSICAO('fim' = 'inicio') 
  if(inicio < fim)
    {

//PARA TODA VEZ QUE UMA INSTANCIA DESSA FUNCAO E CHAMDA
//GERA UM NOVO 'meio' E INICIA NOVAMENTE APENAS A PRIMEIRA FUNCAO
    meio = inicio + (fim - inicio)/2;
    dado->divisao++;
    mergesort(vetor, inicio, meio, dado);
    mergesort(vetor, meio+1, fim, dado);
/*
DEPOIS DE CHEGAR NO VETOR DE UMA POSICAO
EXECUTA merge COMPARANDO AS POSICOES DOS VETORES    
APOS merge SER EXECUTADO A FUNCAO TERMINA E VOLTAMOS UM mergesort ANTES EXECUTADO
COM ESSA VOLTA, O SEGUNDO mergesort EXECUTA FAZENDO O PROCESSO PARA A OUTRA METADE
ASSIM NA VOLTA DO SEGUNDO mergesort A FUNCAO merge E CHAMADA NOVAMENTE
REALIZANDO A ORDENACAO DO VETOR COM AS DUAS METADES
E ASSIM VOLTANDO NOVAMENTE PARA UM mergesort DA FUNCAO CHAMADA ANTERIORMENTE 
*/
    //printf("\n\ninicio = %d, meio = %d, fim = %d\n", inicio, meio, fim);
    merge(vetor, inicio, meio, fim, dado);
//TERMINA QUANDO A CHAMDA VOLTA PARA A PRIMEIRA mergesort QUE FOI CHAMADA
    }
  }

dados *dadosCriar()
  {
  dados *merge_inf = (dados *)calloc(1, sizeof(dados));
  return merge_inf;
  }

void dadosPrint(dados *dado, FILE *arq)
  {
  fprintf(arq,"\n:MERGE:");
  fprintf(arq,"\ntroca[%d]\ncomapracao[%d]\nvarredura[%d]\ndivisao[%d]", dado->troca, dado->comparacao, dado->varredura, dado->divisao);
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