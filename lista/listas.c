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

void listaIniciar(int valor)
{
list *listaEnc =(list *)calloc(1, sizeof(list));
listaEnc->ref = infoCriar(valor);
listaEnc->size++;
}

void listaAddInicio(list *L, int valor)
{
if(L == NULL)
  {
  listaIniciar(valor);
  }
  else
  {
  info *dados =(info *)calloc(1, sizeof(info));
  dados->valor = valor;
  dados->prox = L->ref;
  L->ref = dados;
  L->size++;
  }
}

void listaAddFinal(list *L, int valor)
{
if(L == NULL)
  {
  listaIniciar(valor);
  }
  else
  {
  info *aux = L->ref;
  while(aux->prox != NULL)
    aux = aux->prox;
  
  aux->prox = infoCriar(valor);
  }
}

void listaAddMeio(list *L, int pos, int valor)
{
if(L == NULL)
  {
  listaIniciar(valor);
  }
  else
  {
  info *aux = L->ref, *marcador;
  int i=1;
  
  while(i < pos)
    {
    aux = aux->prox;
    
    if(aux->prox == NULL)
      {
      info *dados =(info *)calloc(1, sizeof(info));
      dados->valor = valor;
      dados->prox = NULL;
      aux->prox = dados;  
      L->size++;
      return;
      }
    
    if(i == pos-1)
      {
      marcador = aux;
      }
    
    i++;
    }

  info *dados =(info *)calloc(1, sizeof(info));
  dados->valor = valor;
  dados->prox = aux;
  marcador->prox = dados;  
  L->size++;
  }
}