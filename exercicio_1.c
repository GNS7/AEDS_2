#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3

typedef struct tad
{
	int vetor[MAX];
}tad;

tad* criaTad ();
void liberaTad (tad *t);
int inserirTad (tad *t, int v);
int retirarTad (tad *t, int *v);
int tadCheia (tad *t);
int tadVazia (tad *t);

int main() {
	tad *t, *t_temp;
  int temp, inicio, escolha;
	while (inicio != 2) // loop inicial
	{
		printf
		(
			"\n1. Criar Tad\n"
			"2. Sair\n"
		);
		scanf ("%d", &inicio);

		switch (inicio)
		{
		case 1:
			t = criaTad(); //cria pilha (vetor e topo)
			do //loop de escolha
			{
				printf
				(
          "1. Criar tad_temporario\n" //tad_temporario
          "2. Uniao\n" //uniao de 2 conjuntos
          "3. Conj. vazio\n"
          "4. Empilhar\n" //empilha um novo numero
          "5. Desempilhar\n" //desempilha um numero
          "6. Interseccao\n" //interseccao entre dois conjuntos
          "7. Diferenca" //numeros que estao diferentes nos conjuntos
          "8. Pertence ao conjunto\n" //verifica se o numero pertence ao conjunto
          "9. Menor valor\n" //menor valor do conjunto
          "10. Maior valor\n" //maior valor do conjunto
          "11. Conj. iguais\n" //verifica se os conjuntos sao iguais
          "12. Tamanho do conjunto\n" //volta para o switch inicial
          "13. Conjunto vazio\n"
          "14. Sair"
				);
				scanf  ("%d", &escolha);

				switch (escolha)
				{
				case 1:
          t_temp = criaTad ();
          for (int i = 0; i < MAX; i++)
          {
            printf ("Digite os valores do conjunto");
            scanf ("%d", &temp);
            inserirTad (t_temp, temp);
          }
          break;
        case 2:
          printf("\nConj. Uniao: %i, %i, %i, %i, %i, %i\n", t->vetor[0], t->vetor[1], t->vetor[2], t_temp->vetor[0], t_temp->vetor[1], t_temp->vetor[2]);
          break;
				case 3:
					printf ("Digite o valor que quer empilhar: \n");
					scanf ("%d", &temp);
					if (inserirTad (t, temp) == -1)
					{
						printf ("A pilha esta cheia\n");
					}
					else
					{
						printf ("Numero adicionado: %i\n", temp);
					}
					break;
				case 4:
					printf ("Digite o valor que quer retirar\n");
					scanf ("%d", &temp);
					if (retirarTad (t, &temp) == 0)
					{
						printf ("A pilha esta vazia\n");
					}
					else
					{
						printf ("Numero %i retirado\n", temp);
					}
					break;
				case 5:
					if (tadVazia (t) == 1)
					{
						printf ("Pilha vazia\n");
					}
					else
					{
						printf ("Pilha nao vazia\n");
					}
					break;
				case 6:
					if (tadCheia(t) == 1)
					{
						printf ("Pilha cheia\n");
					}
					else
					{
						printf ("Pilha nao Cheia\n");
					}
					break;
				case 7:

					break;
				case 13:
					free (t);
					exit (0);
					break;
				}
			} while (escolha != 6);
		case 2: return 0; break;
		}
	}
	return 0;
}

tad* criaTad ()
{
	tad *t;
	t = (tad *) malloc (sizeof (tad));
	return t;
}

tad* criaTadVazio ()
{

}

void liberaTad (tad *t)
{
	free (t);
}

int inserirTad (tad *t, int v)
{
	if (tadCheia(t) == 1)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int retirarTad (tad *t, int *v)
{
	if (tadVazia(t) == 1)
	{
		return -1;
	}
	return 1;
}

int tadCheia (tad *t)
{
	if (< 10) //fix sizeof (t->vetor)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int tadVazia (tad *t)
{
	if (<= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
