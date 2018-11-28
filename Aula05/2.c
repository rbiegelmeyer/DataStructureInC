#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

union paciente {
    char nome[100];
    int numeroficha;
};
union paciente pac;

int main()
{
    printf("\nNome: ");
    gets(pac.nome);
    CLEAR(stdin);
    printf("Nome:          %s\r\n", pac.nome);
    printf("Numero Ficha:: %d\r\n", pac.numeroficha);

    printf("\nNumero Ficha: ");
    scanf("%d", &pac.numeroficha);
    CLEAR(stdin);
    printf("Nome:          %s\r\n", pac.nome);
    printf("Numero Ficha:: %d\r\n", pac.numeroficha);
}
