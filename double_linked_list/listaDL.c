#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Double_LL.h"

int main()
{
srand((unsigned) time(NULL));

doubleList *DL = listaCriar(rand() %140/10.0);

for(int m = 0; m < 4; m++)
  listaInicio(DL, rand() % 130/10.0);

for(int m = 0; m < 5; m++)
  listaFim(DL, rand() % 150/10.0);


listaImprimir(DL);
listaDeletar(DL, 5);
listaOrdenar(DL);
listaTroca(DL, 3, 6);
listaImprimir(DL);

listaLiberar(DL);

return 0;
}