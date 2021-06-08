#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "Cadastro_Escola__.h"

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
return 0;
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

Node* AtPos(Node *Geral)
{
    int opcao, matricula=0;
    char *cpf = malloc(sizeof(char));

    Node *referencia = (Node*) malloc(sizeof(Node));
    referencia = Geral;

    printf("\n Escolha: (1)- Matricula ou (2)- CPF. ");
    scanf("%d", &opcao);

    if(referencia->dados.matricula == matricula)
    {

    }

    do
    {

        referencia = referencia->prox;
    }while(referencia->prox != NULL && referencia->prox->dados.matricula != matricula);

    if(referencia->prox == NULL)
    {
        return NULL;
    }

return referencia;
}
