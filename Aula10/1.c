#include <stdio.h>

#define MAX 10
int stack[MAX];
int top = 0;

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

int pop(void)
{
    if (!top)
    {
        printf("Pilha vazia.\n");
        return 0;
    }
    top--;
    return stack[top];
}

int showStack(void)
{
    for (int i = top; i > 0; i--)
    {
        printf("|#%d: %d|\n", i, stack[i - 1]);
    }
}

int main(int argc, char const *argv[])
{
    push(10);
    push(12);
    push(14);
    push(16);
    showStack();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    printf("%d\n", top);
    push(16);
    showStack();

    return 0;
}
