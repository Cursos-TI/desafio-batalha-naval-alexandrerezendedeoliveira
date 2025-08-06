#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3   // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM]; // Matriz 10x10 representando o tabuleiro
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ------------------------------
    // Posicionando o NAVIO HORIZONTAL
    // ------------------------------

    // Coordenadas iniciais: linha 2, coluna 4 (índice 1,3)
    int linhaH = 1;
    int colunaH = 3;

    // Verifica se cabe horizontalmente
    if (colunaH + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites.\n");
        return 1;
    }

    // ------------------------------
    // Posicionando o NAVIO VERTICAL
    // ------------------------------

    // Coordenadas iniciais: linha 5, coluna 6 (índice 4,5)
    int linhaV = 4;
    int colunaV = 5;
    int sobreposicao = 0;

    // Verifica se cabe verticalmente
    if (linhaV + TAM_NAVIO <= TAM) {
        // Verifica se há sobreposição com o navio horizontal
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: sobreposição entre navios detectada.\n");
            return 1;
        }

    } else {
        printf("Erro: navio vertical fora dos limites.\n");
        return 1;
    }

    // ------------------------------
    // Exibindo o tabuleiro no console
    // ------------------------------

    printf("\nTABULEIRO BATALHA NAVAL:\n");
    printf("   ");

    // Imprime o cabeçalho de colunas A-J
    for (j = 0; j < TAM; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Imprime as linhas numeradas com conteúdo do tabuleiro
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
