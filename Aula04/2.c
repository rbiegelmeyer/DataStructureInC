#include <stdio.h>
#include <string.h>

struct filme
{
    char nome[100];
    char genero[30];
    int classificacao;
};
struct filme filmes[2];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < sizeof(filmes) / sizeof(struct filme); i++)
    {
        printf("Digite o nome do filme:\r\n");
        gets(filmes[i].nome);
        __fpurge(stdin);

        printf("Digite o genero do filme:\r\n");
        gets(filmes[i].genero);
        __fpurge(stdin);

        printf("Digite a classificacao etaria do filme:\r\n");
        scanf("%d", &filmes[i].classificacao);
        __fpurge(stdin);
    }

    int idade = 0;
    printf("Digite a idade da pessoa:\r\n");
    scanf("%d", &idade);
    __fpurge(stdin);

    printf("\r\nLista de filmes disponivel para a idade informada:\r\n");
    printf("Nome           Genero\r\n");
    for (int i = 0; i < sizeof(filmes) / sizeof(struct filme); i++)
    {
        if (filmes[i].classificacao <= idade)
        {
            printf("%s          %s\r\n", filmes[i].nome, filmes[i].genero);
        }
    }

    return 0;
}
