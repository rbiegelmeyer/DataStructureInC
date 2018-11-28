#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v = NULL;
    int n;
    printf("Tamanho do vetor n: ");
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    if (v == NULL)
    {
        exit(1);
    }
    else
    {
        free(v);
        v = NULL;
    }
}
