#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
int dia;
int mes;
int ano;
};

struct aluno {
char nome[100];
char matricula[10];
struct data nascimento;
};

int main()
{
    struct aluno aluno1;

    printf("\nNome do aluno: ");
    gets(aluno1.nome);
    fflush(stdin);

    printf("\nMatricula: ");
    gets(aluno1.matricula);
    fflush(stdin);

    printf("\nDia de nascimento: ");
    scanf("%d", &aluno1.nascimento.dia);

    printf("\nMes de nascimento: ");
    scanf("%d", &aluno1.nascimento.mes);

    printf("\nAno de nascimento: ");
    scanf("%d", &aluno1.nascimento.ano);

    printf("\nDados:\nNome: %s\nMatricula: %s\nData de Nasc.: %d / %d / %d\n", aluno1.nome, aluno1.matricula, aluno1.nascimento.dia, aluno1.nascimento.mes, aluno1.nascimento.ano);
}
