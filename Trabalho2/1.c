#include <stdio.h>
#include <string.h>
#include "sha256.h"

#ifdef unix
#define CLEAR(...) __fpurge(__VA_ARGS__)
#else
#define CLEAR(...) fflush(__VA_ARGS__);
#endif

/*
    Repositorio da biblioteca. (https://github.com/B-Con/crypto-algorithms)
    Utilizada somente a sha256. 
    Nao uso uma IDE com um botao "bonito de build" então tenho que indicar as lib no comando para compilar.
    gcc 1.c sha256.c -o main
*/

//  (in, out)
void encrypt(char *string, char outputBuffer[65])
{
    unsigned char hash[SHA256_BLOCK_SIZE];

    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, string, strlen(string));
    sha256_final(&ctx, hash);
    int i = 0;
    for (i = 0; i < SHA256_BLOCK_SIZE; i++)
    {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int test(char *buf1, char *buf2)
{
    return (strcmp(buf1, buf2) == 0);
}

int main()
{
    FILE *file1;
    FILE *file2;
    char nfile1[100] = "file1.txt";
    char nfile2[100] = "file2.txt";

    printf("\nNome ou caminho completo do arquivo 1: ");
    gets(nfile1);
    CLEAR(stdin);

    printf("Nome ou caminho completo do arquivo 2: ");
    gets(nfile2);
    CLEAR(stdin);

    printf("\n");
    if ((file1 = fopen(nfile1, "r")) == NULL)
    {
        printf("Erro ao abrir arquivo %s!!!\n", nfile1);
        return 0;
    }

    if ((file2 = fopen(nfile2, "r")) == NULL)
    {
        printf("Erro ao abrir arquivo %s!!!\n", nfile2);
        return 0;
    }

    int size;

    fseek(file1, 0, SEEK_END);                         //setting position of stream to the ending
    size = ftell(file1);                               //reading total bytes on file
    rewind(file1);                                     //setting position of stream to the beginning
    char *buff1 = malloc((size + 1) * sizeof(*buff1)); //instance buffer and alloc memory
    fread(buff1, 1, size, file1);                      //read file (out, number readings, bytes per read, in)
    buff1[size] = '\0';                                //add special caracter string end
    // printf("1: %s\n", buff1);                          //print arr char

    fseek(file2, 0, SEEK_END);                         //setting position of stream to the ending
    size = ftell(file2);                               //reading total bytes on file
    rewind(file2);                                     //setting position of stream to the beginning
    char *buff2 = malloc((size + 1) * sizeof(*buff2)); //instance buffer and alloc memory
    fread(buff2, size, 1, file2);                      //read file (out, number readings, bytes per read, in)
    buff2[size] = '\0';                                //add special caracter string end
    // printf("2: %s\n", buff2);                          //print arr char

    char output1[65];
    encrypt(buff1, output1);                           //call encrypt
    // printf("%s ----> %s\n", nfile1, output1);          //print hash

    char output2[65];
    encrypt(buff2, output2);                           //call encrypt
    // printf("%s ----> %s\n", nfile2, output2);          //print hash

    // printf("\nRESULTADO: %s\n", test(output1, output2) ? "CONTEUDO IGUAL!!!" : "CONTEUDO DIFERENTE!!!");
    if (test(output1, output2))
    {
        printf("Os arquivos sao iguais.\n");
        printf("Hash: %s\n\n", output1);
    }
    else
    {
        printf("Os arquivos nao sao iguais.\n");
        printf("Hash 1: %s\n", output1);
        printf("Hash 2: %s\n\n", output2);
    }

    free(buff1);
    free(buff2);
    buff1 = NULL;
    buff2 = NULL;

    fclose(file1);
    fclose(file2);

    return 0;
}