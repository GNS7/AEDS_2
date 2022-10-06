#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
	int matricula;
	int nota1, nota2, nota3;
	float media;
	char nome[100];

}aluno;


int busca_sequencial_struct (int chave, aluno a[], int n);
int busca_sequencial_int (int chave, int a[], int n);
int busca_binaria_struct (int chave, aluno a[], int n);
int busca_binaria_int (int chave, int a[], int n);
void bubblesort_struct (aluno a[], int n);
void bubblesort_int (int a[], int n);


int main()
{
	int num_alunos, opcao, chave, posicao, modo, num;
	aluno *p;
	int *p_int;

	do
	{
		printf
		(
			"\n1-Struct"
			"\n2-Inteiro"
			"\n0-Fecha o programa\n"
		);
		scanf("%i", &modo);

		switch (modo)  //modo Struct ou Inteiro
		{
		case 0: return 1; break;

		case 1: //struct
			printf ("\nInsira o numero de alunos que deseja cadastrar: ");
			scanf ("%i", &num_alunos);

			p = (aluno *) malloc (num_alunos * sizeof (aluno)); //alocacao dinamica de memorai para structs

			for (int i = 0; i < num_alunos; i++) //loop para receber as informacoes da struct de alunos
			{
				printf ("\nDigite o nome do %i aluno:", i + 1);
				fflush (stdin); //flush
				fgets(p[i].nome, 100, stdin);
				fflush (stdin); //flush
				printf ("\nDigite o numero de matricula do aluno:");
				scanf ("%d", &p[i].matricula);
				printf ("\nDigite a 1 nota do aluno:");
				scanf ("%i", &p[i].nota1);
				printf ("\nDigite a 2 nota do aluno:");
				scanf ("%i", &p[i].nota2);
				printf ("\nDigite a 3 nota do aluno:");
				scanf ("%i", &p[i].nota3);
				p[i].media = (p[i].nota1 + p[i].nota2 + p[i].nota3)/2;
			}


			do
			{
				printf
				(
					"\n1 - Busca sequencial"
					"\n2 - Busca binaria\n"
				);
				scanf ("%i", &opcao);

				switch (opcao) //opcao de Busca Sequencial ou Binaria STRUCT
				{
				case 0: break;

				case 1: //Sequencial de struct pronto
					printf ("\nDigite o numero de matricula do aluno:");
					scanf ("%i", &chave);
					posicao = busca_sequencial_struct (chave, p, num_alunos);
					printf ("\nO aluno esta na posicao %i\n", posicao);
					break;

				case 2: //Binaria de struct pronto
					printf ("\nDigite o numero de matricula do aluno:");
					scanf ("%i", &chave);
					printf ("Chave: %i", chave);
					bubblesort_struct (p, num_alunos);
					posicao = busca_binaria_struct (chave, p, num_alunos);
					printf ("\nO aluno esta na posicao %i\n", posicao);
					break;
				}
			} while (opcao != 0);
			break;

		case 2: //int
			printf ("\nInsira a quantidade de numeros desejada: ");
			scanf ("%i", &num);

			p_int = (int *) malloc (num * sizeof (int)); //alocacao dinamica de memorai para ints

			for (int i = 0; i < num; i++) //loop para receber os inteiros
			{
				printf ("\nDigite um numero:");
				scanf ("%i", &p_int[i]);
			}

			do
			{
				printf
				(
					"\n1 - Busca sequencial"
					"\n2 - Busca binaria\n"
				);
				scanf ("%i", &opcao);

				switch (opcao) //opcao de Busca Sequencial ou Binaria INT
				{
				case 0: break;

				case 1: //Sequencial de int pronto
					printf ("\nDigite o numero:");
					scanf ("%i", &chave);
					posicao = busca_sequencial_int (chave, p_int, num);
					printf ("\nO aluno esta na posicao %i\n", posicao);
					break;

				case 2: //Binaria de int pronto
					printf ("\nDigite o numero:");
					scanf ("%i", &chave);
					bubblesort_int (p_int, num_alunos);
					posicao = busca_binaria_int (chave, p_int, num);
					printf ("\nO aluno esta na posicao %i\n", posicao);
					break;
				}
			} while (opcao != 0);
		}

	} while (modo != 0);

	return 0;
}


int busca_sequencial_struct (int chave, aluno a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].matricula == chave)
		{
			return i;
		}
	}
	return -1;
}

int busca_sequencial_int (int chave, int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == chave)
		{
			return i;
		}
	}
	return -1;
}

void bubblesort_struct (aluno a[], int n)
{
	aluno temp;
	for (int i = 0; i < n; i++)
	{
		if (a[i].matricula > a[i+1].matricula)
		{
			temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("\n %s \n %i \n %i \n %i \n %i \n %f", a[i].nome, a[i].matricula, a[i].nota1, a[i].nota2, a[i].nota3, a[i].media);
	// }
}

void bubblesort_int (int a[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i+1])
		{
			temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		}
	}
}

int busca_binaria_struct (int chave, aluno a[], int n)
{
	int esq = 0;
	int dir = n - 1;
	int i = 0;
	do
	{
		int meio = (esq + dir)/2;

		if (a[meio].matricula < chave)
		{
			esq = meio + 1;
		}

		else if (a[meio].matricula > chave)
		{
			dir = meio - 1;
		}

		else
		{
			return meio;
		}

	} while (chave != a[i].matricula && esq <= dir);

	return -1;
}

int busca_binaria_int (int chave, int a[], int n)
{
	int esq = 0;
	int dir = n - 1;
	int i = 0;
	do
	{
		int meio = (esq + dir)/2;

		if (a[meio] < chave)
		{
			esq = meio + 1;
		}

		else if (a[meio] > chave)
		{
			dir = meio - 1;
		}

		else
		{
			return meio;
		}

	} while (chave != a[i] && esq <= dir);

	return -1;
}
