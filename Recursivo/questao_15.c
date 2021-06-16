#include <stdio.h>
#include <stdlib.h>

void decrescente(int n);

int main(void){

    int n;

    printf("Informe um número:");
    scanf("%d", &n);

    decrescente(n);

    return 0;
}

void decrescente(int n){

    if(n >= 0){

    	if(n % 2 == 0)
    		printf("%d ", n);

    	decrescente(n - 1);

    }

}

