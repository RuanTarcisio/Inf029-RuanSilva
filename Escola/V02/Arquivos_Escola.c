#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"



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
    int ndx = 0;

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
        /*fread(&cache, sizeof(cadastro), 1, file);*/
        Push(&lista, &cache, opcao);
        printf(" \n%d ", ndx);
    }
    fclose(file);

return lista;
}


    /*}
    else if(titulo == USIM5_)
    {
        FILE *arqC = fopen("USIM5_Compra.txt", "r");
        while (!feof(arqC))
        {

            fscanf(arqC, "%d  %f  %f  ", &cache.qntd, &cache.valor, &cache.valor_unidade);
            if(cache.qntd != 0)
            {
                insert(lista, &cache, Compra);
            }
        }
        fclose(arqC);

        FILE *arqV = fopen("USIM5_Venda.txt", "r");
        while (!feof(arqV))
        {

            fscanf(arqV, "%d  %f  %f  ", &cache.qntd, &cache.valor, &cache.valor_unidade);
            if(cache.qntd != 0)
            {
                insert(lista, &cache, Venda);
            }
        }
        fclose(arqV);
    }*/
