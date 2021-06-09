#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "Cadastro_Escola__.h"


Node* criar_Lista()
{

    Node* criar = (Node*)malloc(sizeof(Node));
    criar->posicao = 0;
    criar->tamanho = 0;
    criar = NULL;
    return criar;
}


int Push(Node** Geral, cadastro *Pessoas, int select)
{
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->dados = *Pessoas;

    if(*Geral == NULL)
    {
        novo->prox = NULL;
        if(select == 1)
        {
            novo->dados.matricula = MATRICULA_ALUN;
        }
        else
            novo->dados.matricula = MATRICULA_PROF;
        *Geral = novo;
        (*Geral)->tamanho = 1;
        (*Geral)->posicao = 1;
    }
    else
    {
        novo->prox = *Geral;
        if(select == 1)
        {
            novo->dados.matricula = MATRICULA_ALUN + (*Geral)->posicao;
        }
        else
            novo->dados.matricula = MATRICULA_PROF + (*Geral)->posicao;
        *Geral = novo;
        (*Geral)->tamanho ++;
        (*Geral)->posicao ++;
    }
    return 1; /* FUTURAS IMPLEMENTAÇÕES CONFIRMAR SE HA ESPAÇO*/
}

void Display(Node *Geral, int select)
{
    Node *ref = Geral;

    if(ref == NULL)
    {
        if(select == 1)
        {
            printf("\nSem Alunos Cadastrados.");
            getchar();
            menuAlunos();
        }
        else
        {
            printf("\nSem Professores Cadastrados.");
            getchar();
            menuProfessores();
        }
    }

    else
    {
        do
        {
            printf("\n\n%s ", ref->dados.nome);
            printf("\n\n%d ", ref->dados.matricula);
            printf("\n\n%s ", ref->dados.nascimento);
            printf("\n\n%s ", ref->dados.cpf);
            printf("\n\n%s ", ref->dados.sexo);
            printf("\n\n ---------------------------------------------------");
            ref = ref->prox;
        }
        while(ref != NULL);
    }
    printf("\n\n");
    free(ref);
}

int Remove(Node **Geral, int select)
{
    Node *cache = malloc(sizeof(Node));
    Node *next = malloc(sizeof(Node));

    cache = AtPos(*Geral, select);


    if(*Geral == NULL)
    {
        return -1;
    }
    else
    {
        if(cache == *Geral)
        {
            *Geral = cache->prox;
            (*Geral)->tamanho--;
            free(cache);
            return 1;
        }
        else if(cache == NULL)
        {
            return -2;
        }
        else
        {
            next = cache->prox;
            cache->prox = next->prox;
            free(next);
            (*Geral)->tamanho--;
        }
    }
    return 1;
}

void pop(Node** Geral)
{

    Node* cache = (Node*) malloc(sizeof(Node));
    cache = *Geral;

    cache = *Geral;
    *Geral = cache->prox;
    (*Geral)->tamanho--;

    free(cache);
}
void Atualizar(Node **Geral, int select)
{

}

int Buscar_Na_Lista(Node *Geral)
{
    /* PEDIR CPF ou Matricula e verificar se tem na lista, encontrando devolver 1 ou 0 */
    /*CRIAR STRUCT CADASTRO PARA PASSAR COMO REFERENCIA */
    return 1;
}

int CPF_NaBase(Node *Geral, char *cpf)
{
    int validador = -1;
    Node *referencia =(Node*) malloc(sizeof(Node));
    referencia = Geral;

    if(Geral == NULL)
    {
        validador = 0;
    }
    else
    {
        if(strcmp(referencia->dados.cpf, cpf)== 0)
        {
            validador = 1;
        }
        else
        {
            do
            {
                referencia = referencia->prox;
            }
            while(referencia != NULL && strcmp(referencia->dados.cpf, cpf)!= 0);
        }
        if(referencia == NULL)
        {
            validador = 0;
        }
        else
            validador = 1;
    }

    return validador;
}

Node* AtPos(Node *Geral, int select)
{
    int opcao, matricula=0;
    char *cpf = malloc(sizeof(char));
    Node *cache = (Node*) malloc(sizeof(Node));
    Node *referencia = (Node*) malloc(sizeof(Node));
    referencia = Geral;

    printf("\n Escolha: (1)- Matricula ou (2)- CPF, (9)- VOLTAR ou (0)- SAIR. ");
    opcao = getch();

    switch(opcao)
    {
    case '0':
        printf("\nEncerrando o programa. ");
        exit(0);
        break;
    case '1':
        printf("\nInforme a matricula: ");
        scanf("%d", &matricula);
        break;
    case '2':
        printf("\nInforme o CPF: ");
        gets(cpf);
        break;
    case '9':
        if(select == 1)
        {
            menuAlunos();
        }
        else
            menuProfessores();
        break;
    default:
        AtPos(Geral, select);
        break;
    }

    if(opcao == 1)
    {
        if(referencia->dados.matricula == matricula)
        {
            return referencia;
        }
        else
        {
            do
            {
                cache = referencia;
                referencia = referencia->prox;
            }
            while(referencia != NULL && referencia->dados.matricula != matricula);
        }
        if(referencia == NULL)
        {
            return NULL;
        }
    }

    else
    {
        if(referencia->dados.cpf == cpf)
        {
            return referencia;
        }
        else
        {
            do
            {
                cache = referencia;
                referencia = referencia->prox;
            }
            while(referencia != NULL && strcmp(referencia->dados.cpf, cpf)!= 0);
        }
        if(referencia == NULL)
        {
            return NULL;
        }
    }

    return cache;
}
