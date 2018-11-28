#include <stdio.h>
#include <stdlib.h>

int start = 0;
int end = 0;

int enqueue(int *queue, int new, int size)
{
  if (end == size)
  {
    printf("Fila cheia\n");
    return 0;
  }
  queue[end] = new;
  end++;
}

int dequeue(int *queue, int *re)
{
  if (start == end)
  {
    printf("Fila vazia.\n");
    return -1;
  }

  *re = queue[start];
  start++;
  return 0;
}

int showQueue(int *queue)
{
  int i;
  if (start == end)
  {
    printf("Fila vazia\n");
    return -1;
  }
  else
  {
    printf("\nFila:\n\n");
    for (i = start; i < end; i++)
      printf("%d ", queue[i]);

    printf("\n");
  }
}

int main()
{
  int *fila = NULL;
  int *nova = NULL;
  int dado, rem = 0, ret = 0;
  int i, n, nadic;

  printf("\nTamanho da fila: ");
  scanf("%d", &n);
  fila = malloc(n * sizeof(int));

  if (fila == NULL)
  {
    printf("\nErro malloc.\n");
    return 0;
  }

  for (i = 0; i < n; i++)
  {
    printf("\nDado: ");
    scanf("%d", &dado);
    enqueue(fila, dado, n);
    showQueue(fila);
  }

  ret = dequeue(fila, &rem);

  if (ret == 0)
  {
    printf("\nSaiu da fila: %d\n", rem);
  }
  showQueue(fila);

  printf("\nDeseja armazenar mais dados? pressione 0 para sair ou digite a quantidade adicional: ");
  scanf("%d", &nadic);

  if (nadic > 0)
  {
    nova = realloc(fila, (n + nadic) * sizeof(int));
    if (nova == NULL)
    {
      printf("\nErro realloc.\n");
      return 0;
    }

    for (i = 0; i < nadic; i++)
    {
      printf("\nDado: ");
      scanf("%d", &dado);
      enqueue(nova, dado, (n + nadic));
      showQueue(nova);
    }

    ret = dequeue(nova, &rem);

    if (ret == 0)
    {
      printf("\nSaiu da fila: %d\n", rem);
    }
    showQueue(nova);
  }
}
