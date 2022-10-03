#include <stdlib.h>
#include <stdio.h>
#include "Double_LL.h"

int main()
{

doubleList *DL = listaCriar(23.3);
listaInicio(DL, 32.5);
listaInicio(DL, 11.4);
listaFim(DL, 22);

listaImprimir(DL);

listaLiberar(DL);

return 0;
}