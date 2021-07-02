#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "RuanSilva2018216035-T2.h"


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > TAM_VETOR)
        return 0;
    else
        return 1;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(Lista *origem, int posicao, int tamanho)
{
    if (tamanho < 1 )
    {
        return TAMANHO_INVALIDO;
    }
    else if (ehPosicaoValida(posicao) == 0)
    {
        return POSICAO_INVALIDA;
    }
    else if (origem[posicao].head != NULL || origem[posicao].tamanho != 0)
    {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    /*else if (origem[posicao].auxiliar == NULL)    LISTA ALOCADA DINAMICAMENTE 10 POSIÇÕES
        return SEM_ESPACO_DE_MEMORIA;*/

    else{
        origem[posicao].tamanho = tamanho;
        origem[posicao].validador = 1;
    }
    return SUCESSO;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES*/

int inserirNumeroEmEstrutura(Lista *origem, int posicao, int valor)
{
    Node *cache = (Node*)malloc(sizeof(Node));
    cache->recebe.dado = valor;
    cache->prox = origem[posicao].head;

    int resultado = 0;

    if (ehPosicaoValida(posicao) == 0)
        resultado = POSICAO_INVALIDA;

    else if (origem[posicao].tamanho == 0 )
        resultado = SEM_ESTRUTURA_AUXILIAR;

    else if (origem[posicao].tamanho <= origem[posicao].qntd)
        resultado = SEM_ESPACO;

    else
    {
        cache->prox = origem[posicao].head;
        origem[posicao].head = cache;
        origem[posicao].qntd++;
        resultado = SUCESSO;
    }

    return resultado;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(Lista *origem, int posicao)
{

    /*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
    int resultado = 0;


    if (ehPosicaoValida(posicao) == 0){
        resultado = POSICAO_INVALIDA;

    }
    else if (origem[posicao].validador == 0 ){
        resultado = SEM_ESTRUTURA_AUXILIAR;

    }
    else if (origem[posicao].head == NULL){
        resultado = ESTRUTURA_AUXILIAR_VAZIA;

    }
    else if (origem[posicao].head != NULL)
    {
        removerFim(origem, posicao);
        resultado = SUCESSO;
    }

    return resultado;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(Lista *origem, int posicao, int valor)
{
    int existe = 0, retorno = 0;

    existe = consta_Na_base(origem, posicao, valor);


    if (ehPosicaoValida(posicao) == 0)
        retorno = POSICAO_INVALIDA;

    else if (origem[posicao].validador == 0 )
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (origem[posicao].qntd == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else if(existe == -1)
        retorno = NUMERO_INEXISTENTE;

    else
    {
        removerNoEspecifico(origem, posicao, valor);
        retorno = SUCESSO;
    }

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosEstruturaAuxiliar(Lista *origem, int posicao, int vetorAux[])
{
    int retorno = 0, ndx = 0;
    Node *cache;

    if (ehPosicaoValida(posicao) == 0)
        retorno = POSICAO_INVALIDA;

    else if (origem[posicao].validador == 0 )
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else
    {
        for(cache = origem[posicao].head; cache != NULL; cache = cache->prox)
        {
            vetorAux[ndx] = cache->recebe.dado;
            ndx++;
        }
    retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(Lista *origem, int posicao, int vetorAux[])
{

    int retorno, tamanho = 0;

    if (ehPosicaoValida(posicao) == 0)
        retorno = POSICAO_INVALIDA;

    else if (origem[posicao].validador == 0 )
        retorno = SEM_ESTRUTURA_AUXILIAR;


    else
    {
        for(tamanho = 0; vetorAux[tamanho] != '\0'; tamanho++);
        insertionSort(vetorAux, tamanho);
        retorno = SUCESSO;
    }

printf("\n  retorno: %d ", retorno);
system("pause");
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
Node *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(Node *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(Node **inicio)
{
}



/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
