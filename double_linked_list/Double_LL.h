#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct LISTA doubleList;
typedef struct OBJETO vetor;

doubleList *listaCriar();
vetor *objetoCriar(float valor);
void listaInicio(doubleList *DL, float valor);
void listaFim(doubleList *DL, float valor);
void listaMeio(doubleList *DL, int posicao, float valor);
void listaOrdenar(doubleList *DL);
void listaTroca(doubleList *DL, int p1, int p2);
void listaImprimir(doubleList *DL);
void listaConsulta(doubleList *DL, int pos);
void listaLiberar(doubleList *DL);
void listaDeletar(doubleList *DL, int pos);
doubleList *listaUnir(doubleList *DL1, doubleList *DL2);

#endif