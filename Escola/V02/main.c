#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "Cadastro_Escola__.h"
#include <locale.h>



int main()
{
    setlocale( LC_ALL, "" );

    Professores = criar_Lista();
    Alunos = criar_Lista();
    menuGeral();


return 1;
}
