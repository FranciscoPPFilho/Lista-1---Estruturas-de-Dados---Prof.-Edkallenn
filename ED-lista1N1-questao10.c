#include <stdio.h>
#include <stdlib.h>

/*
** Função : Calcula os números de Fibonacci até um valor máximo
** Autor : Francisco Paulino
** Data : 12/04/2024
** Observações:
*/

int* fibonacci_max(int max) {
    if (max < 0) {
        return NULL; // Retorna NULL se o valor de max for inválido
    }

    // Aloca memória inicial para o array
    int capacity = 10; // Capacidade inicial
    int* fib_array = (int*)malloc(capacity * sizeof(int));
    if (fib_array == NULL) {
        return NULL; // Retorna NULL se a alocação falhar
    }

    int a = 0, b = 1, next = 0, count = 0;

    // Adiciona os números de Fibonacci ao array
    while (next <= max) {
        if (count >= capacity) {
            // Realoca memória se necessário
            capacity *= 2;
            int* temp = (int*)realloc(fib_array, capacity * sizeof(int));
            if (temp == NULL) {
                free(fib_array);
                return NULL; // Retorna NULL se a realocação falhar
            }
            fib_array = temp;
        }
        fib_array[count++] = next;
        a = b;
        b = next;
        next = a + b;
    }

    // Adiciona o marcador de posição especial (-1)
    if (count >= capacity) {
        int* temp = (int*)realloc(fib_array, (capacity + 1) * sizeof(int));
        if (temp == NULL) {
            free(fib_array);
            return NULL;
        }
        fib_array = temp;
    }
    fib_array[count] = -1;

    return fib_array;
}

int main() {
    int max;
    printf("Digite o valor máximo: ");
    scanf("%d", &max);

    int* fib_array = fibonacci_max(max);
    if (fib_array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Números de Fibonacci menores ou iguais a %d:\n", max);
    for (int i = 0; fib_array[i] != -1; i++) {
        printf("%d ", fib_array[i]);
    }
    printf("\n");

    free(fib_array); // Libera a memória alocada
    return 0;
}