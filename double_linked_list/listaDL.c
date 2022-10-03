#include <stdlib.h>
#include <stdio.h>
#include "Double_LL.h"

int main()
{

doubleList *DL = listaCriar(23.3);

for(int m = 0; m < 7; m++)
{
float rnd = rand() % 50;
listaInicio(DL, rnd);
}

for(int m = 0; m < 7; m++)
{
float rnd = rand() % 50;
listaFim(DL, rnd);
}


listaImprimir(DL);

listaOrdenar(DL);

listaImprimir(DL);

listaLiberar(DL);

return 0;
}