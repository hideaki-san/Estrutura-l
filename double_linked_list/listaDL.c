#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Double_LL.h"

int main()
{
int o = -1, pos = 0, posR = 0, tamanhoListaRef = 0, refLista = 1, tamL1=0, tamL2=0;
float val = 0.0;
doubleList *lista, *lista1 = listaCriar(), *lista2 = NULL;
lista = lista1;
printf("\n[LISTA DUPLAMENTE ENCADEADA]> Realize as funcoes disponiveis.\n");
    printf("\n [0] SAIR\n [1] ADD Inicio\n [2] ADD Final\n [3] ADD Escolha\n [4] TROCA\n [5] CONSULTA\n [6] ORDENAR\n [7] IMPRIRMIR LISTA\n [8] DELETAR ELEMENTO\n ESCOLHA: ");
    fflush(stdin);
    scanf("%d", &o);

do{
  switch (o)
    {
    case 1:
    system("cls");
    printf("\nINSIRA O VALOR> ");
    fflush(stdin);
    scanf("%f", &val);
    
    listaInicio(lista, val);
    tamanhoListaRef++;
    o = -1;
    break;

    case 2:
    system("cls");
    printf("\nINSIRA O VALOR> ");
    fflush(stdin);
    scanf("%f", &val);
    
    listaFim(lista, val);
    tamanhoListaRef++;
    o = -1;
    break;

    case 3:
    system("cls");
    printf("\nINSIRA O VALOR> ");
    fflush(stdin);
    scanf("%f", &val);
    
    printf("\nTAMANHO> %d", tamanhoListaRef);
    printf("\nINSIRA A POSICAO> ");
    fflush(stdin);
    scanf("%d", &pos);
    listaMeio(lista, pos, val);
    tamanhoListaRef++;
    o = -1;
    break;

    case 4:
    system("cls");
    if(tamanhoListaRef > 1)
      {
      listaImprimir(lista);
      printf("\nINSIRA POSICAO> ");
      fflush(stdin);
      scanf("%d", &pos);
      printf("\nINSIRA POSICAO> ");
      fflush(stdin);
      scanf("%d", &posR);
    
      listaTroca(lista, pos, posR);
      }
    o = -1;
    break;

    case 5:
    system("cls");
    if(tamanhoListaRef > 0)
      {
      printf("\nTAMANHO> [%d]", tamanhoListaRef);
      printf("\nINSIRA POSICAO DE CONSULTA> ");
      fflush(stdin);
      scanf("%d", &pos);
      listaConsulta(lista, pos);
      system("pause");
      }
    o = -1;
    break;

    case 6:
    system("cls");
    listaImprimir(lista);
    listaOrdenar(lista);
    listaImprimir(lista);
    system("pause");
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
    if(tamanhoListaRef > 0)
      {
      listaImprimir(lista);
      printf("\nINSIRA POSICAO QUE DESEJA EXCLUIR> ");
      fflush(stdin);
      scanf("%d", &pos);

      listaDeletar(lista, pos);
      tamanhoListaRef--;
      }
    o = -1;
    break;
  
    case 9:
    system("cls");
    printf("teste");
    if(lista2 == NULL)
      {
      lista2 = listaCriar();
      lista = lista2;
      refLista = 2;
      tamL1 = tamanhoListaRef;
      o = -1;
      break;
      }
    
    if(refLista == 1)
      {
      lista = lista2;
      refLista++;
      tamL1 = tamanhoListaRef;
      tamanhoListaRef = tamL2;
      o = -1;
      break;
      }
    else if(refLista == 2)
      {
      lista = lista1;
      refLista--;
      tamL2 = tamanhoListaRef;
      tamanhoListaRef = tamL1;
      o = -1;
      break;
      }
    o = -1;
    break;

    case 10:
    system("cls");
    if(lista2 == NULL) 
      {
      o = -1;  
      break;
      }
    lista1 = listaUnir(lista1, lista2);
    lista = lista1;
    lista2 = NULL;
    refLista = 1;
    o = -1;
    break;

    default:
    system("cls");
    printf("\nLISTA [%d]>\n", refLista);
    printf("\n [0] SAIR\n [1] ADD Inicio\n [2] ADD Final\n [3] ADD Escolha\n [4] TROCA\n [5] CONSULTA");
    printf("\n [6] ORDENAR\n [7] IMPRIRMIR LISTA\n [8] DELETAR ELEMENTO\n [9] IR PARA OUTRA LISTA");
    printf("\n [10] UNIR LISTAS\n ESCOLHA: ");
    fflush(stdin);
    scanf("%d", &o);
    break;
  }
}while(o != 0);


listaLiberar(lista1);
listaLiberar(lista2);
system("cls");
return 0;
}