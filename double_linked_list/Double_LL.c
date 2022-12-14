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

doubleList *listaCriar()
{
doubleList *DL =(doubleList *)calloc(1, sizeof(doubleList));
DL->inicio = NULL;
DL->fim = DL->inicio;

return DL;
}

void listaTroca(doubleList *DL, int p1, int p2)
{
if(p1 <= 0 || p2 <= 0 || p1 > DL->tamanho || p2 > DL->tamanho || p1 == p2) return;

vetor *aux1, *aux2, *refA, *refP;

if(p1 <= DL->tamanho/2)
  {
  aux1 = DL->inicio;
  for(int n = 1; n < p1; n++)
    aux1 = aux1->prox;
  }else if(p1 > DL->tamanho/2)
    {
    aux1 = DL->fim;
    for(int n = DL->tamanho; n > p1; n--)
      aux1 = aux1->ant;    
    }
  
if(p2 <= DL->tamanho/2)
  {
  aux2 = DL->inicio;
  for(int n = 1; n < p2; n++)
    aux2 = aux2->prox;
  }else if(p2 > DL->tamanho/2)
    {
    aux2 = DL->fim;
    for(int n = DL->tamanho; n > p2; n--)
      aux2 = aux2->ant;
    }
  
  refA = aux1->ant;
  refP = aux1->prox;
  refA->prox = aux2;
  refP->ant = aux2;
  aux1->prox = aux2->prox;
  aux1->ant = aux2->ant;
  aux2->ant = refA;
  aux2->prox = refP;
  refA = aux1->ant;
  refA->prox = aux1;
  refP = aux1->prox;
  refP->ant = aux1;

if(p1 == 1)
  DL->inicio = aux2;

if(p1 == DL->tamanho)
  DL->fim = aux2;

if(p2 == 1)
  DL->inicio = aux1;

if(p2 == DL->tamanho)
  DL->fim = aux1;


printf("\nTROCA REALIZADA> [%d] <-> [%d]\n", p1, p2);
}


void listaInicio(doubleList *DL, float valor)
{
if(DL->inicio == NULL)
  {
  DL->inicio = vetorCriar(valor);
  DL->fim = DL->inicio;
  DL->tamanho++;
  return;
  }

vetor *aux = DL->inicio;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->prox = DL->inicio;
novo->ant = DL->fim;
novo->valor = valor;
aux->ant = novo;

if(aux->prox == aux)
  aux->prox = novo;

DL->fim->prox = novo;
DL->inicio = novo;
DL->tamanho++;
}


void listaFim(doubleList *DL, float valor)
{
if(DL->inicio == NULL)
  {
  DL->inicio = vetorCriar(valor);
  DL->fim = DL->inicio;
  DL->tamanho++;
  return;
  }
  
vetor *aux = DL->fim;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->prox = DL->inicio;
novo->ant = DL->fim;
novo->valor = valor;
aux->prox = novo;

if(aux->ant == aux)
  aux->ant = novo;

DL->inicio->ant = novo;
DL->fim = novo;
DL->tamanho++;
}


void listaMeio(doubleList *DL, int posicao, float valor)
{
if((posicao > (DL->tamanho + 1)) || posicao <= 0 || DL->inicio == NULL) return;

vetor *aux, *novo;

if(posicao <= DL->tamanho/2)
  {
  aux = DL->inicio;
  for(int n = 1; n < posicao; n++)
    aux = aux->prox;

  novo =(vetor *)malloc(sizeof(vetor));
  novo->valor = valor;
  novo ->prox = aux;
  novo ->ant = aux->ant;
  aux->ant = novo;
  aux = novo->ant;
  aux->prox = novo;
  DL->tamanho++;
  }
else
  {
  aux = DL->fim;
  for(int n = DL->tamanho; n > posicao; n--)
    aux = aux->ant;

  novo =(vetor *)malloc(sizeof(vetor));
  novo->valor = valor;
  novo ->prox = aux;
  novo ->ant = aux->ant;
  aux->ant = novo;
  aux = novo->ant;
  aux->prox = novo;
  DL->tamanho++;
  }

if(posicao == 1)
  DL->inicio = novo;

if(posicao == DL->tamanho)
  DL->fim = novo;

printf("\nINSERIDO> [%d](%.2f)\n", posicao, valor);
}

//ordenacao feita pela l??gica de selection sort
void listaOrdenar(doubleList *DL)
{
if(DL->inicio == NULL) return;

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

printf("\n[ORDENADO]\n");
}


void listaConsulta(doubleList *DL, int pos)
{
if(pos <= 0 || pos > DL->tamanho || DL->inicio == NULL) return;

if(pos <= DL->tamanho/2)
  {
  vetor *aux = DL->inicio;
  for(int n = 1; n < pos; n++)
    aux = aux->prox;

  printf("\nPOSICAO> [%d]\nVALOR> (%.2f)\n", pos, aux->valor);
  }
else
  {
  vetor *aux = DL->fim;
  for(int n = DL->tamanho; n > pos; n--)
    aux = aux->ant;
  
  printf("\nPOSICAO> [%d]\nVALOR> (%.2f)\n", pos, aux->valor);
  }
}


void listaDeletar(doubleList *DL, int pos)
{
if(pos <= 0 || pos > DL->tamanho || DL->inicio == NULL) return;

vetor *aux, *auxR;

if(pos == 1)
  {
  aux = DL->inicio; 
  auxR = DL->fim;
  DL->inicio = aux->prox;
  auxR->prox = DL->inicio;
  auxR = aux->prox;
  auxR->ant = DL->fim;
  
  printf("\nOBJETO> [%d](%.2f) (excluido)\n", pos, aux->valor);

  free(aux);
  aux=NULL;
  DL->tamanho--;
  system("pause");
  return;
  }

if(pos == DL->tamanho)
  {
  aux = DL->fim;
  auxR = DL->inicio;
  DL->fim = aux->ant;
  auxR->ant = DL->fim;
  auxR = aux->ant;
  auxR->prox = DL->inicio;

  printf("\nOBJETO> [%d](%.2f) (excluido)\n", pos, aux->valor);

  free(aux);
  aux=NULL;
  DL->tamanho--;
  system("pause");
  return;
  }

if(pos <= DL->tamanho/2)
  {
  aux = DL->inicio;
  vetor *ref_A, *ref_P;
  for(int n = 1; n < pos; n++)
    aux = aux->prox;

  ref_A = aux->ant;
  ref_P = aux->prox;

  ref_A->prox = ref_P;
  ref_P->ant = ref_A;
  }
else
  {
  aux = DL->fim;
  vetor *ref_A, *ref_P;
  for(int n = DL->tamanho; n > pos; n--)
    aux = aux->prox;

  ref_A = aux->ant;
  ref_P = aux->prox;

  ref_A->prox = ref_P;
  ref_P->ant = ref_A;
  }

  printf("\nOBJETO> [%d](%.2f) (excluido)\n", pos, aux->valor);


  free(aux);
  aux = NULL;
  DL->tamanho--;
  system("pause");
  return;
  
}


doubleList *listaUnir(doubleList *DL1, doubleList *DL2)
{
doubleList *novaLista = listaCriar();

listaOrdenar(DL1);
listaOrdenar(DL2);

int R1 = 1, R2 = 1;

vetor *aux1 = DL1->inicio, *aux2 = DL2->inicio;

while(R1 <= DL1->tamanho && R2 <= DL2->tamanho)
  {
    if(aux1->valor <= aux2->valor)
      {
      listaFim(novaLista, aux1->valor);
      aux1 = aux1->prox;
      R1++;
      }
    else
      {
      listaFim(novaLista, aux2->valor);
      aux2 = aux2->prox;
      R2++;
      }
  }

while(R1 <= DL1->tamanho)
  {
  listaFim(novaLista, aux1->valor);
  aux1 = aux1->prox;
  R1++;
  }

while(R2 <= DL2->tamanho)
  {
  listaFim(novaLista, aux2->valor);
  aux2 = aux2->prox;
  R2++;  
  }

listaLiberar(DL1);
listaLiberar(DL2);

return novaLista;
}


void listaImprimir(doubleList *DL)
{
if(DL->tamanho == 0) 
  {
  printf("\nVAZIO\n");
  return;
  }
vetor *aux = DL->inicio;
int c = 1;
printf("\nTAMANHO> %d\n", DL->tamanho);
while(aux->prox != DL->inicio)
  {
  printf("[%d](%.2f) <-> ", c, aux->valor);
  aux = aux->prox;
  c++;
  }
printf("[%d](%.2f) <-> [1](%.2f)\n", c, aux->valor, DL->inicio->valor);
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
aux = NULL;
free(DL);
DL = NULL;
}