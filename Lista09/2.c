#include <stdio.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

int main()
{
    FILE *file;
    char nfile[100] = "file1.txt";

    printf("Digite o nome do arquivo:\n");
    gets(nfile);
    CLEAR(stdin);

    if ((file = fopen(nfile, "r")) == NULL)
    {
        printf("Erro ao abrir arquivo %s!!!\n", nfile);
        return;
    }

    int cont = 0;
    while (!(feof(file)))
    {
        cont++;
        fgetc(file);
    }

    printf("Numero de caracteres: %d\n", cont-1);

    fclose(file);
}
