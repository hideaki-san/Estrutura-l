//ASSINATURAS

//Faz a troca dos valores no vetor
void swap(int *n, int *m);

//FAZ A COMPARACAO SEMPRE COM A POSICAO ADJACENTE 
//CASO POSICAO ATUAL SEJA MAIOR QUE A PROXIMA OCORRE A TROCA
//LEVA O MAIOR VALOR PARA A POSICAO FINAL
void bubble(int *vetor, int size, FILE *arq);

//FAZ A COMPARACAO DA POSICAO ATUAL COM TODAS AS OUTRAS
//CASO POSICAO ATUAL SEJA MAIOR QUE ALGUM VALOR DO VETOR PERCORRIDO
//MENOR VALOR E ARMAZENADO NA PRIMEIRA POSICAO DEPOIS DE MENOR VALOR ANTERIOR
void selection(int *vetor, int size, FILE *arq);

void merge(int *vetor, int inicio, int meio, int fim);

//Faz a impressao ja ordenada do vetor
void printVetor(const int *vetor, int size);
