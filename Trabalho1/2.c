#include <stdio.h>
#include <string.h>

void bubble_sort(int* vetor, int n)
{
    int aux;
    for (int k = 1; k < n; k++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int veto2r[] = {4,2,7,3,0};
    // int veto2r[] = {4,2,7,3,0,4,3,2,8,46,2,13,664,24,1,0,6,42,1,4342,75,865,2,1,24,6,9,77,53,3467,21,36,2,86,223,987,111,4,1,2,3,4,5,6,7,8,999,7,8,8,9,9,6,2};

    printf("{");
    for (int i = 0; i < sizeof(veto2r) / sizeof(int); i++)
    {
        printf("%d, ", veto2r[i]);
    }
    printf("\b\b}\n");

    bubble_sort(&veto2r, sizeof(veto2r) / sizeof(int));

    printf("{");
    for (int i = 0; i < sizeof(veto2r) / sizeof(int); i++)
    {
        printf("%d, ", veto2r[i]);
    }
    printf("\b\b}\n");

    return 0;
}
