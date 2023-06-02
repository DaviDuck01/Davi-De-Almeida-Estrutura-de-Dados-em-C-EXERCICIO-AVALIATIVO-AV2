//-------Estruturas e Métodos da Fila (Letra B)-------
typedef struct NoFi {
    int dadosF;
    struct NoFi* prox;
} NoFi;

typedef struct Fila{
    NoFi* frent;
    NoFi* tras;
} Fila;

void inicializarFila(Fila* fila) {
    fila->frent = NULL;
    fila->tras = NULL;
}

void enqueue(Fila* fila, int dadosF) {
    NoFi* newNode = (NoFi*)malloc(sizeof(NoFi));
    newNode->dadosF = dadosF;
    newNode->prox = NULL;

    if (fila->tras == NULL) {
        fila->frent = newNode;
        fila->tras = newNode;
    } else {
        fila->tras->prox = newNode;
        fila->tras = newNode;
    }
}

int dequeue(Fila* fila) {
    if (fila->frent == NULL) {
        printf("--[Não há elementos na Fila.]--\n");
        return -1;
    }

    NoFi* temp = fila->frent;
    int dadosF = temp->dadosF;
    fila->frent = fila->frent->prox;
    if (fila->frent == NULL) {
        fila->tras = NULL;
    }
    free(temp);
    return dadosF;
}

void imprimirFila(Fila* fila) {
    printf("--[Elementos da Fila]--\n==>");
    NoFi* current = fila->frent;
    while (current != NULL) {
        printf("%d ", current->dadosF);
        current = current->prox;
    }
    printf("\n");
}

void limparFila(Fila* fila) {
    while (fila->frent != NULL) {
        NoFi* temp = fila->frent;
        fila->frent = fila->frent->prox;
        free(temp);
    }
    fila->tras = NULL;
    printf("--[A fila foi limpa]--\n");
}

int maiorDaFila(Fila* fila) {
    if (fila->frent == NULL) {
        printf("--[Não há elementos na Fila.]--\n");
        return -1;
    }

    int max = fila->frent->dadosF;
    NoFi* current = fila->frent->prox;
    while (current != NULL) {
        if (current->dadosF > max) {
            max = current->dadosF;
        }
        current = current->prox;
    }
    return max;
}

int menorDaFila(Fila* fila) {
    if (fila->frent == NULL) {
        printf("--[Não há elementos na Fila.]--\n");
        return -1;
    }

    int min = fila->frent->dadosF;
    NoFi* current = fila->frent->prox;
    while (current != NULL) {
        if (current->dadosF < min) {
            min = current->dadosF;
        }
        current = current->prox;
    }
    return min;
}
