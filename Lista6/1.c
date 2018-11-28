#include <stdio.h>
#include <string.h>

int main()
{
 //Declaração das structs que irão armazenar as informações sobre os eleitores
 struct endereco {
    char rua[100];
    int numero;
    char bairro[100];
    char cep[20];
    char cidade[100];
    char estado[5];
 };

 struct pessoa {
    char nome[100];
    char cpf[20];
    char rg[20];
 };

 struct eleitor{
    struct pessoa pes;
    struct endereco end;
    char titulo[20];
    int zona;
    int secao;
 };

//Declara um vetor de structs do tipo eleitor
 struct eleitor el[2];

//Declara contadores
 int i;


		//__fpurge(stdin);

        printf("\nCadastro de eleitores.\n");
		//Recebe os dados 
 		for(i=0; i<2; i++)
 		{
   			printf("\n\nNome:\n");
            gets(el[i].pes.nome);
            fflush(stdin);

   			printf("CPF:\n");
            gets(el[i].pes.cpf);
            fflush(stdin);

   			printf("RG:\n");
            gets(el[i].pes.rg);
            fflush(stdin);

   			printf("\nEndereco\nRua:\n");
            gets(el[i].end.rua);

            printf("Numero:\n");
            scanf("%d", &el[i].end.numero);
            fflush(stdin);

   			printf("Bairro:\n");
            gets(el[i].end.bairro);
            fflush(stdin);

   			printf("Cidade:\n");
            gets(el[i].end.cidade);
            fflush(stdin);

   			printf("Estado:\n");
            gets(el[i].end.estado);
            fflush(stdin);

   			printf("Cep:\n");
            gets(el[i].end.cep);
            fflush(stdin);

            printf("Numero do titulo de eleitor:\n");
            gets(el[i].titulo);

            printf("Numero da zona eleitoral:\n");
            scanf("%d", &el[i].zona);

            printf("Numero da secao eleitoral:\n");
            scanf("%d", &el[i].secao);
            fflush(stdin);


			}

            for(i=0; i<2; i++)
            {
                printf("\n\nNome: %s\nCPF: %s\nRG: %s\nRua: %s\nNumero: %d\nBairro: %s\nCidade: %s\nEstado: %s\nCep: %s\nTitulo eleitoral: %s\nZona eleitoral: %d\nSecao eleitoral: %d\n\n", el[i].pes.nome,
     				el[i].pes.cpf, el[i].pes.rg, el[i].end.rua, el[i].end.numero, el[i].end.bairro, el[i].end.cidade, el[i].end.estado, el[i].end.cep, el[i].titulo, el[i].zona, el[i].secao);
            }
			//__fpurge(stdin); //Linux

		}





