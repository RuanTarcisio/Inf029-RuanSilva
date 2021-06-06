#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#include "Cadastro_Escola__.h"

Node *Alunos = NULL;
Node *Professores = NULL;

cadastro Pessoas;

void menuGeral()
{
    int escolha;

    printf("\n\n       *********************** PROJETO ESCOLA ***********************\n\n");
    printf("\nDigite: (1)- Alunos, (2)- Professores, (3)- Disciplinas ou (0)- p/ SAIR:  ");
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
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  \n");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        setbuf(stdin, NULL);
        Pessoas = RecebeDadosPessoais();
        Push(&Alunos, &Pessoas);
      /*  teste();*/
        break;
    /*case 2:
        listar(Aluno, Professor, Materia, 1);
        break;
    case 3:
        break;
    case 9:
        RegistroGeral(Aluno, Professor, Materia);*/
    default:
        menuAlunos();
        break;
    }
}


void menuProfessores()
{
   /*int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE PROFESSORES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  \n");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Aluno, Professor, Materia, 1);
        break;
    case 2:
        listar(Aluno, Professor, Materia, 1);
        break;
    case 3:
        break;
    case 9:
        RegistroGeral(Aluno, Professor, Materia);
    default:
        Discente(Aluno, Professor, Materia);
        break;
    }*/
}

void menuDisciplinas()
{


}



