#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "Cadastro_Escola__.h"


void menuGeral()
{
    char escolha;
    setbuf(stdin, NULL);

    printf("\n\n       *********************** PROJETO ESCOLA ***********************\n\n");
    printf("\n Digite: (1)- ALUNOS, (2)- PROFESSORES, (3)- DISCIPLINAS ou (0)- p/ SAIR:  ");

    printf("\n\n  > ");
    escolha = getch();
    setbuf(stdin, NULL);

    switch(escolha)
    {
    case '0':
        printf("\n\nEncerrando o programa.");
        exit(0);
    case '1':
        menuAlunos();
        break;
    case '2':
        menuProfessores();
        break;
    case '3':
        /*menuDisciplinas();*/
        break;
    default:
        system("cls");
        menuGeral();
        break;
    }
}


void menuAlunos()
{
    char escolha;
    int OK_Remove = 0;
    setbuf(stdin, NULL);
    system("cls");
    printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n      ---------------------         ALUNOS       ----------------------\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\n Digite: (1)- CADASTRAR, (2)- LISTAR, (3)- EXCLUIR, (4)- ALTERAR , (9)- VOLTAR   ou (0)- SAIR.  \n");
    escolha = getch();
    setbuf(stdin, NULL);

    switch(escolha)
    {
    case '0':
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    case '1':
        menuCadastro(1);
        break;
    case '2':
        Display(Alunos, 1);
        getch();
        menuAlunos();
        break;
    case '3':
        OK_Remove = Remove(&Alunos, 1);

        if(OK_Remove == 1)
        {
            printf("\n Excluido com sucesso. ");
        }
        else if( OK_Remove == 0)
        {
            printf("\n Lista vazia. ");
        }
        else if(OK_Remove == -1)
        {
            printf("\n Não consta na base. ");
        }
        getch();
        menuAlunos();
        break;
    case '4':
        menuAlterar(1);
        getch();
        break;
    case '9':
        menuGeral();
    default:
        menuAlunos();
        break;
    }
    menuAlunos();
}


void menuProfessores()
{
    char escolha;
    int OK_Remove;
    setbuf(stdin,NULL);
    system("cls");
    printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n     ---------------------       PROFESSORES       ---------------------\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\n Digite: (1)- CADASTRAR, (2)- LISTAR, (3)- EXCLUIR, (4)- ALTERAR , (9)- VOLTAR   ou (0)- SAIR.  \n");
    escolha = getch();
    setbuf(stdin, NULL);

    switch(escolha)
    {
    case '0':
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    case '1':
        menuCadastro(2);
        break;
    case '2':
        Display(Professores, 2);
        getch();
        menuProfessores();
        break;
    case '3':
        OK_Remove = Remove(&Professores, 2);

        if(OK_Remove == 1)
        {
            printf("\n Excluido com sucesso. ");
        }
        else if( OK_Remove == 0)
        {
            printf("\n Lista vazia. ");
        }
        else if(OK_Remove == -1)
        {
            printf("\n Não consta na base. ");
        }
        getch();
        menuProfessores();
        break;
    case '4':
        menuAlterar(2);
        break;
    case '9':
        menuGeral();
    default:
        menuProfessores();
        break;
    }
}


void menuCadastro(int select)
{
    char escolha;
    int v_CPF = 0;

    setbuf(stdin, NULL);
    system("cls");
    printf("\n\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n    *-*-*-*-*-*-*-*-*-*-*       CADASTRAMENTO      *-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    getchar();

    if(select == 1)
    {
        setbuf(stdin, NULL);
        Pessoas = RecebeDadosPessoais();
        v_CPF = CPF_NaBase(Alunos, Pessoas.cpf);
        if(v_CPF == 1)
        {
            printf("\n\n ALUNO JÁ ESTA CADASTRADO. ");
            getchar();
            menuAlunos();
        }
        else
        {
            Push(&Alunos, &Pessoas, select);
            setbuf(stdin, NULL);
            system("cls");
            printf("\n Deseja realizar outro cadastro? ");
            printf("\n Digite (1)- SIM ou (2)- NÃO");
            escolha = getche();
            if(escolha == '1')
            {
                menuCadastro(select);
            }
            else
            {
                menuAlunos();
            }
        }
    }
    else
    {
        setbuf(stdin, NULL);
        Pessoas = RecebeDadosPessoais();
        v_CPF = CPF_NaBase(Professores, Pessoas.cpf);
        if(v_CPF == 1)
        {
            printf("\n\n PROFESSOR JÁ ESTA CADASTRADO. ");
            getchar();
            menuProfessores();
        }
        else
        {
            Push(&Professores, &Pessoas, select);
            setbuf(stdin, NULL);
            system("cls");
            printf("\n Deseja realizar outro cadastro? ");
            printf("\n Digite (1)- SIM ou (2)- NÃO");
            escolha = getche();
            if(escolha == '1')
            {
                menuCadastro(select);
            }
            else
            {
                menuProfessores();
            }
        }
    }
}


void menuAlterar(int select)
{
    int OK_Alterar;

    printf("\n\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n    *-*-*-*-*-*-*-*-*-*-*       ALTERAÇÕES      *-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

    if(select == 1)
    {
        OK_Alterar = Atualizar(&Alunos, 1);

        if(OK_Alterar == 1)
        {
            printf("\n Alterado com sucesso. ");
        }
        else if(OK_Alterar == 0)
        {
            printf("\n Lista vazia. ");
        }
        else if(OK_Alterar == -1)
        {
            printf("\n Não consta na base. ");
        }
        getch();
        menuAlunos();
    }
    else
    {
        OK_Alterar = Atualizar(&Professores, 2);

        if(OK_Alterar == 1)
        {
            printf("\n Alterado com sucesso. ");
        }
        else if(OK_Alterar == 0)
        {
            printf("\n Lista vazia. ");
        }
        else if(OK_Alterar == -1)
        {
            printf("\n Não consta na base. ");
        }
        getch();
        menuProfessores();
    }
}
