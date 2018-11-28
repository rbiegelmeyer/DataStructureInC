#include <stdio.h>
#include <string.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

struct carro
{
    char modelo[100];
    char placa[10];
    unsigned long entry_time;
};

int cadastrar(struct carro *carros_temp, int pos, int n)
{
    for (int i = pos; i < n; i++)
    {
        printf("Digite o modelo do carro:\r\n");
        scanf("%s", carros_temp[i].modelo);
        CLEAR(stdin);

        printf("Digite a placa do carro:\r\n");
        scanf("%s", carros_temp[i].placa);
        CLEAR(stdin);

        printf("Digite o horario(timestamp) de entrada do carro:\r\n");
        scanf("%lu", &carros_temp[i].entry_time);
        CLEAR(stdin);
    }
    int ret = n;

    char temp;
    printf("Cadastrar mais carros? (S/N)\n");
    scanf("%c", &temp);
    CLEAR(stdin);

    if (temp == 's' || temp == 'S')
    {
        int m;
        printf("Quantos carros? ");
        scanf("%d", &m);
        CLEAR(stdin);

        carros_temp = realloc(carros_temp, (n + m) * sizeof(struct carro));

        ret = cadastrar(carros_temp, n, m + n);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    struct carro *carros = NULL;
    int n;
    printf("Quantos carros? ");
    scanf("%d", &n);
    CLEAR(stdin);

    carros = malloc(n * sizeof(struct carro));

    if (carros == NULL)
    {
        return 0;
    }
    else
    {
        int ret = cadastrar(carros, 0, n);

        printf("\nReturn: %d\n", ret);

        for (int i = 0; i < ret; i++)
        {
            printf("Modelo:  %s\n", carros[i].modelo);
            printf("Placa:   %s\n", carros[i].placa);
            printf("Tempo: %lu\n", carros[i].entry_time);
        }
    }

    free(carros);
    carros = NULL;

    return 0;
}
