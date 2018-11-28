#include <stdio.h>
#include <string.h>

char upper(char c)
{
    return c - 32;
}

int main(int argc, char const *argv[])
{
    char caracter;
    printf("\nDigite um char para transformar: ");
    scanf("%c", &caracter);
    if (caracter < 97 || caracter > 122)
    {
        printf("Caracter invalido!!\n");
        return 0;
    }

    printf("Char transformado: %c\n", upper(caracter));

    return 0;
}

