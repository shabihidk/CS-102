#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Gameboard {
private:
    const int SIZE_MAX;
    int WINNING_COUNT;
    char board[15][15];
    int boardSize;

    bool isValidMove(int row, int col) {
    return (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ');
    }

    bool isGameOver(char player) const {
        for (int i = 0; i < boardSize; ++i) {
int row_count = 0, col_count = 0;
    for (int j = 0; j < boardSize; ++j) {
    if (board[i][j] == player && ++row_count == WINNING_COUNT) {
        return true;
               }
    if (board[j][i] == player && ++col_count == WINNING_COUNT) {
        return true;
                }
            }
        }
        return false;
    }

    bool isBoardFull() const {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    bool makeMove(char player, int row, int col) {
        if (!isValidMove(row, col)) {
            cout << "Invalid move! Try again." << endl;
            return false;
        }
        board[row][col] = player;
        return true;
    }

public:
Gameboard(int size, int winningCount) : SIZE_MAX(15), WINNING_COUNT(winningCount), boardSize(size) {
for (int i = 0; i < boardSize; ++i) {
for (int j = 0; j < boardSize; ++j) {
  board[i][j] = ' ';
            }
        }
    }

void displayBoard() const {
for (int i = 0; i < boardSize; ++i) {
for (int j = 0; j < boardSize; ++j) {
cout << board[i][j] << " ";
            }
cout << endl;
        }
    }
    void playAgainstBot() {
        srand(time(0));

char currentPlayer = 'X';
int row, col;

while (true) {
displayBoard();

if (currentPlayer == 'X') {
cout << "Player X's turn:" << endl;
    cout << "Enter row and column (e.g., 0 1): ";
cin >> row >> col;
} else {
cout << "Player O's turn (Bot):" << endl;
row = rand() % boardSize;
col = rand() % boardSize;
cout << "Bot chooses: " << row << " " << col << endl;
            }

if (makeMove(currentPlayer, row, col)) {
        if (isGameOver(currentPlayer)) {
        displayBoard();
        cout << "Player " << currentPlayer << " wins!" << endl;
        break;
        } else if (isBoardFull()) {
        displayBoard();
    cout << "It's a tie!" << endl;
    break;
                }

if (currentPlayer == 'X') {
    currentPlayer = 'O';
} else {
currentPlayer = 'X';
}
}
}
 }


   void playAgainstPlayer() {
    char currentPlayer = 'X';
    int row, col;

while (true) {
     displayBoard();

    cout << "Player " << currentPlayer << "'s turn:" << endl;
    cout << "Enter row and column (e.g., 0 1): ";
          cin >> row >> col;

    if (makeMove(currentPlayer, row, col)) {
        if (isGameOver(currentPlayer)) {
        displayBoard();
        cout << "Player " << currentPlayer << " wins!" << endl;
               break;
    } else if (isBoardFull()) {
                    displayBoard();
                    cout << "It's a tie!" << endl;
                    break;
                }

if (currentPlayer == 'X') {
    currentPlayer = 'O';
} else {currentPlayer = 'X';
}
} } }
};

int main() {
    cout << "Enter the board size (between 9 and 15): ";
    int boardSize;
    cin >> boardSize;

    if (boardSize < 9 || boardSize > 15) {
        cout << "Invalid board size. Exiting." << endl;
        return 1;
    }

    cout << "Enter the winning count: ";
    int winningCount;
    cin >> winningCount;

    Gameboard game(boardSize, winningCount);

    cout << "Choose game mode:" << endl;
    cout << "1. Play against Bot" << endl;
    cout << "2. Play against Player 2" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            game.playAgainstBot();
            break;
        case 2:
            game.playAgainstPlayer();
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            return 1;
    }

    return 0;
}

