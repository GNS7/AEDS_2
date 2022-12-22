// PILHA DINAMICA//

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
  int valor;

  struct elemento *proximo;
} elemento;

typedef struct fila
{
  elemento *comeco;
  elemento *fim;
} fila;

fila *criaFila();

void liberaFila(fila *f);

int emFila(fila *f, int temp);

int retiraFila(fila *f, int *temp);

int filaCheia(fila *f);

int filaVazia(fila *f);

int main()
{
  fila *f;

  int temp, inicio, escolha, descarte, r;

  while (inicio != 2) // loop inicial
  {
    printf(
        "\n1. Criar fila\n"
        "2. Sair\n");

    scanf("%d", &inicio);

    switch (inicio)

    {
    case 1:

      f = criaFila(); // cria fila (vetor e )
      do              // loop de escolha
      {
        printf(
            "\n1. Colocar na fila\n"             // emfila um novo numero
            "2. Retirar da fila\n"               // desemfila um numero
            "3. Conferir se a fila esta vazia\n" //
            "4. Conferir se a fila esta cheia\n" // N funciona
            "5. Liberar a fila e sair\n"         // volta para o switch inicial
        );

        scanf("%d", &escolha);

        switch (escolha)

        {
        case 1:

          printf("Digite o valor que quer colocar na fila: \n");

          scanf("%d", &temp);

          /*if (emFila(f, temp) == -1)

          {
            printf("A fila esta cheia\n");
          }*/

          if (emFila(f, temp) == 1)

          {
            printf("Numero adicionado: %i\n", temp);
          }

          else

          {
            printf("Error");
          }

          break;

        case 2:

          r = retiraFila(f, &descarte);
          if (r == -1)

          {
            printf("A fila esta vazia\n");
          }

          else if (r == 1)

          {
            printf("Numero %i retirado\n", descarte);
          }

          break;

        case 3:

          if (filaVazia(f) == 1)
          {
            printf("fila vazia\n");
          }

          else
          {
            printf("fila nao vazia\n");
          }
          break;

        /*case 4:
           if (filaCheia(p) == 1)
           {
           printf ("fila cheia\n");
           }
           else
           {
           printf ("fila nao Cheia\n");
           }
           break; */
        default:
          return 0;
          break;
        }
      } while (escolha != 6);

    case 2:
      return 0;
      break;
    }
  }

  return 0;
}

fila *criaFila()
{
  fila *f;

  f = (fila *)malloc(sizeof(fila));

  f->comeco = NULL;
  f->fim = NULL;

  return f;
}

void liberaFila(fila *f)
{
  while (f->comeco != NULL)

  {
    elemento *aux;

    aux = f->comeco;

    f->comeco = f->comeco->proximo;

    free(aux);
  }

  free(f);
}

int emFila(fila *f, int temp)
{
  elemento *novo = (elemento *)malloc(sizeof(elemento));

  if (novo == NULL)

  {
    printf("Erro na alocacao de memoria");

    system("pause");
    return 0;
  }

  else if (f->comeco == NULL)

  {
    novo->valor = temp;

    novo->proximo = f->fim;

    f->comeco = novo;
    f->fim = f->comeco;

    return 1;
  }

  else
  {
    novo->valor = temp;

    novo->proximo = f->fim->proximo;

    f->fim->proximo = novo;
    f->fim = novo;

    return 1;
  }
}

int retiraFila(fila *f, int *descarte)
{
  if (filaVazia(f) == 1)

  {
    return -1;
  }

  else

  {
    *descarte = f->comeco->valor;

    elemento *aux;

    aux = f->comeco;

    f->comeco = aux->proximo;

    free(aux);

    return 1;
  }
}

// int filaCheia (elemento n)
//{
//  if (n == NULL)
//{
// return 1;
// }
// else
//{
//  return 0;
//  }
//}

int filaVazia(fila *f)
{
  if (f->comeco == NULL)

  {
    return 1;
  }

  else

  {
    return 0;
  }
}