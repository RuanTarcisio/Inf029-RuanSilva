#ifndef CADASTRO_ESCOLA_DISCIPLINAS_H_INCLUDED
#define CADASTRO_ESCOLA_DISCIPLINAS_H_INCLUDED

#include "Cadastro_Escola__.h"

typedef struct
{
    char nome[MAX_NAME];
    cadastro Professor;
    char codigo[7];
    int semestre;
} _cadastro;


typedef struct List
{
    _cadastro _dados;
    struct List *prox;
    int tamanho;
    int posicao;
} _Node;

void _Display(_Node *Geral);

int Buscar_Disciplina(_Node* Geral , char *codigo);
int _isEmpty(_Node *Geral);

#endif // CADASTRO_ESCOLA_DISCIPLINAS_H_INCLUDED
