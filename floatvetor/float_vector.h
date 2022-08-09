//ARQUIVO ESPECIFICACOES

#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

typedef struct float_vector FloatVector;

//ASSINATURAS COM NOMES QUE PODEM ENTRAR EM CONFLITO(TOMAR CUIDADO)

FloatVector *create(int tam);
void destroy(FloatVector  **vet_ref);
int size(const FloatVector *vector);
int capacity(const FloatVector *vector);
float at(const  FloatVector *vector, int pos);
float get(const FloatVector *vector, int pos);
void append(FloatVector *vector, float elem);
void print(const FloatVector *vector);

//INCLUIR FUNCOES
//bool compare(FloatVector, FloatVector);
//void split(FloatVector, FloatVector);
//void join(FloatVector, FloatVector);
//bool isfull(FloatVector);

#endif