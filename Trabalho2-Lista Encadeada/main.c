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
    testeExcluirNumeroEspecifico();
    testeListar();
    testeRetornarTodosNumeros();
    /*testeMudarTamanhoEstrutura();
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
	printf("\nInserir sem nada\n\n");
    show_log("testeInserirSemNada()");
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, -2, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 0, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 11, 2) == POSICAO_INVALIDA);
}

void testeCriarEstrutura()
{
	printf("\nCriar estrutura\n\n");
    show_log("testeCriarEstrutura()");
    printf("%d\n", criarEstruturaAuxiliar(trab2, -2, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 0, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 11, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, -5) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, 0) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, 3) == SUCESSO);
    printf("%d\n", criarEstruturaAuxiliar(trab2, 2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
}

void testeInserirComEstrutura()
{
	printf("\nInserir com estrutura\n\n");
    show_log("testeInserirComEstrutura()");
    //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 4) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, -2) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 5) == SEM_ESPACO);
}

void testeExcluir()
{
	printf("\nExcluir\n\n");
    show_log("testeExcluir()");
    //###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 0) == POSICAO_INVALIDA);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == ESTRUTURA_AUXILIAR_VAZIA);

}


void testeExcluirNumeroEspecifico()
{
    printf("\nExcluirNumeroEspecifico\n\n");
    //###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
    printf("%d\n", criarEstruturaAuxiliar(trab2, 9, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 9, 7) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(trab2, 9, 12) == NUMERO_INEXISTENTE);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(trab2, 9, 7) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(trab2, 1, 2) == SEM_ESTRUTURA_AUXILIAR);
}


void testeListar()
{
    printf("\nListar\n\n");
    //###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 7) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, -9) == SUCESSO);

    int vet[2];

    printf("%d\n", getDadosEstruturaAuxiliar(trab2, 1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", getDadosEstruturaAuxiliar(trab2, 11, vet) == POSICAO_INVALIDA);
    printf("%d\n", getDadosEstruturaAuxiliar(trab2, 2, vet) == SUCESSO);

    printf("%d\n", vet[0] == 7);
    printf("%d\n", vet[1] == -9);

    printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(trab2, 1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(trab2, 11, vet) == POSICAO_INVALIDA);
    printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(trab2, 2, vet) == SUCESSO);

    printf("%d\n", vet[0] == -9);
    printf("%d\n", vet[1] == 7);

    printf("%d\n", getDadosEstruturaAuxiliar(trab2, 2, vet) == SUCESSO);

    printf("%d\n", vet[0] == 7);
    printf("%d\n", vet[1] == -9);

    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(trab2, 2) == SUCESSO);
}

void testeRetornarTodosNumeros()
{
    printf("\nRetornarTodosNumeros\n\n");
    show_log("testeRetornarTodosNumeros()");
    int vet1[2];
    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 8) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 2, 0) == SUCESSO);
    /*
2 [3,8,0]
*/

    printf("%d\n", criarEstruturaAuxiliar(trab2, 5, 10) == SUCESSO);

    printf("%d\n", inserirNumeroEmEstrutura(trab2, 5, 1) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 5, 34) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 5, 12) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 5, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 5, 27) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(trab2, 5, -6) == SUCESSO);
    /*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/
    int vet[9];

    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);

    printf("%d\n", vet[0] == 3);
    printf("%d\n", vet[1] == 8);
    printf("%d\n", vet[2] == 0);
    printf("%d\n", vet[3] == 1);
    printf("%d\n", vet[4] == 34);
    printf("%d\n", vet[5] == 12);
    printf("%d\n", vet[6] == 6);
    printf("%d\n", vet[7] == 27);
    printf("%d\n", vet[8] == -6);

    int vet2[9];

    printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet2) == SUCESSO);

    printf("%d\n", vet2[0] == -6);
    printf("%d\n", vet2[1] == 0);
    printf("%d\n", vet2[2] == 1);
    printf("%d\n", vet2[3] == 3);
    printf("%d\n", vet2[4] == 6);
    printf("%d\n", vet2[5] == 8);
    printf("%d\n", vet2[6] == 12);
    printf("%d\n", vet2[7] == 27);
    printf("%d\n", vet2[8] == 34);

    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);

    printf("%d\n", vet[0] == 3);
    printf("%d\n", vet[1] == 8);
    printf("%d\n", vet[2] == 0);
    printf("%d\n", vet[3] == 1);
    printf("%d\n", vet[4] == 34);
    printf("%d\n", vet[5] == 12);
    printf("%d\n", vet[6] == 6);
    printf("%d\n", vet[7] == 27);
    printf("%d\n", vet[8] == -6);
}
