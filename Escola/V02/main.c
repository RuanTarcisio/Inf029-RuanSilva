#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"


int main()
{
    setlocale( LC_ALL, "" );

    inicializar();
    menuGeral();
/*
    cadastro teste;

    strcpy(teste.nome, "Laboratorio");
    strcpy(teste.cpf, "01421503557");
    teste.sexo = 'M';
    strcpy(teste.nascimento, "01/02/2002");
    Push(&Alunos, &teste, 1);


    strcpy(teste.nome, "Raquel Catarina Carolina Viana");
    strcpy(teste.cpf, "01421501503");
    teste.sexo = 'M';
    strcpy(teste.nascimento, "01/02/2007");
    Push(&Alunos, &teste, 1);

      strcpy(teste.nome, "Jaqueline Carolina Martins");
    strcpy(teste.cpf, "10399976515");
    teste.sexo = 'M';
    strcpy(teste.nascimento, "01/02/2009");
    Push(&Alunos, &teste, 1);

    strcpy(teste.nome, "Severino Raul Fogaça");
    strcpy(teste.cpf, "23512350968");
    teste.sexo = 'F';
    strcpy(teste.nascimento, "11/02/2002");
    Push(&Alunos, &teste, 1);


    Display(Alunos, 1);
    getch();
    Remove(&Alunos, 1);
    Display(Alunos, 1);
    getch();
    Remove(&Alunos, 1);
    Display(Alunos, 1);
    getch();
        Remove(&Alunos, 1);
    Display(Alunos, 1);
    getch();
        Remove(&Alunos, 1);
    Display(Alunos, 1);


    strcpy(teste.nome, "Jaqueline Carolina Martins");
    strcpy(teste.cpf, "29743122419");
    teste.sexo = 'M';
    strcpy(teste.nascimento, "01/02/2009");
    Push(&Alunos, &teste, 1);

    strcpy(teste.nome, "Severino Raul Fogaça");
    strcpy(teste.cpf, "23512350968");
    teste.sexo = 'M';
    strcpy(teste.nascimento, "11/02/2002");
    Push(&Alunos, &teste, 1);

    Display(Alunos, 1);
    getch();
    Remove(&Alunos, 1);
    Display(Alunos, 1);
    getch();
    Remove(&Alunos, 1);
    Display(Alunos, 1);*/

    /*Materias->Discente->dados.matricula = 20211003;
    strcpy(Materias->Discente->dados.nome, "Ruan Carlos");
    strcpy(Materias->Discente->dados.cpf, "01421503557");
    Materias->Discente->dados.sexo = 'M';
    strcpy(Materias->Discente->dados.nascimento, "06/04/94");




    _Display(Materias);

    strcpy(teste.codigo, "INF028");
    strcpy(teste.nome, "Arquitetura");
    teste.semestre = 2;


    _Push(&Materias, &teste);

    /*_Display(Materias);
    Display(teste.Discente, 1);


    strcpy(teste.codigo, "HUM005");
    strcpy(teste.nome, "Sociologia");
    teste.semestre = 2;


    _Push(&Materias, &teste);

    strcpy(teste.codigo, "HUM002");
    strcpy(teste.nome, "Filosofia");
    teste.semestre = 2;


    _Push(&Materias, &teste);

    _Display(Materias);
*/


return 1;
}
