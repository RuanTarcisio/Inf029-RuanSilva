#ifndef _CADASTRO_ESCOLA_H__
#define _CADASTRO_ESCOLA_H__

#define TAM_NASC 11
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
    char cpf[TAM_NASC+1];
    char nascimento[TAM_NASC];
    char sexo[1];
    int matricula;
    date aniversario;
} cadastro;
cadastro Pessoas;

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

/* FUNÇÕES PARA MENUS */
void menuGeral();
void menuAlunos();
void menuDisciplinas();
void menuProfessores();
void menuCadastro(int select);

/* FUNÇÕES PARA A LISTA ( PROFESSORES E ALUNOS ) */
Node *criar_Lista();
void Display(Node *Geral, int select);
int Push(Node **Geral, cadastro *Pessoas, int select);
int Insert(Node **Geral, int select);
int Pop(Node **Geral, int select);
int Remove(Node **Geral, int select);
int Sort(Node **Geral);
void Atualizar(Node **Geral, int select);  /*MUDAR PARA INT, PARA CONFIRMAÇÕES. */
int Buscar_Na_Lista(Node *Geral);
Node* AtPos(Node *Geral);


cadastro RecebeDadosPessoais();
cadastro validar(cadastro *Dados);
int validarData(char *data);
int validarNascimento(date *guia);
int validarCPF(char *cpf);
int validarNome(char *nome);
int validarSexo(char *sexo);
void _Aniversario(char *data, date *Anv);
#endif
