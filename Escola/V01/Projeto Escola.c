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
    disciplinas materias[MAX_MATE];

    int escolha, ndxEscolha, confirma;


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
            printf("\nOpção invalida. Digite: (1)- Professores, (2)- Alunos, (3)- Disciplinas ou (0)- p/ SAIR:  ");
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
    Aluno[0].ndx=0;

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
    Professor[0].ndx=0;

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


void cadastrar(cadastro *cliente, int x)
{

    void validarNome(cadastro *cliente, int ndxGuia);
    void validarCPF(cadastro *cliente, int ndxGuia);
    void validarSexo_Sangue(cadastro *cliente, int ndxGuia);
    void quebraDataNasc(cadastro *cliente, int ndxGuia);

    int ndxGuia = 0, continua;

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
                while(continua != 1 || continua != 0);
            }

        }
        while(continua == 1);
    }

    else if(x == 2)
    {
        /* FAZER UM LAÇO MAX_PROF e IR SUBINDO CLIENTE->NDX*/

        printf("\nNome do professor:\n");
        gets(cliente->nome);
        /* validarNome(cliente);*/

        printf("\nCPF do professor: \n");
        scanf("%d", &cliente->cpf);
        validarCPF(cliente, ndxGuia);
        setbuf(stdin, NULL);

        printf("\nInforme o sexo: (F)- Feminino ou (M)- Masculino. \n");
        scanf("%c", &cliente->sexo);
        setbuf(stdin, NULL);
        validarSexo_Sangue(cliente, ndxGuia);

        printf("\nInforme a data de nascimento: dd/mm/aaaa\n");
        gets(cliente->nascimento);
        quebraDataNasc(cliente, ndxGuia);
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


void cadastrarMateria(disciplinas *Materia)
{

}


void listar(cadastro *cliente, int x)
{


}


void validarNome(cadastro *cliente, int ndxGuia)
{
    /* void validarNome(cadastro *cliente);*/
    int ndx=0;

    ndx = strlen(cliente->nome);

    if(ndx <= 2 || ndx > 20)
    {
        printf("\nUltrapassou o limite de 20 caracteres ou tem apenas 2 letras.\n");
        printf("Informe o nome:\n");
        gets(cliente->nome);
        validarNome(cliente, ndxGuia);
    }

    else
    {
        ndx=0;
        do
        {
            if(cliente->nome[ndx] >= 97 && cliente->nome[ndx] <= 122 || (cliente->nome[ndx] >= 65 && cliente->nome[ndx] <= 90)
                    || (cliente->nome[ndx] == ' ' && cliente->nome[ndx+1] != ' '))
            {
                ndx++;
            }

            else
            {

                printf("\n\nNome apresenta acento ou algum caractere especial.");
                printf("\nInforme o nome sem acento.\n");
                gets(cliente->nome);
                validarNome(cliente, ndxGuia);
            }

        }
        while(ndx < strlen(cliente->nome));
    }
}


void validarSexo_Sangue(cadastro *cliente, int ndxGuia)
{
    int ndx=0;

    if(cliente->sexo != 'M' && cliente->sexo != 'm' && cliente->sexo != 'F' && cliente->sexo != 'f')
    {
        do
        {
            printf("\nOpção invalida, informe o sexo: (F)- Feminino ou (M)- Masculino. \n");
            scanf("%c", &cliente->sexo);
            setbuf(stdin, NULL);
        }
        while(cliente->sexo != 'M' && cliente->sexo != 'm' && cliente->sexo != 'F' && cliente->sexo != 'f');
    }

    printf("\nInforme o tipo sanguineo.\n");
    gets(cliente->TSangue);

    do
    {
        cliente->TSangue[ndx] = toupper(cliente->TSangue[ndx]);
        ndx++;

    }
    while(ndx < 3 || cliente->TSangue[ndx] != '\0');

    /*if (cliente->TSangue != "A+" && cliente->TSangue != "A-" &&
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

        if(cliente->nascimento[ndxV] != '/')
        {
            recebe.dia[ndx] = cliente->nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            d = 0;
            break;
        }

        if(cliente->nascimento[ndxV] == '/')
        {
            recebe.dia[ndx++] = '\0';
            d = 1;
            cliente->recebe.dia = atoi(recebe.dia);
            break;
        }
    }
    while(cliente->nascimento[ndxV] != '/');


    ndxV++;
    ndx=0;

    do
    {
        if(cliente->nascimento[ndxV] != '/')
        {
            recebe.mes[ndx] = cliente->nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            m = 0;
            break;
        }
        if(cliente->nascimento[ndxV] == '/')
        {
            recebe.mes[ndx++] = '\0';
            m = 1;
            cliente->recebe.mes = atoi(recebe.mes);
            break;
        }
    }
    while(cliente->nascimento[ndxV] != '/');

    ndxV++;
    ndx = 0;

    do
    {
        if(cliente->nascimento[ndxV] != '\0')
        {
            recebe.ano[ndx] = cliente->nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 4)
        {
            a = 0;
            break;
        }
        if(cliente->nascimento[ndxV] == '\0' && ndx >=2)
        {
            recebe.ano[ndx] = '\0';
            a = 1;
            cliente->recebe.ano = atoi(recebe.ano);
            break;
        }
    }
    while(cliente->nascimento[ndxV] != '\0');

    if(d != 1 || m != 1 || a != 1)
    {
        printf("\n Data informa é invalida, informe novamente: dd/mm/aaaa.\n");
        gets(cliente->nascimento);
        quebraDataNasc(cliente, ndxGuia);
    }

    else
    {
        cliente->confirma = validarNascimento(cliente, ndxGuia);

        if(cliente->confirma != 1)
        {
            printf("\n Data informa é invalida, informe novamente: dd/mm/aaaa.\n");
            gets(cliente->nascimento);
            quebraDataNasc(cliente, ndxGuia);
        }
    }
}


int validarNascimento(cadastro *cliente, int ndxGuia)
{

    int d=1, m=1, a=1;

    if((cliente->recebe.ano > 99 && cliente->recebe.ano < 1869) || cliente->recebe.ano > 2021)
    {
        a = 0;
    }

    if(cliente->recebe.dia < 1 || cliente->recebe.dia > 31)
    {
        d = 0;
    }

    switch(cliente->recebe.mes)
    {
    case 1:
        if(cliente->recebe.dia>31)
            m=0;
        break;
    case 2:
        if(cliente->recebe.ano % 4 == 0 && (cliente->recebe.ano % 400 == 0 || cliente->recebe.ano % 100 != 0))
        {
            if(cliente->recebe.dia > 29)

                m=0;
            break;
        }
        if(cliente->recebe.ano % 4 != 0)
        {
            if(cliente->recebe.dia > 28)
            {
                m=0;
                break;
            }
        }
    case 3:
        if(cliente->recebe.dia > 31)
        {
            m=0;
            break;
        }
    case 4:
        if(cliente->recebe.dia > 30)
        {
            m=0;
            break;
        }
    case 5:
        if(cliente->recebe.dia > 31)
        {
            m=0;
            break;
        }
    case 6:
        if(cliente->recebe.dia > 30)
        {
            m=0;
            break;
        }
    case 7:
        if(cliente->recebe.dia > 31)
        {
            m=0;
            break;
        }
    case 8:
        if(cliente->recebe.dia > 30)
        {
            m=0;
            break;
        }
    case 9:
        if(cliente->recebe.dia > 31)
        {
            m=0;
            break;
        }
    case 10:
        if(cliente->recebe.dia > 30)
        {
            m=0;
            break;
        }
    case 11:
        if(cliente->recebe.dia > 31)
        {
            m=0;
            break;
        }
    case 12:
        if(cliente->recebe.dia > 30)
        {
            m=0;
            break;
        }
    }

    if(d == 1 && m == 1 && a == 1)
    {
        return cliente->confirma = 1;
    }

    else
    {
        return cliente->confirma = 0;
    }
}


void validarCPF(cadastro *cliente, int ndxGuia)
{

}


