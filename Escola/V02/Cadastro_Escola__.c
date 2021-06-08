#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
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


void menuGeral()
{
    int escolha;

    printf("\n\n       *********************** PROJETO ESCOLA ***********************\n\n");
    printf("\n Digite: (1)- Alunos, (2)- Professores, (3)- Disciplinas ou (0)- p/ SAIR:  ");
    scanf("%d", &escolha);

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
    case 1:
        menuAlunos();
        break;
    case 2:
        menuProfessores();
        break;
    case 3:
        menuDisciplinas();
        break;
    default:
        system("cls");
        menuGeral();
        break;
    }
}


void teste();


void menuAlunos()
{
    int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE ALUNOS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n Digite: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  \n");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    case 1:
        menuCadastro(1);
        /*  teste();*/
        break;
    case 2:
        Display(Alunos, 1);
        getchar();
        menuAlunos();
        break;
    /* case 3:
         break;*/
    case 9:
        menuGeral();
    default:
        menuAlunos();
        break;
    }
}


void menuProfessores()
{
    int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE PROFESSORES -*-*-*-*-*-*-*-*-*-*-*-*-\n");
    printf("\n Digite: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  \n");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    case 1:
        menuCadastro(2);
        /*  teste();*/
        break;
    case 2:
        Display(Professores, 2);
        getchar();
        menuProfessores();
        break;
    /* case 3:
         break;*/
    case 9:
        menuGeral();
    default:
        menuProfessores();
        break;
    }
}

void menuDisciplinas()
{


}

void menuCadastro(int select)
{
    int escolha = 0;

    printf("\n Digite: \n(1)- INCLUIR NOVO CADASTRO \n(2)- ATUALIZAR CADASTRO \n(3)- EXCLUIR CADASTRO \n(4)- LISTAR CADASTROS \n(9)- MENU ANTERIOR \n(0)- SAIR. \n");
    scanf("%d", &escolha);

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    case 1:
        if(select == 1)
        {
            setbuf(stdin, NULL);
            Pessoas = RecebeDadosPessoais();
            Push(&Alunos, &Pessoas, select);
            menuCadastro(select);
        }
        else
        {
            setbuf(stdin, NULL);
            Pessoas = RecebeDadosPessoais();
            Push(&Professores, &Pessoas, select);
            menuCadastro(select);
        }
        break;
    /*case 2:
        Atualizar(&Alunos);
        break*/
    case 3:
        if(select == 1)
        {
            Remove(&Alunos, select);
        }
        else
        {
            Remove(&Professores, select);
        }
        break;
    case 4:
        if(select == 1)
        {
            setbuf(stdin,NULL);
            Display(Alunos, select);
            getchar();
        }
        else
        {
            Display(Professores, select);
            getchar();
        }
    case 9:
        if(select == 1)
        {
            menuAlunos();
        }
        else
            menuProfessores();
        break;
    default:
        printf("\nOPCAO INVALIDA.");
        menuCadastro(select);
        break;
    }
}
