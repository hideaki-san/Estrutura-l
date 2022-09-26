#ifndef LISTA_H
#define LISTA_H

typedef struct INFO info;
typedef struct LIST list;

info *infoCriar(int valor);
list *listaIniciar(int valor);
void listaAddInicio(list *L, int valor);
void listaAddFinal(list *L, int valor);
void listaAddMeio(list *L, int pos, int valor);
void listaAddOrdenado(list *L, int valor);
void listaImprimir(list *L);
void listaFree(list *L);

//ADICIONAR
void listaDeletar(list *L, int valor);
//void listaOrdenar(list *L);

#endif