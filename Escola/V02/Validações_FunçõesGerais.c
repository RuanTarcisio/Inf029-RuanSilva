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

    setbuf(stdin, NULL);

    printf("\n Informe o nome: ");
    gets(&Dados.nome);
    scanf("");
    setbuf(stdin, NULL);
    scanf("");
    setbuf(stdin, NULL);
    printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
    scanf("");
    scanf("%s", &Dados.nascimento);
    setbuf(stdin, NULL);
    printf("\n Informe o CPF: ");
    gets(&Dados.cpf);
    setbuf(stdin, NULL);
    printf("\n Informe o sexo (F/M): ");
    gets(&Dados.sexo);


    Dados = validar(&Dados);



    return Dados;
}


cadastro validar(cadastro *Dados) /* VALIDAR PELAS OUTRAS FUNÇÕES E RETORNAR*/
{
    int a, b, c, d;


    a = validarNome(Dados->nome);
    b = validarData(&Dados->nascimento);
    c = validarCPF(&Dados->cpf);
    d = validarSexo(&Dados->sexo);

    printf("\n  %d   %d   %d   %d",a, b, c, d);

    do
    {
        if (a != 1)
        {
            setbuf(stdin, NULL);
            printf("\n Informe o nome: ");
            gets(Dados->nome);
            a = validarNome(&Dados->nome);
        }
        if (b != 1)
        {
            printf("\nData Invalida.");
            setbuf(stdin, NULL);
            printf("\n Informe a data de nascimento dd/mm/aaaa:  ");
            gets(Dados->nascimento);
            b = validarData(&Dados->nascimento);
            printf("%d ",b);
        }
        if (c != 1)
        {
            printf("\nCPF Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o CPF: ");
            gets(Dados->cpf);
            c = validarCPF(&Dados->cpf);
        }
        if (d != 1)
        {
            setbuf(stdin, NULL);
            printf("\nSexo Invalido.");
            setbuf(stdin, NULL);
            printf("\n Informe o sexo (F/M): ");
            gets(&Dados->sexo);
            d = validarSexo(&Dados->sexo);
        }
    }
    while(a != 1 || b != 1 || c != 1 || d != 1);

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

	if(strlen(cpf)  > 11) {
		return 0;
	} else {
		double cpfInt = atof(cpf);

		double primeiroDigitoF = 0;
		int primeiroDigito = 0;
		int segundoDigito = 0;
		int terceiroDigito = 0;
		int quartoDigito = 0;
		int quintoDigito = 0;
		int sextoDigito = 0;
		int setimoDigito = 0;
		int oitavoDigito = 0;
		int nonoDigito = 0;

		/*/ Validando primeiro digito vericador  */

		int multiDigito1 = 0;
		int multiDigito2 = 0;
		int multiDigito3 = 0;
		int multiDigito4 = 0;
		int multiDigito5 = 0;
		int multiDigito6 = 0;
		int multiDigito7 = 0;
		int multiDigito8 = 0;
		int multiDigito9 = 0;

		int somaDigitos = 0;
		int restoDigitos = 0;
		int subDigitos = 0;

		int primeiroDigitoVerificador = 0;

		primeiroDigitoF = cpfInt / 10000000000;
		primeiroDigito = primeiroDigitoF;
		segundoDigito = cpfInt / 1000000000;
		segundoDigito = segundoDigito % 10;
		terceiroDigito = cpfInt / 100000000;
		terceiroDigito = terceiroDigito % 10;
		quartoDigito = cpfInt / 10000000;
		quartoDigito = quartoDigito % 10;
		quintoDigito = cpfInt / 1000000;
		quintoDigito = quintoDigito % 10;
		sextoDigito = cpfInt / 100000;
		sextoDigito = sextoDigito % 10;
		setimoDigito = cpfInt / 10000;
		setimoDigito = setimoDigito % 10;
		oitavoDigito = cpfInt / 1000;
		oitavoDigito = oitavoDigito % 10;
		nonoDigito = cpfInt / 100;
		nonoDigito = nonoDigito % 10;

		/*/	Pegando últimos digitos informados  */

		long long int decimoDigito  =0;
		long long int decimo1Digito = 0;

		decimoDigito = cpfInt / 10;
		decimoDigito = decimoDigito % 10;
		decimo1Digito = cpfInt;
		decimo1Digito = decimo1Digito % 10;

		multiDigito1 = primeiroDigito * 10;
		multiDigito2 = segundoDigito  * 9;
		multiDigito3 = terceiroDigito * 8;
		multiDigito4 = quartoDigito   * 7;
		multiDigito5 = quintoDigito   * 6;
		multiDigito6 = sextoDigito    * 5;
		multiDigito7 = setimoDigito   * 4;
		multiDigito8 = oitavoDigito   * 3;
		multiDigito9 = nonoDigito     * 2;

		somaDigitos = (multiDigito1 + multiDigito2 + multiDigito3 + multiDigito4
					    + multiDigito5 + multiDigito6 + multiDigito7 + multiDigito8 + multiDigito9);

		restoDigitos = somaDigitos % 11;

		subDigitos = 11 - restoDigitos;

		if(subDigitos >= 10) {
			primeiroDigitoVerificador = 0;
		} else {
			primeiroDigitoVerificador = subDigitos;
		}

		/*/ Validando segundo digito verifcador   */

		int multi2Digito1 = 0;
		int multi2Digito2 = 0;
		int multi2Digito3 = 0;
		int multi2Digito4 = 0;
		int multi2Digito5 = 0;
		int multi2Digito6 = 0;
		int multi2Digito7 = 0;
		int multi2Digito8 = 0;
		int multi2Digito9 = 0;
		int multi2Digito10 = 0;

		int soma2Digitos = 0;
		int resto2Digitos = 0;
		int sub2Digitos = 0;

		int segundoDigitoVerificador = 0;

		multi2Digito1 = primeiroDigito * 11;
		multi2Digito2 = segundoDigito  * 10;
		multi2Digito3 = terceiroDigito * 9;
		multi2Digito4 = quartoDigito   * 8;
		multi2Digito5 = quintoDigito   * 7;
		multi2Digito6 = sextoDigito    * 6;
		multi2Digito7 = setimoDigito   * 5;
		multi2Digito8 = oitavoDigito   * 4;
		multi2Digito9 = nonoDigito     * 3;
		multi2Digito10 = primeiroDigitoVerificador * 2;

		soma2Digitos = (multi2Digito1 + multi2Digito2 + multi2Digito3 + multi2Digito4 + multi2Digito5
					    + multi2Digito6 + multi2Digito7 + multi2Digito8 + multi2Digito9 + multi2Digito10);

		resto2Digitos = soma2Digitos % 11;

		sub2Digitos = 11 - resto2Digitos;

		if(sub2Digitos >= 10) {
			segundoDigitoVerificador = 0;
		} else {
			segundoDigitoVerificador = sub2Digitos;
		}

		if(decimoDigito == primeiroDigitoVerificador && decimo1Digito == segundoDigitoVerificador) {
			return 1;
		} else {
			return 0;
		}
	}
}

int validarNome(char *nome)
{
    int ndx=0;

    ndx = strlen(nome);

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

    if(sexo[0] == 'F' || sexo[0] == 'f' || sexo[0] == 'M' || sexo[0] == 'm'){
        return 1;
    }
    else
        return 0;
}

int Push(Node** Geral, cadastro *Pessoas)
{
    Node *novo = (Node*) malloc (sizeof(Node));
}
