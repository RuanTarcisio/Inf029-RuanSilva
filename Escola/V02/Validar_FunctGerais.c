#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"


_cadastro RecebeDados_Materia()
{
    _cadastro _Dados;
    /*char *nome, *codigo;
    int semestre;*/

    setbuf(stdin, NULL);
    printf("\n Digite o nome disciplina: ");
    setbuf(stdin, NULL);
    gets(_Dados.nome);
    setbuf(stdin, NULL);
    printf(" \n Digite o código da disciplina: ");
    gets(_Dados.codigo);
    setbuf(stdin, NULL);
    printf("\n Digite o semestre da disciplina: ");
    scanf("%d", &_Dados.semestre);
    setbuf(stdin, NULL);


    _Dados = _Validar(&_Dados);

    return _Dados;
}


_cadastro AlteraDados_Materia(_cadastro _Dados)
{

    setbuf(stdin, NULL);
    printf("\n Digite o nome disciplina: ");
    setbuf(stdin, NULL);
    gets(_Dados.nome);
    setbuf(stdin, NULL);
    printf(" \n Digite o código da disciplina: ");
    gets(_Dados.codigo);
    setbuf(stdin, NULL);
    printf("\n Digite o semestre da disciplina: ");
    scanf("%d", &_Dados.semestre);
    setbuf(stdin, NULL);


    _Dados = _Validar(&_Dados);

    return _Dados;
}


_cadastro _Validar(_cadastro *_Materia)
{
    int a, b, c=1, ndx=0 ;
    char confirma, *nome, *codigo;

    nome = _Materia->nome;
    codigo = _Materia->codigo;

    a = validarNome(nome);
    b = validarCodigo(codigo);
    printf("AQQQ");

    if(_Materia->semestre < 1 || _Materia->semestre > 10)
    {
        c = 0;
    }

    do
    {
        if (a != 1)
        {
            printf("\nNome Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o nome: ");
            gets(nome);
            setbuf(stdin, NULL);
            a = validarNome(nome);
        }
        if (b != 1)
        {
            printf("\n Codigo Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o codigo da disciplina:  ");
            setbuf(stdin, NULL);
            gets(codigo);
            setbuf(stdin, NULL);
            b = validarCodigo(codigo);
        }
        if (c != 1)
        {
            printf("\n Semestre Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o CPF: ");
            setbuf(stdin, NULL);
/*
            c = validarCPF(cpf);                        */
        }

    }
    while(a != 1 || b != 1 || c != 1);

    ndx=0;
    do
    {
        _Materia->nome[ndx] = toupper(_Materia->nome[ndx]);
        ndx++;
    }
    while(ndx < strlen(_Materia->nome));

    do
    {
        _Materia->codigo[ndx] = toupper(_Materia->codigo[ndx]);
        ndx++;
    }
    while(ndx < strlen(_Materia->codigo));


    system("cls");
    printf("\n\n");
    puts(_Materia->nome);
    printf("\n");
    puts(_Materia->codigo);
    printf("\n");
    printf("%d", _Materia->semestre);
    printf("\n Confirma os dados? Digite, (1)- SIM, (2)- NAO ou (9)- SAIR\n");
    confirma = getch();
    setbuf(stdin, NULL);

    switch(confirma)
    {
    case '1':
        return *_Materia;
    case '2':
        RecebeDados_Materia();
        break;
    case '0':
        printf("\nEncerrando o programa.");
        exit(0);
        break;
    default:
        _Validar(_Materia);
        break;
    }
    return *_Materia;
}


int validarCodigo(char *codigo)
{
    int v_ndx = 1, ndx = 0;

    if(strlen(codigo) != 6)
    {
        return 0;
    }

    do
    {
        if(!isalpha(codigo[ndx]))
        {
            v_ndx = 0;
            break;
        }
        ndx++;
    }while(ndx < 3);

    do
    {
        if(!isdigit(codigo[ndx]))
        {
            v_ndx = 0;
            break;
        }
        ndx++;
    }while(ndx < 7 && codigo[ndx] != '\0');

    return v_ndx;
}


cadastro RecebeDadosPessoais()
{
    cadastro Dados;

    char *nome, *sexo, *nascimento, *cpf;

    nome = Dados.nome;
    sexo = &Dados.sexo;
    nascimento = Dados.nascimento;
    cpf = Dados.cpf;

    setbuf(stdin, NULL);
    printf("\n Digite o nome: ");
    setbuf(stdin, NULL);
    gets(nome);
    setbuf(stdin, NULL);
    printf(" \n Digite a data de nascimento < dd/mm/aaaa >: ");
    gets(nascimento);
    setbuf(stdin, NULL);
    printf("\n Digite o CPF: ");
    gets(cpf);
    setbuf(stdin, NULL);
    printf("\n Digite o sexo (F)- FEMININO ou (M) MASCULINO: ");
    gets(sexo);
    setbuf(stdin, NULL);

    printf("\n TO AQ 0");
    Dados = validar(&Dados);

    return Dados;
}


cadastro AlterarDadosPessoais(cadastro Dados)
{
    char *nome, *sexo, *nascimento;

    nome = Dados.nome;
    sexo = &Dados.sexo;
    nascimento = Dados.nascimento;

    printf("\n\n\n Informe os novos dados. ");
    printf("\n Digite o nome: ");
    setbuf(stdin, NULL);
    gets(nome);
    setbuf(stdin, NULL);
    printf(" \n Digite a data de nascimento < dd/mm/aaaa >: ");
    gets(nascimento);
    setbuf(stdin, NULL);
    /*printf("\n Digite o CPF: ");
    gets(cpf);
    setbuf(stdin, NULL);*/
    printf("\n Digite o sexo (F)- FEMININO ou (M) MASCULINO: ");
    gets(sexo);
    setbuf(stdin, NULL);

    Dados = alt_validar(&Dados);

    return Dados;
}


cadastro validar(cadastro *Dados) /* VALIDAR PELAS OUTRAS FUNÇÕES E RETORNAR*/
{
    int a, b, c, d, ndx=0 ;
    char confirma, *sexo, *nascimento, *nome, *cpf;

    date *rcbAniversario = &Dados->aniversario;
    nascimento = Dados->nascimento;
    nome = Dados->nome;
    cpf = Dados->cpf;
    sexo = &Dados->sexo;

    a = validarNome(nome);
    b = validarData(nascimento);
    c = validarCPF(cpf);
    d = validarSexo(sexo);

    do
    {
        if (a != 1)
        {
            printf("\nNome Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o nome: ");
            gets(nome);
            setbuf(stdin, NULL);
            a = validarNome(nome);
        }
        if (b != 1)
        {
            printf("\n Data Invalida.");
            setbuf(stdin, NULL);
            printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
            setbuf(stdin, NULL);
            gets(nascimento);
            setbuf(stdin, NULL);
            b = validarData(nascimento);
        }
        if (c != 1)
        {
            printf("\nCPF Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o CPF: ");
            setbuf(stdin, NULL);
            gets(cpf);
            c = validarCPF(cpf);
        }
        if (d != 1)
        {
            setbuf(stdin, NULL);
            printf("\nSexo Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o sexo (F/M): ");
            gets(sexo);
            setbuf(stdin, NULL);
            d = validarSexo(sexo);
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
    Dados->sexo = toupper(Dados->sexo);

    _Aniversario(nascimento, rcbAniversario);

    system("cls");
    printf("\n\n");
    puts(Dados->nome);
    printf("\n");
    puts(Dados->nascimento);
    printf("\n");
    puts(Dados->cpf);
    printf("\n");
    puts(sexo);
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


cadastro alt_validar(cadastro *Dados) /* VALIDAR PELAS OUTRAS FUNÇÕES E RETORNAR*/
{
    int a, b, c, d, ndx=0 ;
    char *sexo, *nascimento, *nome, *cpf;

    date *rcbAniversario = &Dados->aniversario;
    nascimento = Dados->nascimento;
    nome = Dados->nome;
    cpf = Dados->cpf;
    sexo = &Dados->sexo;

    a = validarNome(nome);
    b = validarData(nascimento);
    c = validarCPF(cpf);
    d = validarSexo(sexo);

    do
    {
        if (a != 1)
        {
            printf("\nNome Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o nome: ");
            gets(nome);
            setbuf(stdin, NULL);
            a = validarNome(nome);
        }
        if (b != 1)
        {
            printf("\n Data Invalida.");
            setbuf(stdin, NULL);
            printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
            setbuf(stdin, NULL);
            gets(nascimento);
            setbuf(stdin, NULL);
            b = validarData(nascimento);
        }
        if (c != 1)
        {
            printf("\nCPF Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o CPF: ");
            setbuf(stdin, NULL);
            gets(cpf);
            c = validarCPF(cpf);
        }
        if (d != 1)
        {
            setbuf(stdin, NULL);
            printf("\nSexo Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o sexo (F/M): ");
            gets(sexo);
            setbuf(stdin, NULL);
            d = validarSexo(sexo);
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
    Dados->sexo = toupper(Dados->sexo);

    _Aniversario(nascimento, rcbAniversario);

    system("cls");
    printf("\n\n");
    puts(Dados->nome);
    printf("\n");
    puts(Dados->nascimento);
    printf("\n");
    puts(Dados->cpf);
    printf("\n");
    puts(sexo);
    getch();

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
    date *guia = NULL ;

    int validador;

    int ndx=0, ndxV=0, ndxB=0;

    do
    {
        if(!isdigit(data[ndx]) && data[ndx] != '/')
        {
            printf("\nInvalida");
            break;
            return 0;
        }
        ndx++;
        printf("\nValida");
    }while(ndx < strlen(data));

    ndx = 0;
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
    else if(cpf[1] == cpf[0] &&
            cpf[2] == cpf[0] &&
            cpf[3] == cpf[0] &&
            cpf[4] == cpf[0] &&
            cpf[5] == cpf[0] &&
            cpf[6] == cpf[0] &&
            cpf[7] == cpf[0] &&
            cpf[8] == cpf[0] &&
            cpf[9] == cpf[0] &&
            cpf[10] == cpf[0])
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

    validador1 = ( aux[0]*10 +
                  (aux[1]*9) +
                  (aux[2]*8) +
                  (aux[3]*7) +
                  (aux[4]*6) +
                  (aux[5]*5) +
                  (aux[6]*4) +
                  (aux[7]*3) +
                  (aux[8]* 2)) ;
    validador1 = validador1 * 10 % 11;

    validador2 = ( aux[0]*11 +
                  (aux[1]*10)+
                  (aux[2]*9) +
                  (aux[3]*8) +
                  (aux[4]*7) +
                  (aux[5]*6) +
                  (aux[6]*5) +
                  (aux[7]*4) +
                  (aux[8]*3)+
                  (aux[9]*2)) ;
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
