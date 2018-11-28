#include <stdio.h>
#include <string.h>

//Resposta: tudo e matematica!

int main(int argc, char const *argv[])
{
    char caracter;
    printf("\nDigite um char para transformar: ");
    scanf("%c", &caracter);

    caracter = caracter < 97 ? caracter + 32 : caracter - 32;
    // if (caracter < 97)
    // {
    //     caracter += 32;
    // }
    // else
    // {
    //     caracter -= 32;
    // }

    printf("Char transformado: %c\n", caracter);

    return 0;
}

