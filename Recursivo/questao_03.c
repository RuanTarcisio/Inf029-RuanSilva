#include<stdio.h>
int numero;
int aux;
int invert(int n)
{
    int resultado;

    if(n<10)
        return n;

     if(n >= 10000 && n < 100000)
    {
        resultado = ((n%10)* 10000) + ((n%100)/10)*1000 + ((n%1000)/100)*100 + ((n%10000)/1000)*10 + (n/10000);
    }
    else if(n >= 1000 && n < 10000)
    {
        resultado = ((n%10)* 1000) + ((n%100)/10)*100 + ((n%1000)/100)*10 + (n/1000);
    }
    else if(n >= 100 && n < 1000)
    {
        resultado = ((n%10)* 100) + ((n/10)%10)*10 + (n/100);
    }
    else if(n >=10 && n < 100)
    {
       resultado = (n%10)*10 + n/10;
    }

return resultado;
}
int main()
{
    int invertido;
    printf("Digite um numero:");
    scanf("%d",&numero);
    invertido = invert(numero);

    printf("\n%d", invertido);
    return 0;
}
