#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"
#include <locale.h>



int main()
{
    setlocale( LC_ALL, "" );

    inicializar();
    /*menuGeral();*/

    _cadastro teste;
    cadastro teste1;

    strcpy(teste.codigo, "INF001");
    strcpy(teste.nome, "Laboratorio");
    teste.semestre = 2;
    teste.Discente = NULL;


    teste1.matricula=20211001;
    strcpy(teste1.nome, "Ruan Tarcisio");
    strcpy(teste1.cpf, "10399976515");
    teste1.sexo = 'M';
    strcpy(teste1.nascimento, "06/04/94");

    Push(&teste.Discente, &teste1, 1);
    _Push(&Materias, &teste);

    _Display(Materias);
    Display(teste.Discente, 1);

    strcpy(teste.codigo, "INF028");
    strcpy(teste.nome, "Arquitetura");
    teste.semestre = 2;

    _Push(&Materias, &teste);

    _Display(Materias);
    Display(teste.Discente, 1);

    /*
    strcpy(teste.codigo, "HUM005");
    strcpy(teste.nome, "Sociologia");
    teste.semestre = 2;

    _Push(&Materias, &teste);

    strcpy(teste.codigo, "HUM002");
    strcpy(teste.nome, "Filosofia");
    teste.semestre = 2;

    _Push(&Materias, &teste);

    _Display(Materias);*/



return 1;
}
