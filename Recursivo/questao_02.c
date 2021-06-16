#include<stdio.h>
#include<stdlib.h>

int recur_Fib(int num)
{
int resultado;

if (num == 0 || num == 1){
    return 1;
}
else{
resultado = recur_Fib(num-2) + recur_Fib(num-1);
printf("\n%d",resultado);
}
return resultado;
}


main(){

    int numero, fib;

    printf("Informe um numero.\n");
    scanf("%d", &numero);

    printf("numero %d no fibonacci = %d", numero, recur_Fib(numero));
}
