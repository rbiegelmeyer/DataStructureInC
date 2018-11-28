#include <stdio.h>

float tensao(int r, int i)
{
    return r * i;
}

main(int argc, char const *argv[])
{

    //Exercicio 1
    int r;
    float v,i;

    printf("\nDigite um valor de resistencia: ");
    scanf("%d", &r);
    printf("Digite um valor de corrente:2 ");
    scanf("%f", &i);


    printf("Tensao = %.2f\n", tensao(r,i));

    //Exercicio 2
    float n1,n2,n3;




    return 0;
}
