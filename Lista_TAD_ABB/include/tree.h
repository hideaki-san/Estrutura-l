#ifndef TREE_H
#define TREE_H

#include<stdbool.h>

typedef struct ALUNO aluno;
typedef struct noABB no;
typedef struct TREE tree;

tree *tree_criar();
no *noABB_criar(int matricula, char *nome, float media);

void tree_free(tree **t);

bool tree_vazia(tree *t);

void aluno_inserir(tree *t, int matricula, char *nome, float media);
void aluno_remove(tree *t, float media);
void aluno_busca(tree *t, float media);
void aluno_maiorMedia(tree *t);
void aluno_aprovados(tree *t);

void in_order(tree *t);

#endif