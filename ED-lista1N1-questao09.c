#include <stdio.h>
#include <stdbool.h>

/*
** Função : Verifica se um número é perfeito
** Autor : Francisco Paulino
** Data : 09/04/2024
** Observações:
*/

bool eh_numero_perfeito(int n) {
    if (n <= 1) return false;

    int soma = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma == n;
}

int main() {
    printf("Números perfeitos entre 1 e 100000:\n");
    for (int i = 1; i <= 100000; i++) {
        if (eh_numero_perfeito(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}