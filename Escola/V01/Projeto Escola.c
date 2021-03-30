#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define MAX_ALUN 100
#define MAX_PROF 50
#define MAX_MATE 50
#define NAME_NOMES 30
#define MATRICULA_ALUN 20211000
#define MATRICULA_PROF 2021100

/*:
•	Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF e TIPO SANGUINEO) .
•	Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF e TIPO SANGUINEO).
•	Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
*/



typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    char nome[NAME_NOMES];
    int matricula;
    int cpf;
    int confirma;
    char nascimento[11];
    char sexo;
    char TSangue[3];
    data recebe;
    int ndx;
} cadastro;

typedef struct
{
    char nome[NAME_NOMES];
    char codigo[6];
    int semestre;
    char professor[NAME_NOMES];
    int ndx;
} disciplinas;


main()
{
    setlocale( LC_ALL, "" );
    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);

    disciplinas materias[MAX_MATE];
    cadastro professor[MAX_PROF], aluno[MAX_ALUN];
    aluno[0].ndx = 0;
    aluno[0].matricula = MATRICULA_ALUN;
    professor[0].ndx = 0;
    professor[0].matricula = MATRICULA_PROF;
    materias[0].ndx = 0;



    RegistroGeral(aluno, professor, materias);

}


void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia)
{

    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Discente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Docente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Disciplina(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);

    int escolha;

    printf("\n\n       *********************** PROJETO ESCOLA ***********************\n\n");
    printf("\nDigite: (1)- Alunos, (2)- Professores, (3)- Disciplinas ou (0)- p/ SAIR:  ");
    scanf("%d", &escolha);

    switch(escolha)
    {
    case 0:
        printf("\nEncerrando o programa.");
        exit(0);
    case 1:
        Discente(Aluno, Professor, Materia);
        break;
    case 2:
        Docente(Aluno, Professor, Materia);
        break;
    case 3:
        Disciplina(Aluno, Professor, Materia);
        break;
    default:
        system("cls");
        RegistroGeral(Aluno, Professor, Materia);
    }
}


void Discente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia)
{

    void Discente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void cadastrar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void listar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void excluir(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);

    int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE ALUNOS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  \n");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Aluno, Professor, Materia, 1);
        break;
    case 2:
        listar(Aluno, Professor, Materia, 1);
        break;
    case 3:
        break;
    case 9:
        RegistroGeral(Aluno, Professor, Materia);
    default:
        Discente(Aluno, Professor, Materia);
        break;
    }
}


void Docente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia)
{

    void Docente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void cadastrar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void listar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void excluir(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);

    int escolha;

    system("cls");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-* CADASTRO DE PROFESSORES *-*-*-*-*-*-*-*-*-*-*-*-*-* \n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  \n");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Aluno, Professor, Materia, 2);
        break;
    case 2:
        listar(Aluno, Professor, Materia, 2);
        break;
    case 3:
        break;
    case 9:
        RegistroGeral(Aluno, Professor, Materia);
        break;
    default:
        Docente(Aluno, Professor, Materia);
        break;
    }
}


void Disciplina(cadastro *Aluno, cadastro *Professor, disciplinas *Materia)
{

    void cadastrar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void Disciplina(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void listar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void excluirMateria(disciplinas *Materia);

    int escolha;

    system("cls");
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*- CADASTRO DE MATERIAS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
    printf("\nEscolha: (1)- p/ cadastrar, (2)- p/ listar, (3)- p/ excluir, (9)- voltar ou (0)- p/sair.  ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastrar(Aluno, Professor, Materia, 3);
        break;
    case 2:
        listar(Aluno, Professor, Materia, 3);
        break;
    case 9:
        RegistroGeral(Aluno, Professor, Materia);
    default:
        Disciplina(Aluno, Professor, Materia);
        break;
    }
}


void cadastrar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x)
{

    void cadastrar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x);
    void RegistroGeral (cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Discente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Docente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void validarDisciplina(disciplinas *Materia, int ndxGuia, int x);
    void validarNome(cadastro *cliente, int ndxGuia);
    void validarMatricula(cadastro *cliente, int ndxGuia);
    void validarCPF(cadastro *cliente, int ndxGuia);
    void validarSexo_Sangue(cadastro *cliente, int ndxGuia);
    void quebraDataNasc(cadastro *cliente, int ndxGuia);

    int ndxGuia;
    char confirma, continua;


    if(x == 1)
    {
        ndxGuia = Aluno[0].ndx;
        do
        {
            validarMatricula(Aluno, ndxGuia);

            printf("\nNome do aluno:  ");
            gets(Aluno[ndxGuia].nome);
            validarNome(Aluno, ndxGuia);

            printf("\nInforme a data de nascimento dd/mm/aaaa:  ");
            gets(Aluno[ndxGuia].nascimento);
            quebraDataNasc(Aluno, ndxGuia);

            printf("\nInforme o CPF:  ");
            scanf("%d", &Aluno[ndxGuia].cpf);
            validarCPF(Aluno, ndxGuia);

            validarSexo_Sangue(Aluno, ndxGuia);

            do
            {
                system("cls");
                printf("\nMATRICULA:  %d", Aluno[ndxGuia].matricula);
                printf("\nNOME: %s", Aluno[ndxGuia].nome);
                printf("\nDATA DE NASCIMENTO: %s", Aluno[ndxGuia].nascimento);
                printf("\nCPF: %d", Aluno[ndxGuia].cpf);
                printf("\nSEXO: %c", Aluno[ndxGuia].sexo);
                printf("\n\nCONFIRMA OS DADOS? (S)- SIM, (N)- NÃO:   ");
                scanf("%c", &confirma);
                confirma = toupper(confirma);
            }
            while(confirma != 'S' && confirma != 'N');

            if(confirma == 'N')
            {
                setbuf(stdin, NULL);
                printf("\nInforme os dados novamente. \n");
                cadastrar(Aluno, Professor, Materia, 1);
            }

            else if(confirma == 'S')
            {
                ndxGuia++;
                Professor[0].ndx++;
            }

            do
            {
                setbuf(stdin, NULL);
                printf("\nDeseja cadastrar outro aluno?(S)- SIM ou (N)- NÃO:  ");
                scanf("%c", &continua);
                continua = toupper(continua);
                setbuf(stdin, NULL);
            }
            while(continua != 'S' && continua != 'N');

        }
        while(continua == 'S' && ndxGuia < MAX_ALUN);

        continua = -1;

        if(continua == -1)
        {

            do
            {
                setbuf(stdin, NULL);
                printf("\n Digite (1)- menu anterior, (2)- menu inicial ou (0)- p/ Sair: ");
                scanf("%c", &continua);
            }
            while(continua != '1' && continua != '2' && continua != '0');


            switch(continua)
            {
            case '1':
                Discente(Aluno, Professor, Materia);
                break;
            case '2':
                RegistroGeral(Aluno, Professor, Materia);
                break;
            case '0':
                printf("\n Encerrando o programa.\n");
                exit(0);
                break;
            }
        }
    }

    else if(x == 2)
    {
        ndxGuia=Professor[0].ndx;
        do
        {
            validarMatricula(Professor, ndxGuia);

            printf("\nNome do professor:  ");
            gets(Professor[ndxGuia].nome);
            validarNome(Professor, ndxGuia);

            printf("\nInforme a data de nascimento dd/mm/aaaa:  ");
            gets(Professor[ndxGuia].nascimento);
            quebraDataNasc(Professor, ndxGuia);

            printf("\nInforme o CPF:  ");
            scanf("%d", &Professor[ndxGuia].cpf);
            validarCPF(Professor, ndxGuia);

            validarSexo_Sangue(Professor, ndxGuia);

            do
            {
                system("cls");
                printf("\nMATRICULA:  %d", Professor[ndxGuia].matricula);
                printf("\nNOME: %s", Professor[ndxGuia].nome);
                printf("\nDATA DE NASCIMENTO: %s", Professor[ndxGuia].nascimento);
                printf("\nCPF: %d", Professor[ndxGuia].cpf);
                printf("\nSEXO: %c", Professor[ndxGuia].sexo);
                printf("\n\nCONFIRMA OS DADOS? (S)- SIM, (N)- NÃO:   ");
                scanf("%c", &confirma);
                confirma = toupper(confirma);
            }
            while(confirma != 'S' && confirma != 'N');

            if(confirma == 'N')
            {
                setbuf(stdin, NULL);
                printf("\nInforme os dados novamente. \n");
                cadastrar(Aluno, Professor, Materia, 2);
            }

            else if(confirma == 'S')
            {
                ndxGuia++;
                Professor[0].ndx++;
            }

            do
            {
                setbuf(stdin, NULL);
                printf("\nDeseja cadastrar outro professor?(S)- SIM ou (N)- NÃO:  ");
                scanf("%c", &continua);
                continua = toupper(continua);
                setbuf(stdin, NULL);
            }
            while(continua != 'S' && continua != 'N');

        }
        while(continua == 'S' && ndxGuia < MAX_PROF);

        continua = -1;

        if(continua == -1)
        {

            do
            {
                setbuf(stdin, NULL);
                printf("\n Digite (1)- menu anterior, (2)- menu inicial ou (0)- p/ Sair: ");
                scanf("%c", &continua);
            }
            while(continua != '1' && continua != '2' && continua != '0');

            switch(continua)
            {
            case '1':
                Docente(Aluno, Professor, Materia);
                break;
            case '2':
                RegistroGeral(Aluno, Professor, Materia);
                break;
            case '0':
                printf("\n Encerrando o programa.\n");
                exit(0);
                break;
            }
        }
    }

    else if( x == 3 )
    {
        ndxGuia = Materia[0].ndx;
        do
        {
            setbuf(stdin, NULL);
            printf("\n\nNome da materia:\n");
            gets(Materia[ndxGuia].nome);
            validarDisciplina(Materia, ndxGuia, 1);

            printf("\nCodigo da Materia: \n");
            gets(Materia[ndxGuia].codigo);
            validarDisciplina(Materia, ndxGuia, 2);
            setbuf(stdin, NULL);

            printf("\nInforme o semestre da matéria: \n");
            scanf("%d", &Materia[ndxGuia].semestre);
            setbuf(stdin, NULL);

            setbuf(stdin, NULL);
            printf("\nInforme o nome do professor: \n");
            gets(Materia[ndxGuia].professor);
            validarDisciplina(Materia, ndxGuia, 3);

            ndxGuia++;
            Materia[0].ndx++;

            do
            {
                setbuf(stdin, NULL);
                printf("\nDeseja cadastrar outra materia?(1)- SIM ou (0)- NÃO.\n");
                scanf("%c", &continua);
                setbuf(stdin, NULL);
            }
            while(continua != '1' && continua != '0');
        }
        while(continua == 1 && ndxGuia < MAX_PROF);
    }
}


void listar(cadastro *Aluno, cadastro *Professor, disciplinas *Materia, int x)
{

    void RegistroGeral(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Discente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);
    void Docente(cadastro *Aluno, cadastro *Professor, disciplinas *Materia);


    int escolha, ndx=0;
    

    if( x == 1 )
    {
        setbuf(stdin, NULL);
        printf("\n\n                  *-*-*-*-*-*-*LISTAR ALUNOS*-*-*-*-*-*-* \n\n\nEscolha: (1)- p/ matricula, (2)- p/ nome, (8) p/ menu anterior, (9)- p/ menu inicial ou (0)- p/ sair.\n\n");
        scanf("%d", &escolha);

        if(escolha != 1 && escolha != 2 && escolha != 8 && escolha != 9 && escolha != 0)
        {
            do
            {
                getchar();
                printf("\nOpção invalida. (1)- p/ matricula, (2)- p/ nome, (8) p/ menu anterior, (9)- p/ menu inicial ou (0)- p/ sair.\n");
                scanf("%d", &escolha);
            }
            while(escolha != 1 && escolha != 2 && escolha != 8 && escolha != 9 && escolha != 0);
        }

        switch(escolha)
        {
        case 1:
            if(Aluno[0].ndx > 0)
            {
                do
                {
                    printf("\n%d\n", Aluno[ndx].matricula);
                    ndx++;
                }
                while(ndx < Aluno[0].ndx);
            }
            else
            {
                if(Aluno[0].matricula == MATRICULA_ALUN)
                {
                    printf("\nNão há alunos matriculados. \n");
                }
                else
                {
                    printf("\n%d\n", Aluno[0].matricula);
                }
            }
            break;
        case 2:
            break;
        case 8:
            Discente(Aluno, Professor, Materia);
            /*chamar menu anterior*/
            break;
        case 9:
            RegistroGeral(Aluno, Professor, Materia);
            break;
        case 0:
            printf("\nEncerrando o programa.\n");
            exit(0);
        }

    }

    else if ( x == 2 )
    {
        setbuf(stdin, NULL);
        printf("\n\n             *-*-*-*-*-*-* LISTAR PROFESSORES *-*-*-*-*-*-* \n\n\nEscolha: (1)- p/ matricula, (2)- p/ nome, (8) p/ menu anterior, (9)- p/ menu inicial ou (0)- p/ sair. \n\n");
        scanf("%d", &escolha);

        if(escolha != 1 && escolha != 2 && escolha != 8 && escolha != 9 && escolha != 0)
        {
            do
            {
                getchar();
                printf("\nOpção invalida. (1)- p/ matricula, (2)- p/ nome, (8) p/ menu anterior, (9)- p/ menu inicial ou (0)- p/ sair.\n\n");
                scanf("%d", &escolha);
            }
            while(escolha != 1 && escolha != 2 && escolha != 8 && escolha != 9 && escolha != 0);
        }

        switch(escolha)
        {
        case 1:
            if(Professor[0].ndx > 0)
            {
                do
                {
                    printf("\n%d\n", Professor[ndx].matricula);
                    ndx++;

                }
                while(ndx < Professor[0].ndx);
            }
            else
            {
                if(Professor[0].matricula == MATRICULA_PROF)
                {
                    printf("\nNão há professores matriculados. \n");
                }
                else
                {
                    printf("\n%d\n", Professor[0].matricula);
                }
            }
            break;
        case 2:
            break;
        case 8:
            Docente(Aluno, Professor, Materia);
            /*chamar menu anterior*/
            break;
        case 9:
            RegistroGeral(Aluno, Professor, Materia);
            /*chamar menu inicial*/
            break;
        case 0:
            printf("\nEncerrando o programa.\n");
            exit(0);
        }

    }
}


void validarNome(cadastro *cliente, int ndxGuia)
{
    void validarNome(cadastro *cliente, int ndxGuia);
    int ndx=0;

    ndx = strlen(cliente[ndxGuia].nome);

    if(ndx <= 2 || ndx > 20)
    {
        printf("\nUltrapassou o limite de 20 caracteres ou tem apenas 2 letras.\n");
        printf("Informe o nome:\n");
        gets(cliente[ndxGuia].nome);
        validarNome(cliente, ndxGuia);
    }

    else
    {
        ndx=0;
        do
        {
            if(cliente[ndxGuia].nome[ndx] >= 97 && cliente[ndxGuia].nome[ndx] <= 122 || (cliente[ndxGuia].nome[ndx] >= 65 && cliente[ndxGuia].nome[ndx] <= 90)
                    || (cliente[ndxGuia].nome[ndx] == ' ' && cliente[ndxGuia].nome[ndx+1] != ' '))
            {
                ndx++;
            }

            else
            {
                printf("\n\nNome apresenta acento ou algum caractere especial.");
                printf("\nInforme o nome sem acento.\n");
                gets(cliente[ndxGuia].nome);
                validarNome(cliente, ndxGuia);
            }

        }
        while(ndx < strlen(cliente[ndxGuia].nome));
    }

    ndx=0;
    
    do
    {
        cliente[ndxGuia].nome[ndx] = toupper(cliente[ndxGuia].nome[ndx]);
        ndx++;
    }
    while(ndx < strlen(cliente[ndxGuia].nome));
}


void validarMatricula(cadastro *cliente, int ndxGuia)
{
    if(ndxGuia < 1)
    {
        cliente[ndxGuia].matricula= MATRICULA_PROF+1;
    }
    else if(ndxGuia >= 1)
    {
        cliente[ndxGuia].matricula= cliente[ndxGuia-1].matricula+1;
    }
}


void validarDisciplina(disciplinas *Materia, int ndxGuia, int x)
{
    void validarDisciplina(disciplinas *Materia, int ndxGuia, int x);

    int ndx;

    if( x == 1)
    {
        printf("Estou aq 1");
        ndx = strlen(Materia[ndxGuia].nome);

        if(ndx <= 5 || ndx > NAME_NOMES)
        {
            printf("\nUltrapassou o limite de 20 caracteres ou tem apenas 2 letras.\n");
            printf("Informe o nome da materia:\n");
            gets(Materia[ndxGuia].nome);
            validarDisciplina(Materia, ndxGuia, 1);
        }

        else
        {
            ndx=0;
            do
            {
                if(Materia[ndxGuia].nome[ndx] >= 97 && Materia[ndxGuia].nome[ndx] <= 122 || (Materia[ndxGuia].nome[ndx] >= 65 && Materia[ndxGuia].nome[ndx] <= 90)
                        || (Materia[ndxGuia].nome[ndx] == ' ' && Materia[ndxGuia].nome[ndx+1] != ' '))
                {
                    ndx++;
                }

                else
                {
                    printf("\n\nNome apresenta acento ou algum caractere especial.");
                    printf("\nInforme o nome sem acento.\n");
                    gets(Materia[ndxGuia].nome);
                    validarDisciplina(Materia, ndxGuia, 1);
                }

            }
            while(ndx < strlen(Materia[ndxGuia].nome));
        }

        ndx=0;

        do
        {
            Materia[ndxGuia].nome[ndx] = toupper(Materia[ndxGuia].nome[ndx]);
            ndx++;

        }
        while(ndx < strlen(Materia[ndxGuia].nome));

    }

    else if(x == 2)
    {

    }

    else if(x == 3)
    {
        printf("Estou aq 2");
        ndx = strlen(Materia[ndxGuia].professor);

        if(ndx <= 2 || ndx > 20)
        {
            printf("\nUltrapassou o limite de 20 caracteres ou tem apenas 2 letras.\n");
            printf("Informe o nome do professor:\n");
            gets(Materia[ndxGuia].professor);
            validarDisciplina(Materia, ndxGuia, 3);
        }

        else
        {
            ndx=0;
            do
            {
                if(Materia[ndxGuia].professor[ndx] >= 97 && Materia[ndxGuia].professor[ndx] <= 122 ||
                        (Materia[ndxGuia].professor[ndx] >= 65 && Materia[ndxGuia].professor[ndx] <= 90)||
                        (Materia[ndxGuia].professor[ndx] == ' ' && Materia[ndxGuia].professor[ndx+1] != ' '))
                {
                    ndx++;
                }

                else
                {

                    printf("\n\nNome apresenta acento ou algum caractere especial.");
                    printf("\nInforme o nome sem acento.\n");
                    gets(Materia[ndxGuia].professor);
                    validarDisciplina(Materia, ndxGuia, 3);
                }

            }
            while(ndx < strlen(Materia[ndxGuia].professor));
        }

        ndx=0;

        do
        {
            Materia[ndxGuia].professor[ndx] = toupper(Materia[ndxGuia].professor[ndx]);
            ndx++;

        }
        while(ndx < strlen(Materia[ndxGuia].professor));
    }
}


void validarSexo_Sangue(cadastro *cliente, int ndxGuia)
{
    int ndx=0;

    setbuf(stdin, NULL);
    printf("\nInforme o sexo, (M)- MASCULINO ou (F)- FEMININO:  ");
    scanf("%c", &cliente[ndxGuia].sexo);

    cliente[ndxGuia].sexo = toupper(cliente[ndxGuia].sexo);

    if(cliente[ndxGuia].sexo != 'M' && cliente[ndxGuia].sexo != 'F')
    {
        do
        {
            setbuf(stdin, NULL);
            printf("\nOpção invalida, informe o sexo: (F)- Feminino ou (M)- Masculino:  ");
            scanf("%c", &cliente[ndxGuia].sexo);
            cliente[ndxGuia].sexo = toupper(cliente[ndxGuia].sexo);
        }
        while(cliente[ndxGuia].sexo != 'M' && cliente[ndxGuia].sexo != 'F');
    }

    /*printf("\nInforme o tipo sanguineo.\n");
    gets(cliente->TSangue);

    do
    {
        cliente->TSangue[ndx] = toupper(cliente->TSangue[ndx]);
        ndx++;

    }
    while(ndx < 3 || cliente->TSangue[ndx] != '\0');

    if (cliente->TSangue != "A+" && cliente->TSangue != "A-" &&
        cliente->TSangue != "B+" && cliente->TSangue != "B-" &&
        cliente->TSangue != "AB+" && cliente->TSangue != "O+" &&
        cliente->TSangue != "AB-" && cliente->TSangue != "O-")
    {
            printf("estou aq");
    }*/
}


void quebraDataNasc(cadastro *cliente, int ndxGuia)
{
    typedef struct
    {
        char dia[3];
        char mes[3];
        char ano[5];
    } date;

    date recebe;

    void quebraDataNasc(cadastro *cliente, int ndxGuia);
    int validarNascimento(cadastro *cliente, int ndxGuia);
    int ndx=0, ndxV=0;
    int d=0, m=0, a=0;

    do
    {
        if(cliente[ndxGuia].nascimento[ndxV] != '/')
        {
            recebe.dia[ndx] = cliente[ndxGuia].nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            d = 0;
            break;
        }

        if(cliente[ndxGuia].nascimento[ndxV] == '/')
        {
            recebe.dia[ndx++] = '\0';
            d = 1;
            cliente[ndxGuia].recebe.dia = atoi(recebe.dia);
            break;
        }
    }
    while(cliente[ndxGuia].nascimento[ndxV] != '/');


    ndxV++;
    ndx=0;

    do
    {
        if(cliente[ndxGuia].nascimento[ndxV] != '/')
        {
            recebe.mes[ndx] = cliente[ndxGuia].nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 2)
        {
            m = 0;
            break;
        }
        if(cliente[ndxGuia].nascimento[ndxV] == '/')
        {
            recebe.mes[ndx++] = '\0';
            m = 1;
            cliente[ndxGuia].recebe.mes = atoi(recebe.mes);
            break;
        }
    }
    while(cliente[ndxGuia].nascimento[ndxV] != '/');

    ndxV++;
    ndx = 0;

    do
    {
        if(cliente[ndxGuia].nascimento[ndxV] != '\0')
        {
            recebe.ano[ndx] = cliente[ndxGuia].nascimento[ndxV];
            ndx++;
            ndxV++;
        }
        if(ndx > 4)
        {
            a = 0;
            break;
        }
        if(cliente[ndxGuia].nascimento[ndxV] == '\0' && ndx >=2)
        {
            recebe.ano[ndx] = '\0';
            a = 1;
            cliente[ndxGuia].recebe.ano = atoi(recebe.ano);
            break;
        }
    }
    while(cliente[ndxGuia].nascimento[ndxV] != '\0');

    if(d != 1 || m != 1 || a != 1)
    {
        printf("\n Data informa é invalida, informe novamente: dd/mm/aaaa.\n");
        gets(cliente[ndxGuia].nascimento);
        quebraDataNasc(cliente, ndxGuia);
    }

    else
    {
        cliente[ndxGuia].confirma = validarNascimento(cliente, ndxGuia);

        if(cliente[ndxGuia].confirma != 1)
        {
            printf("\n Data informa é invalida, informe novamente dd/mm/aaaa:  ");
            gets(cliente[ndxGuia].nascimento);
            quebraDataNasc(cliente, ndxGuia);
        }
    }
}


int validarNascimento(cadastro *cliente, int ndxGuia)
{

    int d=1, m=1, a=1;

    if((cliente[ndxGuia].recebe.ano > 99 && cliente[ndxGuia].recebe.ano < 1869) || cliente[ndxGuia].recebe.ano > 2021)
    {
        a = 0;
    }

    if(cliente[ndxGuia].recebe.dia < 1 || cliente[ndxGuia].recebe.dia > 31)
    {
        d = 0;
    }

    switch(cliente[ndxGuia].recebe.mes)
    {
    case 1:
        if(cliente[ndxGuia].recebe.dia>31)
            m = 0;
        break;
    case 2:
        if(cliente[ndxGuia].recebe.ano % 4 == 0 && (cliente[ndxGuia].recebe.ano % 400 == 0 || cliente[ndxGuia].recebe.ano % 100 != 0))
        {
            if(cliente[ndxGuia].recebe.dia > 29)

                m = 0;
            break;
        }
        if(cliente[ndxGuia].recebe.ano % 4 != 0)
        {
            if(cliente[ndxGuia].recebe.dia > 28)
            {
                m = 0;
                break;
            }
        }
    case 3:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 4:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 5:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 6:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 7:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 8:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 9:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 10:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        }
    case 11:
        if(cliente[ndxGuia].recebe.dia > 31)
        {
            m = 0;
            break;
        }
    case 12:
        if(cliente[ndxGuia].recebe.dia > 30)
        {
            m = 0;
            break;
        default:
            m = 0;
            break;
        }
    }

    if(d == 1 && m == 1 && a == 1)
    {
        return cliente[ndxGuia].confirma = 1;
    }

    else
    {
        return cliente[ndxGuia].confirma = 0;
    }
}


void validarCPF(cadastro *cliente, int ndxGuia)
{

}


