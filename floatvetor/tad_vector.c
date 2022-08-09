#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "float_vector.h"

int main(int argc, char *argv[])
  {
  FloatVector *vetor = create(5);

  append(vetor, 2);
  append(vetor, 4);
  append(vetor, 7);
  append(vetor, 9);
  append(vetor, 3);
  print(vetor);

  destroy(&vetor);

  return 0;
  }