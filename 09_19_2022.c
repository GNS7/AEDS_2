#include <stdio.h>
#include <math.h>

typedef struct pontos
{
	int x1, x2, y1, y2;
}pontos;

pontos lePonto ();//Le os pontos da coordenada
pontos lePontoS ();
pontos lePontoReferencia (); //
void leQuadrante(int *quadrante); //
void alterar (pontos *a);//Alterar o valor de x ou y
float calculoDistancia (pontos p); //Calcula a distancia entre pontos
int determinaQuadrante (pontos p); //Determina em qual quadrante esta localizado o ponto
int maior (pontos p);//Verifica se o x e maior que y e vice versa


int main()
{
	pontos a;
	//int x1, x2, y1, y2;
	int quadrante;
	float distancia;
	int opcao;

	//MENU//
	while (opcao != 0)
	{
		printf (
			"\n1-Ponto\n"
			"2-Ponto (Referencia)\n"
			"3-Ponto e quadrante\n"
			"4-Alterar o valor do ponto\n"
			"5-Retornar a distancia entre os pontos\n"
			"6-Retornar o maior valor de coordenada de um ponto\n"
			"0-Fecha o programa\n\n"
			);
		scanf ("%i", &opcao);

		switch (opcao)
		{
		case 0: return 0; break;
		case 1: a = lePonto(); break;
		case 2: a = lePontoReferencia(); break;
		case 3:
			a = lePonto();
			leQuadrante (&quadrante);
			if (quadrante == determinaQuadrante(a))
			{
				printf ("\nVerdadeiro!\n");
				break;
			}
			else
			{
				printf ("\nO quadrante fornecido nao corresponde ao quadrante real.\n");
				break;
			}
		case 4:
			alterar (&a);
			printf ("\nO novo valor de x: %i e y: %i\n", a.x1, a.y1);
		case 5:
			a = lePontoS();
			distancia = calculoDistancia(a);
			printf ("\nDistancia entre o ponto inicial e o final e %.2f\n", distancia);
			break;
		case 6:
			if (maior(a) == 0)
			{
				printf ("\nValores iguais\n");
			}
			else if (maior(a) == 1)
			{
				printf ("\nx: %i, e maior\n", a.x1);
			}
			else if (maior(a) == 2)
			{
				printf ("\ny: %i, e maior\n", a.y1);
			}
			else
			{
				printf ("\n ERROR \n");
			}
			break;
		}
	}
	return 0;
}

pontos lePonto ()
{
	pontos p;

	printf ("\nDigite o valor de x do ponto inicial: ");
	scanf ("%i", &p.x1);
	printf ("Digite o valor de y do ponto inicial: ");
	scanf ("%i", &p.y1);
	return p;
}

pontos lePontoS ()
{
	pontos p;

	printf ("\nDigite o valor de x do ponto inicial: ");
	scanf ("%i", &p.x1);
	printf ("Digite o valor de y do ponto inicial: ");
	scanf ("%i", &p.y1);
	printf ("\nDigite o valor de x do ponto inicial: ");
	scanf ("%i", &p.x2);
	printf ("Digite o valor de y do ponto inicial: ");
	scanf ("%i", &p.y2);
	return p;
}

pontos lePontoReferencia (int x1, int x2, int y1, int y2)
{
	pontos p;

	printf ("\nDigite o valor de x do ponto inicial: ");
	scanf ("%i", &p.x1);
	printf ("Digite o valor de y do ponto inicial: ");
	scanf ("%i", &p.y1);
	return p;
}

void leQuadrante(int *quadrante)
{
	printf ("Qual o quadrante do ponto inicial? ");
	scanf ("%i", quadrante);
}

void alterar (pontos *a)
{
	int op;
	printf ("\n Qual valor voce deseja alterar (1 para x e 2 para y): ");
	scanf ("%i", &op);

	switch (op)
	{
	case 0: printf ("Numero invalido."); break;
	case 1:
		printf ("Digite o novo valor de x: ");
		scanf ("%i", &a->x1);
		break;
	case 2:
		printf ("Digite o novo valor de y: ");
		scanf ("%i", &a->y1);
		break;
	}
}

float calculoDistancia (pontos p)
{
	float d;
	d = sqrt(pow(p.x2 - p.x1, 2) + pow(p.y2 - p.y1, 2));
	return d;
}

int determinaQuadrante (pontos p)
// 0 = origem, 1 = quadrante 1, 2 = quadrante 2, 3 = quadrante 3, 4 = quadrante 4, 5 = eixo x, 6 = eixo y
{
	if (p.x1 == 0 && p.y1 == 0)
	{
		return 0;
	}
	else if (p.x1 == 0)
	{
		return 5;
	}
	else if (p.y1 == 0)
	{
		return 6;
	}
	else if (p.x1 > 0 && p.y1 > 0)
	{
		return 1;
	}
	else if (p.x1 < 0 && p.y1 > 0)
	{
		return 2;
	}
	else if (p.x1 < 0 && p.y1 < 0)
	{
		return 3;
	}
	else if (p.x1 > 0 && p.y1 < 0)
	{
		return 4;
	}
	else
	{
		return 100;
	}
}

int maior (pontos p)
{
	if (p.x1 == p.y1)
	{
		return 0;
	}
	else if (p.x1 > p.y1)
	{
		return 1;
	}
	else if (p.x1 < p.y1)
	{
		return 2;
	}
	else
	{
		return 100;
	}
}
