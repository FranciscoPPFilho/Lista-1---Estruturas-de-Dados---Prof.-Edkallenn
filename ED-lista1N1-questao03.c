#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdbool.h> // Biblioteca para usar o tipo booleano (true/false)

/*
** Função : Verifica se dois números são amigáveis e encontra pares amigáveis até um limite n
** Autor : Francisco Paulino
** Data : 03/04/2024
** Observações:
*/

// Função que verifica se dois números são amigáveis
bool saoAmigaveis(int a, int b) {
    int somaDivA = 0, somaDivB = 0;

    // Calcula e exibe os divisores próprios de 'a' (exclui o próprio número)
    printf("Divisores de %d: ", a);
    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            printf("%d ", i);
            somaDivA += i; // Soma dos divisores de 'a'
        }
    }
    printf("\nSoma dos divisores de %d: %d\n", a, somaDivA);

    // Calcula e exibe os divisores próprios de 'b'
    printf("Divisores de %d: ", b);
    for (int i = 1; i < b; i++) {
        if (b % i == 0) {
            printf("%d ", i);
            somaDivB += i; // Soma dos divisores de 'b'
        }
    }
    printf("\nSoma dos divisores de %d: %d\n", b, somaDivB);

    // Verifica se são amigáveis: soma dos divisores de um é igual ao outro e vice-versa
    if (somaDivA == b && somaDivB == a && a != b) {
        printf("%d e %d sao numeros amigaveis!\n", a, b);
        return true;
    } else {
        printf("%d e %d nao sao numeros amigaveis.\n", a, b);
        return false;
    }
}

// Função que encontra todos os pares de números amigáveis até o limite 'n'
void encontrarParesAmigaveis(int n) {
    printf("\nProcurando pares amigaveis até %d...\n", n);
    
    for (int a = 1; a <= n; a++) {
        int somaDivA = 0;

        // Calcula a soma dos divisores próprios de 'a'
        for (int i = 1; i < a; i++) {
            if (a % i == 0) {
                somaDivA += i;
            }
        }

        // Verifica se a soma dos divisores é maior que 'a' e dentro do limite
        if (somaDivA > a && somaDivA <= n) {
            int somaDivB = 0;

            // Calcula a soma dos divisores próprios do número encontrado (somaDivA)
            for (int i = 1; i < somaDivA; i++) {
                if (somaDivA % i == 0) {
                    somaDivB += i;
                }
            }

            // Verifica se os dois números são amigáveis
            if (somaDivB == a) {
                printf("\nPar amigavel encontrado: (%d, %d)\n", a, somaDivA);
                saoAmigaveis(a, somaDivA); // Chama função para exibir detalhes
            }
        }
    }
}

int main() {
    int opcao, num1, num2, n;

    // Menu de opções para o usuário
    printf("Escolha uma opcao:\n");
    printf("1 - Verificar se dois numeros sao amigaveis\n");
    printf("2 - Encontrar todos os pares amigaveis ate um limite n\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            // Verificação de dois números fornecidos pelo usuário
            printf("Digite dois numeros separados por espaco: ");
            scanf("%d %d", &num1, &num2);
            saoAmigaveis(num1, num2);
            break;
        case 2:
            // Encontra todos os pares até um limite 'n'
            printf("Digite o valor limite n: ");
            scanf("%d", &n);
            encontrarParesAmigaveis(n);
            break;
        default:
            // Opção inválida
            printf("Opcao invalida!\n");
    }

    return 0; // Fim do programa
}
