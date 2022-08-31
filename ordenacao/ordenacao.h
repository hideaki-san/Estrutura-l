//ASSINATURAS

typedef struct DADOS dados;
typedef struct VETOR vetor;

//Faz a troca dos valores no vetor
void swap(float *n, float *m);

//FAZ A COMPARACAO SEMPRE COM A POSICAO ADJACENTE 
//CASO POSICAO ATUAL SEJA MAIOR QUE A PROXIMA OCORRE A TROCA
//LEVA O MAIOR VALOR PARA A POSICAO FINAL ONDE ELE SEJA O MAIOR
void bubble(vetor *vetor, int size, FILE *arq);

//FAZ A COMPARACAO DA POSICAO ATUAL COM TODAS AS OUTRAS
//CASO POSICAO ATUAL SEJA MAIOR QUE ALGUM VALOR DO VETOR PERCORRIDO
//MENOR VALOR VAI PARA A PRIMEIRA POSICAO EM QUE ELE SEJA O MENOR 
void selection(vetor *vetor, int size, FILE *arq);

//FAZ A SEPARACAO DO VETOR ATE TAMANHO DO VETOR = 1
int mergesort(vetor *vetor, int inicio, int fim, dados *dado);

//CHAMADA PARA ORDENAR OS VETORES DA INSTANCIA QUE O PROCESSO ESTIVER
void merge(vetor *vetor, int inicio, int meio, int fim, dados *dado);


void quicksort(vetor *vetor, int inicio, int fim, dados *dado);

int quick(vetor *vetor, int inicio, int fim, dados *dado);

//DADOS DAS TROCAS, VARREDURAS E COMPARACOES
dados *dadosCriar();
void dadosPrint(dados *dado, FILE *arq, float tempo, int size);
void dadosLiberar(dados *dado);

vetor *vetorCriar(int size);
void vetorExcluir(vetor *vet);
int vetorSize(vetor *vet);
int vetorQuantidade(vetor *vet);
void vetorImprimir(vetor *vet);
void vetorInserir(vetor *vet, float valor);

//Faz a impressao do vetor
void printVetor(const int *vetor, int size);
