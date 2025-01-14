#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include "ordenacao.h"

void reinicia_vetor(int vetor[], int tam) {
    for (ssize_t i = 0; i < tam; i++) {
        vetor[i] = tam - i; 
    }
}

void imprime_vetor(int vetor[], int tam) {
    for (ssize_t  i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp;
    clock_t start,end;
    ssize_t tamVetor = 2000;
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria."); 
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
    printf("\n");


    printf("Insertion Sort iterativo:\n"); 
    reinicia_vetor(vetor, tamVetor);
    start = clock();
    uint64_t comparacoes = insertionSort(vetor, tamVetor);
    end = clock();
    double total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);
    printf("Comparações: %lu\n", comparacoes);
    printf("Vetor ordenado: ");
    imprime_vetor(vetor, tamVetor);
    printf("\n");

    printf("Insertion Sort Recursivo:\n");
    reinicia_vetor(vetor, tamVetor);
    start = clock();
    comparacoes = insertionSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);
    printf("Comparações: %lu\n", comparacoes);
    printf("Vetor ordenado: ");
    imprime_vetor(vetor, tamVetor);
    printf("\n");

    printf("Selection Sort iterativo:\n");
    reinicia_vetor(vetor, tamVetor);
    start = clock();
    comparacoes = selectionSort(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);
    printf("Comparações: %lu\n", comparacoes);
    printf("Vetor ordenado: ");
    imprime_vetor(vetor, tamVetor);
    printf("\n");

    printf("Selection Sort Recursivo:\n");
    reinicia_vetor(vetor, tamVetor);
    start = clock();
    comparacoes = selectionSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);
    printf("Comparações: %lu\n", comparacoes);
    printf("Vetor ordenado: ");
    imprime_vetor(vetor, tamVetor);
    printf("\n");

    printf("Merge Sort Recursivo:\n");
    reinicia_vetor(vetor, tamVetor);
    start = clock();
    comparacoes = mergeSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);
    printf("Comparações: %lu\n", comparacoes);
    printf("Vetor ordenado: ");
    imprime_vetor(vetor, tamVetor);
    printf("\n");

    printf("Busca Sequencial (ingênua) iterativa:\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaSequencial(vetor, tamVetor, 80, &numComp);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("índice: %zd, Comparações: %lu\n", idxBusca, numComp);
    printf("Tempo total: %f\n\n", total);

    printf("Busca Sequencial (ingênua) recursiva:\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaSequencialRec(vetor, tamVetor, 80, &numComp);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("índice: %zd, Comparações:%lu\n", idxBusca, numComp);
    printf("Tempo total: %f\n\n", total);

    printf("Busca binária iterativa:\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, 80, &numComp);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("índice: %zd, Comparações: %lu\n", idxBusca, numComp);
    printf("Tempo total: %f\n\n", total);

    printf("Busca binária recursiva:\n");
    numComp = 0;
    start = clock();
    idxBusca = buscaBinariaRec(vetor, tamVetor, 80, &numComp);
    end = clock();
    total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("índice: %zd, Comparações: %lu\n", idxBusca, numComp);
    printf("Tempo total: %f\n\n", total);

    free(vetor);
    return 0;
}