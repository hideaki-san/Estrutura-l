#include <stdio.h>
#include <stdlib.h>
#include "Double_LL.h"

struct OBJETO
{
float valor;
vetor *prox;
vetor *ant;
};

struct LISTA 
{
int tamanho;
vetor *inicio;
vetor *fim;
};

vetor *vetorCriar(float valor)
{
vetor *vet =(vetor *)malloc(sizeof(vetor));
vet->prox = vet;
vet->ant = vet;
vet->valor = valor;

return vet;
}

doubleList *listaCriar(float valor)
{
doubleList *DL =(doubleList *)calloc(1, sizeof(doubleList));
DL->inicio = vetorCriar(valor);
DL->fim = DL->inicio;
DL->tamanho++;
}

void listaInicio(doubleList *DL, float valor)
{
vetor *aux = DL->inicio;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->prox = DL->inicio;
novo->ant = DL->fim;
novo->valor = valor;
aux->ant = novo;

if(aux->prox == aux)
  aux->prox = novo;

DL->inicio = novo;
DL->tamanho++;
}

void listaFim(doubleList *DL, float valor)
{
vetor *aux = DL->fim;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->prox = DL->inicio;
novo->ant = DL->fim;
novo->valor = valor;
aux->prox = novo;

if(aux->ant == aux)
  aux->ant = novo;

DL->fim = novo;
DL->tamanho++;
}


//ordenacao feita pela lógica de selection sort
void listaOrdenar(doubleList *DL)
{
vetor *aux, *ref, *troca;
float T;

for(aux = DL->inicio; aux->prox != DL->inicio; aux = aux->prox)
  {
  troca = aux;
  
  for(ref = DL->fim; ref != aux; ref = ref->ant)
    if(troca->valor > ref->valor)
      troca = ref;
  
  T = troca->valor;
  troca->valor = aux->valor;
  aux->valor = T;
  }
}

void listaImprimir(doubleList *DL)
{
vetor *aux = DL->inicio;
printf("\nTAMANHO> %d\n\n", DL->tamanho);
while(aux != DL->fim)
  {
  printf("[%.2f]->", aux->valor);
  aux = aux->prox;
  }
printf("[%.2f]->(inicio)[%.2f]\n", aux->valor, DL->inicio->valor);
}

void listaLiberar(doubleList *DL)
{
vetor *aux = DL->inicio;
while(aux != DL->fim)
  {  
  DL->inicio = aux->prox;
  free(aux);
  aux = DL->inicio;
  }
free(aux);
free(DL);
}