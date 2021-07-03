#ifndef RUANSILVA2018216035_INCLUDED
#define RUANSILVA2018216035_H_INCLUDED

#define TAM_VETOR 10

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO
     };


typedef struct
{
    int dado;
} dados;

typedef struct No
{
    dados recebe;
    struct No *prox;
} Node;

typedef struct
{
    int validador;
    int tamanho;
    Node *head;
    int qntd;
} Lista;


Lista *trab2, *trab2aux;




void inicializar();

Lista* criar_Lista();
void Push(Lista *origem, int valor);
void Pop(Lista *origem, int posicao);
void removerFim(Lista *origem, int posicao);
void removerNoEspecifico(Lista *origem, int posicao, int valor);

int Estrutura_Vazia(Lista *origem);

int consta_Na_base(Lista *origem, int posicao, int valor);



void show_log(char *str);


int criarEstruturaAuxiliar(Lista *origem, int posicao, int tamanho);
int inserirNumeroEmEstrutura(Lista *origem, int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(Lista *origem, int posicao);
int excluirNumeroEspecificoDeEstrutura(Lista *origem, int posicao, int valor);
int getDadosEstruturaAuxiliar(Lista *origem, int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(Lista *origem, int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(Lista *origem, int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(Lista *origem, int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(Lista *origem, int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(Lista *origem, int posicao);
Node *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(Lista *origem, int vetorAux[]);
void destruirListaEncadeadaComCabecote(Lista *origem);

void inicializar();
void finalizar();
void dobrar(int *x);
void insertionSort(int *vet, int tam);




#endif // RUANSILVA2018216035-T2_H_INCLUDED
