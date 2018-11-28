#include <stdio.h>
#include <string.h>

int main()
{

    char str1[50], str2[50], str3[100];
    char *ps, *ps3;
    int i;

    printf("Digite duas palavras:\n");

    scanf("%s", str1);
    scanf("%s", str2);

    printf("Palavras que vc digitou:\n%s\n%s\n", str1, str2);

    ps3 = str3;
    ps = str1;

    for (i = 0; i < (strlen(str1)); i++)
    {
        *ps3 = *ps;
        ps++;
        ps3++;
    }

    ps = str2;
    for (i = 0; i < (strlen(str2)); i++)
    {
        *ps3 = *ps;
        ps++;
        ps3++;
    }

    *ps3 = '\0';

    printf("str3 = %s\n", str3);
}
