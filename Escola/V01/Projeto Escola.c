#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define MAX_ALUN 100
#define MAX_PROF 50
#define MAX_MATE 50
#define NAME_NOMES 30

/*:
•	Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF e TIPO SANGUINEO) .
•	Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF e TIPO SANGUINEO).
•	Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
*/


/* CRIAR UMA FUNÇÃO GERAL QUE RECEBE ALUNO, MATERIA E PROFESSOR. */


typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    char nome[NAME_NOMES];
    int matricula;
    int cpf;
    int confirma;
    char nascimento[10];
    char sexo;
    char TSangue[3];
    data recebe;
    int ndx;
} cadastro;

typedef struct
{
    char nome[NAME_NOMES];
    int codigo;
    int semestre;
    char professor[NAME_NOMES];
} disciplinas;


main()
{
    setlocale( LC_ALL, "" );
    void Discente(cadastro *Aluno);
    void Docente(cadastro *Professor);
    void Disciplina(disciplinas *Materia);
    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);


    cadastro professor[MAX_PROF], aluno[MAX_ALUN];
    professor[0].ndx = 0;
    aluno[0].ndx = 0;
    disciplinas materias[MAX_MATE];



    RegistroGeral(professor, aluno, materias);

}


void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia)
{
    void Discente(cadastro *Aluno);
    void Docente(cadastro *Professor);
    void Disciplina(disciplinas *Materia);

    int escolha;

    printf("\nDigite: (1)- Professores, (2)- Alunos, (3)- Disciplinas ou (0)- p/ SAIR:  ");
    scanf("%d", &escolha);

    if(escolha != 0 && escolha != 1 && escolha != 2 && escolha != 3)
    {
        do
        {
            printf("\nInvalido. Digite: (1)- Professores, (2)- Alunos, (3)- Disciplinas ou (0)- p/ SAIR:  ");
            scanf("%d", &escolha);

        }
        while(escolha != 0 && escolha != 1 && escolha != 2 && escolha != 3);
    }

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
    case 1:
        Discente(Aluno);
        break;
    case 2:
        Docente(Professor);
        break;
    case 3:
        Disciplina(Materia);
        break;
    }
}


void Discente(cadastro *Aluno)
{

    void cadastrar(cadastro *cliente, int x);
    void listar(cadastro *cliente, int x);
    void excluir(cadastro *cliente);

    int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE ALUNOS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir ou (0)- p/sair.  ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Aluno, 1);
        break;
    case 2:
        listar(Aluno, 1);
        break;
    case 3:
        break;
    }
}


void Docente(cadastro *Professor)
{

    void cadastrar(cadastro *cliente, int x);
    void listar(cadastro *cliente, int x);
    void excluir(cadastro *cliente);

    int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-* CADASTRO DE PROFESSORES *-*-*-*-*-*-*-*-*-*-*-*-*-* \n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir ou (0)- p/sair.  ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Professor, 2);
        break;
    case 2:
        listar(Professor, 2);
        break;
    case 3:
        break;
    }

}


void Disciplina(disciplinas *Materia)
{

    void cadastrarMateria(disciplinas *Materia);
    void listarMateria(disciplinas *Materia);
    void excluirMateria(disciplinas *Materia);

    int escolha;

    system("cls");
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE MATERIAS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir ou (0)- p/sair.  ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrarMateria(Materia);
        break;
    case 2:
        break;
    }
}


void cadastrar(cadastro *cliente, int x)
{

    void validarNome(cadastro *cliente, int ndxGuia);
    void validarCPF(cadastro *cliente, int ndxGuia);
    void validarSexo_Sangue(cadastro *cliente, int ndxGuia);
    void quebraDataNasc(cadastro *cliente, int ndxGuia);

    int ndxGuia = cliente[0].ndx, continua;



    if(x == 1)
    {
        /* FAZER UM LAÇO MAX_ALUN e IR SUBINDO CLIENTE->NDX */

        do
        {
            printf("\n%d\n%d", ndxGuia, cliente[0].ndx);
            setbuf(stdin, NULL);
            printf("\n\nNome do aluno:\n");
            gets(cliente[ndxGuia].nome);
            validarNome(cliente, ndxGuia);

            printf("\nCPF do aluno: \n");
            scanf("%d", &cliente[ndxGuia].cpf);
            validarCPF(cliente, ndxGuia);
            setbuf(stdin, NULL);

            printf("\nInforme o sexo: (F)- Feminino ou (M)- Masculino. \n");
            scanf("%c", &cliente[ndxGuia].sexo);
            setbuf(stdin, NULL);
            validarSexo_Sangue(cliente, ndxGuia);

            printf("\nInforme a data de nascimento: dd/mm/aaaa\n");
            gets(cliente[ndxGuia].nascimento);
            quebraDataNasc(cliente, ndxGuia);

            ndxGuia++;
            cliente[0].ndx = ndxGuia;

            setbuf(stdin, NULL);
            printf("\nDeseja cadastrar outro aluno?(1)- SIM ou (0)- NÃO.\n");
            scanf("%d", &continua);

            if(continua != 1 && continua != 0)
            {
                do
                {
                    setbuf(stdin, NULL);
                    printf("\nOpção invalida. Deseja cadastrar outro aluno?(1)- SIM ou (0)- NÃO.\n");
                    scanf("%d", &continua);

                }
                while(continua != 1 && continua != 0);
            }

        }
        while(continua == 1 || cliente[ndxGuia].ndx < MAX_ALUN);
    }

    else if(x == 2)
    {
        /* FAZER UM LAÇO MAX_PROF e IR SUBINDO CLIENTE->NDX*/

        do
        {
            printf("\n%d\n%d", ndxGuia, cliente[0].ndx);
            setbuf(stdin, NULL);
            printf("\n\nNome do professor:\n");
            gets(cliente[ndxGuia].nome);
            validarNome(cliente, ndxGuia);

            printf("\nCPF do professor: \n");
            scanf("%d", &cliente[ndxGuia].cpf);
            validarCPF(cliente, ndxGuia);
            setbuf(stdin, NULL);

            printf("\nInforme o sexo: (F)- Feminino ou (M)- Masculino. \n");
            scanf("%c", &cliente[ndxGuia].sexo);
            setbuf(stdin, NULL);
            validarSexo_Sangue(cliente, ndxGuia);

            printf("\nInforme a data de nascimento: dd/mm/aaaa\n");
            gets(cliente[ndxGuia].nascimento);
            quebraDataNasc(cliente, ndxGuia);

            ndxGuia++;
            cliente[0].ndx = ndxGuia;

            setbuf(stdin, NULL);
            printf("\nDeseja cadastrar outro professor?(1)- SIM ou (0)- NÃO.\n");
            scanf("%d", &continua);

            if(continua != 1 && continua != 0)
            {
                do
                {
                    setbuf(stdin, NULL);
                    printf("\nInvalido. Deseja cadastrar outro professor?(1)- SIM ou (0)- NÃO.\n");
                    scanf("%d", &continua);

                }
                while(continua != 1 && continua != 0);
            }

        }
        while(continua == 1 || cliente[ndxGuia].ndx < MAX_PROF);
    }



}


void cadastrarMateria(disciplinas *Materia)
{

}


void listar(cadastro *cliente, int x)
{

    if( x == 1 )
    {

    }

    else if ( x == 2 )
    {

    }

}


void validarNome(cadastro *cliente, int ndxGuia)
{
    void validarNome(cadastro *cliente, int ndxGuia);
    int ndx=0;

    ndx = strlen(cliente[ndxGuia].nome);

    if(ndx <= 2 || ndx > 20)
    {
        printf("\nUltrapassou o limite de 20 caracteres ou tem apenas 2 letras.\n");
        printf("Informe o nome:\n");
        gets(cliente[ndxGuia].nome);
        validarNome(cliente, ndxGuia);
    }

    else
    {
        ndx=0;
        do
        {
            if(cliente[ndxGuia].nome[ndx] >= 97 && cliente[ndxGuia].nome[ndx] <= 122 || (cliente[ndxGuia].nome[ndx] >= 65 && cliente[ndxGuia].nome[ndx] <= 90)
                    || (cliente[ndxGuia].nome[ndx] == ' ' && cliente[ndxGuia].nome[ndx+1] != ' '))
            {
                ndx++;
            }

            else
            {

                printf("\n\nNome apresenta acento ou algum caractere especial.");
                printf("\nInforme o nome sem acento.\n");
                gets(cliente[ndxGuia].nome);
                validarNome(cliente, ndxGuia);
            }

        }
        while(ndx < strlen(cliente[ndxGuia].nome));
    }
}


void validarSexo_Sangue(cadastro *cliente, int ndxGuia)
{
    int ndx=0;

    cliente[ndxGuia].sexo = toupper(cliente[ndxGuia].sexo);

    if(cliente[ndxGuia].sexo != 'M' && cliente[ndxGuia].sexo != 'F')
    {
        do
        {
            printf("\nOpção invalida, informe o sexo: (F)- Feminino ou (M)- Masculino. \n");
            scanf("%c", &cliente[ndxGuia].sexo);
            cliente[ndxGuia].sexo = toupper(cliente[ndxGuia].sexo);
            setbuf(stdin, NULL);
        }
        while(cliente[ndxGuia].sexo != 'M' && cliente[ndxGuia].sexo != 'F');
    }

    /*printf("\nInforme o tipo sanguineo.\n");
    gets(cliente->TSangue);

    do
    {
        cliente->TSangue[ndx] = toupper(cliente->TSangue[ndx]);
        ndx++;

    }
    while(ndx < 3 || cliente->TSangue[ndx] != '\0');

    if (cliente->TSangue != "A+" && cliente->TSangue != "A-" &&
        cliente->TSangue != "B+" && cliente->TSangue != "B-" &&
        cliente->TSangue != "AB+" && cliente->TSangue != "O+" &&
        cliente->TSangue != "AB-" && cliente->TSangue != "O-")
    {
            printf("estou aq");
    }*/
}


void quebraDataNasc(cadastro *cliente, int ndxGuia)
{
    typedef struct
    {
        char dia[3];
        char mes[3];
        char ano[5];
    } date;

    date recebe;

    void quebraDataNasc(cadastro *cliente, int ndxGuia);
    int validarNascimento(cadastro *cliente, int ndxGuia);
    int ndx=0, ndxV=0;
    int d=0, m=0, a=0;

    do
    {

        if(cliente[ndxGuia].nascimento[ndxV] != '/')
        {
            recebe.dia[ndx] = cliente[ndxGuia].nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            d = 0;
            break;
        }

        if(cliente[ndxGuia].nascimento[ndxV] == '/')
        {
            recebe.dia[ndx++] = '\0';
            d = 1;
            cliente[ndxGuia].recebe.dia = atoi(recebe.dia);
            break;
        }
    }
    while(cliente[ndxGuia].nascimento[ndxV] != '/');


    ndxV++;
    ndx=0;

    do
    {
        if(cliente[ndxGuia].nascimento[ndxV] != '/')
        {
            recebe.mes[ndx] = cliente[ndxGuia].nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            m = 0;
            break;
        }
        if(cliente[ndxGuia].nascimento[ndxV] == '/')
        {
            recebe.mes[ndx++] = '\0';
            m = 1;
            cliente[ndxGuia].recebe.mes = atoi(recebe.mes);
            break;
        }
    }
    while(cliente[ndxGuia].nascimento[ndxV] != '/');

    ndxV++;
    ndx = 0;

    do
    {
        if(cliente[ndxGuia].nascimento[ndxV] != '\0')
        {
            recebe.ano[ndx] = cliente[ndxGuia].nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 4)
        {
            a = 0;
            break;
        }
        if(cliente[ndxGuia].nascimento[ndxV] == '\0' && ndx >=2)
        {
            recebe.ano[ndx] = '\0';
            a = 1;
            cliente[ndxGuia].recebe.ano = atoi(recebe.ano);
            break;
        }
    }
    while(cliente[ndxGuia].nascimento[ndxV] != '\0');

    if(d != 1 || m != 1 || a != 1)
    {
        printf("\n Data informa é invalida, informe novamente: dd/mm/aaaa.\n");
        gets(cliente[ndxGuia].nascimento);
        quebraDataNasc(cliente, ndxGuia);
    }

    else
    {
        cliente[ndxGuia].confirma = validarNascimento(cliente, ndxGuia);

        if(cliente[ndxGuia].confirma != 1)
        {
            printf("\n Data informa é invalida, informe novamente: dd/mm/aaaa.\n");
            gets(cliente[ndxGuia].nascimento);
            quebraDataNasc(cliente, ndxGuia);
        }
    }
}


int validarNascimento(cadastro *cliente, int ndxGuia)
{

    int d=1, m=1, a=1;

    if((cliente[ndxGuia].recebe.ano > 99 && cliente[ndxGuia].recebe.ano < 1869) || cliente[ndxGuia].recebe.ano > 2021)
    {
        a = 0;
    }

    if(cliente[ndxGuia].recebe.dia < 1 || cliente[ndxGuia].recebe.dia > 31)
    {
        d = 0;
    }

    if(cliente[ndxGuia].recebe.mes > 12 || cliente[ndxGuia].recebe.mes < 1)
    {
        m = 0;
    }

    switch(cliente[ndxGuia].recebe.mes)
    {
    case 1:
        if(cliente[ndxGuia].recebe.dia>31)
            m = 0;
        break;
    case 2:
        if(cliente[ndxGuia].recebe.ano % 4 == 0 && (cliente[ndxGuia].recebe.ano % 400 == 0 || cliente[ndxGuia].recebe.ano % 100 != 0))
        {
            if(cliente[ndxGuia].recebe.dia > 29)

                m = 0;
            break;
        }
        if(cliente[ndxGuia].recebe.ano % 4 != 0)
        {
            if(cliente[ndxGuia].recebe.dia > 28)
            {
                m = 0;
                break;
            }
        }
    case 3:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 4:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 5:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 6:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 7:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 8:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 9:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 10:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 11:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 12:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    }

    if(d == 1 && m == 1 && a == 1)
    {
        return cliente[ndxGuia].confirma = 1;
    }

    else
    {
        return cliente[ndxGuia].confirma = 0;
    }
}


void validarCPF(cadastro *cliente, int ndxGuia)
{

}


