#include <stdio.h>

int main(int argc, char const *argv[])
{
    float vetor[5];

    printf("\n");
    for (int i = 0; i < sizeof(vetor) / sizeof(float); i++)
    {
        printf("Digite o %d o valor : ", i + 1);
        scanf("%f", &vetor[i]);
    }

    float sum = 0;
    for (int i = 0; i < sizeof(vetor) / sizeof(float); i++)
    {
        sum += vetor[i];
    }
    printf("A soma dos elementos e: %.2f", sum);

    return 0;
}
