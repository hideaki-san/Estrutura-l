#include<stdlib.h>
#include<stdio.h>
#include"listas.h"

struct INFO
{
int valor;
info *prox;
}INFO;

struct LIST
{
info *ref;
int size;
}LIST;


info *infoCriar(int valor)
{    
info *dados =(info *)calloc(1, sizeof(info));
dados->valor = valor;
dados->prox = NULL;

return dados; 
}

list *listaIniciar(int valor)
{
list *L =(list *)calloc(1, sizeof(list));
L->ref = infoCriar(valor);
L->size++;

return L;
}

void listaAddInicio(list *L, int valor)
{
  info *dados =(info *)calloc(1, sizeof(info));
  dados->valor = valor;
  dados->prox = L->ref;
  L->ref = dados;
  L->size++;
  return;
}

void listaAddFinal(list *L, int valor)
{
  info *aux = L->ref;
  while(aux->prox != NULL)
  {
    aux = aux->prox;
  }
  aux->prox = infoCriar(valor);
  L->size++;
  return;
}


void listaAddMeio(list *L, int pos, int valor)
{
if(pos > L->size || pos <= 0)
  {
  printf("\nINSERIDO NO FINAL DA LISTA(posicao nao existe)\n");
  system("pause");
  listaAddFinal(L, valor);
  return;
  }
  else
  {
  info *aux = L->ref;
  int i=1;
  
  while(i < (pos-1))
    {
    aux = aux->prox;
    
    if(aux->prox == NULL)
      {
      info *dados =infoCriar(valor);
      aux->prox = dados;  
      L->size++;
      return;
      }
    i++;
    }

  info *dados =(info *)calloc(1, sizeof(info));
  dados->valor = valor;
  dados->prox = aux->prox;
  aux->prox = dados;  
  L->size++;
  return;
  }
}

void listaAddOrdenado(list *L, int valor)
{ 
info *aux = L->ref;

while(aux->prox != NULL)
  {
  if(aux->prox->valor > valor)
    {
    info *dados =(info *)calloc(1, sizeof(info));
    dados->valor = valor;
    dados->prox = aux->prox;
    aux->prox = dados;
    L->size++;
    return;
    }
  aux = aux->prox;
  }
info *dados =(info *)calloc(1, sizeof(info));
dados->valor = valor;
dados->prox = aux->prox;
aux->prox = dados;
L->size++;
return;
}

void listaImprimir(list *L)
{
info *aux = L->ref;
printf("\nTAMANHO: %d\n", L->size);
while(aux != NULL)
  {
  printf("[%d]->", aux->valor);
  aux = aux->prox;
  }
printf("[NULL]\n\n");
}

void listaDeletar(list *L, int valor)
{
info *aux = L->ref, *ref;
  
if(aux->valor == valor)
  {
  L->ref = aux->prox;
  free(aux);
  aux == NULL;
  L->size--;
  return;
  }

while(aux->valor != valor)
  {

  ref = aux;
  aux = aux->prox;
  
  if(aux == NULL)
    {
    printf("\nVALOR NAO ENCONTRADO NA LISTA\n");
    system("pause");
    return;
    }
  }

ref->prox = aux->prox;
free(aux);
aux == NULL;
L->size--;
}

void listaFree(list *L)
{
info *aux = L->ref;
for(int f = 1; f <= L->size; f++)
  {
  L->ref = aux->prox;
  free(aux);
  aux = L->ref;
  }

free(L);
L = NULL;
}