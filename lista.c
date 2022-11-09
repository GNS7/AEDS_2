#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct lista {
	int fim;
	int vetor[MAX];
} lista;


lista* criaLista ();
void liberaLista (lista *l);
int inserirListaFim (lista *l, int v);
int inserirListaPosicao (lista *l, int v, int p);
int retirarListaFim (lista *l, int *v);
int retirarListaPosicao (lista *l, int *v, int p);
int recuperarItemChave (lista *l, int *v);
int recuperarItemPosicao (lista *l, int p);
int listaCheia (lista *l);
int listaVazia (lista *l);
void imprimirLista (lista *l);

int main() {
	lista *l;
	int escolha, inicio, temp, posicaoTemp, inserirPosicao, retirarPosicao;

	while (inicio != 2) // loop inicial
	{
		printf
		(
			"\n1. Criar lista\n"
			"2. Sair\n"
		);
		scanf ("%d", &inicio);

		switch (inicio)
		{
		case 1:
			l = criaLista(); //cria lista (vetor e fim)
			do //loop de escolha
			{
				printf
				(
					"\n1. Emlistar\n" //emlista um novo numero
                    "2. Emlistar Posicao\n" //emlista um novo numero
					"3. Desemlistar\n" //desemlista um numero
                    "4. Desemlistar posicao\n" //desemlista um numero
					"5. Conferir se a lista esta vazia\n" //
					"6. Conferir se a lista esta cheia\n" //
					"7. Recuperar item por chave\n"
					"8. Recuperar item por posicao\n"
					"9. Liberar a lista\n" //
                    "10. Imprimir lista\n" //
					"11. Sair\n" //volta para o switch inicial
                    "12. Quantidade de items\n"
				);
				scanf  ("%d", &escolha);

				switch (escolha)
				{
				case 1:
					printf ("Digite o valor que quer emlistar: \n");
					scanf ("%d", &temp);

					if (inserirListaFim (l, temp) == -1)
					{
						printf ("A lista esta cheia\n");
					}
					else
					{
						printf ("Numero adicionado: %i\n", temp);
					}
					break;
                case 2:
                    printf ("Digite o valor que quer emlistar: \n");
					scanf ("%d", &temp);
                    printf ("Digite a posicao desse valor\n");
                    scanf ("%d", &posicaoTemp);
					
					inserirPosicao = inserirListaPosicao (l, temp, posicaoTemp);
					if (inserirPosicao == -1)
					{
						printf ("A lista esta cheia\n");
					}
					else if (inserirPosicao == 0)
					{
						printf ("Posicao invalida\n");
					}
					else
					{
						printf ("Numero adicionado: %i na posicao: %d\n", temp, posicaoTemp);
					}
					break;
				case 3:
					if (retirarListaFim (l, &temp) == -1)
                    {
                        printf ("A lista esta vazia\n");
                    }
                    else
                    {
                        printf ("Numero %i retirado\n", temp);
                    }
					break;
                case 4:
                    printf ("Digite a posicao do valor que quer retirar\n");
                    scanf ("%d", &posicaoTemp);
                    
					retirarPosicao = retirarListaPosicao(l, &temp, posicaoTemp);
                    if (retirarPosicao == -1)
                    {
                        printf("Lista vazia\n");
                    }
                    else if (retirarPosicao == 0)
                    {
                        printf ("posicao invalida");
                    }
                    else
                    {
                        printf ("valor retirado: %d\n", temp);
                    }
                    break;
                    
				case 5:
					if (listaVazia (l) == 1)
					{
						printf ("Lista vazia\n");
					}
					else
					{
						printf ("Lista nao vazia\n");
					}
					break;
				case 6:
					if (listaCheia(l) == 1)
					{
						printf ("Lista cheia\n");
					}
					else
					{
						printf ("Lista nao Cheia\n");
					}
					break;
				case 7:
				    printf ("Digite o valor a ser recuperado\n");
				    scanf("%d", &temp);
				    posicaoTemp = recuperarItemChave (l, &temp);
				    if (posicaoTemp == -1)
				    {
				    	printf ("item nao encontrado");
					}
					else
					{
						printf("O valor esta na posicao: %d\n", posicaoTemp);
					}
				    break;
				case 8:
				    printf ("A posicao do valor a ser recuperado\n");
				    scanf ("%d", &posicaoTemp);
				    temp = recuperarItemPosicao (l, posicaoTemp);
				    if (temp == -1)
				    {
				    	printf ("posicao invalida");
					}
					else 
					{
						printf ("O valor recuperado foi: %d\n", temp);
					}
				    break;
				case 9:
					liberaLista (l);
					break;
                case 10:
                    imprimirLista (l);
                    break;
				case 11:
					exit (0);
					break;
                case 12:
                printf ("fim: %i\n", l->fim);
                }
            } while (escolha != 9);

            case 2: return 0; break;
		}
	}
	return 0;
}


lista* criaLista ()
{
	lista *l;
	l = (lista *) malloc (sizeof (lista));
	l->fim = 0;
	return l;
}

void liberaLista (lista *l)
{
	free (l);
}

int inserirListaFim (lista *l, int v)
{
	if (listaCheia(l) == 1)
	{
		return -1;
	}
	else
	{
		l->vetor[l->fim] = v;
		l->fim++;
		return 1;
	}
}

int inserirListaPosicao (lista *l, int v, int p)
{
	if (listaCheia(l) == 1)
	{
		return -1;
	}
	else
	{
		if (p-1 > l->fim || p-1 < 0)
		{
			return 0;
		}
        for (int i = l->fim; i > p-1; i--)
        {
            int aux = l->vetor[i];
            l->vetor[i] = l->vetor[i-1];
            l->vetor[i+1] = aux;
        }
        l->vetor[p-1] = v;
        l->fim++;
        
		return 1;
	}
}

int retirarListaFim (lista *l, int *v)
{
	if (listaVazia(l) == 1)
	{
		return -1;
	}
    *v = l->vetor[l->fim-1];
	l->fim -= 1;

	return 1;
}

int retirarListaPosicao (lista *l, int *v, int p)
{
	if (listaVazia(l) == 1)
	{
		return -1;
	}
	else
	{
		if (p-1 < l->fim || p-1 < 0)
		{
			*v = l->vetor[p-1];
	        for (int i = p-1; i < MAX - (p-1); i++)
	        {
	            l->vetor[i] = l->vetor[i+1];
        	}
		}
		else
		{
			return 0;
		}
	}
	l->fim--;
	return 1;
}

int recuperarItemChave (lista *l, int *v)
{
    int p;
    for (int i = 0; i < MAX; i++)
    {
        if (l->vetor[i] == *v)
        {
            p = i;
            return ++p;
        }
    }
    return -1;
}

int recuperarItemPosicao (lista *l, int p)
{   
	int v;
    for (int i = 0; i < l->fim; i++)
    {
        if (i == p - 1)
        {
        	int v = l->vetor[p-1];
           	return v;
        }
    }
    return -1;
}

void imprimirLista (lista *l)
{
    for (int i = 0; i < l->fim; i++)
    {
    	printf ("\n");
        printf ("%d ", l->vetor[i]);
        printf ("\n");
    }
}

int listaCheia (lista *l)
{
	if (l->fim < MAX) //fix sizeof (p->vetor)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int listaVazia (lista *l)
{
	if (l->fim <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}