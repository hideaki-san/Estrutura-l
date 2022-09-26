#include<stdlib.h>
#include<stdio.h>
#include"listas.h"

int main()
{
int o = -1, val = 0, pos = 0, init = 0;
list *lista;

do{
  switch (o)
    {
    case 1:
    system("cls");
    printf("\nINSIRA O VALOR: ");
    fflush(stdin);
    scanf("%d", &val);
    if(init == 0)
      {
      lista = listaIniciar(val);
      init++;
      o = -1;
      break;
      }
    listaAddInicio(lista, val);
    o = -1;
    break;

    case 2:
    system("cls");
    printf("\nINSIRA O VALOR: ");
    fflush(stdin);
    scanf("%d", &val);
    if(init == 0)
      {
      lista = listaIniciar(val);
      init++;
      o = -1;
      break;
      }
    listaAddFinal(lista, val);
    o = -1;
    break;

    case 3:
    system("cls");
    printf("\nINSIRA O VALOR: ");
    fflush(stdin);
    scanf("%d", &val);
    if(init == 0)
      {
      lista = listaIniciar(val);
      init++;
      o = -1;
      break;
      }
    printf("\nINSIRA A POSICAO: ");
    fflush(stdin);
    scanf("%d", &pos);
    listaAddMeio(lista, pos, val);
    o = -1;
    break;

    case 4:
    system("cls");
    printf("\nINSIRA O VALOR: ");
    fflush(stdin);
    scanf("%d", &val);
    if(init == 0)
      {
      lista = listaIniciar(val);
      init++;
      o = -1;
      break;
      }
    listaAddOrdenado(lista, val);
    o = -1;
    break;

    case 7:
    system("cls");
    listaImprimir(lista);
    system("pause");
    o = -1;
    break;
    
    case 8:
    system("cls");
    printf("\nINSIRA VALOR QUE DESEJA EXCLUIR: ");
    fflush(stdin);
    scanf("%d", &val);
    listaDeletar(lista, val);
    o = -1;
    break;

    default:
    system("cls");
    printf("\n ADICIONAR NA LISTA\n\t[1] - Inicio\n\t[2] - Final\n\t[3] - Meio\n\t[4] - Ordenado\n [0] SAIR\n [7] IMPRIRMIR LISTA\n [8] DELETAR ELEMENTO\n ESCOLHA: ");
    fflush(stdin);
    scanf("%d", &o);
    break;
  }
}while(o != 0);

system("cls");
listaFree(lista);
return 0;   
}