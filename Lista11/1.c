#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int fila[MAX];
int inicio = 0;
int fim = 0;

int armazenar(int novo)
{

  if (fim == MAX)
  {
    printf("Fila cheia\n");
    return 0;
  }
  fila[fim] = novo;
  fim++;
}

int remover(int *re)
{
  if (inicio == fim)
  {
    printf("Fila vazia.\n");
    return -1;
  }

  *re = fila[inicio];
  inicio++;
  return 0;
}

int imprimir()
{
  int i;
  if (inicio == fim)
  {
    printf("Fila vazia\n");
    return -1;
  }
  else
  {
    printf("\nFila:\n\n");
    for (i = inicio; i < fim; i++)
      printf("%d ", fila[i]);

    printf("\n");
  }
}

int main()
{
  int dado;
  int rem = 0;
  int ret = 0;

  printf("\nInserir: ");
  scanf("%d", &dado);
  armazenar(dado);
  imprimir();

  printf("\nInserir: ");
  scanf("%d", &dado);
  armazenar(dado);
  imprimir();

  ret = remover(&rem);

  if (ret == 0)
  {
    printf("\nSaiu da fila: %d\n", rem);
  }
  imprimir();

  ret = remover(&rem);

  if (ret == 0)
  {
    printf("\nSaiu da fila: %d\n", rem);
  }
  imprimir();

  ret = remover(&rem);

  if (ret == 0)
  {
    printf("\nSaiu da fila: %d\n", rem);
  }
  imprimir();
}