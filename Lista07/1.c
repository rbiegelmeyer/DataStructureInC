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

int main(int argc, char const *argv[])
{
    struct carro *carros = NULL;
    int n;
    printf("Quantos carros? ");
    scanf("%d", &n);
    carros = malloc(n * sizeof(struct carro));

    if (carros == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Digite o modelo do carro:\r\n");
            scanf("%s", carros[i].modelo);
            CLEAR(stdin);

            printf("Digite a placa do carro:\r\n");
            scanf("%s", carros[i].placa);
            CLEAR(stdin);

            printf("Digite o horario(timestamp) de entrada do carro:\r\n");
            scanf("%lu", &carros[i].entry_time);
            CLEAR(stdin);
        }

        for (int i = 0; i < n; i++)
        {
            printf("Modelo:  %s\n", carros[i].modelo);
            printf("Placa:   %s\n", carros[i].placa);
            printf("Tempo: %lu\n", carros[i].entry_time);
        }

        free(carros);
        carros = NULL;
    }

    return 0;
}
