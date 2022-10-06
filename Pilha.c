#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
	int topo;
	int vetor[10];
} pilha;


pilha* criaPilha ();
void liberaPilha (pilha *p);
int inserirPilha (pilha *p, int v);
int retirarPilha (pilha *p, int *v);
int pilhaCheia (pilha *p);
int pilhaVazia (pilha *p);

int main() {
	pilha *p;
	int escolha, inicio, temp;

	while (inicio != 2) // loop inicial
	{
		printf
		(
			"\n1. Criar pilha\n"
			"2. Sair\n"
		);
		scanf ("%d", &inicio);

		switch (inicio)
		{
		case 1:
			p = criaPilha(); //cria pilha (vetor e topo)
			do //loop de escolha
			{
				printf
				(
					"\n1. Empilhar\n" //empilha um novo numero
					"2. Desempilhar\n" //desempilha um numero
					"3. Conferir se a pilha esta vazia\n" //
					"4. Conferir se a pilha esta cheia\n" //
					"5. Liberar a pilha\n" //
					"6. Sair\n" //volta para o switch inicial
          "7. Topo\n"
				);
				scanf  ("%d", &escolha);

				switch (escolha)
				{
				case 1:
					printf ("Digite o valor que quer empilhar: \n");
					scanf ("%d", &temp);
					if (inserirPilha (p, temp) == -1)
					{
						printf ("A pilha esta cheia\n");
					}
					else
					{
						printf ("Numero adicionado: %i\n", temp);
					}
					break;
				case 2:
					printf ("Digite o valor que quer retirar\n");
          scanf ("%d", &temp);
          if (retirarPilha (p, &temp) == 0)
          {
            printf ("A pilha esta vazia\n");
          }
          else
          {
            printf ("Numero %i retirado\n", temp);
          }

					break;
				case 3:
					if (pilhaVazia (p) == 1)
					{
						printf ("Pilha vazia\n");
					}
					else
					{
						printf ("Pilha nao vazia\n");
					}
					break;
				case 4:
					if (pilhaCheia(p) == 1)
					{
						printf ("Pilha cheia\n");
					}
					else
					{
						printf ("Pilha nao Cheia\n");
					}
					break;
				case 5:
					liberaPilha (p);
					break;
				case 6:
					exit (0);
					break;
        case 7:
          printf ("Topo: %i\n", p->topo);
				}
			} while (escolha != 6);
		case 2: return 0; break;
		}
	}
	return 0;
}


pilha* criaPilha ()
{
	pilha *p;
	p = (pilha *) malloc (sizeof (pilha));
	p->topo = 0;
	return p;
}

void liberaPilha (pilha *p)
{
	free (p);
}

int inserirPilha (pilha *p, int v)
{
	if (pilhaCheia(p) == 1)
	{
		return -1;
	}
	else
	{
		p->vetor[p->topo] = v;
		p->topo++;
		return 1;
	}
}

int retirarPilha (pilha *p, int *v)
{
	if (pilhaVazia(p) == 1)
	{
		return -1;
	}
	p->topo -= 1;
	return 1;
}

int pilhaCheia (pilha *p)
{
	if (p->topo < 10) //fix sizeof (p->vetor)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int pilhaVazia (pilha *p)
{
	if (p->topo <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
