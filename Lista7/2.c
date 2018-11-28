#include <stdio.h>
#include <string.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

struct dhcp
{
    char bc[17];
    char mask[17];
    char ip[17];
    char dns[17];
};

int main(int argc, char const *argv[])
{
    struct dhcp *d = NULL;
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    CLEAR(stdin);
    d = malloc(n * sizeof(struct dhcp));

    if (d == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Broadcast: \r\n");
            scanf("%s", d[i].bc);
            CLEAR(stdin);

            printf("Mascara: \r\n");
            scanf("%s", d[i].mask);
            CLEAR(stdin);

            printf("IP: \r\n");
            scanf("%s", d[i].ip);
            CLEAR(stdin);

            printf("DNS: \r\n");
            scanf("%s", d[i].dns);
            CLEAR(stdin);
        }

        for (int i = 0; i < n; i++)
        {
            printf("\nBroadcast: %s\n", d[i].bc);
            printf("Mascara:   %s\n", d[i].mask);
            printf("IP:        %s\n", d[i].ip);
            printf("DNS:       %s\n", d[i].dns);
        }

        free(d);
        d = NULL;
    }
}