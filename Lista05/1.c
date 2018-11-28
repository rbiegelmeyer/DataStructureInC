#include <stdio.h>
#include <string.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

struct produto
{
    char tipo[50];
    char fabricante[50];
    char dataf[50];
    char datav[50];
    float preco;
};
struct produto produtos[3];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < sizeof(produtos) / sizeof(struct produto); i++)
    {
        printf("\r\nDigite o tipo do produto:\r\n");
        gets(produtos[i].tipo);
        CLEAR(stdin);

        printf("Digite o fabricante do produto:\r\n");
        gets(produtos[i].fabricante);
        CLEAR(stdin);

        printf("Digite a data de fabricacao do produto:\r\n");
        gets(produtos[i].dataf);
        CLEAR(stdin);

        printf("Digite a data de validade do produto:\r\n");
        gets(produtos[i].datav);
        CLEAR(stdin);

        printf("Digite o preco do produto:\r\n");
        scanf("%f", &produtos[i].preco);
        CLEAR(stdin);
    }

    printf("\r\nProdutos:\r\n");
    for (int i = 0; i < sizeof(produtos) / sizeof(struct produto); i++)
    {
        printf("Tipo:        %s\r\n", produtos[i].tipo);
        printf("Fabricante:  %s\r\n", produtos[i].fabricante);
        printf("Data de Fab: %s\r\n", produtos[i].dataf);
        printf("Data de Val: %s\r\n", produtos[i].datav);
        printf("Preco:       %0.2f\r\n\r\n", produtos[i].preco);
    }

    return 0;
}
