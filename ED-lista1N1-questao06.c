#include <stdio.h>
#include <stdbool.h>

/*
** Função : Verifica se um número é um número de Carmichael
** Autor : Francisco Paulino
** Data : 05/04/2024
** Observações:
*/

// Função para calcular o máximo divisor comum (MDC)
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular a^b % n usando exponenciação modular
int exponenciacao_modular(int a, int b, int n) {
    int resultado = 1;
    a = a % n;
    while (b > 0) {
        if (b % 2 == 1) {
            resultado = (resultado * a) % n;
        }
        b = b / 2;
        a = (a * a) % n;
    }
    return resultado;
}

// Função para verificar se um número é um número de Carmichael
bool verificar_numero_carmichael(int n) {
    if (n < 2) return false;

    // Um número de Carmichael não pode ser primo
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n == i) return false;
        }
    }

    // Verificar a propriedade de Carmichael
    for (int a = 2; a < n; a++) {
        if (mdc(a, n) == 1) {
            if (exponenciacao_modular(a, n - 1, n) != 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    printf("Números de Carmichael de 2 até %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (verificar_numero_carmichael(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}