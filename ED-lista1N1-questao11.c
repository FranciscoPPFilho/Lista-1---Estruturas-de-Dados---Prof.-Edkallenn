#include <stdio.h>
#include <stdlib.h>

/*
** Função : Verifica se um número é um número de Carmichael
** Autor : Francisco Paulino
** Data : 12/04/2024
** Observações:
*/

// Função auxiliar para verificar se dois arrays são iguais
int arrays_iguais(int *a, int *b, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

// Função para verificar se um array é uma permutação circular de outro
int permutacao_circular(int *array1, int *array2, int tamanho) {
    // Aloca dinamicamente um array temporário para armazenar a concatenação de array1 com ele mesmo
    int *temp = malloc(2 * tamanho * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 0;
    }

    // Concatena array1 com ele mesmo no array temporário
    for (int i = 0; i < tamanho; i++) {
        temp[i] = array1[i];
        temp[i + tamanho] = array1[i];
    }

    // Verifica se array2 é uma sublista de temp
    for (int i = 0; i < tamanho; i++) {
        if (arrays_iguais(temp + i, array2, tamanho)) {
            free(temp); // Libera a memória alocada
            return 1;
        }
    }

    free(temp); // Libera a memória alocada
    return 0;
}

// Função principal para teste
int main() {
    int array1[] = {1, 2, 3, 4};
    int array2[] = {3, 4, 1, 2};
    int tamanho = 4;

    if (permutacao_circular(array1, array2, tamanho)) {
        printf("Os arrays são permutações circulares.\n");
    } else {
        printf("Os arrays não são permutações circulares.\n");
    }

    return 0;
}