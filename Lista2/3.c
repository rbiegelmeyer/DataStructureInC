#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char text[101];
    printf("\nDigite uma string de ate 100 char: ");
    scanf("%s", text);
    printf("Tamanho da string digitada: %lu\n", strlen(text));

    return 0;
}

