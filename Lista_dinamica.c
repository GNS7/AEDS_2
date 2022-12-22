#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct lista
{
    Elemento *inicio;
} Lista;

Lista *inicializaLista();
void limpaLista(Lista *lista);
int listaVazia(Lista *lista);
int inserirItem(Lista *lista, int valor);
int inserirItemPosicao(Lista *lista, int valor, int posicao);
int removerItem(Lista *lista, int *valor);
int removerItemPosicao(Lista *lista, int *valor, int posicao);
void imprimirLista(Lista *lista);

int main()
{
    Lista *lista;
    int inicio, valor, posicao, escolha, temp, descarte;

    while (inicio != 2) // loop inicial
    {
        printf(
            "\n1. Criar lista\n"
            "2. Sair\n");

        scanf("%d", &inicio);

        switch (inicio)

        {
        case 1:

            lista = inicializaLista();
            if (lista == NULL || lista->inicio != NULL) // cria a lista
            {
                printf("Erro ao criar lista\n");
                return 0;
            }

            do // loop de escolha
            {
                printf(
                    "\n1. Colocar na lista\n"              // emlista um novo numero"
                    "2. Colocar na lista em uma posicao\n" // emlista um novo numero em uma posicao que o usuario escolher
                    "3. Retirar da lista\n"                // desemlista um numero
                    "4. Retirar da lista em uma posicao\n" // desemlista um numero em uma posicao que o usuario escolher
                    "3. Conferir se a lista esta vazia\n"  //
                    "4. Conferir se a lista esta cheia\n"  // N funciona
                    "5. Liberar a lista e sair\n"          // libera e sai do programa
                );

                scanf("%d", &escolha);

                switch (escolha)

                {
                case 1:

                    printf("Digite o valor que quer colocar na lista: \n");

                    scanf("%d", &temp);

                    int inserir = inserirItem(lista, temp);

                    if (inserir == 0)
                    {
                        printf("A lista esta cheia\n");
                    }
                    else if (inserir == 1)
                    {
                        printf("Numero adicionado: %i\n", temp);
                        imprimeLista(lista);
                    }
                    else
                    {
                        printf("Error");
                    }
                    break;

                case 2:

                    printf("Digite o valor que quer colocar na lista: \n");

                    scanf("%d", &temp);

                    printf("Digite a posicao que quer colocar na lista: \n");

                    scanf("%d", &posicao);

                    int inserirPosicao = inserirItemPosicao(lista, temp, posicao);

                    if (inserirPosicao == 0)
                    {
                        printf("A lista esta cheia\n");
                    }
                    else if (inserirPosicao == 1)
                    {
                        printf("Numero adicionado: %i\n", temp);
                        imprimeLista(lista);
                    }
                    else
                    {
                        printf("Error");
                    }
                    break;

                case 3:
                    printf(""); // da erro se declarar int antes do printf

                    int remover = removerItem(lista, &descarte);

                    if (remover == 0)
                    {
                        printf("A lista esta vazia\n");
                    }
                    else if (remover == 1)
                    {
                        printf("Numero %d retirado\n", descarte);
                        imprimeLista(lista);
                    }
                    else
                    {
                        printf("Error");
                    }
                    break;
                case 4:
                    printf("Digite a posicao que quer retirar da lista: \n");

                    scanf("%d", &posicao);

                    int removerPosicao = removerItemPosicao(lista, &descarte, posicao);

                    if (removerPosicao == 0)
                    {
                        printf("A lista esta vazia\n");
                    }
                    else if (removerPosicao == 1)
                    {
                        printf("Numero %d retirado\n", descarte);
                        imprimeLista(lista);
                    }
                    else
                    {
                        printf("Error");
                    }
                    break;

                default:
                    printf("Opcao invalida\n");
                    return 0;
                    break;
                }
            } while (1);

        case 2:
            return 0;
            break;
        }
    }

    return 0;
}

Lista *inicializaLista()
{
    Lista *l;

    l = (Lista *)malloc(sizeof(Lista));

    l->inicio = NULL;

    return l;
}

void limpaLista(Lista *l)
{
    l->inicio = NULL;
}

int inserirItem(Lista *l, int valor)
{
    Elemento *novo, *aux;
    novo = (Elemento *)malloc(sizeof(Elemento));

    if (novo == NULL) // verifica se a lista esta cheia
        return 0;

    novo->valor = valor;
    novo->proximo = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->proximo != NULL) // percorre a lista até o final
            aux = aux->proximo;
        aux->proximo = novo;
    }
    return 1;
}

int inserirItemPosicao(Lista *l, int valor, int posicao) ////////////////////////N Funciona
{
    Elemento *novo, *aux, *ant;
    int count = 0;

    novo = (Elemento *)malloc(sizeof(Elemento));

    if (novo == NULL) // verifica se a lista esta cheia
        return 0;

    novo->valor = valor;
    novo->proximo = NULL;
    if (posicao == 1)
    {
        novo->proximo = l->inicio->proximo;
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->proximo != NULL) // percorre a lista até o final
        {
            if (count == posicao - 2) // se a posicao for igual a posicao que o usuario escolheu4
            {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                return 1;
            }
            aux = aux->proximo;
            count++;
        }
        aux->proximo = novo; // se a posicao for maior que o tamanho da lista, adiciona na ultima posicao
    }
    return 1;
}

int removerItem(Lista *l, int *valor)
{
    Elemento *aux, *ant;

    if (l->inicio == NULL) // verifica se a lista esta vazia
        return 0;

    aux = l->inicio;
    while (aux->proximo != NULL) // percorre a lista até o final
    {
        ant = aux;
        aux = aux->proximo;
    }
    *valor = ant->proximo->valor;
    ant->proximo = NULL; // ant->proximo = aux = ultimo elemento da fila

    free(aux);
    return 1;
}

int removerItemPosicao(Lista *l, int *valor, int posicao)
{
    Elemento *aux, *ant;
    int i, count = 0, count_posicao = 0;

    if (l->inicio == NULL) // verifica se a lista esta vazia
        return 0;

    aux = l->inicio;
    while (aux->proximo != NULL) // percorre a lista até o final
    {
        aux = aux->proximo;
        count++;
    }
    if (posicao > count + 1) // verifica se a posicao é maior que o tamanho da lista
    {
        printf("Posicao invalida");
        return -1;
    }
    aux = l->inicio;  // RESET aux = primeiro elemento da lista
    if (posicao == 1) // se a posicao for igual a 1, remove o primeiro elemento
    {
        *valor = l->inicio->valor;
        l->inicio = aux->proximo;
        return 1;
    }
    else
    {
        while (aux->proximo != NULL) // percorre a lista até o final
        {
            if (count_posicao == posicao - 2) // se a posicao for igual a posicao que o usuario escolheu4
            {
                *valor = aux->proximo->valor;
                aux->proximo = aux->proximo->proximo;
                return 1;
            }
            aux = aux->proximo;
            count_posicao++;
            printf("%d", count_posicao);
        }
    }

    free(aux);
    return 1;
}

int listaVazia(Lista *l)
{
    if (l->inicio == NULL)
        return 1;
    else
        return 0;
}

void imprimeLista(Lista *l)
{
    Elemento *aux;
    aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}