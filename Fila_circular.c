//FILA CIRCULAR//
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct fila {
    int comeco;
    int fim;
    int tamanho;
    int vetor[MAX];

} fila;

fila *criaFila();

void liberafila(fila *f);

int emFila(fila *f, int temp);

int retiraFila(fila *f, int *temp);

int filaCheia(fila *f);

int filaVazia(fila *f);

int main() {
    fila *f;
    int temp, inicio, escolha;


    while (inicio != 2) // loop inicial
    {
        printf
                (
                        "\n1. Criar fila\n"
                        "2. Sair\n"
                );
        scanf("%d", &inicio);

        switch (inicio) {
            case 1:
                f = criaFila(); //cria fila (vetor e topo)
                do //loop de escolha
                {
                    printf
                            (
                                    "\n1. Enfileirar\n" //emfila um novo numero
                                    "2. Desenfileirar\n" //desemfila um numero
                                    "3. Conferir se a fila esta vazia\n" //
                                    "4. Conferir se a fila esta cheia\n" //
                                    "5. Liberar a fila\n" //
                                    "6. Sair\n" //volta para o switch inicial
                            );
                    scanf("%d", &escolha);

                    switch (escolha) {
                        case 1:
                            printf("Digite o valor que quer enfileirar: \n");
                            scanf("%d", &temp);
                            if (emFila(f, temp) == -1) {
                                printf("A fila esta cheia\n");
                            } else {
                                printf("Numero adicionado: %i\n", temp);
                            }
                            break;
                        case 2:
                            if (retiraFila(f, &temp) == -1) {
                                printf("A fila esta vazia\n");
                            } else {
                                printf("Numero %i retirado\n", temp);
                            }
                            break;
                        case 3:
                            if (filaVazia(f) == 1) {
                                printf("fila vazia\n");
                            } else {
                                printf("fila nao vazia\n");
                            }
                            break;
                        case 4:
                            if (filaCheia(f) == 1) {
                                printf("fila cheia\n");
                            } else {
                                printf("fila nao Cheia\n");
                            }
                            break;
                        case 5:
                            liberafila(f);
                            break;
                        case 6:
                            exit(0);
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

fila *criaFila() {
    fila *f;
    f = (fila *) malloc(sizeof(fila));
    f->comeco = 0;
    f->fim = 0;
    f->tamanho = 0;
    return f;
}

void liberafila(fila *f) {
    free(f);
}

int emFila(fila *f, int temp) {
    if (filaCheia(f) == 1) {
        return -1;
    } else {
        f->comeco = f->comeco % MAX;
        f->fim = f->fim % MAX;
        f->vetor[f->fim] = temp;
        f->fim += 1;
        f->tamanho += 1;
        return 1;
    }
}

int retiraFila(fila *f, int *temp) {
    if (filaVazia(f) == 1) {
        return -1;
    } else {
        *temp = f->vetor[f->comeco];
        f->comeco = f->comeco % MAX;
        f->fim = f->fim % MAX;
        f->comeco += 1;
        f->tamanho -= 1;
        return 1;
    }
}

int filaCheia(fila *f) {
    if (f->tamanho == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int filaVazia(fila *f) {
    if (f->tamanho == 0) {
        return 1;
    } else {
        return 0;
    }
}
