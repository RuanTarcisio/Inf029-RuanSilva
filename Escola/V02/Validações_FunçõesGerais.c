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
    int ndx=0;

    printf("\n Informe o nome: ");
    setbuf(stdin, NULL);
    fgets(Dados.nome, MAX_NAME,stdin);
    scanf("");
    setbuf(stdin, NULL);
    scanf("");
    setbuf(stdin, NULL);
    printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
    scanf("");
    scanf("%s", Dados.nascimento);
    setbuf(stdin, NULL);
    printf("\n Informe o CPF: ");
    gets(Dados.cpf);
    setbuf(stdin, NULL);
    printf("\n Informe o sexo (F/M): ");
    gets(&Dados.sexo);

    do
    {
        Dados.nome[ndx] = toupper(Dados.nome[ndx]);
        ndx++;
    }
    while(ndx < strlen(Dados.nome));

    Dados.sexo = toupper(Dados.sexo);

    Dados = validar(&Dados);

    return Dados;
}


cadastro validar(cadastro *Dados) /* VALIDAR PELAS OUTRAS FUNÇÕES E RETORNAR*/
{
    int a, b, c, d, confirma, ndx=0 ;

    a = validarNome(Dados->nome);
    b = validarData(&Dados->nascimento);
    c = validarCPF(&Dados->cpf);
    d = validarSexo(&Dados->sexo);

    do
    {
        if (a != 1)
        {
            setbuf(stdin, NULL);
            printf("\n Informe o nome: ");
            gets(Dados->nome);

            do
            {
                Dados->nome[ndx] = toupper(Dados->nome[ndx]);
                ndx++;

            }
            while(ndx < strlen(Dados->nome));

            a = validarNome(&Dados->nome);
        }
        if (b != 1)
        {
            printf("\nData Invalida.");
            setbuf(stdin, NULL);
            printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
            gets(Dados->nascimento);
            b = validarData(&Dados->nascimento);
        }
        if (c != 1)
        {
            printf("\nCPF Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o CPF: ");
            scanf("%s", Dados->cpf);
            c = validarCPF(&Dados->cpf);
        }
        if (d != 1)
        {
            setbuf(stdin, NULL);
            printf("\nSexo Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o sexo (F/M): ");
            gets(&Dados->sexo);
            Dados->sexo = toupper(Dados->sexo);
            d = validarSexo(&Dados->sexo);
        }
    }
    while(a != 1 || b != 1 || c != 1 || d != 1);

    system("cls");
    printf("\n\n Confirmas os dados: \n\n");
    puts(Dados->nome);
    printf("\n");
    puts(Dados->nascimento);
    printf("\n");
    puts(Dados->cpf);
    printf("\n");
    printf("%c\n", Dados->sexo);
    printf("\nDigite, (1)- SIM, (2)- NAO ou (0)- SAIR\n");
    scanf("%d", &confirma);

    switch(confirma)
    {
    case 1:
        printf("\nRealizado com sucesso.");
        return *Dados;
    case 2:
        RecebeDadosPessoais();
        break;
    case 0:
        exit(0);
        break;
    default:
        validar(&Dados);
        break;
    }
}

int validarData(char *data)
{
    typedef struct
    {
        char dia[2];
        char mes[2];
        char ano[4];
    } nascimento;

    nascimento recebe;
    date guia;

    int validador;

    int ndx=0, ndxV=0;
    guia.ano = 0;
    guia.mes = 0;
    guia.dia = 0;

    do
    {
        if(data[ndxV] != '/')
        {
            recebe.dia[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            return 0;
        }

        if(data[ndxV] == '/')
        {
            recebe.dia[ndx++] = '\0';
            guia.dia = atoi(recebe.dia);
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
            recebe.mes[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            return 0;
        }
        if(data[ndxV] == '/')
        {
            recebe.mes[ndx++] = '\0';
            guia.mes = atoi(recebe.mes);
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
            recebe.ano[ndx] = data[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 4)
        {
            return 0;
        }
        if(data[ndxV] == '\0' && ndx >=2)
        {
            recebe.ano[ndx] = '\0';
            guia.ano = atoi(recebe.ano);
            break;
        }
    }
    while(data[ndxV] != '\0');

    validador = validarNascimento(guia);
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
    int ndx, validador, validador2, aux[11];

    if(strlen(cpf) != 11)
    {
        return 0;
        printf("\n\n AQ 0");
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

    validador = (aux[0]*10 + (aux[1]*9) + (aux[2]*8) + (aux[3]*7) + (aux[4]*6) + (aux[5]*5) + (aux[6]*4) + (aux[7]*3) + (aux[8]* 2)) ;
    validador = validador * 10 % 11;
    validador2 = (aux[0]*11 + (aux[1]*10) + (aux[2]*9) + (aux[3]*8) + (aux[4]*7) + (aux[5]*6) + (aux[6]*5) + (aux[7]*4) + (aux[8]*3)+ (aux[9]*2)) ;
    validador2 = validador2 * 10 % 11;

    if(aux[9] == validador && aux[10] == validador2)
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

    nome[ndx-1] = '\0';

    if(ndx <= 2 || ndx > MAX_NAME)
    {
        printf("\nUltrapassou o limite de 50 caracteres ou tem apenas 2 letras.\n");
        printf("Informe o nome:\n");
        return 0;
    }
    else
    {
        ndx=0;
        do
        {
            if(nome[ndx] >= 97 && nome[ndx] <= 122 || (nome[ndx] >= 65 && nome[ndx] <= 90)
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

int Push(Node** Geral, cadastro *Pessoas, int opcao)
{
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->dados = *Pessoas;

    if(*Geral == NULL)
    {
        novo->prox = NULL;
        if(opcao == 1)
        {
            novo->dados.matricula = MATRICULA_ALUN;
        }
        else
            novo->dados.matricula = MATRICULA_PROF;
        *Geral = novo;
        (*Geral)->tamanho = 1;
        (*Geral)->posicao = 1;
    }
    else
    {
        novo->prox = *Geral;
        if(opcao == 1)
        {
            novo->dados.matricula = MATRICULA_ALUN + (*Geral)->posicao;
        }
        else
            novo->dados.matricula = MATRICULA_PROF + (*Geral)->posicao;
        *Geral = novo;
        (*Geral)->tamanho ++;
        (*Geral)->posicao ++;
    }
}

void Display(Node *Geral, int opcao)
{
    Node *ref = Geral;

    if(ref == NULL)
    {
        if(opcao == 1)
        {
            printf("\nSem Alunos Cadastrados.");
            getchar();
            menuAlunos();
        }
        else
            printf("\nSem Professores Cadastrados.");
        getchar();
        menuProfessores();
    }

    else
    {
        do
        {
            printf("\n\n%s ", ref->dados.nome);
            printf("\n\n%d ", ref->dados.matricula);
            printf("\n\n%s ", ref->dados.nascimento);
            printf("\n\n%s ", ref->dados.cpf);
            printf("\n\n%c ", ref->dados.sexo);
            printf("\n ---------------------------------------------------");
            ref = ref->prox;
        }
        while(ref != NULL);
    }
    printf("\n\n");
    free(ref);
}
