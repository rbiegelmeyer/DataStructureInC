#include <stdio.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

int main()
{
    FILE *file1;
    FILE *file2;
    char nfile1[100] = "file1.txt";
    char nfile2[100] = "file2.txt";

    printf("\nDigite o nome do primeiro arquivo:\n");
    gets(nfile1);
    CLEAR(stdin);

    printf("\nDigite o nome do segundo arquivo:\n");
    gets(nfile2);
    CLEAR(stdin);

    if ((file1 = fopen(nfile1, "r")) == NULL)
    {
        printf("Erro ao abrir arquivo %s!!!\n", nfile1);
        return;
    }

    if ((file2 = fopen(nfile2, "w")) == NULL)
    {
        printf("Erro ao abrir arquivo %s!!!\n", nfile2);
        return;
    }

    char c;
    while (!(feof(file1)))
    {
        c = fgetc(file1);
        if (c != EOF)
        {
            fprintf(file2, "%c", c);
        }
    }

    fclose(file1);
    fclose(file2);
}
