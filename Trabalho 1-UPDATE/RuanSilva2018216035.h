#ifndef RUANSILVA2018216035_H_INCLUDED
#define RUANSILVA2018216035_H_INCLUDED


struct  data                     // STRUCT Q2
{
    char dia[3];
    char mes[3];
    char ano[5];
    int  validado;

}validar;

struct dataV                     // STRUCT Q2
{
    int dia;
    int mes;
    int ano;
    int result;
};


int q1(char *data);
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);


int validar_data(char s_dia[], char s_mes[], char s_ano[], int d_dia, int m_mes, int a_ano);
struct data Quebrar_Data(struct data x, char *date);
struct dataV Validar_Data(struct data y,  struct dataV z);
struct dataV Diferenciar(struct dataV a, struct dataV b, struct dataV c);
int inverter(int num);




#endif // RUANSILVA2018216035_H_INCLUDED
