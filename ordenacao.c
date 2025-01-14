#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include <string.h>

void getNome(char nome[]) {
    strncpy(nome, "Matheus Gastal Magalhães", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] = '\0';
}

uint32_t getGRR() { return 20244620; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    for (ssize_t  i = 0; i < tam; i++) {
        (*numComparacoes)++;
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    if (tam == 0) {
        return -1;
    }
    (*numComparacoes)++;

    if (vetor[0] == valor) {
        return 0;
    }

    ssize_t resultado = buscaSequencialRec(vetor + 1, tam - 1, valor, numComparacoes);

    if (resultado == -1) {
        return -1;
    } else {
        return resultado + 1;
    }
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    ssize_t valmax = tam - 1;
    ssize_t  valmin = 0;
    ssize_t valormedio;

    while (valmin <= valmax) {
        valormedio = (valmax + valmin) / 2;
        (*numComparacoes)++;

        if (vetor[valormedio] < valor) {
          valmin = valormedio + 1;
        } else if (vetor[valormedio] > valor) {
            valmax = valormedio - 1;
        } else {
            return valormedio;
        }
    }
    return -1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    ssize_t  valmin = 0;
    ssize_t  valmax = tam - 1;

    if (valmin > valmax) {
        return -1;
    }

    (*numComparacoes)++;
    ssize_t  valormedio = (valmin + valmax) / 2;

    if (vetor[valormedio] == valor) {
        return valormedio;
    }

    if (vetor[valormedio] < valor) {
        ssize_t resultado = buscaBinariaRec(vetor + valormedio + 1, tam - (valormedio + 1), valor, numComparacoes);
        if (resultado != -1) {
            return resultado + (valormedio + 1);
        }
    } else {
        ssize_t resultado = buscaBinariaRec(vetor, valormedio, valor, numComparacoes);
        return resultado;
    }

    return -1;
}

uint64_t selectionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    for (ssize_t i = 0; i < tam; i++) {
        ssize_t indiceminimo = i;
        for (ssize_t j = i + 1; j < tam; j++) {
            if (vetor[j] < vetor[indiceminimo]) {
                indiceminimo = j;
            }
            numComparacoes++;
        }

        if (indiceminimo != i) {
            ssize_t  temp = vetor[i];
            vetor[i] = vetor[indiceminimo];
            vetor[indiceminimo] = temp;
        }
    }
    return numComparacoes;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    if (tam <= 1) {
        return 0;
    }

    uint64_t numComparacoes = 0;
    ssize_t maximo = tam - 1;

    for (ssize_t i = tam - 2; i >= 0; i--) {
        if (vetor[i] > vetor[maximo]) {
            maximo = i;
        }
        numComparacoes++;
    }

    ssize_t  temp = vetor[tam - 1];
    vetor[tam - 1] = vetor[maximo];
    vetor[maximo] = temp;

    numComparacoes += selectionSortRec(vetor, tam - 1);
    return numComparacoes;
}

uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    for (ssize_t  i = 1; i < tam; i++) {
        ssize_t  aux = vetor[i];
        ssize_t  j = i - 1;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j--;
            numComparacoes++;
        }
        vetor[j + 1] = aux;
        numComparacoes++;
    }
    return numComparacoes;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    if (tam <= 1) {
        return 0;
    }

    uint64_t numComparacoes = insertionSortRec(vetor, tam - 1);
    ssize_t  aux = vetor[tam - 1];
    ssize_t  j = tam - 2;

    while (j >= 0 && vetor[j] > aux) {
        vetor[j + 1] = vetor[j];
        j--;
        numComparacoes++;
    }
    vetor[j + 1] = aux;

    return numComparacoes + 1;
}



uint64_t mergeSortRec(int vetor[], size_t tam) {
    if (tam < 2) {
        return 0;
    }

    uint64_t numComparacoes = 0;
    ssize_t  meio = tam / 2;

    numComparacoes += mergeSortRec(vetor, meio);
    numComparacoes += mergeSortRec(vetor + meio, tam - meio);

    int *temp = malloc(tam * sizeof(int));
    if (temp == NULL) {
        printf("Falha ao alocar memória para o vetor temporário.\n");
        return -1;
    }

    ssize_t  i = 0, j = meio, k = 0;

    while (i < meio && j < tam) {
        if (vetor[i] <= vetor[j]) {
            temp[k] = vetor[i];
            i++;
            k++;
        } else {
            temp[k] = vetor[j];
            j++;
            k++;
        }
        numComparacoes++;
    }

    while (i < meio) {
        temp[k] = vetor[i];
        i++;
        k++;
    }

    while (j < tam) {
        temp[k] = vetor[j];
        j++;
        k++;
    }

    for (i = 0; i < tam; i++) {
        vetor[i] = temp[i];
    }
    free(temp); 
    return numComparacoes;
}

