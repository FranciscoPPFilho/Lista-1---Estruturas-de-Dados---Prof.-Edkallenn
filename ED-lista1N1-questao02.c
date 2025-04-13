#include <stdio.h> // Biblioteca padrão de entrada e saída

/*
** Função : Fatorial Duplo e Normal
** Autor : Francisco Paulino
** Data : 02/04/2024
** Observações: Precisa usar um compilador 64bits para evitar overflow e rodar long long int
*/

// Função que calcula o fatorial duplo de um número
// Se n for ímpar: n * (n-2) * (n-4) * ... * 1
// Se n for par:  n * (n-2) * (n-4) * ... * 2
long long int fatorial_duplo(int n) {
    long long resultado = 1;

    if (n % 2 != 0) { // Caso ímpar
        for (int i = 1; i <= n; i += 2) {
            resultado *= i;
        }
        return resultado;
    } else { // Caso par
        for (int i = 2; i <= n; i += 2) {
            resultado *= i;
        }
        return resultado;
    }
}

// Função recursiva que calcula o fatorial normal de um número (n!)
long long int fatorial_normal(int n) {
    if (n == 0 || n == 1) {
        return 1; // Casos base
    }
    return n * fatorial_normal(n - 1); // Chamada recursiva
}

// Função que mostra e grava a tabela com os fatoriais normais e duplos
void mostrar_tabela(FILE *arquivo, long long *array_fatorial_duplo, long long *array_fatorial_normal) {
    // Cabeçalhos da tabela
    printf("%-15s %-25s %-25s\n", "N", "Fatorial Normal", "Fatorial Duplo");
    printf("----------------------------------------------------------------------------------------------\n");

    fprintf(arquivo, "%-15s %-25s %-25s\n", "N", "Fatorial Normal", "Fatorial Duplo");
    fprintf(arquivo, "----------------------------------------------------------------------------------------------\n");

    // Loop de 2 a 20 para calcular e exibir os fatoriais
    for (int i = 2; i <= 20; i++) {
        array_fatorial_normal[i - 2] = fatorial_normal(i); // Armazena o fatorial normal
        array_fatorial_duplo[i - 2] = fatorial_duplo(i);   // Armazena o fatorial duplo

        // Exibe na tela e grava no arquivo
        printf("%-15d %-25lld %-25lld\n", i, array_fatorial_normal[i - 2], array_fatorial_duplo[i - 2]);
        fprintf(arquivo, "%-15d %-25lld %-25lld\n", i, array_fatorial_normal[i - 2], array_fatorial_duplo[i - 2]);
    }

    // Linha final da tabela
    printf("----------------------------------------------------------------------------------------------\n");
    fprintf(arquivo, "----------------------------------------------------------------------------------------------\n");
}

// Função que mostra e grava a tabela com a diferença entre os fatoriais
void mostrar_tabela_diferenca(FILE *arquivo, long long *array_fatorial_duplo, long long *array_fatorial_normal) {
    // Cabeçalhos da tabela
    printf("%-15s %-25s %-25s %-25s\n", "N", "Fatorial Normal", "Fatorial Duplo", "Diferenca");
    printf("----------------------------------------------------------------------------------------------\n");

    fprintf(arquivo, "%-15s %-25s %-25s %-25s\n", "N", "Fatorial Normal", "Fatorial Duplo", "Diferença");
    fprintf(arquivo, "----------------------------------------------------------------------------------------------\n");

    // Loop de 2 a 20 para calcular e exibir a diferença
    for (int i = 2; i <= 20; i++) {
        long long diff = array_fatorial_normal[i - 2] - array_fatorial_duplo[i - 2]; // Calcula a diferença

        // Exibe na tela e grava no arquivo
        printf("%-15d %-25lld %-25lld %-25lld\n", i, array_fatorial_normal[i - 2], array_fatorial_duplo[i - 2], diff);
        fprintf(arquivo, "%-15d %-25lld %-25lld %-25lld\n", i, array_fatorial_normal[i - 2], array_fatorial_duplo[i - 2], diff);
    }

    // Linha final da tabela
    printf("----------------------------------------------------------------------------------------------\n");
    fprintf(arquivo, "----------------------------------------------------------------------------------------------\n");
}

int main () {
    // Vetores para armazenar os valores dos fatoriais
    long long array_fatorial_duplo[19], array_fatorial_normal[19];

    // Abre o arquivo para escrita
    FILE *arquivo = fopen("Tabela Fatorial.txt", "w");

    if (arquivo == NULL) { // Verifica erro de abertura
        printf("Erro para abrir o arquivo\n");
        return 1;
    }

    // Gera as tabelas
    mostrar_tabela(arquivo, array_fatorial_duplo, array_fatorial_normal);
    mostrar_tabela_diferenca(arquivo, array_fatorial_duplo, array_fatorial_normal);

    // Fecha o arquivo
    fclose(arquivo);

    return 0; 
}
