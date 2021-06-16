#include <stdio.h>



int somatorio(int n)
{
    int soma;

    if (n == 0)
    {
        soma = 0;
    }
    else
    {
    soma = n + somatorio(n-1);
    }

    return soma;
}


main()
{
 int valor = 5, resultado;

 resultado = somatorio(40000);

 printf("\n%d ", resultado);
}
