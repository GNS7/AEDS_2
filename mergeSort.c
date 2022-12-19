#include <stdio.h>
#include <stdlib.h>

void mergeSort (int v[], int n);
void intercala (int v[], int n);

int main()
{
    int vetor[10], opcao;

    for (int i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 50; //gera numeros aleatorios entre 0 e 50
    }

    for (int i = 0; i < 10; i++)
    {
        printf ("%d ", vetor[i]); //imprime o vetor desordenado
    }
 
    printf (
            "\nDigite 1 para ordenar o vetor" 
            "\nDigite 2 para sair\n"
            );
    scanf ("%d", &opcao);

    switch (opcao)
    {
        case 1: 
            mergeSort(vetor, 10);  //chama a funcao mergeSort
            for (int i = 0; i < 10; i++)
            {
                printf ("%d ", vetor[i]); 
            }
            break;
        case 2: exit(0);break;
        default: printf ("Numero invalido\n"); return 0;break;

    }
    return 0;
}


void intercala (int v[], int n)
{
    int tmp[n]; //vetor temporario
    int meio = n/2; //meio do vetor
    int i = 0; //contador
    int j = meio; //contador
    int k = 0; //contador

    while (i < meio && j < n) //enquanto i e j forem menores que o meio e o tamanho do vetor
    {
        if (v[i] <= v[j]) //se o valor de v[i] for menor ou igual ao valor de v[j]
        {
            tmp[k] = v[i]; //o vetor temporario recebe o valor de v[i]
            i++;
        }
        else
        {
            tmp[k] = v[j]; //o vetor temporario recebe o valor de v[j]
            j++;
        }
        k++;
    }

    if (i == meio) //se i for igual ao meio
    {
        while (j < n) //enquanto j for menor que o tamanho do vetor
        { 
            tmp[k] = v[j]; //o vetor temporario recebe o valor de v[j]
            j++;
            k++;
        }
    }
    else
    {
        while (i < meio) //enquanto i for menor que o meio
        {
            tmp[k] = v[i]; //o vetor temporario recebe o valor de v[i]
            i++;
            k++;
        }

    }

    for (i = 0; i < n; i++)
    {
        v[i] = tmp[i]; //o vetor recebe o valor do vetor temporario
    }

}

void mergeSort (int v[], int n)
{
    int meio;
    if (n > 1) //se o tamanho do vetor for maior que 1
    {
        meio = n/2; //meio recebe o tamanho do vetor dividido por 2
        mergeSort (v, meio); //chama a funcao mergeSort, ordena o arranjo ate o meio
        mergeSort (v + meio, n - meio); //chama a funcao mergeSort ordena o arranjo a partir do meio
        intercala (v, n); //chama a funcao intercala para intercalar os arranjos ordenados anteriormente
    }
}

