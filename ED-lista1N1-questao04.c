#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Para uso de malloc/realloc/free
#include <math.h>    // Para uso da função pow()

/*
** Função : Verifica se um número é automórfico
** Autor : Francisco Paulino
** Data : 05/04/2024
** Observações:
*/

// Função que verifica se um número é automórfico
// Um número é automórfico se o quadrado dele termina com os mesmos dígitos do número original
int eh_automorfico(int n) {
    int quadrado = n * n;

    int temp = n;
    int digitos = 0;

    // Conta quantos dígitos tem o número original
    while (temp > 0) {
        digitos++;
        temp /= 10;
    }

    // Gera 10^digitos, para isolar os últimos dígitos do quadrado
    int potencia = pow(10, digitos);

    // Verifica se os últimos dígitos do quadrado são iguais ao número original
    if (quadrado % potencia == n) {
        return 1; // É automórfico
    }

    return 0; // Não é automórfico
}

int main() {
    int n;

    // Solicita um número ao usuário
    printf("Digite um número inteiro positivo maior que 2: ");
    scanf("%d", &n);

    // Valida a entrada
    if (n < 2) {
        printf("Número inválido. Deve ser maior que 2.\n");
        return 1;
    }

    // Ponteiro para armazenar os números automórficos encontrados
    int *automorficos = NULL;
    int tamanho = 0;

    // Percorre os números de 2 até n
    for (int i = 2; i <= n; i++) {
        if (eh_automorfico(i)) {
            // Realoca espaço no vetor a cada novo número automórfico
            automorficos = realloc(automorficos, (tamanho + 1) * sizeof(int));

            // Verifica se houve erro na alocação de memória
            if (automorficos == NULL) {
                printf("Erro de alocação de memória.\n");
                return 1;
            }

            // Adiciona o número automórfico ao vetor
            automorficos[tamanho] = i;
            tamanho++;
        }
    }

    // Exibe os números automórficos encontrados
    printf("Números automórficos entre 2 e %d:\n", n);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", automorficos[i]);
    }
    printf("\n");

    // Libera a memória alocada dinamicamente
    free(automorficos);

    return 0;
}
