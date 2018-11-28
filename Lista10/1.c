#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Variaveis declaradas aqui são visiveis por todas as funções
int stack[MAX];
int top = 0;

//Insere um item na pilha
int push(int new)
{
    if (top >= MAX)
    {
        printf("Pilha cheia.\n");
        return 0;
    }
    stack[top] = new;
    top++;
}

//Remove um item da pilha (o ultimo que entrou)
int pop(int *dado)
{
    top--;
    if (top < 0)
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    *dado = stack[top];
    return 0;
}

//Mostra o conteúdo da pilha
int showStack(void)
{
    int i;

    if (top < 0)
    {
        printf("Pilha vazia.\n");
        return 0;
    }
    printf("Pilha:\n");
    for (i = 0; i < top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n\n");
}

int main()
{
    int p = 0;
    int ret = 0;

    // Adiciona elementos
    push(34);
    push(45);

    showStack();

    // Remove elemento
    ret = pop(&p);

    printf("Elemento retirado da pilha: %d, retorno = %d\n\n", p, ret);

    // Mostra
    showStack();

    // Remove elemento
    p = 0;
    ret = pop(&p);

    printf("Elemento retirado da pilha: %d, retorno = %d\n\n", p, ret);

    // Remove elemento
    p = 0;
    ret = pop(&p);

    printf("Elemento retirado da pilha: %d, retorno = %d\n\n", p, ret);
}
