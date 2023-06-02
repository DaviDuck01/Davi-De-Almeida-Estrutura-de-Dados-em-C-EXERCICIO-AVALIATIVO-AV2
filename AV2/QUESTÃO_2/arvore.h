//-------Estruturas e Métodos da Árvore (Letra C)-------
typedef struct NodeArvore {
    int dadosA;
    struct NodeArvore* esq;
    struct NodeArvore* dir;
} NodeArvore;

NodeArvore* inserir(NodeArvore* raiz, int dadosA) {
    if (raiz == NULL) {
        NodeArvore* newNode = (NodeArvore*)malloc(sizeof(NodeArvore));
        newNode->dadosA = dadosA;
        newNode->esq = NULL;
        newNode->dir = NULL;
        return newNode;
    } else {
        if (dadosA < raiz->dadosA) {
            raiz->esq = inserir(raiz->esq, dadosA);
        } else if (dadosA > raiz->dadosA) {
            raiz->dir = inserir(raiz->dir, dadosA);
        }
        return raiz;
    }
}

void imprimirArvore(NodeArvore* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->dir);
        printf("%d ", raiz->dadosA);
        imprimirArvore(raiz->esq);
    }
}

NodeArvore* buscaElemento(NodeArvore* raiz, int elemento) {
    if (raiz == NULL || raiz->dadosA == elemento) {
        return raiz;
    }

    if (elemento < raiz->dadosA) {
        return buscaElemento(raiz->esq, elemento);
    } else {
        return buscaElemento(raiz->dir, elemento);
    }
}

int encontrarMaiorElemento(NodeArvore* raiz) {
    if (raiz == NULL) {
        printf("--[Não há elementos na árvore]--\n");
        return -1;
    }
  else{
    
  }
  
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz->dadosA;
}
