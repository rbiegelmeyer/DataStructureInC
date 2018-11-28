#include <stdio.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

int main()
{
    struct data
    {
        int dia;
        char mes[15];
        int ano;
    };
    struct data *d = NULL;
    d = malloc(sizeof(struct data));

    if (d == NULL)
    {
        exit(1);
    }
    else
    {
        printf("Digite o dia: ");
        scanf("%d", &d->dia);
        CLEAR(stdin);

        printf("Digite o mes: ");
        gets(d->mes);
        CLEAR(stdin);

        printf("Digite o ano: ");
        scanf("%d", &d->ano);
        CLEAR(stdin);

        printf("Dia: %d\n", d->dia);
        printf("Mes: %s\n", d->mes);
        printf("Ano: %d\n", d->ano);

        free(d);
        d = NULL;
    }
}
