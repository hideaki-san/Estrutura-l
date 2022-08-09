//ARQUIVO FUNCOES

#include "float_vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct float_vector
  {
  int capacity; //num max de elemento
  int size;     //num atual de elemntos
  float *data;  //vetor de float
  };

/**
 * @brief Cria(aloca) um vetor de floats com uma dada capacidade.
 * 
 * @param capacity Capacidade do vetor.
 * @return FloatVector* um vetor de floats alocado/criado.
 */ 

FloatVector *create(int tam)
  {
  FloatVector *vet = (FloatVector *)calloc(1, sizeof(FloatVector));
  vet->capacity = tam;
  vet->size = 0;
  vet->data = (float *) calloc(vet->capacity, sizeof(float));
  
  return vet;
  };

void destroy(FloatVector **vet_ref)
  {
  FloatVector *vet = *vet_ref;
  free(vet->data);
  free(vet);
  *vet_ref = NULL;
  }

int size(const FloatVector *vector)
  {
  return vector->size;
  }

int capacity(const FloatVector *vector)
  {
  return vector->capacity;
  }

float at(const FloatVector *vector, int pos)
  {
//FORMA DE DRIBLAR A SAIDA DO PROGRAMA
//RECURSIVIDADE, CHAMAR A FUNÇAO NOVAMENTE ATE RECEBER POSIÇAO EXISTENTE
  if(pos < 0 || pos >= vector->size)
    {
    fprintf(stderr, "ERRO: POSIÇAO INVALIDA!\n");
    fprintf(stderr, "ENDEREÇO [%d] FORA DO LIMITE\n");
    at(vector, pos);
    }

  return vector->data[pos];
  }


//SEM VERIFICAÇAO DO ELEMENTO NA POSIÇAO
//PARA QUANDO VETOR ESTIVER CHEIO, QUANDO (capacity == size)

float get(const FloatVector *vector, int pos)
  {
  return vector->data[pos];
  }


void append(FloatVector *vector, float elem)
  {
  if(vector->size == vector->capacity)
    {
    fprintf(stderr, "ERRO: VETOR CHEIO!");
    exit(EXIT_FAILURE);
    }
  vector->size++;
  vector->data[vector->size] = elem;
  }


void print(const FloatVector *vector)
  {
  int ref = 1;

  printf("\nCAPACIDADE: [%d]\nTAMANHO: [%d]\nELEMENTOS:\n", vector->capacity, vector->size);
  while(ref <= vector->size)
    {
    printf("[%f]\n", vector->data[ref]);
    ref++;
    }
  }