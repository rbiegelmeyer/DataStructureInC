#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

struct aluno
{
    char
        nome[100];
    int
        matricula;
};

int main()
{
    struct aluno aluno1, *pa;
    pa = &aluno1;
    printf("Nome: ");
    scanf("%s", pa->nome);
    CLEAR(stdin);

    printf("Matricula: ");
    scanf("%d", &pa->matricula);
    CLEAR(stdin);

    printf("Nome:          %s\r\n", pa->nome);
    printf("Matricula:     %d\r\n", pa->matricula);
}