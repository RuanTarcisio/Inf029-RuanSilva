#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define MAX_ALUN 100
#define MAX_PROF 20

/*:
•	Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF e TIPO SANGUINEO) .
•	Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF e TIPO SANGUINEO).
•	Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
*/

typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    char nome[30];
    int matricula;
    int cpf;
    int confirma;
    char nascimento[10];
    char sexo;
    char TSangue[3];
    data recebe;
} cadastro;

main()
{
    setlocale( LC_ALL, "" );
    void Discente(cadastro *Aluno);
    void Docente(cadastro *Professor);
    void Disciplina();


    cadastro professor[MAX_PROF], aluno[MAX_ALUN];
    int escolha, ndxEscolha, confirma;


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
        Discente(aluno);
        break;
    case 2:
        Docente(professor);
        break;
    case 3:
        /*Disciplina();*/
        break;

    }


}


void Discente(cadastro *Aluno)
{

    void cadastrar(cadastro *cliente);
    void listar(cadastro *cliente);

    int escolha;

    system("cls");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir ou (0)- p/sair.  ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Aluno);
        break;
    case 2:
        listar(Aluno);
        break;
    case 3:
        break;
    }
}


void Docente(cadastro *Professor)
{

    void cadastrar(cadastro *cliente);
    void listar(cadastro *cliente);

    int escolha;

    system("cls");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir ou (0)- p/sair.  ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Professor);
        break;
    case 2:
        listar(Professor);
        break;
    case 3:
        break;
    }

}


void cadastrar(cadastro *cliente)
{
    void validarNome(cadastro *cliente);
    void validarCPF(cadastro *cliente);
    void validarSexo(cadastro *cliente);
    void quebraDataNasc(cadastro *cliente);

    printf("\nInforme o nome:\n");
    gets(cliente->nome);
    validarNome(cliente);

    printf("\nInforme o CPF: \n");
    scanf("%d", &cliente->cpf);
    validarCPF(cliente);
    setbuf(stdin, NULL);

    printf("\nInforme o sexo: (F)- Feminino ou (M)- Masculino. \n");
    scanf("%c", &cliente->sexo);
    setbuf(stdin, NULL);
    validarSexo(cliente);

    printf("\nInforme a data de nascimento: dd/mm/aaaa\n");
    gets(cliente->nascimento);
    quebraDataNasc(cliente);

}


void listar(cadastro *cliente)
{


}



void validarNome(cadastro *cliente)
{
    void validarNome(cadastro *cliente);
    int ndx=0;

    ndx = strlen(cliente->nome);

    if(ndx <= 2 || ndx > 20)
    {
        printf("\nUltrapassou o limite de 20 caracteres ou tem apenas 2 letras.\n");
        printf("Informe o nome:\n");
        gets(cliente->nome);
        validarNome(cliente);
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
                validarNome(cliente);
            }

        }
        while(ndx < strlen(cliente->nome));
    }
}


void validarSexo(cadastro *cliente)
{

    if(cliente->sexo == 'M' || cliente->sexo == 'm' || cliente->sexo == 'F' || cliente->sexo == 'f')
    {
        return;
    }
    else
    {
        do
        {
            printf("\nOpção invalida, informe o sexo: (F)- Feminino ou (M)- Masculino. \n");
            scanf("%c", &cliente->sexo);
            setbuf(stdin, NULL);
        }
        while(cliente->sexo != 'M' && cliente->sexo != 'm' && cliente->sexo != 'F' && cliente->sexo != 'f');
    }

}


void quebraDataNasc(cadastro *cliente)
{
    typedef struct
    {
        char dia[3];
        char mes[3];
        char ano[5];
    } date;

    date recebe;

    void quebraDataNasc(cadastro *cliente);
    int validarNascimento(cadastro *cliente);
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
        quebraDataNasc(cliente);
    }

    else
    {
        cliente->confirma = validarNascimento(cliente);

        if(cliente->confirma != 1)
        {
            printf("\n Data informa é invalida, informe novamente: dd/mm/aaaa.\n");
            gets(cliente->nascimento);
            quebraDataNasc(cliente);
        }
    }
}


int validarNascimento(cadastro *cliente)
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


void validarCPF(cadastro *cliente)
{

}
