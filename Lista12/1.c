#include <stdio.h>
#include <stdlib.h>

int inicio = 0;
int fim = 0;

int armazenar(int *fila, int novo, int tamanho)
{

  if (fim == tamanho)
  {
    printf("Fila cheia\n");
    return 0;
  }
  fila[fim] = novo;
  fim++;
}

int remover(int *fila, int *re)
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

int imprimir(int *fila)
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
    armazenar(fila, dado, n);
    imprimir(fila);
  }

  ret = remover(fila, &rem);

  if (ret == 0)
  {
    printf("\nSaiu da fila: %d\n", rem);
  }
  imprimir(fila);

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
      armazenar(nova, dado, (n + nadic));
      imprimir(nova);
    }

    ret = remover(nova, &rem);

    if (ret == 0)
    {
      printf("\nSaiu da fila: %d\n", rem);
    }
    imprimir(nova);
  }
}
