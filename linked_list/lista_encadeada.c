#include<stdlib.h>
#include<stdio.h>
#include"listas.h"

int main()
{
list *lista;
lista = listaIniciar(1);
listaAddOrdenado(lista,8);
listaAddOrdenado(lista,5);
listaAddOrdenado(lista,2);

listaImprimir(lista);
return 0;   
}