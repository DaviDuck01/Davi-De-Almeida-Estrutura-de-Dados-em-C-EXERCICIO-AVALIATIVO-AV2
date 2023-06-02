void Bolha(int vetor[], int n) {
    int b, s;
    for (b = 0; b < n - 1; b++) {
        for (s = 0; s < n - b - 1; s++) {
            if (vetor[s] > vetor[s + 1]) {
                int temp = vetor[s];
                vetor[s] = vetor[s + 1];
                vetor[s + 1] = temp;
            }
        }
    }
}

void insercao(int vetor[], int n) {
    int i, aux, c;
    for (i = 1; i < n; i++) {
        aux = vetor[i];
        c = i - 1;
        while (c >= 0 && vetor[c] > aux) {
            vetor[c + 1] = vetor[c];
            c = c - 1;
        }
        vetor[c + 1] = aux;
    }
}

void printVetor(int vetor[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
