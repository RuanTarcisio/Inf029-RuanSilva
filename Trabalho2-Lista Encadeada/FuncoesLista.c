#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "RuanSilva2018216035-T2.h"


Lista* criar_Lista()
{
    Lista *list= (Lista*) malloc(sizeof(Lista)* TAM_VETOR);

    for(int ndx=0; ndx < TAM_VETOR; ndx++)
     {
        list[ndx].head = NULL;
        list[ndx].tamanho = 0;
        list[ndx].qntd = 0;
        list[ndx].validador = 0;
    }

    return list;
}


void inicializar()
{
    trab2 = criar_Lista();

    trab2[0].tamanho = 2;
    trab2[1].tamanho = 4;
    trab2[3].tamanho = 8;
    trab2[4].tamanho = 3;
    trab2[6].tamanho = 5;

}


void Push(Lista *origem, int posicao, int valor)
{
    Node* cache = (Node*) malloc(sizeof(Node));
    cache->recebe.dado = valor;

    cache->prox = origem[posicao].head;
    origem[posicao].head = cache;
    origem[posicao].qntd ++;
    origem[posicao].validador = 1;
}


void removerFim(Lista *origem, int posicao)
{
    Node *cache = origem[posicao].head;


    if(origem[posicao].head->prox == NULL)
    {
        origem[posicao].head = NULL;
        origem[posicao].qntd--;
    }

    else
    {
        Node *atual;
        for(cache = origem[posicao].head; cache->prox != NULL; cache = cache->prox)
        {
            atual = cache;
        }
        atual->prox = NULL;

        origem[posicao].qntd--;
    }

    free(cache);
}

int consta_Na_base(Lista *origem, int posicao, int valor)
{
    Node *cache = malloc(sizeof(Node));
    cache = origem->head;

    int validador = -1;

    if(origem == NULL)
    {
        validador = 0;
    }
    else
    {
        if(cache->recebe.dado == valor)
        {
            validador = 1;
        }
        else
        {
            for(cache = origem[posicao].head; cache != NULL && cache->recebe.dado != valor; cache = cache->prox);
        }
        if(cache == NULL)
        {
            validador = 0;
        }
        else
            validador = 1;
    }
}
