#include <stdio.h> // Biblioteca padrão de entrada e saída

/*
** Função : Potência Fatorial Crescente e Decrescente
** Autor : Francisco Paulino
** Data : 02/04/2024
** Observações: Precisa usar um compilador 64 bits para evitar overflow e rodar long long int
*/

// Função que calcula a potência fatorial crescente: x * (x + 1) * (x + 2) * ... * (x + n - 1)
long long int potencia_fatorial_crescente(int x, int n) {
    long long int resultado = 1; // Inicializa o resultado como 1
    for (int i = 0; i < n; i++) {
        resultado *= (x + i); // Multiplica pelo próximo número da sequência crescente
    }
    return resultado; // Retorna o resultado final
}

// Função que calcula a potência fatorial decrescente: x * (x - 1) * (x - 2) * ... * (x - n + 1)
long long int potencia_fatorial_decrescente(int x, int n) {
    long long int resultado = 1; // Inicializa o resultado como 1
    for (int i = 0; i < n; i++) {
        resultado *= (x - i); // Multiplica pelo próximo número da sequência decrescente
    }
    return resultado; // Retorna o resultado final
}

// Função que exibe e salva em arquivo uma tabela com x fixo (x = 5) e n variando de 2 a 10
void exibirTabelaXfixo(FILE *arquivo) {
    int x = 5; // Valor fixo de x

    printf("Tabela de Potencias Fatoriais: (x = %d)\n", x);
    printf("\n%-5s %-5s %-20s %-20s\n", "X", "N", "Crescente", "Decrescente");
    printf("--------------------------------------------\n");

    // Escreve o cabeçalho no arquivo
    fprintf(arquivo, "Tabela de Potencias Fatoriais: (x = %d)\n", x);
    fprintf(arquivo, "\n%-5s %-5s %-20s %-20s\n", "X", "N", "Crescente", "Decrescente");
    fprintf(arquivo, "--------------------------------------------\n");

    // Loop para n de 2 até 10
    for (int i = 2; i <= 10; i++) {
        // Imprime e salva os valores de x, n e os resultados das potências fatoriais
        printf("%-5d %-5d %-20lld %-20lld\n", x, i, potencia_fatorial_crescente(x, i), potencia_fatorial_decrescente(x, i));
        fprintf(arquivo, "%-5d %-5d %-20lld %-20lld\n", x, i, potencia_fatorial_crescente(x, i), potencia_fatorial_decrescente(x, i));
    }

    printf("--------------------------------------------\n");
    fprintf(arquivo, "--------------------------------------------\n");
}

// Função que exibe e salva em arquivo uma tabela com x e n variando de 2 a 10 (x = n)
void exibirTabelaXvariavel(FILE *arquivo) {
    printf("Tabela de Potencias Fatoriais: X variavel\n");
    printf("\n%-5s %-5s %-20s %-20s\n", "X", "N", "Crescente", "Decrescente");
    printf("--------------------------------------------\n");

    // Escreve o cabeçalho no arquivo
    fprintf(arquivo, "Tabela de Potencias Fatoriais: X variavel\n");
    fprintf(arquivo, "\n%-5s %-5s %-20s %-20s\n", "X", "N", "Crescente", "Decrescente");
    fprintf(arquivo, "--------------------------------------------\n");

    // Loop para x e n variando de 2 até 10
    for (int i = 2; i <= 10; i++) {
        // Imprime e salva os valores de x, n e os resultados das potências fatoriais
        printf("%-5d %-5d %-20lld %-20lld\n", i, i, potencia_fatorial_crescente(i, i), potencia_fatorial_decrescente(i, i));
        fprintf(arquivo, "%-5d %-5d %-20lld %-20lld\n", i, i, potencia_fatorial_crescente(i, i), potencia_fatorial_decrescente(i, i));
    }

    printf("--------------------------------------------\n");
    fprintf(arquivo, "--------------------------------------------\n");
}

int main() {
    // Abre o arquivo para escrita
    FILE *arquivo = fopen("Potencia Fatorial.txt", "w");

    // Verifica se houve erro ao abrir o arquivo
    if (arquivo == NULL) {
        printf("Erro para abrir o arquivo\n");
        return 1; // Encerra o programa com erro
    }

    // Chama as funções para gerar e exibir as tabelas
    exibirTabelaXfixo(arquivo);
    exibirTabelaXvariavel(arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados salvos em resultado.txt\n");

    return 0; 
}
