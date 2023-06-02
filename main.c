#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main(){
    int caso, n, i;

    printf("---Insira o tamanho do vetor---\n\n-->");
    scanf("%d", &n);

    int* vetor = (int*)malloc(n * sizeof(int));

    printf("\n---Insira os elementos do vetor---\n\n");
    for (i = 0; i < n; i++) {
      printf("-->");
        scanf("%d", &vetor[i]);
    }

    printf("\n---Escolha o método de ordenação---\n\n");
    printf("<-1-> Bubble Sort\n");
    printf("<-2-> Insertion Sort\n");
    printf("\n-->");
    scanf("%d", &caso);

    switch (caso) {
        case 1:
            Bolha(vetor, n);
            printf("\n---Vetor em ordem por Bubble Sort---\n\n==>");
            printVetor(vetor, n);
            break;
        case 2:
            insercao(vetor, n);
            printf("\n---Vetor por Insertion Sort---\n\n==>");
            printVetor(vetor, n);
            break;
        default:
            printf("\nOpção invalida.\n");
    }

    return 0;
}
