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
    if ((file = fopen("text.txt", "w")) == NULL)
    {
        printf("Erro ao abrir arquivo!!!\n");
        return;
    }
    char text[100];
    scanf("%s", text);
    CLEAR(stdin);


    for (int i = 0; text[i] != '\0' ; i++)
    {
        fprintf(file, "%c\n", text[i]);
    }
    fclose(file);
}
