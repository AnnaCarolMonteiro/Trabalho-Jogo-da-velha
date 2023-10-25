#include <stdio.h>

void ImprimirTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int VerificarVitoriaX(char tabuleiro[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' && tabuleiro[i][2] == 'X') {
            return 1; 
        }
        if (tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i] == 'X') {
            return 1; 
        }
    }

    
    if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X') {
        return 1; 
    }
    if (tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X') {
        return 1; 
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

        printf("Tabuleiro atual:\n");
        ImprimirTabuleiro(tabuleiro);

        printf("Jogador X, informe a linha (0-2) e a coluna (0-2): ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = 'X';
        jogadas++;

        vitoria = VerificarVitoriaX(tabuleiro);

        if (vitoria) {
            printf("Jogador X venceu!\n");
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

