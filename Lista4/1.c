#include <stdio.h>
#include <string.h>

struct carro
{
    char modelo[100];
    char placa[10];
    unsigned long entry_time;
};
struct carro carro1 ;


int main(int argc, char const *argv[])
{
    printf("Digite o modelo do carro:\r\n");
    scanf("%s", carro1.modelo);
    fflush(stdin);

    printf("Digite a placa do carro:\r\n");
    scanf("%s", carro1.placa);
    fflush(stdin);

    printf("Digite o horario(timestamp) de entrada do carro:\r\n");
    scanf("%lu", &carro1.entry_time);
    fflush(stdin);

    printf("Modelo:  %p\n", carro1.modelo);
    printf("Placa:   %p\n", carro1.placa);


    return 0;
}
