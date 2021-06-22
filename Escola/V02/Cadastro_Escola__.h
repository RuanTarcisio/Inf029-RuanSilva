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
    char cpf[TAM_NASC+6];
    char nascimento[TAM_NASC+5];
    char sexo;
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




/* FUNÇÕES PARA MENUS */
void inicializar();
void menuGeral();
void menuAlunos();
void menuDisciplinas();
void menuProfessores();
void menuCadastro(int select);
void menuAlterar (int select);
void menuExcluir (int select);

/* FUNÇÕES PARA A LISTA ( PROFESSORES E ALUNOS ) */
Node *criar_Lista();
void Display(Node *Geral, int select);
int Push(Node **Geral, cadastro *Pessoas, int select);
int Insert(Node **Geral, int select);
void Pop(Node **Geral);
int Remove(Node **Geral, int select);
int Sort(Node **Geral);
int Atualizar(Node **Geral, int select);  /*MUDAR PARA INT, PARA CONFIRMAÇÕES. */
int Buscar_Na_Lista(Node *Geral, int matricula);
Node* AtPos(Node *Geral, int select);
int CPF_NaBase(Node *Geral, char *cpf);
int isEmpty(Node *Geral);


cadastro RecebeDadosPessoais();
cadastro alt_validar(cadastro *Dados);
cadastro AlterarDadosPessoais(cadastro Dados);
cadastro validar(cadastro *Dados);
int validarData(char *data);
int validarNascimento(date *guia);
int validarCPF(char *cpf);
int validarNome(char *nome);
int validarSexo(char *sexo);
void _Aniversario(char *data, date *Anv);
#endif
