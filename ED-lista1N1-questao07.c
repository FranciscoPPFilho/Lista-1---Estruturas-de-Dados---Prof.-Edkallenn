#include <stdio.h>
#include <stdbool.h>

/*
** Função : Verifica se um número é feliz
** Autor : Francisco Paulino
** Data : 06/04/2024
** Observações:
*/

#define MAX_VISITED 1000

int soma_dos_quadrados_dos_digitos(int n) {
    int soma = 0;
    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

bool eh_numero_feliz(int n) {
    int visitados[MAX_VISITED] = {0};
    int indice = 0;

    while (n != 1) {
        for (int i = 0; i < indice; i++) {
            if (visitados[i] == n) {
                return false; 
            }
        }
        if (indice < MAX_VISITED) {
            visitados[indice++] = n;
        }
        n = soma_dos_quadrados_dos_digitos(n);
    }
    return true; 
}

int main() {
    int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1;
    }

    if (eh_numero_feliz(numero)) {
        printf("%d é um número feliz!\n", numero);
    } else {
        printf("%d não é um número feliz.\n", numero);
    }

    return 0;
}