#include <stdio.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

int main(int argc, char const *argv[])
{
    FILE *file;
    char text[100];
    printf("Digite algo:\n");
    gets(text);
    CLEAR(stdin);

    if ((file = fopen("Aula9/text.txt","w+")) == NULL)
    {
        printf("Erro ao abrir arquivo!!!\n");
        exit(1);
    }
    fwrite(&text,sizeof(char),strlen(text),file);

    fclose(file);

    return 0;   
}
