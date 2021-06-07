#ifndef _CADASTRO_ESCOLA_H__
#define _CADASTRO_ESCOLA_H__

#define TAM_NASC 10
#define MAX_NAME 50
#define MATRICULA_ALUN 20211001
#define MATRICULA_PROF 2021101

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
    int matricula;
    /*date D_M_A;*/
} cadastro;

typedef struct Lista
{
    cadastro dados;
    struct Lista *prox;
    int tamanho;
    int posicao;
} Node;
Node* Professores;
Node* Alunos;


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
void menuCadastro();


void Display(Node *Geral, int opcao);
int Push(Node **Geral, cadastro *Pessoas, int opcao);
int Insert(Node **Geral, int select);
int Pop(Node **Geral, int select);
int Remove(Node **Geral, int select);
int Sort(Node **Geral);

cadastro RecebeDadosPessoais();
cadastro validar(cadastro *Dados);

#endif
