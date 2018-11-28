#include <stdio.h>

int quadrado(int x, int *y)
{

    *y = x * x;
    return 0;
}

int main()
{

    int x, y;

    printf("Programa que calcula o quadrado de x. Digite o valor para x: ");
    scanf("%d", &x);

    quadrado(x, &y);

    printf("y = %d\n", y);
}
