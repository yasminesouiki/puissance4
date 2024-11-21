#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

void initializeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");
}

int dropDisc(char board[ROWS][COLS], int col, char disc) {
    if (col < 0 || col >= COLS) return 0;
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == '.') {
            board[i][col] = disc;
            return 1;
        }
    }
    return 0; 
}

int checkVictory(char board[ROWS][COLS], char disc) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == disc && board[i][j + 1] == disc &&
                board[i][j + 2] == disc && board[i][j + 3] == disc)
                return 1;
        }
    }
  
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == disc && board[i + 1][j] == disc &&
                board[i + 2][j] == disc && board[i + 3][j] == disc)
                return 1;
        }
    }
   
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == disc && board[i + 1][j + 1] == disc &&
                board[i + 2][j + 2] == disc && board[i + 3][j + 3] == disc)
                return 1;
        }
    }
   
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == disc && board[i + 1][j - 1] == disc &&
                board[i + 2][j - 2] == disc && board[i + 3][j - 3] == disc)
                return 1;
        }
    }
    return 0;
}

int main() {
    char board[ROWS][COLS];
    initializeBoard(board);

    char players[2] = {'X', 'O'};
    int currentPlayer = 0;
    int moves = 0;
    int maxMoves = ROWS * COLS;

    while (1) {
        printBoard(board);
        printf("Joueur %d (%c), choisissez une colonne (1-%d) : ", currentPlayer + 1, players[currentPlayer], COLS);

        int col;
        scanf("%d", &col);
        col -= 1; 

        if (dropDisc(board, col, players[currentPlayer])) {
            moves++;
            if (checkVictory(board, players[currentPlayer])) {
                printBoard(board);
                printf("Joueur %d (%c) gagne !\n", currentPlayer + 1, players[currentPlayer]);
                break;
            }
            if (moves == maxMoves) {
                printBoard(board);
                printf("Match nul !\n");
                break;
            }
            currentPlayer = 1 - currentPlayer;
        } else {
            printf("Colonne invalide ou pleine. Réessayez.\n");
        }
    }

    return 0;
}
