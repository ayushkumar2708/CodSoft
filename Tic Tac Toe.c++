#include <iostream>
using namespace std;

char board[3][3]; 
char currentPlayer = 'X';


void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j; 
}


void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool makeMove(int cell) {
    if (cell < 1 || cell > 9) return false;
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') return false;
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
   
    for (int i = 0; i < 3; i++)
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}


bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}


int main() {
    initializeBoard();
    int move;

    cout << "Welcome to Tic Tac Toe!\n";
    printBoard();

    while (true) {
        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> move;

        if (!makeMove(move)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        printBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
