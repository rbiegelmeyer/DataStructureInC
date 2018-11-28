#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

struct endereco
{
    char rua[100];
    int numero;
    char cep[10];
    char bairro[100];
    char cidade[100];
    char estado[3];
};

void cadastraEndereco(struct endereco *pe)
{
    printf("Rua: ");
    gets(pe->rua);
    CLEAR(stdin);

    printf("Numero: ");
    scanf("%d", &pe->numero);
    CLEAR(stdin);

    printf("CEP: ");
    gets(pe->cep);
    CLEAR(stdin);

    printf("Bairro: ");
    gets(pe->bairro);
    CLEAR(stdin);

    printf("cidade: ");
    gets(pe->cidade);
    CLEAR(stdin);

    printf("Estado: ");
    gets(pe->estado);
    CLEAR(stdin);
}

int main()
{
    struct endereco end;
    cadastraEndereco(&end);

    printf("\nRua:    %s\r\n", end.rua);
    printf("Numero: %d\r\n", end.numero);
    printf("cep:    %s\r\n", end.cep);
    printf("Bairro: %s\r\n", end.bairro);
    printf("Cidade: %s\r\n", end.cidade);
    printf("Estado: %s\r\n", end.estado);
}