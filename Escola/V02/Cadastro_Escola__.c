#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"

void inicializar()
{
    Professores = ler_Arq(PROF);
    Alunos = ler_Arq(ALUN);
    Materias = _criar_Lista();

}


void menuGeral()
{
    char escolha;
    system("cls");
    printf("\n     |-------------------------------------------------------|");
    printf("\n     |  ***************** PROJETO ESCOLA ******************  |");
    printf("\n     |-------------------------------------------------------|\n\n");
    printf("\n");
    printf("\n       |------------------------------------------------|");
    printf("\n       |      DIGITE:                                   |");
    printf("\n       |                                                |");
    printf("\n       |       (1)- ALUNOS                              |");
    printf("\n       |       (2)- PROFESSORES                         |");
    printf("\n       |       (3)- DISCIPLINAS                         |");
    printf("\n       |       (0)- SAIR                                |");
    printf("\n       |                                                |");
    printf("\n       |------------------------------------------------|");
    /*printf("\n Digite: \n\n (1)- ALUNOS \n (2)- PROFESSORES \n (3)- DISCIPLINAS  \n (0)- SAIR:  ");*/
    printf("\n\n   ");
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
        menuDisciplinas();
        break;
    default:
        system("cls");
        setbuf(stdin, NULL);
        menuGeral();
        break;
    }
}


void menuAlunos()
{
    char escolha;
    /*int OK_Remove = 0;*/
    setbuf(stdin, NULL);
    system("cls");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n     ----------------------   CADASTRO ALUNOS   ---------------------\n");
    printf("\n   ---------------------------------------------------------------------\n\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n   |                                                                   |");
    printf("\n   |                                                                   |");
    printf("\n   |  Digite:                                                          |");
    printf("\n   |                                                                   |");
    printf("\n   |  (1)- CADASTRAR                                                   |");
    printf("\n   |  (2)- LISTAR                                                      |");
    printf("\n   |  (3)- EXCLUIR                                                     |");
    printf("\n   |  (4)- ALTERAR                                                     |");
    printf("\n   |  (9)- VOLTAR                                                      |");
    printf("\n   |  (0)- SAIR.                                                       |");
    printf("\n   |                                                                   |");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
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
        menuExcluir(1);
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
    /*int OK_Remove = 0;*/
    setbuf(stdin, NULL);
    system("cls");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n     --------------------   CADASTRO PROFESSORES   -------------------\n");
    printf("\n   ---------------------------------------------------------------------\n\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n   |                                                                   |");
    printf("\n   |                                                                   |");
    printf("\n   |  Digite:                                                          |");
    printf("\n   |                                                                   |");
    printf("\n   |  (1)- CADASTRAR                                                   |");
    printf("\n   |  (2)- LISTAR                                                      |");
    printf("\n   |  (3)- EXCLUIR                                                     |");
    printf("\n   |  (4)- ALTERAR                                                     |");
    printf("\n   |  (9)- VOLTAR                                                      |");
    printf("\n   |  (0)- SAIR.                                                       |");
    printf("\n   |                                                                   |");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
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
        menuExcluir(2);
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


void menuDisciplinas()
{
    char escolha;
    int OK_Remove = 0;
    setbuf(stdin, NULL);
    system("cls");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n     -------------------   CADASTRO DISCIPLINAS   -------------------\n");
    printf("\n   ---------------------------------------------------------------------\n\n");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n   |                                                                   |");
    printf("\n   |                                                                   |");
    printf("\n   |  Digite:                                                          |");
    printf("\n   |                                                                   |");
    printf("\n   |  (1)- CADASTRAR                                                   |");
    printf("\n   |  (2)- LISTAR                                                      |");
    printf("\n   |  (3)- EXCLUIR                                                     |");
    printf("\n   |  (4)- ALTERAR                                                     |");
    printf("\n   |  (9)- VOLTAR                                                      |");
    printf("\n   |  (0)- SAIR.                                                       |");
    printf("\n   |                                                                   |");
    printf("\n   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    escolha = getch();
    setbuf(stdin, NULL);
    ;

    switch(escolha)
    {
    case '0':
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    case '1':
        menuCadastro(3);
        break;
    case '2':
        _Display(Materias);
        getch();
        menuDisciplinas();
        break;
    case '3':
        OK_Remove = _Remove(&Materias);

        if(OK_Remove == 1)
        {
            printf("\n Excluido com sucesso. \n");
        }
        else if( OK_Remove == 0)
        {
            printf("\n Lista vazia. \n");
        }
        else if(OK_Remove == -1)
        {
            printf("\n Não consta na base. \n");
        }
        system("pause");
        menuDisciplinas();
        break;
    case '4':
        menuAlterar(3);
        break;
    case '9':
        menuGeral();
    default:
        menuDisciplinas();
        break;
    }
}


void menuCadastro(int select)
{
    char escolha;
    int v_CPF = 0, v_MATERIA = 0;

    setbuf(stdin, NULL);
    system("cls");
    printf("\n\n   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|");
    printf("\n   |                              CADASTRO                             |");
    printf("\n   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");

    if(select == 1)
    {
        setbuf(stdin, NULL);
        Pessoas = RecebeDadosPessoais();
        v_CPF = CPF_NaBase(Alunos, Pessoas.cpf);
        if(v_CPF == 1)
        {
            printf("\n\n ALUNO JÁ ESTA CADASTRADO. \n\n");
            system("pause");
            menuAlunos();
        }
        else
        {
            Push(&Alunos, &Pessoas, select);
            ArqSalvar(Alunos, ALUN);
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
    else if (select == 2)
    {
        setbuf(stdin, NULL);
        Pessoas = RecebeDadosPessoais();
        v_CPF = CPF_NaBase(Professores, Pessoas.cpf);
        if(v_CPF == 1)
        {
            printf("\n\n PROFESSOR JÁ ESTA CADASTRADO. \n\n");
            system("pause");
            menuProfessores();
        }
        else
        {
            Push(&Professores, &Pessoas, select);
            ArqSalvar(Professores, PROF);
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
    else if(select == 3)
    {
        setbuf(stdin, NULL);
        _Disciplina = RecebeDados_Materia();
        v_MATERIA = Buscar_Disciplina(Materias, _Disciplina.codigo);

        if(v_MATERIA == 1)
        {
            printf("\n\n DISCIPLINA JÁ ESTÁ CADASTRADA. \n\n");
            system("pause");
            menuDisciplinas();
        }
        else
        {
            _Push(&Materias, &_Disciplina);
            setbuf(stdin, NULL);
            system("cls");
            printf("\n Deseja realizar cadastrar outra disciplina? ");
            printf("\n Digite (1)- SIM ou (2)- NÃO");
            escolha = getche();
            if(escolha == '1')
            {
                menuCadastro(select);
            }
            else
            {
                menuDisciplinas();
            }
        }
    }
}


void menuAlterar(int select)
{
    int OK_Alterar, opcao;
    _search dado;

    system("cls");
    printf("\n\n   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|");
    printf("\n   |                             ALTERAÇÕES                            |");
    printf("\n   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");

    do
    {
        setbuf(stdin, NULL);

        printf("\n\n\n\n PARA ALTERAR, ESCOLHA:  \n");
        printf("\n (1)- BUSCAR P/ MATRICULA \n (2)- BUSCAR P/ CPF \n (9)- VOLTAR  \n (0)- SAIR \n");
        opcao = getch();
    }
    while(opcao != '1' && opcao != '2' && opcao != '9' && opcao != '0');

    switch(opcao)
    {
    case '1':
        setbuf(stdin, NULL);
        printf("\n Digite a matricula: ");
        setbuf(stdin, NULL);
        scanf("%d", &dado.matricula);
        strcpy(dado.cpf, "NULL");
        break;
    case '2':
        setbuf(stdin, NULL);
        printf("\n Digite o CPF: ");
        setbuf(stdin, NULL);
        gets(dado.cpf);
        dado.matricula = -1;
        break;
    case '9':
        if(select == 1)
        {
            menuAlunos();
        }
        else
        {
            menuProfessores();
        }
        break;
    case '0':
        printf("\n\nEncerrando o programa.");
        exit(0);
        break;
    }

    if(select == 1)
    {
        OK_Alterar = Atualizar(&Alunos, &dado, opcao);

        if(OK_Alterar == 1)
        {
            printf("\n Alterado com sucesso.\n ");
        }
        else if(OK_Alterar == -1)
        {
            printf("\n Não consta na base.\n");
        }
        else if(OK_Alterar == 0)
        {
            printf("\n Lista vazia. \n");
        }
        system("pause");
        menuAlunos();
    }
    else if(select == 2)
    {
        OK_Alterar = Atualizar(&Alunos, &dado, opcao);

        if(OK_Alterar == 1)
        {
            printf("\n Alterado com sucesso. \n");
        }
        else if(OK_Alterar == 0)
        {
            printf("\n Lista vazia. ");
        }
        else if(OK_Alterar == -1)
        {
            printf("\n Não consta na base. \n");
        }
        system("pause");
        menuProfessores();
    }
    else if(select == 3)
    {
        OK_Alterar = _Atualizar(&Materias);

        if(OK_Alterar == 1)
        {
            printf("\n Alterado com sucesso. \n");
        }
        else if(OK_Alterar == 0)
        {
            printf("\n Lista vazia. ");
        }
        else if(OK_Alterar == -1)
        {
            printf("\n Não consta na base. \n");
        }
        system("pause");
        menuDisciplinas();
    }
}


void menuExcluir(int select)
{
    _search dado;
    int opcao, OK_Remove;

    system("cls");
    printf("\n\n   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|");
    printf("\n   |                             EXCLUSÕES                             |");
    printf("\n   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");

    do
    {
        setbuf(stdin, NULL);

        printf("\n\n\n\n PARA REMOVER, ESCOLHA:  \n");
        printf("\n (1)- BUSCAR P/ MATRICULA \n (2)- BUSCAR P/ CPF \n (9)- VOLTAR  \n (0)- SAIR \n");
        opcao = getch();
    }
    while(opcao != '1' && opcao != '2' && opcao != '9' && opcao != '0');

    switch(opcao)
    {
    case '1':
        setbuf(stdin, NULL);
        printf("\n Digite a matricula: ");
        setbuf(stdin, NULL);
        scanf("%d", &dado.matricula);
        strcpy(dado.cpf, "NULL");
        break;
    case '2':
        setbuf(stdin, NULL);
        printf("\n Digite o CPF: ");
        setbuf(stdin, NULL);
        gets(dado.cpf);
        dado.matricula = -1;
        break;
    case '9':
        if(select == 1)
        {
            menuAlunos();
        }
        else
        {
            menuProfessores();
        }
        break;
    case '0':
        printf("\n\nEncerrando o programa.");
        exit(0);
        break;
    }

    if(select == 1)
    {
        OK_Remove = Remove(&Alunos, &dado, opcao);

        if(OK_Remove == 1)
        {
            printf("\n Excluido com sucesso. \n");
        }
        else if( OK_Remove == 0)
        {
            printf("\n Lista vazia. \n");
        }
        else if(OK_Remove == -1)
        {
            printf("\n Não consta na base. \n");
        }
    }
    else
    {
        OK_Remove = Remove(&Professores, &dado, opcao);

        if(OK_Remove == 1)
        {
            printf("\n Excluido com sucesso. \n");
        }
        else if( OK_Remove == 0)
        {
            printf("\n Lista vazia. \n");
        }
        else if(OK_Remove == -1)
        {
            printf("\n Não consta na base. \n");
        }
    }
    system("pause");

}


void menuListar()
{
    /*
    Listar Alunos
    Listar Professores
    Listar Disciplinas (dados da disciplina sem os alunos)
    Listar uma disciplina (dados da disciplina e os alunos matriculados)
    Listar Alunos por sexo (Masculino/Feminino)
    Listar Alunos ordenados por Nome
    Listar Alunos ordenados por data de nascimento
    Listar Professores por sexo (Masculino/Feminino)
    Listar Professores ordenados por Nome
    Listar Professores ordenados por data de nascimento
    Aniversariantes do mês
    Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no nome.
    */
    system("cls");
}
