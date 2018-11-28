#include <stdio.h>
#include <string.h>

#define SPACING 20

struct filme
{
    char nome[100];
    char genero[30];
    int classificacao;
};

void quicksort(struct filme *filmes_temp, int began, int end)
{
    struct filme aux;
    int i = began;
    int j = end - 1;
    
    // int pivo = (filmes_temp + ((began + end) / 2))->classificacao;
    int pivo = (filmes_temp[(began + end) / 2]).classificacao;

    while (i <= j)
    {
        while (filmes_temp[i].classificacao < pivo && i < end)
        {
            i++;
        }
        while (filmes_temp[j].classificacao > pivo && j > began)
        {
            j--;
        }
        if (i <= j)
        {
            aux = filmes_temp[i];
            filmes_temp[i] = filmes_temp[j];
            filmes_temp[j] = aux;
            i++;
            j--;
        }
    }
    if (j > began)
        quicksort(filmes_temp, began, j + 1);
    if (i < end)
        quicksort(filmes_temp, i, end);
}

int main(int argc, char const *argv[])
{
    struct filme filmes[] = {
        {"ddd", "Ficcao", 16},
        {"fdfd", "Ficcao", 12},
        {"Roberto", "Terror", 18},
        {"Adriele", "Romantico", 14},
        {"Sdsf", "Ficcao", 18}};

    // Print pre ordenacao
    printf("Lista de filmes:\n");
    printf("Nome                Genero              Classificacao\n");
    for (int i = 0; i < sizeof(filmes) / sizeof(struct filme); i++)
    {
        char text[50] = "";
        sprintf(text, "%s%s", text, filmes[i].nome);

        for (int j = strlen(filmes[i].nome); j < SPACING; j++)
        {
            sprintf(text, "%s ", text);
        }
        sprintf(text, "%s%s", text, filmes[i].genero);
        for (int j = strlen(filmes[i].genero); j < SPACING; j++)
        {
            sprintf(text, "%s ", text);
        }
        printf("%s%d\n", text, filmes[i].classificacao);
    }

    // Ordenacao
    quicksort(&filmes, 0, sizeof(filmes) / sizeof(struct filme));

    // Print pos ordenacao
    printf("\r\nLista de filmes ordenada por classificacao ascendente:\r\n");
    printf("Nome                Genero              Classificacao\r\n");
    for (int i = 0; i < sizeof(filmes) / sizeof(struct filme); i++)
    {
        char text[50] = "";
        sprintf(text, "%s%s", text, filmes[i].nome);

        for (int j = strlen(filmes[i].nome); j < SPACING; j++)
        {
            sprintf(text, "%s ", text);
        }
        sprintf(text, "%s%s", text, filmes[i].genero);
        for (int j = strlen(filmes[i].genero); j < SPACING; j++)
        {
            sprintf(text, "%s ", text);
        }
        printf("%s%d\n", text, filmes[i].classificacao);
    }

    return 0;
}
