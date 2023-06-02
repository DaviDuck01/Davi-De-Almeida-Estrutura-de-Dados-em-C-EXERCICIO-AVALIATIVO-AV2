//-------Estruturas e Métodos da Pilha (Letra A)-------
typedef struct NoPi {
    int dadosP;
    struct NoPi* prox;
} NoPi;

typedef struct Pilha {
    NoPi* topo;
} Pilha;


void inicioPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

void empilha(Pilha* pilha, int dadosP) {
    NoPi* newNode = (NoPi*)malloc(sizeof(NoPi));
    newNode->dadosP
    = dadosP
    ;
    newNode->prox = pilha->topo;
    pilha->topo = newNode;
}

int desempilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n");
        printf("--[Não há elementos na pilha.]--\n");
        return -1;
    }

    NoPi* temp = pilha->topo;
    int dadosP
= temp->dadosP
;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return dadosP
    ;
}

void imprimirPilha(Pilha* pilha) {
    printf("\n");
    printf("--[Elementos da Pilha]--\n==>");
    NoPi* current = pilha->topo;
    while (current != NULL) {
        printf("%d ", current->dadosP
        );
        current = current->prox;
    }
    printf("\n");
}

void limparPilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        NoPi* temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(temp);
    }
    printf("\n--[A Pilha foi limpa]--\n");
}

void imprimirTopoPilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n");
        printf("--[Não há elementos na pilha.]--\n");
    } else {
        printf("\n");
        printf("--[Topo da pilha]-- \n==>%d\n", pilha->topo->dadosP
        );
    }
}
