#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 3

void tabuleiro(char campo[TAM][TAM])
{
    system("cls");
    setbuf(stdin, NULL);
    printf("\t %c | %c | %c \n", campo[0][0], campo[0][1], campo[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", campo[1][0], campo[1][1], campo[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", campo[2][0], campo[2][1], campo[2][2]);
}

main()
{
    char confirmacao;
    int jogadas, posX, posY, i, j;
    int player = 0;
    char casas[TAM][TAM] = { {' ',' ',' '},
                         {' ',' ',' '},
                         {' ',' ',' '},
    };

    //tabuleiro(casas);


        jogadas = 1;
        for(i=0;i<TAM-1;i++){
            for(j=0;j<TAM-1;j++){
                casas[i][j] = ' ';
            }
        }
        do
        {
            tabuleiro(casas);
            if(player %2 == 0)
            {
                printf(" Jogador X\n");
            }
            else
            {
                printf(" Jogador O\n");
            }

            printf("Informe a Linha.\n");
            scanf("%d", &posX);
            printf("Informe a Coluna.\n");
            scanf("%d", &posY);
            if(posX < 1 || posY < 1 || posX > 3 || posY>3)
            {
                posX = 0;
                posY = 0;
            }
            else if(casas[posX-1][posY-1] != ' ')
            {
                posX = 0;
                posY = 0;
            }
            else
            {
                if(player % 2 == 0)
                {
                    casas[posX-1][posY-1] = 'X';
                    jogadas++;
                }
                else
                {
                    casas[posX-1][posY-1] = 'O';
                    jogadas++;
                }
                player++;
            }

        if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){jogadas = 11;}
        if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){jogadas = 11;}
        if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){jogadas = 11;}
        if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){jogadas = 11;}
        if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){jogadas = 11;}
        if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){jogadas = 11;}
        if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){jogadas = 11;}
        if(casas[0][3] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){jogadas = 11;}

        if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){jogadas = 12;}
        if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){jogadas = 12;}
        if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){jogadas = 12;}
        if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){jogadas = 12;}
        if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){jogadas = 12;}
        if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){jogadas = 12;}
        if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){jogadas = 12;}
        if(casas[0][3] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){jogadas = 12;}

        }while(jogadas <= 9);
        tabuleiro(casas);
        if(jogadas==10){
            printf("Empate, Try Again\n");
        }
        else if(jogadas==11){
            printf("Jogador 'X' venceu. Parabens!\n");
        }
        else if(jogadas==12){
            printf("Jogador 'O' venceu. Parabens!\n");
        }

}
