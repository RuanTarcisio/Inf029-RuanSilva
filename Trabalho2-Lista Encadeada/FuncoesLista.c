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
    }

    return list;
}

void Push(Lista *origem, int posicao, int valor)
{
    Node* cache = (Node*) malloc(sizeof(Node));
    cache->recebe.dado = valor;

    cache->prox = origem[posicao].head;
    origem[posicao].head = cache;
    origem[posicao].qntd ++;
}


void removerFim(Lista *origem, int posicao)
{
    Node *cache = (Node*)malloc(sizeof(Node));
    Node *atual;

    for(cache = origem[posicao].head; cache->prox != NULL; cache = cache->prox)
    {
        atual = cache;
    }
    atual->prox = cache->prox;

}
