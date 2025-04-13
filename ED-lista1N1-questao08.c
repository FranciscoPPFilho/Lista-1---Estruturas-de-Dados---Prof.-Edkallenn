#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
** Função : Verifica se um número é um número de Armstrong
** Autor : Francisco Paulino
** Data : 08/04/2024
** Observações:
*/

bool eh_numero_armstrong(int n) {
    int original = n, soma = 0, digitos = 0;

    while (n > 0) {
        digitos++;
        n /= 10;
    }

    n = original;

    while (n > 0) {
        int digito = n % 10;
        soma += pow(digito, digitos);
        n /= 10;
    }

    return soma == original;
}

int main() {

    printf("Números de Armstrong entre 1 e 100:\n");
    for (int i = 1; i <= 100; i++) {
        if (eh_numero_armstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}