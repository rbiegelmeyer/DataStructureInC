#include <stdio.h>
#include <string.h>

struct aluno
{
    char nome[100];
    char rg[15];
    int matricula;
};
struct aluno aluno1;

struct endereco
{
    char rua[100];
    int numero;
    char bairro[100];
    char cidade[100];
};
struct endereco end1;

int main(int argc, char const *argv[])
{
    printf("Digite o nome do aluno:\r\n");
    scanf("%s", aluno1.nome);
    __fpurge(stdin);

    printf("Digite o rg do aluno:\r\n");
    scanf("%s", aluno1.rg);
    __fpurge(stdin);

    printf("Digite a matricula do aluno:\r\n");
    scanf("%d", &aluno1.matricula);
    __fpurge(stdin);

    printf("Digite a rua:\r\n");
    scanf("%s", end1.rua);
    __fpurge(stdin);

    printf("Digite o numero:\r\n");
    scanf("%d", &end1.numero);
    __fpurge(stdin);

    printf("Digite o bairro:\r\n");
    scanf("%s", end1.bairro);
    __fpurge(stdin);

    printf("Digite a cidade:\r\n");
    scanf("%s", end1.cidade);
    __fpurge(stdin);

    printf("Nome:      %s\n", aluno1.nome);
    printf("RG:        %s\n", aluno1.rg);
    printf("Matricula: %d\n", aluno1.matricula);

    printf("Rua:       %s\n", end1.rua);
    printf("Numero:    %d\n", end1.numero);
    printf("Bairro:    %s\n", end1.bairro);
    printf("Cidade:    %s\n", end1.cidade);

    return 0;
}
