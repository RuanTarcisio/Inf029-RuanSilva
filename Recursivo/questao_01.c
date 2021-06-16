#include<stdio.h>
#include<stdlib.h>

main(){
int resultado, numero;
int fatorial(int x);

printf("INFORME UM NUMERO INTEIRO POSITIVO.\n");
scanf("%i", &numero);
    if(numero < 1){
        while(numero <= 0){
            printf("Informe um numero inteiro positivo.\n");
            scanf("%i", &numero);
        }
    }
    printf("\nO fatorial de %d eh : %d\n", numero, fatorial(numero));
}

int fatorial(int x){
    int result;

printf("\n");
    if(x == 0){
        result = 1;
    } else {
        result = x + fatorial(x - 1);
        printf("%d\n", result);
        }

        return result;

}


