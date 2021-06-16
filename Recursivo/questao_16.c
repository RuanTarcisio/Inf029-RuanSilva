#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(void){

    int n;

    printf("Informe um número");
    scanf("%d", &n);

    printf("%d!! = %d", n, fatorial(n));

    return 0;
}

int fatorial(int n){

    if(n == 1)
        return 1;

    if(n % 2 != 0)
        return n * fatorial(n - 1);

    return fatorial(n - 1);
}

