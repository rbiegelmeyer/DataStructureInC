#include <stdio.h>
#include <string.h>


// Exemplo Bublue Sort
// 
void bubble_sort(int vetor[], int n)
{
    int aux;

    for (int k = 1; k < n; k++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void quicksort(int values[], int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end - 1;
    pivo = values[(began + end) / 2];
    printf("Pivo: %d\n", pivo);
    while (i <= j)
    {
        while (values[i] < pivo && i < end)
        {
            i++;
        }
        while (values[j] > pivo && j > began)
        {
            j--;
        }
        if (i <= j)
        {
            printf("T: values[%d] = %d por values[%d] = %d\n", i, values[i], j, values[j]);
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;

            // printf("\n");
            // for (int k = 0; k < sizeof(values) / sizeof(int); k++)
            // {
            //     printf("%d, ", values[k]);
            // }
            // printf("\n");
        }
    }
    if (j > began)
        quicksort(values, began, j + 1);
    if (i < end)
        quicksort(values, i, end);
}

int main(int argc, char const *argv[])
{
    int veto2r[] = {1, 2, 4, 3, 5, 43, 5, 2, 11, 55, 8, 221, 9, 1, 2, 5, 98, 23, 123, 99999, 6, 9};
    // bubble_sort(veto2r, sizeof(veto2r) / sizeof(int));
    quicksort(veto2r, 0, sizeof(veto2r) / sizeof(int));

    printf("\n");
    for (int i = 0; i < sizeof(veto2r) / sizeof(int); i++)
    {
        printf("%d, ", veto2r[i]);
    }
    printf("\n");

    return 0;
}
