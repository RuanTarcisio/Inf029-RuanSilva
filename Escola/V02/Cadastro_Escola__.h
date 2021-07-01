#ifndef _CADASTRO_ESCOLA_H__
#define _CADASTRO_ESCOLA_H__

#define TAM_NASC 11
#define MAX_NAME 50
#define MATRICULA_ALUN 20211001
#define MATRICULA_PROF 2021101
#define ALUN 1
#define PROF 2
#define MATE 3

typedef struct
{
    int dia;
    int mes;
    int ano;
} date;

typedef struct
{
    char nome[MAX_NAME];
    char cpf[TAM_NASC+4];
    char nascimento[TAM_NASC+3];
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
    int qntd;
} Node;
Node* Professores;
Node* Alunos;

typedef struct
{
    int matricula;
    char cpf[TAM_NASC+4];
} _search;

void clear_keyboard_buffer(void);
/* FUNÇÕES PARA MENUS */
void inicializar();
void menuGeral();
void menuAlunos();
void menuDisciplinas();
void menuProfessores();
void menuListar();
void menuCadastro(int select);
void menuAlterar (int select);
void menuExcluir (int select);


void ArqSalvar(Node *list, int opcao);
Node* ler_Arq(int opcao);
void inserir_Arq(Node** Geral, cadastro *Pessoas);


/* FUNÇÕES PARA A LISTA ( PROFESSORES E ALUNOS ) */
Node *criar_Lista();
void Display(Node *Geral, int select);
int Push(Node **Geral, cadastro *Pessoas, int select);
int Insert(Node **Geral, int select);
void Pop(Node **Geral);
int Remove(Node **Geral, _search *dado, int opcao);
int Sort(Node **Geral);
int Atualizar(Node **Geral, _search *dado, int opcao);  /*MUDAR PARA INT, PARA CONFIRMAÇÕES. */
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
int validarCodigo(char *codigo);
int validarCPF(char *cpf);
int validarNome(char *nome);
int validarSexo(char *sexo);
void _Aniversario(char *data, date *Anv);
#endif
