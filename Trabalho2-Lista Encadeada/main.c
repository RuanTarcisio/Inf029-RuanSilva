#include <stdio.h>
#include <stdlib.h>

#include "RuanSilva2018216035-T2.h"

void show_log(char *str);

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeExcluirNumeroEspecifico();
void testeListar();
void testeRetornarTodosNumeros();
void testeMudarTamanhoEstrutura();
void testeListaEncadeada();

int main()
{
    inicializar();
    testeInserirSemNada();
    testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    /*testeExcluirNumeroEspecifico();
    testeListar();
    testeRetornarTodosNumeros();
    testeMudarTamanhoEstrutura();
    testeListaEncadeada();
    finalizar();*/
}
int ligado = 0;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}

void testeInserirSemNada()
{
	printf("Inserir sem nada\n");
    show_log("testeInserirSemNada()");
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, -2, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 0, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 11, 2) == POSICAO_INVALIDA);
}

void testeCriarEstrutura()
{
	printf("Criar estrutura\n");
    show_log("testeCriarEstrutura()");
    printf("%d\n", criarEstruturaAuxiliar(trab2, -2, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 0, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 11, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, -5) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, 0) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, 3) == SUCESSO);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
}
/*
2 [ , , ]
*/

void testeInserirComEstrutura()
{
	printf("Inserir com estrutura\n");
    show_log("testeInserirComEstrutura()");
    //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 4) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, -2) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 5) == SEM_ESPACO);
}
/*
2 [4,-2,6]
*/

void testeExcluir()
{
	printf("Excluir\n");
    show_log("testeExcluir()");
    //###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 0) == POSICAO_INVALIDA);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == ESTRUTURA_AUXILIAR_VAZIA);
}

