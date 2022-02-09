#define TAM_MAX  1000

typedef enum{
    Desmarcada,
    Marcada
} Situacao;

typedef struct celula
{
    Situacao situacao;
    char nome[TAM_MAX];
}Celula;


void inicializaLista(Celula*** lista, int N);

void permutar(Celula ***cidades,
                        int N,
                        int pos,
                        char array[],
                        char** permutacoes,
                        int* j);
