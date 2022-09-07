#include<stdlib.h>
#include<stdio.h>
#include"listas.h"

int main()
{
list *lista;
lista = listaIniciar(1);
listaAddOrdenado(lista,53);
listaAddOrdenado(lista,64);
listaAddOrdenado(lista,12);
listaAddOrdenado(lista,74);
listaAddOrdenado(lista,85);
listaAddOrdenado(lista,23);

listaImprimir(lista);
listaFree(lista);


printf("\nlista vazia\n");

return 0;   
}