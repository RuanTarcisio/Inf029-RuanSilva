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
        (*Geral)->posicao =1;
    }
    else
    {
        novo->prox = *Geral;
        if(select == 1)
        {
            novo->dados.matricula = (*Geral)->dados.matricula +1;
            *Geral = novo;
            (*Geral)->tamanho ++;
            (*Geral)->posicao ++;
        }
        else
            novo->dados.matricula = (*Geral)->dados.matricula +1;
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
            printf("\n \n%c", ref->dados.sexo);
            printf("\n\n ---------------------------------------------------");
            ref = ref->prox;
        }
        while(ref != NULL);
    }
    printf("\n\n");

}


int Remove(Node **Geral, int select)
{
    int matricula, opcao, validador;
    char cpf[12];
    Node *inicio = NULL;
    Node* cache = 0;

    cache = *Geral;

    setbuf(stdin, NULL);
    printf("\n Informe o CPF ou a matricula. ");
    printf("\n(1)- Matricula \n(2)- CPF \n");
    opcao = getch();

    switch(opcao)
    {
    case '1':
        setbuf(stdin, NULL);
        printf("\n Digite a matricula: ");
        setbuf(stdin, NULL);
        scanf("%d", &matricula);
        break;
    case '2':
        setbuf(stdin, NULL);
        printf("\n Digite o CPF: ");
        setbuf(stdin, NULL);
        gets(cpf);
        break;
    }

    if(opcao == '1')
    {
        if(cache == NULL)
        {
            return 0;
        }
        if(Buscar_Na_Lista(cache, matricula) == 0)
        {
            return -1;
        }
        else if(cache->prox == NULL)
        {
            if(isEmpty(cache)== 1)
            {
                *Geral = criar_Lista();
            }
            validador = 1;
        }
        else if(cache->dados.matricula == matricula)
        {
            *Geral = cache->prox;
            (*Geral)->tamanho--;

            validador = 1;
        }
        else
        {
            cache = cache->prox;
            while (cache != NULL && cache->dados.matricula != matricula)
            {
                inicio = cache;
                cache= cache->prox;
            }
            if(cache->dados.matricula == matricula)
            {
                inicio->prox = cache->prox;
                (*Geral)->tamanho --;

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

        if(cache == NULL)
        {
            return 0 ;
        }
        if(CPF_NaBase(cache, cpf) == 0)
        {
            return -1;
        }
        else if(cache->prox == NULL)
        {
            if(isEmpty(cache)== 1)
            {
                *Geral = criar_Lista();
            }
            validador = 1;
        }
        else if(strcmp(cache->dados.cpf, cpf) == 0)
        {
            *Geral = cache->prox;
            (*Geral)->tamanho--;

            validador = 1;
        }
        else
        {
            cache = cache->prox;
            while (cache != NULL && strcmp(cache->dados.cpf, cpf) == 0)
            {
                inicio = cache;
                cache = cache->prox;
            }
            if(strcmp(cache->dados.cpf, cpf) == 0)
            {
                inicio->prox = cache->prox;
                (*Geral)->tamanho --;

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


/* Node *cache = NULL, *next = NULL;
 int validador;

 setbuf(stdin,NULL);

 if(*Geral == NULL)
 {
     validador = 0;
 }

 else if(*Geral != NULL)
 {
     cache = AtPos(*Geral, select);

     if(cache == NULL)
     {
         validador = -1;
     }

     else if(cache->prox == NULL)
     {
         if(isEmpty(cache)== 1)
         {
             *Geral = criar_Lista();
         }
         validador = 1;
     }
     else if(cache->prox != NULL)
     {
         next = cache->prox;
         cache->prox = next ->prox;
         (*Geral)->tamanho--;
         validador = 1;
     }
 }

 free(next);
 return validador;
}*/


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


int Atualizar(Node **Geral, int select)
{
    int matricula, opcao, validador;
    char  cpf[12];

    Node* cache = 0;
    cadastro Dados;

    cache = *Geral;

    setbuf(stdin, NULL);
    printf("\n Informe o CPF ou a matricula. ");
    printf("(1)- Matricula ou (2)- CPF ");
    opcao = getch();

    switch(opcao)
    {
    case '1':
        setbuf(stdin, NULL);
        printf("\n Digite a matricula: ");
        setbuf(stdin, NULL);
        scanf("%d", &matricula);
        break;
    case '2':
        setbuf(stdin, NULL);
        printf("\n Digite o CPF: ");
        setbuf(stdin, NULL);
        gets(cpf);
        break;
    }

    if(opcao == '1')
    {
        if(cache == NULL)
        {
            return 0;
        }
        if(Buscar_Na_Lista(cache, matricula) == 0)
        {
            return -1;
        }
        else if(cache->dados.matricula == matricula)
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
            while (cache != NULL && cache->dados.matricula != matricula)
            {
                cache= cache->prox;
            }
            if(cache->dados.matricula == matricula)
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
        if(cache == NULL)
        {
            return 0 ;
        }
        if(CPF_NaBase(cache, cpf) == 0)
        {
            return -1;
        }
        else if(strcmp(cache->dados.cpf, cpf) == 0)
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
            while (cache != NULL && strcmp(cache->dados.cpf, cpf) == 0)
            {
                cache= cache->prox;
            }
            if(strcmp(cache->dados.cpf, cpf) == 0)
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
            do
            {
                referencia = referencia->prox;
            }
            while(referencia != NULL && referencia->dados.matricula == matricula);
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
