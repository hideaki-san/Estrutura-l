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
}

void listaImprimir(doubleList *DL)
{
vetor *aux = DL->inicio;
while(aux != DL->fim)
  {
  printf("[%.2f]->", aux->valor);
  aux = aux->prox;
  }
printf("[%.2f]->(inicio)[%.2f]", aux->valor, DL->inicio->valor);
}

void listaLiberar(doubleList *DL)
{
vetor *aux;
while(aux != DL->fim)
  {  
  DL->inicio = aux->prox;
  free(aux);
  aux = DL->inicio;
  }
free(aux);
free(DL);
}