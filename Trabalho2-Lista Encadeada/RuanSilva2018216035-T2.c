#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "RuanSilva2018216035-T2.h"



void inicializar()
{
    trab2 = criar_Lista();

    trab2[0].tamanho = 2;
    trab2[1].tamanho = 4;
    trab2[3].tamanho = 8;
    trab2[4].tamanho = 3;
    trab2[6].tamanho = 5;

    Push(trab2, 0, 4);
    Push(trab2, 1, 3);
    Push(trab2, 1, 5);
    Push(trab2, 3, 23);
    Push(trab2, 3, 35);
    Push(trab2, 3, 2);
    Push(trab2, 4, 6);
    Push(trab2, 6, -16);
    Push(trab2, 6, 18);
    Push(trab2, 6, -1);


}



// se posi��o � um valor v�lido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > TAM_VETOR)
        return 0;
    else
        return 1;
}



void dobrar(int *x)
{

    *x = *x * 2;
}

/*
Objetivo: criar estrutura auxiliar na posi��o 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - j� tem estrutura na posi��o
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espa�o de mem�ria
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
    else if (origem[posicao].tamanho != 0)
    {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    /*else if (origem[posicao].auxiliar == NULL)    LISTA ALOCADA DINAMICAMENTE 10 POSI��ES
        return SEM_ESPACO_DE_MEMORIA;*/

    else
        origem[posicao].tamanho = tamanho;

    return SUCESSO;

}

/*
Objetivo: inserir n�mero 'valor' em estrutura auxiliar da posi��o 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - n�o tem espa�o
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
CONSTANTES*/

int inserirNumeroEmEstrutura(Lista *origem, int posicao, int valor)
{
    Node *cache = (Node*)malloc(sizeof(Node));
    cache->recebe.dado = valor;


    if (ehPosicaoValida(posicao) == 0)
        return POSICAO_INVALIDA;

    else if (origem[posicao].tamanho == 0 )
        return SEM_ESTRUTURA_AUXILIAR;

    else if (origem[posicao].tamanho <= origem[posicao].qntd)
        return SEM_ESPACO;

    else
    {
        Push(origem, posicao, valor);
    }

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Ap�s excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta � uma exclus�o l�gica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(Lista *origem, int posicao)
{

    if (ehPosicaoValida(posicao) == 0)
        return POSICAO_INVALIDA;

    else if (origem[posicao].tamanho == 0)
        return SEM_ESTRUTURA_AUXILIAR;

    else if (origem[posicao].qntd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    else
        removerFim(origem, posicao);

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posi��o 'posicao'.
Caso seja excluido, os n�meros posteriores devem ser movidos para as posi��es anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta � uma exclus�o l�gica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posi��o 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    NUMERO_INEXISTENTE - N�mero n�o existe
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar

int excluirNumeroEspecificoDeEstrutura(Lista *origem, int posicao, int valor)
{
    int existe = 0;
    int aux;
    posicao--;

    if (ehPosicaoValida(posicao) == 0)
        return POSICAO_INVALIDA;

    else if (origem[posicao].tamanho == 0)
        return SEM_ESTRUTURA_AUXILIAR;

    else if (origem[posicao].qntd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    else if(consta_na_Base(origem, valor) == 0)
        return NUMERO_INEXISTENTE;

    else
        /*remover_NoEspecifico(origem, posicao, valor);

    return SUCESSO;
}


/*
Objetivo: retorna os n�meros da estrutura auxiliar da posi��o 'posicao (1..10)'.
os n�meros devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/

int getDadosEstruturaAuxiliar(Lista *origem, int posicao, int vetorAux[])
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: retorna os n�meros ordenados da estrutura auxiliar da posi��o 'posicao (1..10)'.
os n�meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: retorna os n�meros de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares est�o vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os n�meros ordenados de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares est�o vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posi��o 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho n�o pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na aloca��o do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posi��o 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posi��o inv�lida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um n�mero int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabe�ote com todos os n�meros presentes em todas as estruturas.

Retorno (No*)
    NULL, caso n�o tenha nenhum n�mero nas listas
    No*, ponteiro para o in�cio da lista com cabe�ote
*/
Node *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os n�meros da lista enceada com cabe�ote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(Node *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabe�ote a partir de in�cio.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(Node **inicio)
{
}



/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espa�os de mem�ria das estruturas auxiliares.

*/

void finalizar()
{
}
