#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"



void inserir_ArqDisciplina()
{
    _cadastro dados;
    FILE *file;

    file = fopen("ALUNOS_ALL.DAT", "ab");
    if(!file)
    {
        printf("\n ERROR FILE  \n");
        getch();
        exit(0);
    }
    else
    {
        dados = RecebeDados_Materia();
    }
    fclose(file);


}

void ArqSalvar(Node *list, int opcao)
{
    Node* cache;
    FILE *file;

    if(opcao == ALUN)
    {
        file = fopen("ALUNOS_ALL.DAT", "wb");
        if(!file)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(opcao == PROF)
    {
        file = fopen("PROFESSORES_ALL.DAT", "wb");
        if(!file)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }

    for(cache = list; cache != NULL; cache = cache->prox)
    {
        fwrite(&cache->dados, sizeof(cadastro), 1, file);
    }
    fclose(file);


}


Node* ler_Arq(int opcao)
{
    cadastro cache;
    Node *lista = criar_Lista();
    FILE *file;

    if(opcao == ALUN)
    {
        file = fopen("ALUNOS_ALL.DAT", "rb");
        if(!file)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(opcao == PROF)
    {
        file = fopen("PROFESSORES_ALL.DAT", "rb");
        if(!file)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    while(fread(&cache, sizeof(cadastro), 1, file) == 1)
    {
        inserir_Arq(&lista, &cache);
    }
    fclose(file);

    return lista;
}


void inserir_Arq(Node** Geral, cadastro *Pessoas)
{
    Node* novo = (Node*) malloc (sizeof(Node));
    Node* cache;

    novo->dados = *Pessoas;
    novo->prox = NULL;

    if(*Geral == NULL)
    {
        *Geral = novo;
    }
    else
    {
        for(cache = *Geral; cache->prox != NULL; cache = cache->prox)
        {
            cache->qntd++;
        }
        cache->qntd++;
        cache->prox = novo;

    }
}

/*void inserir_Arq(Node** Geral, cadastro *Pessoas)
{
    Node *novo = (Node*) malloc(sizeof(Node));
    Node *Prox;
    novo->dados = *Pessoas;

    if(*Geral == NULL)
    {
        novo->prox = NULL;
        *Geral = novo;

    }
    else
    {

        novo->prox = *Geral;
        novo->qntd = (*Geral)->qntd+1;
        *Geral = novo;
    }
}*/
