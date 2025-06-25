#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char current_marker;
int current_player;

void reset_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int place_marker(int row, int col) {
    if (board[row][col] != ' ') {
        return 0;
    }
    board[row][col] = current_marker;
    return 1;
}

int check_winner() {
    // Check rows & columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == current_marker && board[i][1] == current_marker && board[i][2] == current_marker) ||
            (board[0][i] == current_marker && board[1][i] == current_marker && board[2][i] == current_marker))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == current_marker && board[1][1] == current_marker && board[2][2] == current_marker) ||
        (board[0][2] == current_marker && board[1][1] == current_marker && board[2][0] == current_marker))
        return 1;

    return 0;
}

void swap_player_and_marker() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    int row, col;
    int moves = 0;
    reset_board();

    current_marker = 'X';
    current_player = 1;

    printf("Tic-Tac-Toe Game\nPlayer 1: X\nPlayer 2: O\n");

    while (1) {
        print_board();
        printf("Player %d, enter row and column (1-3) to place %c: ", current_player, current_marker);
        scanf("%d %d", &row, &col);
        row--; col--;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (!place_marker(row, col)) {
            printf("Spot taken. Try another.\n");
            continue;
        }

        moves++;

        if (check_winner()) {
            print_board();
            printf("Player %d wins!\n", current_player);
            break;
        } else if (moves == 9) {
            print_board();
            printf("It's a draw!\n");
            break;
        }

        swap_player_and_marker();
    }

    return 0;
}