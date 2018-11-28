#include <stdio.h>
#include <stdlib.h>

int soma(int n, int num)
{
  if(num == 0)
  {
    return n;
  }
  else
  {
    return (n + soma(n+1,num-1));
  }
}

int main(int argc, char const *argv[])
{
  printf("\nTotal: %d\n\n",soma(0,5));
  return 0;
}
