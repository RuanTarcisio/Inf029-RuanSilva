#include<stdio.h>

int somarVetor(int num[])
{
    int ndx = 0, resultado, n=4;

    if(n < 0)
        resultado = 0;
   /* do
    {
        resultado += num[ndx];
        ndx++;

    }while (num[ndx] != '\0');*/

    resultado = num[n] + somarVetor(num[n-1]);



    return resultado;
}

main()
{
    int num[5];
    int soma = 0;

    for(int i = 0; i < 5; i++)
    {
        printf("Informe um nmro. ");
        scanf("%d", &num[i]);
    }

    soma = somarVetor(num);

    printf("\n soma = %d", soma);
}
