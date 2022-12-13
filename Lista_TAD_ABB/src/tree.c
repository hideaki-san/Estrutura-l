#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../include/tree.h"

struct ALUNO
{
int matricula;
char nome[50];
float media;
}ALUNO;

struct TREE
{
no *raiz;
}TREE;

struct noABB
{
aluno *info;
no *esq;
no *dir;
}noABB;

void add(no *n, int matricula, char *nome, float media);
no *rmv(no *n, float media);
void in(no *n);
void n_free(no *n);
void busca(no *n, float media);
void busca_maior(no *n);
int aprov(no *n);

tree *tree_criar()
{
tree *T =(tree *)calloc(1 ,sizeof(tree));
T->raiz = NULL;
return T;
}

no *noABB_criar(int matricula, char *nome, float media)
{
no *novo =(no *)calloc(1, sizeof(no));
novo->info =(aluno *)calloc(1, sizeof(aluno));
novo->info->matricula = matricula;
novo->info->media = media;
strcpy(novo->info->nome, nome);

novo->dir = NULL;
novo->esq = NULL;

return novo;
}

void n_free(no *n)
{
if(n != NULL)
  {
  n_free(n->esq);
  n_free(n->dir);
  free(n);
  }
}

void tree_free(tree **t)
{
tree *aux = *t;
if(aux->raiz != NULL) return;
  
n_free(aux->raiz);

free(aux);
}


bool tree_vazia(tree *t)
{
return t->raiz == NULL;
}

void aluno_inserir(tree *t, int matricula, char *nome, float media)
{
if(tree_vazia(t))
  {
  t->raiz = noABB_criar(matricula, nome, media);
  return;
  }
add(t->raiz, matricula, nome, media);
}

void add(no *n, int matricula, char *nome, float media)
{
no *novo = noABB_criar(matricula, nome, media);
if(n->info->media > media)
  {
  if(n->esq == NULL)
    {
    n->esq = novo;
    return;
    }
  add(n->esq, matricula, nome, media);
  }else{
  if(n->dir == NULL)
    {
    n->dir = novo;
    return;
    }
  add(n->dir, matricula, nome, media);
  }
}

void busca(no *n, float media)
{
if(n->info->media == media)
  {
  printf("\nnumero matricula> %d\nnome> %s\nmedia> %.2f", n->info->matricula, n->info->nome, n->info->media);
  return;
  }
if(n->info->media > media)
  {
  if(n->esq == NULL) 
    {
    puts("\nmedia nao encontrada..\n");
    return;
    }
  busca(n->esq, media);
  }
if(n->info->media < media)
  {
  if(n->dir == NULL)
    {
    puts("\nmedia nao encontrada..\n"); 
    return;
    }
  busca(n->dir, media);
  }
}

void aluno_busca(tree *t, float media)
{
if(tree_vazia(t)) return;

busca(t->raiz, media);
}

void busca_maior(no *n)
{
if(n->dir != NULL)
  busca_maior(n->dir);
if(n->dir == NULL)
  printf("\nnumero matricula> %d\nnome> %s\nmedia> %.2f", n->info->matricula, n->info->nome, n->info->media);
}

void aluno_maiorMedia(tree *t)
{
if(tree_vazia(t)) return;
busca_maior(t->raiz);
}


no *rmv(no *n, float media)
{
if(n == NULL){
  puts("\nNao encontrado..");
  return NULL;
  }

if(n->info->media == media){
  if(n->dir == NULL && n->esq ==NULL){
    free(n->info);
    free(n);
    return NULL;
    }
  else{
    if(n->esq != NULL && n->dir != NULL){
      no *aux = n->esq;
      aluno *ref;
      while(aux->dir != NULL)
        aux = aux->dir;
      ref = n->info;
      n->info = aux->info;
      aux->info = ref;
      n->esq = rmv(n->esq, media);
      return n;
      }
    else{
      no *aux;
      if(n->esq != NULL)
        aux = n->esq;
      else
        aux = n->dir;
      
      free(n->info);
      free(n);
      return aux;
    }
  }
}
else{
  if(media > n->info->media)
    n->dir = rmv(n->dir, media);
  else
    n->esq = rmv(n->esq, media);
  
  return n;
}
}


void aluno_remove(tree *t, float media)
{
  if(t == NULL){
  puts("\nvazio..");
  return;
  }
  t->raiz = rmv(t->raiz, media);
}

void in_order(tree *t)
{
if(tree_vazia(t)) return;

printf("In_order: ");
in(t->raiz);
}

void in(no *n)
{
if(n != NULL)
  {
  in(n->esq);
  printf("\n\nnumero matricula> %d\nnome> %s\nmedia> %.2f", n->info->matricula, n->info->nome, n->info->media);
  in(n->dir);
  }
}

int aprov(no *n)
{
int c=1;

if(n==NULL)
  return 0;

if(n->info->media >= 5.0 && n != NULL){
  c += aprov(n->esq) + aprov(n->dir); 
  return c ;
  }
  
return 0;
}


void aluno_aprovados(tree *t)
{
if(t == NULL || t->raiz == NULL) return;
int c =0;
c = aprov(t->raiz);
printf("%d\n", c);
}