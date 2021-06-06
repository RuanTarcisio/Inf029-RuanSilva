#ifndef _CADASTRO_ESCOLA_H__
#define _CADASTRO_ESCOLA_H__

#define TAM_NASC 10
#define MAX_NAME 50
#define MATRICULA_ALUN 20211000
#define MATRICULA_PROF 2021100

typedef struct
{
    int dia;
    int mes;
    int ano;
} date;

typedef struct
{
    char nome[MAX_NAME];
    char cpf[12];
    char nascimento[11];
    char sexo;
    date D_M_A;
    /*int confirma;
    char TSangue[3];
    data recebe;
    int ndx;
    data date;*/
} cadastro;

typedef struct Lista
{
    int matricula;
    cadastro dados;
    struct Lista *prox;
    int tamanho;
    int posicao;
} Node;


typedef struct
{
    char nome[MAX_NAME];
    int semestre;
    char professor[MAX_NAME];
    char area[3];
    int ndx;
} disciplinas;

typedef struct Lista_Mat
{
    disciplinas materias;
    struct Lista_Mat *prox;
    int tamanho;
    int posicao;
} Node_Mat;



Node *criar_Lista();


void menuGeral();
void menuAlunos();
void menuDisciplinas();
void menuProfessores();


void Display(Node *Geral);
int Push(Node **Geral, cadastro *Pessoas);
int Insert(Node **Geral, int select);  /* NA FUNÇÂO DETERMINAR COMO QUER INSERIR, P/ POSIÇÃO, P/ NOME, MATRICULA... etc */
int Pop(Node **Geral, int select);
int Remove(Node **Geral, int select); /* NA FUNÇÂO DETERMINAR COMO QUER EXCLUIR, P/ POSIÇÃO, P/ NOME, MATRICULA... etc */
int Sort(Node **Geral);

cadastro RecebeDadosPessoais();
cadastro validar(cadastro *Dados);

#endif
