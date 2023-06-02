#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "arvore.h"

//-------Menu da Pilha-(Letra A)-------
void exibirMenuPilha() {
    printf("\n");
    printf("---[Escolha uma opção]---\n\n");
    printf("<-1-> Empilhar\n");
    printf("<-2-> Desempilhar\n");
    printf("<-3-> Imprimir Pilha\n");
    printf("<-4-> Limpar Pilha\n");
    printf("<-5-> Imprimir Topo da Pilha\n");
    printf("<-0-> Voltar ao menu principal\n\n-->");
}
//-------Menu da Fila-(Letra B)-------
void exibirMenuFila() {
    printf("\n");
    printf("---[Escolha uma opção]---\n\n");
    printf("<-1-> Enfileirar\n");
    printf("<-2-> Desenfileirar\n");
    printf("<-3-> Imprimir Fila\n");
    printf("<-4-> Limpar Fila\n");
    printf("<-5-> Maior elemento da Fila\n");
    printf("<-6-> Menor elemento da Fila\n");
    printf("<-0-> Voltar ao menu principal\n\n-->");
}
//-------Menu da Árvore-(Letra C)-------
void exibirMenuArvore() {
    printf("\n");  
    printf("---[Escolha uma opção]---\n\n");
    printf("<-1-> Inserir elemento\n");
    printf("<-2-> Imprimir Árvore (Direita-Raiz-Esquerda)\n");
    printf("<-3-> Buscar elemento na Árvore\n");
    printf("<-4-> Maior elemento da Árvore\n");
    printf("<-0-> Voltar ao menu principal\n\n-->");
}

int main() {
    int menuP = -1;
    int menuE = -1;

    Pilha pilha;
    Fila fila;
    NodeArvore* arvore = NULL;

    while (menuP != 0) {
        printf("\n");
       printf("---[Escolha uma opção]---\n\n");
        printf("<-1-> Executar Pilha\n");
        printf("<-2-> Executar Fila\n");
        printf("<-3-> Executar Árvore\n");
        printf("<-0-> Sair\n\n-->");
        scanf("%d", &menuP);

        switch (menuP) {
            case 1:
                inicioPilha(&pilha);
                menuE = -1;

                while (menuE != 0) {
                    exibirMenuPilha();
                    scanf("%d", &menuE);

                    switch (menuE) {
                        case 1: {
                            int dataP;
                            printf("\n");
                            printf("--[Insira o valor a ser empilhado]--\n-->");
                            scanf("%d", &dataP);
                            empilha(&pilha, dataP);
                            break;
                        }
                        case 2: {
                            int data = desempilha(&pilha);
                            if (data != -1) {
                                printf("\n");
                                printf("--[Elemento desempilhado]-- \n==>%d\n", data);
                            }
                            break;
                        }
                        case 3:
                            imprimirPilha(&pilha);
                            break;
                        case 4:
                            limparPilha(&pilha);
                            break;
                        case 5:
                            imprimirTopoPilha(&pilha);
                            break;
                        case 0:
                            printf("\n--[Retornando ao menu principal]--\n");
                            break;
                        default:
                            printf("\n<<ERRO>>\n");
                            break;
                    }
                }
                break;

            case 2:
                inicializarFila(&fila);
                menuE = -1;

                while (menuE != 0) {
                    exibirMenuFila();
                    scanf("%d", &menuE);

                    switch (menuE) {
                        case 1: {
                            int dataF;
                            printf("\n");
                            printf("--[Insira o valor a ser enfileirado]--\n-->");
                            scanf("%d", &dataF);
                            enqueue(&fila, dataF);
                            break;
                        }
                        case 2: {
                            int data = dequeue(&fila);
                            if (data != -1) {
                                printf("\n");
                                printf("--[Elemento desenfileirado]--\n==>%d\n", data);
                            }
                            break;
                        }
                        case 3:
                            imprimirFila(&fila);
                            break;
                        case 4:
                            limparFila(&fila);
                            break;
                        case 5: {
                            int maior = maiorDaFila(&fila);
                            printf("--[Maior elemento da Fila]--\n==>%d\n", maior);
                            break;
                        }
                        case 6: {
                            int menor = menorDaFila(&fila);
                            printf("--[Menor elemento da Fila]--\n==>%d\n", menor);
                            break;
                        }
                        case 0:
                            printf("--[Retornando ao menu principal]--\n");
                            break;
                        default:
                            printf("<<ERRO>>\n");
                            break;
                    }
                }
                break;

            case 3:
                menuE = -1;

                while (menuE != 0) {
                    exibirMenuArvore();
                    scanf("%d", &menuE);

                    switch (menuE) {
                        case 1: {
                            int dataA;
                            printf("--[Insira um valor na Árvore]--\n->");
                            scanf("%d", &dataA);
                            arvore = inserir(arvore, dataA);
                            break;
                        }
                        case 2:
                            printf("--[Elementos da Árvore (Direita-Raiz-Esquerda)]--\n==>");
                            imprimirArvore(arvore);
                            printf("\n");
                            break;
                        case 3: {
                            int elemento;
                            printf("--[Insira o elemento a ser buscado na Árvore]--\n-->");
                            scanf("%d", &elemento);
                            NodeArvore* resultado = buscaElemento(arvore, elemento);
                            if (resultado != NULL) {
                                printf("==>%d foi encontrado na Árvore.\n", elemento);
                            } else {
                                printf("=>%d não foi encontrado na Árvore.\n", elemento);
                            }
                            break;
                        }
                        case 4: {
                            int maior = encontrarMaiorElemento(arvore);
                            printf("--[Maior elemento da Árvore]--\n==>%d\n", maior);
                            break;
                        }
                        case 0:
                            printf("--[Retornando ao menu principal]--\n");
                            break;
                        default:
                            printf("<<ERRO>>\n");
                            break;
                    }
                }
                break;

            case 0:
                printf("--[Encerrando.]--\n");
                break;

            default:
                printf("<<ERRO>>\n");
                break;
        }
    }

    return 0;
}
