// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Ruan Tarcisio da Mota Silva
//  email:RuanTarciisio@gmail.com
//  Matrícula:2018216035
//  Semestre:2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */


//////////////////////////////////

struct  data                     // STRUCT Q2
{
    char dia[3];
    char mes[3];
    char ano[5];
    int  validado;

};data validar;

struct dataV                     // STRUCT Q2
{
    int dia;
    int mes;
    int ano;
    int result;
};

int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}




int q1(char *data){

    int ano=-1, mes=-1, dia=-1;
    int ndx=0, ndx_D=0, ndx_M=0, ndx_A=0, resultado =-1;

    int validar_data(char s_dia[], char s_mes[], char s_ano[], int d_dia, int m_mes, int a_ano);

    do
    {
        if(data[ndx_D] != '/')
        {
            validar.dia[ndx_D] = data[ndx];
            ndx++;
            ndx_D++;
        }
        if(ndx_D > 2)
        {
            dia = 0;
            break;
        }

        if(data[ndx] == '/')
        {
            validar.dia[ndx_D] = '\0';
            break;
        }
}while(data[ndx_D] != '/');

    ndx++;

    do
    {
        if(data[ndx] != '/')
        {
            validar.mes[ndx_M] = data[ndx];
            ndx++;
            ndx_M++;
        }
        if(ndx_M > 2)
        {
            mes = 0;
            break;
        }
        if(data[ndx] == '/')
        {
            validar.mes[ndx_M] = '\0';
            break;
        }
    }while(data[ndx] != '/');

    ndx++;

    do
    {
        if(data[ndx] != '\0')
        {
            validar.ano[ndx_A] = data[ndx];
            ndx++;
            ndx_A++;
        }
        if(ndx_A > 4)
        {
            ano = 0;
            break;
        }
        if(data[ndx] == '\0')
        {
            validar.ano[ndx_A] = '\0';
            break;
        }
}while(data[ndx] != '\0');

    resultado = validar_data(validar.dia, validar.mes, validar.ano, dia, mes, ano);

    return resultado;
}


int validar_data(char s_dia[], char s_mes[], char s_ano[], int d_dia, int m_mes, int a_ano){

int dia=0, mes=0, ano=0, validar=-1;

    if(d_dia == 0|| m_mes == 0|| a_ano == 0){
        validar = 0;
        return validar;
    }

dia = atoi(s_dia);
mes = atoi(s_mes);
ano = atoi(s_ano);

 if((ano > 99 && ano < 1869) || ano > 2020){
            ano = 0;
        }

            if(dia < 1 || dia > 31){
                dia = 0;
            }

                switch(mes){
                    case 1: if(dia>31)
                                    mes=0;break;
                    case 2: if(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)){
                                if(dia > 29)
                                    mes=0;break;
                                }
                                    if(ano % 4 != 0){
                                        if(dia >28)
                                            mes=0;break;
                                    }
                    case  3: if(dia>31)
                                    mes=0;break;
                    case  4: if(dia>30)
                                    mes=0;break;
                    case  5: if(dia>31)
                                    mes=0;break;
                    case  6: if(dia>30)
                                    mes=0;break;
                    case  7: if(dia>31)
                                    mes=0;break;
                    case  8: if(dia>30)
                                    mes=0;break;
                    case  9: if(dia>31)
                                    mes=0;break;
                    case 10: if(dia>30)
                                    mes=0;break;
                    case 11: if(dia>31)
                                    mes=0;break;
                    case 12: if(dia>30)
                                    mes=0;break;

                           default: mes=0;break;

                }

if(dia !=0 && mes !=0 && ano !=0){
    validar=1;
    return validar;
    }
        else
            validar=0;
            return validar;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial < datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
    int nDias=-1, nMeses=-1, nAnos=-1;
    struct data S_Validar, Validado[1];
    struct dataV Data_Quebrada[1], Diferenca;


    struct data Quebrar_Data(struct data x, char *date);
    struct dataV Validar_Data(struct data y, struct dataV z);
    struct dataV Diferenciar(struct dataV a, struct dataV b, struct dataV c);



    Validado[0] = Quebrar_Data(S_Validar, datainicial);
    Validado[1] = Quebrar_Data(S_Validar, datafinal);

    Data_Quebrada[0] = Validar_Data(Validado[0], Data_Quebrada[0]);
    Data_Quebrada[1] = Validar_Data(Validado[1], Data_Quebrada[1]);

    Diferenca = Diferenciar(Data_Quebrada[0], Data_Quebrada[1], Diferenca);


    if(Data_Quebrada[0].result == 0 && Data_Quebrada[1].result == 0)
    {
        return 5;
    }
    else if(Data_Quebrada[0].result == 0)
    {
        return 2;
    }
    else if(Data_Quebrada[1].result == 0)
    {
        return 3;
    }
    else if(Diferenca.result == 1)
    {
        *qtdDias  = Diferenca.dia;
        *qtdMeses = Diferenca.mes;
        *qtdAnos  = Diferenca.ano;
        return 1;
    }
    else if(Diferenca.result == 4)
    {
        return 4;
    }


}


struct data Quebrar_Data(struct data x, char *date)
{
    int dia=-1, mes=-1, ano=-1;
    int ndx=0, ndx_D=0, ndx_M=0, ndx_A=0;

    do
    {

        if(date[ndx_D] != '/')
        {
            x.dia[ndx_D] = date[ndx];
            ndx++;
            ndx_D++;
        }
        if(ndx_D > 2)
        {
            dia = 0;
            break;
        }

        if(date[ndx] == '/')
        {
            x.dia[ndx_D] = '\0';
            break;
        }


    }
    while(date[ndx_D] != '/');

    ndx++;

    do
    {
        if(date[ndx] != '/')
        {
            x.mes[ndx_M] = date[ndx];
            ndx++;
            ndx_M++;
        }
        if(ndx_M > 2)
        {
            mes = 0;
            break;
        }
        if(date[ndx] == '/')
        {
            x.mes[ndx_M] = '\0';
            break;
        }
    }
    while(date[ndx] != '/');

    ndx++;

    do
    {
        if(date[ndx] != '\0')
        {
            x.ano[ndx_A] = date[ndx];
            ndx++;
            ndx_A++;
        }
        if(ndx_A > 4)
        {
            ano = 0;
            break;
        }
        if(date[ndx] == '\0')
        {
            x.ano[ndx_A] = '\0';
            break;
        }

    }
    while(date[ndx] != '\0');;

    if(dia == 0 || mes == 0 || ano == 0)
    {
        x.validado = 0;
    }

    return x;
}

struct dataV Validar_Data(struct data y,  struct dataV z)
{


    int dia=0, mes=0, ano=0, validar=-1;

    z.dia = atoi(y.dia);
    z.mes = atoi(y.mes);
    z.ano = atoi(y.ano);
    z.result = -1;


    if((z.ano > 99 && z.ano < 1869) || z.ano > 2020)
    {
        z.result = 0;
        return z;
    }

    if(z.dia < 1 || z.dia > 31)
    {
        z.result = 0;
        return z;
    }

    switch(z.mes)
    {
    case 1:
        if(z.dia>31)
            z.result = 0;
        return z;
    case 2:
        if(z.ano % 4 == 0 && (z.ano % 400 == 0 || z.ano % 100 != 0))
        {
            if(z.dia > 29)
                z.result = 0;
            return z;
        }
        if(z.ano % 4 != 0)
        {
            if(z.dia > 28)
                z.result = 0;
            return z;
        }
    case  3:
        if(z.dia > 31)
            z.result = 0;
        return z;
    case  4:
        if(z.dia > 30)
            z.result = 0;
        return z;
    case  5:
        if(z.dia > 31)
            z.result = 0;
        return z;
    case  6:
        if(z.dia>30)
            z.result = 0;
        return z;
    case  7:
        if(z.dia > 31)
            z.result = 0;
        return z;
    case  8:
        if(z.dia > 30)
            z.result = 0;
        return z;
    case  9:
        if(z.dia > 31)
            z.result = 0;
        return z;
    case 10:
        if(z.dia > 30)
            z.result = 0;
        return z;
    case 11:
        if(z.dia > 31)
            z.result = 0;
        return z;
    case 12:
        if(z.dia > 30)
            z.result = 0;
        return z;

    default:
        z.result = 0;
        return z;

    }


    return z;

}
struct dataV Diferenciar(struct dataV a, struct dataV b, struct dataV c)
{
    c.dia=-1;
    c.mes=-1;
    c.ano=-1;

    if(b.ano >= a.ano)
    {

        if((b.ano > a.ano) && b.mes < a.mes && b.dia < a.dia)
        {
            c.result = 1;

            c.ano = b.ano - 1 - a.ano;

            if(a.mes == 2)
            {
                if(a.ano % 4 == 0 && (a.ano % 400 == 0 || a.ano % 100 != 0))
                {
                    c.mes = (b.mes + 11) - a.mes;
                    c.dia = (b.dia + 29) - a.dia;
                }
                else
                {
                    c.mes = (b.mes + 11) - a.mes;
                    c.dia = (b.dia + 28) - a.dia;
                }
            }
            else if(a.mes != 2 && a.mes % 2 == 0)
            {
                c.mes = (b.mes + 11) - a.mes;
                c.dia = (b.dia + 30) - a.dia;
            }
            else if(a.mes != 2 && a.mes % 2 == 1)
            {
                c.mes = (b.mes + 11) - a.mes;
                c.dia = (b.dia + 31) - a.dia;
            }
        }

        else if((b.ano == a.ano) && b.mes < a.mes && b.dia < a.dia)
        {
            c.result = 4;
        }

        else if((b.ano > a.ano) && b.mes < a.mes && b.dia >= a.dia)
        {

            c.result = 1;

            c.ano = (b.ano - 1) - a.ano;
            c.mes = (b.mes + 12) - a.mes;
            c.dia = b.dia - a.dia;
        }
        else if((b.ano == a.ano) && b.mes < a.mes && b.dia >= a.dia)
        {
            c.result = 4;
        }

        else if((b.ano > a.ano) && b.mes < a.mes && b.dia >= a.dia)
        {
            c.result = 1;
        }

        else if((b.ano == a.ano) && b.mes < a.mes && b.dia >= a.dia)
        {
            c.result = 4;
        }
        else if(b.mes > a.mes && b.dia < a.dia)//////////////// I'm Here!!!
        {
            c.result = 1;

            c.ano = b.ano - a.ano;
            if(a.mes == 2)
            {
                if(b.ano % 4 == 0 && (b.ano % 400 == 0 || b.ano % 100 != 0))
                {
                    c.mes = (b.mes + 11) - a.mes;
                    c.dia = (b.dia + 29) - a.dia;
                }
                else
                {
                    c.mes = (b.mes + 11) - a.mes;
                    c.dia = (b.dia + 28) - a.dia;
                }
            }
            else if((a.mes != 2) && a.mes % 2 == 0)
            {
                c.dia = b.dia + 30 - a.dia;
                c.mes = b.mes - a.mes - 1;
            }
            else if(a.mes % 2 == 1)
            {
                c.dia = b.dia + 31 - a.dia;
                c.mes = b.mes - a.mes - 1;
            }
        }

        else if(b.mes > a.mes && b.dia >= a.dia)
        {
            c.result = 1;

            c.ano = b.ano  - a.ano;
            c.dia = b.dia  - a.dia;
            c.mes = b.mes  - a.mes;
        }

        else if((b.ano > a.ano) && b.mes == a.mes && b.dia < a.dia)
        {
            c.result = 1;

            c.ano = b.ano - a.ano;
            c.mes = 11;


            if(a.mes == 2)
            {
                if(a.ano % 4 == 0 && (a.ano % 400 == 0 || a.ano % 100 != 0))
                {
                    c.dia = (b.dia + 29) - a.dia;
                }
                else
                {
                    c.dia = (b.dia + 28) - a.dia;
                }
            }
            else if((a.mes != 2) && a.mes % 2 == 0)
            {
                c.dia = b.dia + 30 - a.dia;
            }
            else if(a.mes % 2 == 1)
            {
                c.dia = b.dia + 31 - a.dia;
            }
        }

        else if((b.ano == a.ano) && b.mes == a.mes && b.dia < a.dia)
        {
            c.result = 4;
        }

        else if(b.mes == a.mes && b.dia >= a.dia)
        {
            c.result = 1;

            c.ano = b.ano - a.ano;

            if(a.mes % 2 == 0)
            {
                c.mes = 0;
                c.dia = b.dia - a.dia;
            }
            if(a.mes % 2 == 1)
            {
                c.mes = 0;
                c.dia = b.dia - a.dia;;
            }
        }
    }
    else if(b.ano < a.ano)
    {
        c.result = 4;
    }
    return c;
}




/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias=0;
    int len_Texto=0, ndx=0, ndxTexto=0;
    len_Texto = strlen(texto);

    ndx=0;


    if(isCaseSensitive==0)
    {

        do
        {
            texto[ndxTexto]=toupper(texto[ndxTexto]);
            c=toupper(c);

            if(texto[ndxTexto] == c)
            {
                qtdOcorrencias++;
            }
            else if(texto[ndxTexto] != c)
            {


            }
            ndxTexto++;
        }
        while(ndxTexto < len_Texto);
    }

    else if(isCaseSensitive == 1)
    {

        do
        {

            if(texto[ndxTexto] == c)
            {
                qtdOcorrencias++;
            }
            ndxTexto++;
        }
        while(ndxTexto < len_Texto);
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente.
    Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1,
     deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3,
     e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto,
     deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){


int ndxTexto=0, ndxPalavra=0, ndx=0, qtdOcorrencias=0;
int tamTexto=0, tamPalavra=0;

tamTexto = strlen(strTexto);
tamPalavra = strlen(strBusca);

    do
    {
        if(strTexto[ndxTexto] == strBusca[ndxPalavra])
        {
            ndxPalavra++;

            if(ndxPalavra == tamPalavra && tamPalavra > 1)
            {
                posicoes[ndx] = ndxTexto - tamPalavra+2;
                ndx++;
                posicoes[ndx] = ndxTexto+1;
                ndx++;

                qtdOcorrencias++;
                ndxPalavra=0;

            }
        }
        else if(strTexto[ndxTexto] != strBusca[ndxPalavra])
        {
            ndxPalavra=0;
            posicoes[ndx] = '\0';

        }

        ndxTexto++;

    }
    while(ndxTexto < tamTexto);


return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int inverso=0;

    int inverter(int num);

    inverso = inverter(num);


    return inverso;
}


int inverter(int num)
{

    int a, b, c, d, e, f, g, h, i, j;
    int inverso = 0;


    if(num < 10)
    {
        inverso = num;
        return inverso;
    }
    else if(num >= 10 && num < 100)
    {
        a = (num / 10);
        b = (num % 10);
        inverso = (b * 10) + a;
        return inverso;
    }
    else if(num >= 100 && num < 1000)
    {
        a = (num / 100);
        b = (num % 100) / 10;
        c = (num % 10);
        inverso = (c * 100) + (b * 10) + a;
        return inverso;
    }
    else if(num >= 1000 && num < 10000)
    {
        a = (num / 1000);
        b = (num % 1000) / 100;
        c = (num % 100) / 10;
        d = (num % 10);
        inverso = (d * 1000) + (c * 100) + (b * 10) + a;
        return inverso;
    }
    else if(num >= 10000 && num < 100000)
    {
        a = (num / 10000);
        b = (num % 10000) / 1000;
        c = (num % 1000) / 100;
        d = (num % 100) / 10;
        e = (num % 10) ;
        inverso = (e * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
        return inverso;
    }
    else if(num >= 100000 && num < 1000000)
    {
        a = (num / 100000);
        b = (num % 100000) / 10000;
        c = (num % 10000) / 1000;
        d = (num % 1000) / 100;
        e = (num % 100) / 10;
        f = (num % 10) ;
        inverso = (f * 100000) + (e * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
        return inverso;
    }
    else if(num >= 1000000 && num < 10000000)
    {
        a = (num / 1000000);
        b = (num % 1000000) / 100000;
        c = (num % 100000) / 10000;
        d = (num % 10000) / 1000;
        e = (num % 1000) / 100;
        f = (num % 100) / 10;
        g = (num % 10) ;
        inverso = (g * 1000000) + (f * 100000) + (e * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
        return inverso;
    }
    else if(num >= 10000000 && num < 100000000)
    {
        a = (num / 10000000);
        b = (num % 10000000) / 1000000;
        c = (num % 1000000) / 100000;
        d = (num % 100000) / 10000;
        e = (num % 10000) / 1000;
        f = (num % 1000) / 100;
        g = (num % 100) / 10;
        h = (num % 10) ;
        inverso = (h * 10000000) + (g * 1000000) + (f * 100000) + (e * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
        return inverso;
    }
    else if(num >= 100000000 && num < 1000000000)
    {
        a =   num / 100000000;
        b = (num % 100000000) / 10000000;
        c = (num % 10000000) / 1000000;
        d = (num % 1000000) / 100000;
        e = (num % 100000) / 10000;
        f = (num % 10000) / 1000;
        g = (num % 1000) / 100;
        h = (num % 100) / 10;
        i = (num % 10) ;
        inverso = (i * 100000000) + (h * 10000000) + (g * 1000000) + (f * 100000) + (e * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
        return inverso;
    }

}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int num_0_0;
    int num_1_1;
    int quoc_0, quoc_1, resto_0, resto_1, resto_aux=0, num_verif=0, aux, i=0;
    int qtdOcorrencias=0;


    resto_0 = -1;
    resto_1 = -2;
    resto_aux = 0;
    num_verif=0;

    aux = 1;
    num_0_0 = numerobase;
    num_1_1 = numerobusca;

    for(i=0; i<10; i++)
    {

        if(resto_0 == resto_1)
        {
            resto_aux = resto_0 * aux;
            num_verif += resto_aux;
            num_0_0 = quoc_0;
            quoc_0 = num_0_0 / 10;
            resto_0 = num_0_0 % 10;
            num_1_1 = quoc_1;
            quoc_1 = num_1_1 / 10;
            resto_1 = num_1_1 % 10;

            aux *=10;
        }

        if(num_verif == numerobusca)
        {
            qtdOcorrencias++;
            resto_aux = 0;
            num_verif = 0;
            aux = 1;
            num_0_0 = quoc_0;
            quoc_1 = numerobusca / 10;
            resto_1 = numerobusca % 10;
        }
        else if(resto_0 != resto_1)
        {
            resto_aux = 0;
            num_verif = 0;
            aux = 1;
            quoc_0 = num_0_0 / 10;
            resto_0 = num_0_0 % 10;
            num_0_0 = quoc_0;
            quoc_1 = numerobusca / 10;
            resto_1 = numerobusca % 10;
            num_1_1 = quoc_1;

        }

    }

    return qtdOcorrencias;

}

