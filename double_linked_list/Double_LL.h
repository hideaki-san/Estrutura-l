#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct LISTA doubleList;
typedef struct OBJETO vetor;

doubleList *listaCriar(float valor);
vetor *objetoCriar(float valor);
void listaInicio(doubleList *DL, float valor);
void listaFim(doubleList *DL, float valor);
void listaMeio(doubleList *DL, int posicao, float valor);
void listaImprimir(doubleList *DL);
void listaLiberar(doubleList *DL);
void listaDeletar(doubleList *DL, float valor);

#endif