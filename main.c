#include <stdio.h>

void ImprimirTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int VerificarVitoria(char tabuleiro[3][3], char jogador) {
    // Verifica se o jogador venceu nas linhas, colunas e diagonais
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1; // Vitória nas linhas
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1; // Vitória nas colunas
        }
    }

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1; // Vitória na diagonal principal
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1; // Vitória na diagonal secundária
    }

    return 0;
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int jogadas = 0;
    int vitoria = 0;

    printf("Jogo da Velha\n");

    while (jogadas < 9) {
        int linha, coluna;
        char jogador = (jogadas % 2 == 0) ? 'X' : 'O';

        printf("Tabuleiro atual:\n");
        ImprimirTabuleiro(tabuleiro);

        printf("Jogador %c, informe a linha (0-2) e a coluna (0-2): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador;
        jogadas++;

        vitoria = VerificarVitoria(tabuleiro, jogador);

        if (vitoria) {
            printf("Jogador %c venceu!\n", jogador);
            break;
        }
    }

    if (!vitoria) {
        printf("Empate!\n");
    }

    printf("Tabuleiro final:\n");
    ImprimirTabuleiro(tabuleiro);

    return 0;
}
