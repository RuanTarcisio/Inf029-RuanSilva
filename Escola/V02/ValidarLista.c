#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"


Node* criar_Lista()
{

    Node* criar = (Node*)malloc(sizeof(Node));
    criar->qntd = 0;
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
        (*Geral)->qntd = 1;
    }
    else
    {
        novo->prox = *Geral;
        novo->dados.matricula = (*Geral)->dados.matricula +1;
        novo->qntd = (*Geral)->qntd+1;
        *Geral = novo;
    }

    return 1; /* FUTURAS IMPLEMENTAÇÕES CONFIRMAR SE HA ESPAÇO*/
}


void Display(Node *Geral, int select)
{
    Node *ref = Geral;

    system("cls");

    if(ref == NULL)
    {
        if(select == 1)
        {
            printf("\n Sem Alunos Cadastrados.");
            getchar();
            menuAlunos();
        }
        else
        {
            printf("\n Sem Professores Cadastrados.");
            getchar();
            menuProfessores();
        }
    }

    else
    {
        do
        {
            printf("\n\n%d ", ref->qntd);
            printf("\n\n%s ", ref->dados.nome);
            printf("\n\n%d ", ref->dados.matricula);

            printf("\n\n%s ", ref->dados.nascimento);
            printf("\n\n%s ", ref->dados.cpf);
            printf("\n \n%c", ref->dados.sexo);
            printf("\n\n ---------------------------------------------------");
            ref = ref->prox;
        }
        while(ref != NULL);
    }
    printf("\n\n");

}


int Remove(Node **Geral, _search *dado, int opcao)
{
    int validador;

    Node *inicio = NULL;
    Node* cache = (Node*) malloc(sizeof(Node));


    if(opcao == '1')
    {
        cache = *Geral;

        if(Buscar_Na_Lista(cache, dado->matricula) == 0)
        {
            return -1;
        }
        else if(*Geral == NULL)
        {
            return 0;
        }
        else if(cache->prox == NULL)
        {
            if(isEmpty(cache)== 1)
            {
                *Geral = criar_Lista();
            }
            return 1;
        }
        else if(cache->dados.matricula == dado->matricula)
        {
            *Geral = cache->prox;
            (*Geral)->tamanho--;

            validador = 1;
        }
        else
        {
            for (cache = *Geral; cache != NULL && cache->dados.matricula != dado->matricula; cache = cache->prox)
            {
                inicio = cache;
            }
            if(cache->dados.matricula == dado->matricula)
            {
                inicio->prox = cache->prox;

                (*Geral)->tamanho --;

                return 1;
            }
            else
            {
                validador = -1;
            }
        }
    }
    else if(opcao == '2')
    {
        cache = *Geral;

        if(CPF_NaBase(cache, dado->cpf) == 0)
        {
            return -1;
        }
        else if(*Geral == NULL)
        {
            return 0 ;
        }
        else if(cache->prox == NULL)
        {
            if(isEmpty(cache)== 1)
            {
                *Geral = criar_Lista();
            }
            return 1;
        }
        else if(strcmp(cache->dados.cpf, dado->cpf) == 0)
        {
            *Geral = cache->prox;
            (*Geral)->tamanho--;

            validador = 1;
        }
        else
        {
            for (cache = *Geral; cache != NULL && (strcmp(cache->dados.cpf, dado->cpf) != 0); cache = cache->prox)
            {
                inicio = cache;
            }
            if(cache != NULL)
            {
                inicio->prox = cache->prox;

                (*Geral)->tamanho --;
                return 1;
            }
            else
            {
                validador = -1;
            }
        }
    }
    free(cache);
    return validador;
}


void Pop(Node** Geral)
{

    Node* cache = (Node*) malloc(sizeof(Node));
    cache = *Geral;

    if(cache->prox == NULL)
    {
        *Geral = criar_Lista();
    }
    else
    {
        cache = *Geral;
        *Geral = cache->prox;
        (*Geral)->tamanho--;
    }
    free(cache);
}


int Atualizar(Node **Geral, _search *dado, int opcao)
{
    int validador;

    Node* cache = 0;
    cadastro Dados;


    if(opcao == '1')
    {
        cache = *Geral;

        if(Buscar_Na_Lista(cache, dado->matricula) == 0)
        {
            return -1;
        }
        else if(cache == NULL)
        {
            return 0;
        }
        else if(cache->dados.matricula == dado->matricula)
        {
            Dados = cache->dados;

            Dados = AlterarDadosPessoais(Dados);
            Dados.matricula = cache->dados.matricula;
            cache->dados = Dados;

            validador = 1;
        }
        else
        {
            cache = cache->prox;
            while (cache != NULL && cache->dados.matricula != dado->matricula)
            {
                cache= cache->prox;
            }
            if(cache->dados.matricula == dado->matricula)
            {
                Dados = cache->dados;

                Dados = AlterarDadosPessoais(Dados);
                Dados.matricula = cache->dados.matricula;
                cache->dados = Dados;

                validador = 1;
            }
            else
            {
                validador = -1;
            }
            free(cache);
        }
    }
    else
    {
        cache = *Geral;

        if(CPF_NaBase(cache, dado->cpf) == 0)
        {
            return -1;
        }
        else if(cache == NULL)
        {
            return 0 ;
        }
        else if(strcmp(cache->dados.cpf, dado->cpf) == 0)
        {
            Dados = cache->dados;

            Dados = AlterarDadosPessoais(Dados);
            Dados.matricula = cache->dados.matricula;
            cache->dados = Dados;

            validador = 1;
        }
        else
        {
            cache = cache->prox;
            while (cache != NULL && strcmp(cache->dados.cpf, dado->cpf) != 0)
            {
                cache = cache->prox;
            }
            if(cache != NULL)
            {
                Dados = cache->dados;

                Dados = AlterarDadosPessoais(Dados);
                Dados.matricula = cache->dados.matricula;
                cache->dados = Dados;

                validador = 1;
            }
            else
            {
                validador = 0;
            }
            free(cache);
        }
    }
    return validador;
}


int Buscar_Na_Lista(Node *Geral, int matricula)
{
    int validador = -1;
    Node *referencia = Geral;

    if(Geral == NULL)
    {
        validador = 0;
    }
    else
    {
        if(referencia->dados.matricula == matricula)
        {
            validador = 1;
        }
        else
        {
            for(referencia = Geral; referencia != NULL && referencia->dados.matricula != matricula; referencia = referencia->prox);
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


int CPF_NaBase(Node *Geral, char *cpf)
{
    int validador = -1;
    Node *referencia = Geral;

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
            for(referencia = Geral; referencia != NULL && strcmp(referencia->dados.cpf, cpf) != 0; referencia = referencia->prox)
            {
            }
        }
        if(referencia != NULL)
        {
            validador = 1;
        }
        else
            validador = 0;

    }
    return validador;
}


Node* AtPos(Node *Geral, int select)
{
    int opcao, matricula=0;
    char cpf[12];
    Node *cache = NULL;
    Node *referencia = Geral;

    printf("\n Escolha: (1)- Matricula ou (2)- CPF, (9)- VOLTAR ou (0)- SAIR. ");
    opcao = getch();
    setbuf(stdin,NULL);

    switch(opcao)
    {
    case '0':
        printf("\nEncerrando o programa. ");
        exit(0);
        break;
    case '1':
        setbuf(stdin,NULL);
        printf("\n\n Informe a matricula: ");
        scanf("%d", &matricula);
        break;
    case '2':
        setbuf(stdin,NULL);
        printf("\n\n Informe o CPF: ");
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

    if(opcao == '1')
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

            if(referencia == NULL)
            {
                return NULL;
            }
        }
    }

    else
    {
        if(strcmp(referencia->dados.cpf, cpf) == 0)
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


int isEmpty(Node *Geral)
{
    int aux = 0, validador;
    Node *cache = Geral;

    do
    {
        cache = cache->prox;
        aux++;
    }
    while(cache != NULL && aux < 2);

    if(aux >= 2)
    {
        validador = 0;
    }
    else
    {
        validador = 1;
    }

    return validador;
}
