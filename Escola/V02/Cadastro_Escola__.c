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
    printf("\n Digite: (1)- Alunos, (2)- Professores, (3)- Disciplinas ou (0)- p/ SAIR:  ");
    escolha = getch();
    setbuf(stdin, NULL);

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
    case '1':
        menuAlunos();
        break;
    case '2':
        menuProfessores();
        break;
    case '3':
        menuDisciplinas();
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
    setbuf(stdin, NULL);
    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE ALUNOS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n Digite: (1)- CADASTRAR, (2)- LISTAR, (3)- EXCLUIR , (9)- VOLTAR ou (0)- SAIR.  \n");
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
        /*  teste();*/
        break;
    case '2':
        Display(Alunos, 1);
        getchar();
        menuAlunos();
        break;
    case 3:
        Remove(&Alunos, 1);
        break;
    case '9':
        menuGeral();
    default:
        menuAlunos();
        break;
    }
}


void menuProfessores()
{
    char escolha;
    setbuf(stdin,NULL);
    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE PROFESSORES -*-*-*-*-*-*-*-*-*-*-*-*-\n");
    printf("\n Digite: (1)- CADASTRAR, (2)- LISTAR, (3)- EXCLUIR, (9)- VOLTAR ou (0)- SAIR.  \n");
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
        /*  teste();*/
        break;
    case '2':
        Display(Professores, 2);
        getchar();
        menuProfessores();
        break;
    case '3':
        Remove(&Professores, 2);
        break;
    case '9':
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
    char escolha;
    int v_CPF = 0;

    setbuf(stdin, NULL);

    printf("\n\n    *-*-*-*-*-*-*-*-*-*-* BEM-VINDO AO CADASTRAMENTO *-*-*-*-*-*-*-*-*-*-*\n\n");
    getchar();
    system("cls");

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
            printf("\n\n ALUNO JÁ ESTA CADASTRADO. ");
            getchar();
            menuAlunos();
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
