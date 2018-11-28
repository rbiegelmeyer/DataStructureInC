#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

/*
Circular Queue adaptada de:
http://www.xappsoftware.com/wordpress/2012/09/27/a-simple-implementation-of-a-circular-queue-in-c-language/
*/

#define MAX_ITEMS 10

typedef struct
{
    int num_chamado;
    char assunto[100];
    char descricao[250];
} chamado;

// Struct da Fila
typedef struct circularQueue_s
{
    int first;
    int last;
    int validItems;
    chamado chamados[MAX_ITEMS];
} circularQueue_t;

// Prototype
void initializeQueue(circularQueue_t *theQueue);
int isEmpty(circularQueue_t *theQueue);
int putItem(circularQueue_t *theQueue, chamado *theItemValue);
int getItem(circularQueue_t *theQueue, chamado *theItemValue);
void printQueue(circularQueue_t *theQueue);

// Initialize Circular Queue
void initializeQueue(circularQueue_t *theQueue)
{
    int i;
    theQueue->validItems = 0;
    theQueue->first = 0;
    theQueue->last = 0;
    // for (i = 0; i < MAX_ITEMS; i++)
    // {
    //     theQueue->chamados[i] = {0,"\0","\0"};
    // }
    return;
}

int isEmpty(circularQueue_t *theQueue)
{
    if (theQueue->validItems == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Put Element in CircularQueue
int putItem(circularQueue_t *theQueue, chamado *theItemValue)
{
    if (theQueue->validItems >= MAX_ITEMS)
    {
        printf("The queue is full\n");
        printf("You cannot add items\n");
        return (-1);
    }
    else
    {
        theQueue->validItems++;
        theQueue->chamados[theQueue->last] = *theItemValue;
        theQueue->last = (theQueue->last + 1) % MAX_ITEMS;
    }
}

// Get Element by Circular Queue
int getItem(circularQueue_t *theQueue, chamado *theItemValue)
{
    if (isEmpty(theQueue))
    {
        // printf("isempty\n");
        return (-1);
    }
    else
    {
        *theItemValue = theQueue->chamados[theQueue->first];
        theQueue->first = (theQueue->first + 1) % MAX_ITEMS;
        theQueue->validItems--;
        return (0);
    }
}

// Print CiruclarQueue
void printQueue(circularQueue_t *theQueue)
{
    int aux = theQueue->first, aux1 = theQueue->validItems;
    while (aux1 > 0)
    {
        printf("    Print Queue Element #%d\n", aux);
        printf("    Num_chamado = %d\n", theQueue->chamados[aux].num_chamado);
        printf("    Assunto     = %s\n", theQueue->chamados[aux].assunto);
        printf("    Desricao    = %s\n", theQueue->chamados[aux].descricao);
        printf("\n");
        aux = (aux + 1) % MAX_ITEMS;
        aux1--;
    }
    return;
}

int createChamado(chamado *aux_chm)
{
    int temp_num_chm;
    printf("Numero do chamado: ");
    if (!scanf("%d", &aux_chm->num_chamado))
    {
        return 0;
    }
    CLEAR(stdin);

    printf("Assunto do chamado: ");
    gets(aux_chm->assunto);
    CLEAR(stdin);

    printf("Descricao do chamado: ");
    gets(aux_chm->descricao);
    CLEAR(stdin);

    return 1;
}

// organize args
void WriteFormatted(FILE *stream, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(stream, format, args);
    va_end(args);
}

void addToFile(chamado *aux_chm)
{
    FILE *file;
    if ((file = fopen("atedimentos.txt", "a")) == NULL)
    {
        printf("Erro ao abrir arquivo %s!!!\n", "atendimentos.txt");
        return;
    }

    time_t curtime = time(NULL);
    struct tm *loctime = localtime(&curtime);

    WriteFormatted(file, "Numero do chamado: %d\n", aux_chm->num_chamado);
    WriteFormatted(file, "Descricao: %s\n", aux_chm->descricao);
    WriteFormatted(file, "Horario do atendimento: %s\n", asctime(loctime));

    fclose(file);
}

int main(void)
{
    // Aux variables
    chamado x;
    chamado readValue;
    circularQueue_t myQueue;
    initializeQueue(&myQueue);

    while (1)
    {
        int option = 0;
        printf("\nSelecione uma opcao.\n");
        printf("1 - Cadastrar Novo Chamado\n");
        printf("2 - Exibir Todos os chamados\n");
        printf("3 - Atender Chamado\n");
        printf("4 - Sair\n");
        printf("\nQual sua opcao? ");
        scanf("%d", &option);
        printf("\n"); 
        CLEAR(stdin);

        switch (option)
        {
        case 1:
            if (!(myQueue.validItems >= MAX_ITEMS))
            {
                if (createChamado(&x))
                {
                    putItem(&myQueue, &x);
                }
                else
                {
                    printf("DADOS DIGITADOS INCORRETAMENTE!!!\n");
                }
            }
            else
            {
                printf("FILA CHEIA!!!\n");
            }
            break;
        case 2:
            printQueue(&myQueue);
            break;
        case 3:
            if (getItem(&myQueue, &readValue) != -1)
            {
                addToFile(&readValue);
                printf("Get Item Element\n");
                printf("Num_chamado = %d\n", readValue.num_chamado);
                printf("Assunto     = %s\n", readValue.assunto);
                printf("Desricao    = %s\n", readValue.descricao);
                printf("\n");
            }
            else
            {
                printf("SEM CHAMADOS!!!\n");
            }
            break;
        case 4:
            return 0;
        default:
            printf("OPCAO INVALIDA!!!\n");
        }
    }
    return 0;
}