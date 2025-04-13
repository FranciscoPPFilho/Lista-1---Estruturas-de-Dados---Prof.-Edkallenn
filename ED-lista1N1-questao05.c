#include <stdio.h>

/*
** Função : Calcula a soma dos inversos dos fatoriais de 1 até n
** Autor : Francisco Paulino
** Data : 05/04/2024
** Observações:
*/

// Função que calcula a soma: 1/1! + 1/2! + 1/3! + ... + 1/n!
double soma_fatoriais_inversos(int n) {
    double soma = 0.0;     // Variável acumuladora da soma
    int fatorial = 1;      // Inicializa o fatorial com 1 (pois 1! = 1)

    for (int i = 1; i <= n; i++) {
        fatorial *= i;     // Calcula o fatorial de i
        soma += 1.0 / fatorial; // Adiciona o inverso do fatorial à soma
    }

    return soma;           // Retorna o resultado final
}

int main() {
    int n;

    // Solicita ao usuário um número inteiro positivo
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    // Validação básica da entrada
    if (n < 1) {
        printf("Número inválido. Digite um inteiro maior ou igual a 1.\n");
        return 1;
    }

    // Chama a função e imprime o resultado com 10 casas decimais
    double resultado = soma_fatoriais_inversos(n);
    printf("Soma dos fatoriais inversos até %d: %.10f\n", n, resultado);

    return 0;
}
