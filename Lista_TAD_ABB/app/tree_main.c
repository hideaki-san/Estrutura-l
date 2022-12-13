#include<stdio.h>
#include<stdlib.h>
#include "../include/tree.h"

int main()
{
tree *aluno = tree_criar();
int matricula, c=-1;
float media;
char nome[50];
do
{
  switch(c)
  {
  case 1:
  puts("INSERIR ALUNO>");
  printf("\nnome> ");
  fflush(stdin);
  scanf("%s", &nome);
  printf("\nmedia> ");
  fflush(stdin);
  scanf("%f", &media);
  matricula = rand() % 1000;
  aluno_inserir(aluno, matricula, nome, media);
  puts("\nINSERIDO COM SUCESSO\n");
  system("pause");
  c = -1;
  break;

  case 2:
  puts("REMOVER ALUNO>");
  printf("\nmedia> ");
  fflush(stdin);
  scanf("%f", &media);
  aluno_remove(aluno, media);
  puts("REMOVIDO COM SUCESSO\n");
  system("pause");
  c = -1;
  break;

  case 3:
  puts("BUSCA PELA MEDIA> ");
  scanf("%f", &media);
  aluno_busca(aluno, media);
  printf("\n\n");
  system("pause");
  c =- 1;
  break;

  case 4:
  puts("MAIOR MEDIA> ");
  aluno_maiorMedia(aluno);
  printf("\n\n");
  system("pause");
  c = -1;
  break;

  case 5:
  printf("APROVADOS> ");
  aluno_aprovados(aluno);
  system("pause");
  c = -1;
  break; 

  case 6:
  in_order(aluno);
  printf("\n\n");
  system("pause"); 
  c = -1;
  break;

  default:
  system("cls");
  printf("ABB> \n[1] inserir\n[2] remover\n[3] pesquisar\n[4] Maior Media\n[5] Alunos Aprovados\n[6] Listar\n[0] SAIR\nopcao: ");
  fflush(stdin);
  scanf("%d", &c);
  system("cls");
  break;
  }
}while(c != 0);

tree_free(&aluno);
return 0;
}