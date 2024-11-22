#include <iostream>
using namespace std;

const int SIZE = 3;

void printBoard(char board[SIZE][SIZE]) {
    cout << "\nTic-Tac-Toe\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---|---|---\n";
    }
}

bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move, try again.\n";
        }
    }
}

void playGame() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    printBoard(board);

    while (true) {
        playMove(board, player);
        printBoard(board);

        if (checkWin(board, player)) {
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (isBoardFull(board)) {
            cout << "It's a tie!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    playGame();
    return 0;
}
