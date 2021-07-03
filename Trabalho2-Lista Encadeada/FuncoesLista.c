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
    trab2aux = (Lista*)malloc(sizeof(Lista));

    trab2[0].tamanho = 2;
    trab2[1].tamanho = 4;
    trab2[3].tamanho = 8;
    trab2[4].tamanho = 3;
    trab2[6].tamanho = 5;

}


void Push(Lista *origem, int valor)
{
    Node* cache = (Node*) malloc(sizeof(Node));
    cache->recebe.dado = valor;

    cache->prox = origem->head;
    origem->head = cache;
    origem->tamanho++;

}

void inserirNoFim(Lista *origem, int posicao, int valor)
{
    Node *cache = (Node*)malloc(sizeof(Node));
    cache->recebe.dado = valor;
    cache->prox = NULL;

    if(origem[posicao].head == NULL)
    {
        origem[posicao].head = cache;
        origem[posicao].qntd++;
    }
    else
    {   Node *atual;
        for(atual = origem[posicao].head; atual->prox != NULL; atual = atual->prox);

        atual->prox = cache;
        origem[posicao].qntd++;
    }

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


void removerNoEspecifico(Lista *origem, int posicao, int valor)
{
    Node *cache = (Node*) malloc(sizeof(Node));
    cache = origem[posicao].head;

    if(cache->recebe.dado == valor)
    {
        origem[posicao].head = cache->prox;
        origem[posicao].qntd--;
        free(cache);
    }
    else
    {
        Node *atual;

        for(cache = origem[posicao].head; cache != NULL && cache->recebe.dado != valor; cache = cache->prox)
        {
            atual = cache;
        }

        if(cache != NULL)
        {
            atual->prox = cache->prox;
            origem[posicao].qntd--;
            free(cache);
        }
    }
}


int consta_Na_base(Lista *origem, int posicao, int valor)
{
    Node *cache = malloc(sizeof(Node));
    cache = origem[posicao].head;

    int validador = 0;

    if(origem[posicao].head == NULL)
    {
        validador = -1;
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
            validador = -1;
        }
        else
            validador = 1;
    }
    return validador;
}

void insertionSort(int *vet, int tam)
{
    int j;

    for(int i = 1; i < tam; i++)
    {
        int x = vet[i];
        for(j = i - 1; j >= 0 && x < vet[j]; j--)
        {
            vet[j+1] = vet[j];
        }
        vet[j+1] = x;
    }
}

int Estrutura_Vazia(Lista *origem)
{

    int vazia = 0;

    for (int i = 0; i < TAM_VETOR; i++)
    {
        Node *cache = origem[i].head;
        if(cache == NULL)
        {
            /*printf("  aq  %d   ", i);
            system("pause");*/
            vazia++;
        }
    }

    /*printf("VAZIO ? %d ", vazia);
    system("pause");
    system("pause");*/




    if (vazia == TAM_VETOR)
        return 1;

    return 0;
}


void Pop(Lista *origem, int posicao)
{
    Node *cache = (Node*) malloc(sizeof(Node));
    cache = origem[posicao].head;

    if(origem[posicao].head == NULL)
    {

    }
    else
    {
        origem[posicao].head = cache->prox;
        origem[posicao].qntd--;
    }
    free(cache);
}
