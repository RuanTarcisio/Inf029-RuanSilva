#ifndef _CADASTRO_ESCOLA_DISCIPLINAS_H__
#define _CADASTRO_ESCOLA_DISCIPLINAS_H__

#include "Cadastro_Escola__.h"

typedef struct
{
    char nome[MAX_NAME];
    Node *Docente;
    Node *Discente;
    char codigo[7];
    int semestre;
} _cadastro;
_cadastro _Disciplina;


typedef struct List
{
    _cadastro _dados;
    struct List *prox;
    int tamanho;
    int posicao;
} _Node;
_Node* Materias;


_Node* _criar_Lista();
int _Push(_Node** Geral, _cadastro *Materias);
int _Remove(_Node **Geral);
int _Atualizar(_Node **Geral);
void _Display(_Node *Geral);

int Buscar_Disciplina(_Node* Geral , char *codigo);
int _isEmpty(_Node *Geral);



_cadastro RecebeDados_Materia();
_cadastro AlteraDados_Materia(_cadastro Dados);
_cadastro _Validar(_cadastro *_Materia);

#endif // CADASTRO_ESCOLA_DISCIPLINAS_H_INCLUDED
