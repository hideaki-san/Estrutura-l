#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Double_LL.h"

int main()
{
srand((unsigned) time(NULL));

doubleList *lista1 = listaCriar();
doubleList *lista2 = listaCriar();

for(int m = 0; m < 3; m++)
  listaInicio(lista1, rand() % 130/10.0);

for(int m = 0; m < 4; m++)
  listaFim(lista1, rand() % 150/10.0);


for(int m = 0; m < 4; m++)
  listaInicio(lista2, rand() % 130/10.0);

for(int m = 0; m < 3; m++)
  listaFim(lista2, rand() % 150/10.0);


listaImprimir(lista1);
listaImprimir(lista2);

doubleList *novo = listaUnir(lista1, lista2);

listaImprimir(novo);

listaMeio(novo, 5, 33.33);

listaImprimir(novo);

listaLiberar(novo);

return 0;
}