#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "Cadastro_Escola__.h"


cadastro RecebeDadosPessoais()
{
    cadastro Dados;

    printf("\n Informe o nome: ");
    setbuf(stdin, NULL);
    gets(Dados.nome);
    setbuf(stdin, NULL);
    printf("\n Informe a data de nascimento dd/mm/aaaa: ");
    fgets(Dados.nascimento, TAM_NASC, stdin);
    setbuf(stdin, NULL);
    printf("\n Informe o CPF: ");
    gets(Dados.cpf);
    setbuf(stdin, NULL);
    printf("\n Informe o sexo (F/M): ");
    gets(Dados.sexo);
    setbuf(stdin, NULL);

    Dados = validar(&Dados);

    return Dados;
}


cadastro validar(cadastro *Dados) /* VALIDAR PELAS OUTRAS FUNÇÕES E RETORNAR*/
{
    int a, b, c, d, ndx=0 ;
    char confirma;

    date *rcbAniversario = &Dados->aniversario;
    char *_data = Dados->nascimento;

    a = validarNome(Dados->nome);
    b = validarData(Dados->nascimento);
    c = validarCPF(Dados->cpf);
    d = validarSexo(Dados->sexo);

    do
    {
        if (a != 1)
        {
            printf("\nNome Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o nome: ");
            gets(Dados->nome);
            a = validarNome(Dados->nome);
        }
        if (b != 1)
        {
            printf("\nData Invalida.");
            setbuf(stdin, NULL);
            printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
            setbuf(stdin, NULL);
            gets(Dados->nascimento);
            b = validarData(Dados->nascimento);
        }
        if (c != 1)
        {
            printf("\nCPF Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o CPF: ");
            gets(Dados->cpf);
            c = validarCPF(Dados->cpf);
        }
        if (d != 1)
        {
            setbuf(stdin, NULL);
            printf("\nSexo Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o sexo (F/M): ");
            gets(Dados->sexo);
            d = validarSexo(Dados->sexo);
        }
    }
    while(a != 1 || b != 1 || c != 1 || d != 1);

    ndx=0;
    do
    {
        Dados->nome[ndx] = toupper(Dados->nome[ndx]);
        ndx++;
    }
    while(ndx < strlen(Dados->nome));
    Dados->sexo[0] = toupper(Dados->sexo[0]);

    _Aniversario(_data, rcbAniversario);

    system("cls");
    printf("\n\n");
    puts(Dados->nome);
    printf("\n");
    puts(Dados->nascimento);
    printf("\n");
    puts(Dados->cpf);
    printf("\n");
    puts(Dados->sexo);
    printf("\n Confirma os dados? Digite, (1)- SIM, (2)- NAO ou (9)- SAIR\n");
    confirma = getch();
    setbuf(stdin, NULL);

    switch(confirma)
    {
    case '1':
        return *Dados;
    case '2':
        RecebeDadosPessoais();
        break;
    case '0':
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    default:
        validar(Dados);
        break;
    }
    return *Dados;
}


int validarData(char *data)
{
    typedef struct
    {
        char dia[2];
        char mes[2];
        char ano[4];
    } nascimento;

    nascimento *recebe = malloc(sizeof(nascimento));
    date *guia = malloc(sizeof(date));

    int validador;

    int ndx=0, ndxV=0, ndxB=0;

    do
    {
        if(data[ndxV] != '/')
        {
            recebe->dia[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            return 0;
        }

        if(data[ndxV] == '/')
        {
            ndxB++;
            recebe->dia[ndx++] = '\0';
            guia->dia = atoi(recebe->dia);
            break;
        }
    }
    while(data[ndxV] != '/');

    ndxV++;
    ndx=0;

    do
    {
        if(data[ndxV] != '/')
        {
            recebe->mes[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            return 0;
        }
        if(data[ndxV] == '/')
        {
            ndxB++;
            recebe->mes[ndx++] = '\0';
            guia->mes = atoi(recebe->mes);
            break;
        }
    }
    while(data[ndxV] != '/');

    ndxV++;
    ndx = 0;

    do
    {
        if(data[ndxV] == '/')
        {
            ndxB++;
        }
        if(data[ndxV] != '\0')
        {
            recebe->ano[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 4)
        {
            return 0;
        }
        if(data[ndxV] == '\0' && ndx >=2)
        {
            recebe->ano[ndx] = '\0';
            guia->ano = atoi(recebe->ano);
            break;
        }
    }
    while(data[ndxV] != '\0');

    ndx = 0;

    do
    {
        if((data[ndx] > 47 && data[ndx] < 58) || data[ndx] == '/')
        {
            ndx++;
        }
        else
            return 0;
    }
    while(ndx < strlen(data) && data[ndx] != '\n');

    if(ndxB > 2)
    {
        return 0;
    }
    validador = validarNascimento(guia);
    free(recebe);
    return validador;
}


int validarNascimento(date *guia)
{
    if((guia->ano > 99 && guia->ano < 1869) || guia->ano > 2021)
    {
        return 0;
    }

    if(guia->dia < 1 || guia->dia > 31)
    {
        return 0;
    }

    switch(guia->mes)
    {
    case 1:
        if(guia->dia>31)
            return 0;
    case 2:
        if(guia->ano % 4 == 0 && (guia->ano % 400 == 0 || guia->ano % 100 != 0))
        {
            if(guia->dia > 29)
                return 0;
        }
        if(guia->ano % 4 != 0)
        {
            if(guia->dia > 28)
            {
                return 0;
            }
        }
    case 3:
        if(guia->dia > 31)
        {
            return 0;
        }
    case 4:
        if(guia->dia > 30)
        {
            return 0;
        }
    case 5:
        if(guia->dia > 31)
        {
            return 0;
        }
    case 6:
        if(guia->dia > 30)
        {
            return 0;
        }
    case 7:
        if(guia->dia > 31)
        {
            return 0;
        }
    case 8:
        if(guia->dia > 30)
        {
            return 0;
        }
    case 9:
        if(guia->dia > 31)
        {
            return 0;
        }
    case 10:
        if(guia->dia > 30)
        {
            return 0;
        }
    case 11:
        if(guia->dia > 31)
        {
            return 0;
        }
    case 12:
        if(guia->dia > 30)
        {
            return 0;
        default:
            return 0;
        }
    }
    return 1;
}


int validarCPF(char *cpf)
{
    int ndx, validador1, validador2, aux[11];

    if(strlen(cpf) != 11)
    {
        return 0;
    }
    else if(cpf[1] == cpf[0] && cpf[2] == cpf[0] && cpf[3] == cpf[0] && cpf[4] == cpf[0]
            && cpf[5] == cpf[0] && cpf[6] == cpf[0] && cpf[7] == cpf[0] && cpf[8] == cpf[0]
            && cpf[9] == cpf[0] && cpf[10] == cpf[0])
    {
        return 0;
    }
    else
        for(ndx = 0; ndx < strlen(cpf); ndx++)
        {
            if(cpf[ndx] == '0')
                aux[ndx] = 0;
            else
                aux[ndx] = cpf[ndx] - '0';
        }

    validador1 = (aux[0]*10 + (aux[1]*9) + (aux[2]*8) + (aux[3]*7) + (aux[4]*6) + (aux[5]*5) + (aux[6]*4) + (aux[7]*3) + (aux[8]* 2)) ;
    validador1 = validador1 * 10 % 11;
    validador2 = (aux[0]*11 + (aux[1]*10) + (aux[2]*9) + (aux[3]*8) + (aux[4]*7) + (aux[5]*6) + (aux[6]*5) + (aux[7]*4) + (aux[8]*3)+ (aux[9]*2)) ;
    validador2 = validador2 * 10 % 11;

    if(aux[9] == validador1 && aux[10] == validador2)
    {
        return 1;
    }
    else
        return 0;
}


int validarNome(char *nome)
{
    int ndx=0;

    ndx = strlen(nome);

    if(ndx < 3 || ndx > MAX_NAME)
    {
        return 0;
    }
    else
    {
        ndx=0;
        do
        {
            if((nome[ndx] >= 97 && nome[ndx] <= 122) || (nome[ndx] >= 65 && nome[ndx] <= 90)
                    || (nome[ndx] == ' ' && nome[ndx+1] != ' '))
            {
                ndx++;
            }
            else
            {
                printf("\n\nNome apresenta acento ou algum caractere especial.");
                printf("\nInforme o nome sem acento.\n");
                return 0;
            }

        }
        while(ndx < strlen(nome));
    }
    return 1;
}


int validarSexo(char *sexo)
{
    int tamanho;

    tamanho = strlen(sexo);

    if(tamanho > 1)
    {
        return 0;
    }

    if(sexo[0] == 'F' || sexo[0] == 'f' || sexo[0] == 'M' || sexo[0] == 'm')
    {
        return 1;
    }
    else
        return 0;
}

void _Aniversario(char *data, date *Anv)
{

    typedef struct
    {
        char dia[2];
        char mes[2];
        char ano[4];
    } nascimento;

    nascimento *recebe = (nascimento*) malloc (sizeof(nascimento));

    int ndx=0, ndxV=0, ndxB=0;

    do
    {
        if(data[ndxV] != '/')
        {
            recebe->dia[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(data[ndxV] == '/')
        {
            ndxB++;
            recebe->dia[ndx++] = '\0';
            Anv->dia = atoi(recebe->dia);
            break;
        }
    }
    while(data[ndxV] != '/');

    ndxV++;
    ndx=0;

    do
    {
        if(data[ndxV] != '/')
        {
            recebe->mes[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(data[ndxV] == '/')
        {
            ndxB++;
            recebe->mes[ndx++] = '\0';
            Anv->mes = atoi(recebe->mes);
            break;
        }
    }
    while(data[ndxV] != '/');

    ndxV++;
    ndx = 0;

    do
    {
        if(data[ndxV] != '\0')
        {
            recebe->ano[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(data[ndxV] == '\0' && ndx >=2)
        {
            recebe->ano[ndx] = '\0';
            Anv->ano = atoi(recebe->ano);
            break;
        }
    }
    while(data[ndxV] != '\0');

    free(recebe);
}
