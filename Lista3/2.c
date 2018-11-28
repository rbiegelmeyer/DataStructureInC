#include <stdio.h>
#include <string.h>

int pesquisaLetra(char letra, char *str)
{
    int ocorrencias = 0;

    printf("\n\nString: %s\n", str);

    while (*str != '\0')
    {
        if (*str == letra)
        {
            ocorrencias++;
        }
        str++;
    }
    printf("Numero de ocorrencias da letra %c: %d\n", letra, ocorrencias);
    return 0;
}

int main()
{

    char str[100];
    char letra;

    printf("Digite uma palavra:\n");
    gets(str);

    printf("Pesquisar qual letra?\n");
    scanf("%c", &letra);

    pesquisaLetra(letra, str);
}
