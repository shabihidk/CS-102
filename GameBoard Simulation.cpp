#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GameBoard {
private:
    int Size;
    char Board[15][15];
    bool Player1Turn;

public:
    GameBoard(int size) {
        Size = size;
        Player1Turn = true;
        InitializeBoard();
    }

    void InitializeBoard() {
        for (int i = 0; i < Size; ++i) {
            for (int j = 0; j < Size; ++j) {
                Board[i][j] = ' ';
            }
        }
    }

    void DisplayBoard() {
        for (int i = 0; i < Size; ++i) {
            for (int j = 0; j < Size; ++j) {
                cout << Board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool IsValidMove(int row, int col) {
        return row >= 0 && row < Size && col >= 0 && col < Size && Board[row][col] == ' ';
    }

    void MakeMove(int row, int col, char symbol) {
        if (IsValidMove(row, col)) {
            Board[row][col] = symbol;
        } else {
            cout << "Invalid move! This cell is already occupied. Please try again." << endl;
        }
    }

    bool CheckWin(char symbol) {
        // Check rows and columns
        for (int i = 0; i < Size; ++i) {
            int rowCount = 0;
            int colCount = 0;

            for (int j = 0; j < Size; ++j) {
                if (Board[i][j] == symbol) {
                    rowCount++;
                } else {
                    rowCount = 0;
                }

                if (Board[j][i] == symbol) {
                    colCount++;
                } else {
                    colCount = 0;
                }

                if (rowCount == 5 || colCount == 5) {
                    return true;
                }
            }
        }

     
    void SwitchTurn() {
        Player1Turn = !Player1Turn;
    }

    void MakeBotMove() {
        int Row, Col;
        do {
            Row = rand() % Size;
            Col = rand() % Size;
        } while (!IsValidMove(Row, Col));

        MakeMove(Row, Col, 'O');
    }

    void StartGame() {
        while (true) {
            DisplayBoard();

            int Row, Col;
            char Symbol = (Player1Turn) ? 'X' : 'O';

if (Player1Turn) {
    cout << "Player " << ((Player1Turn) ? "1" : "2") << ", enter your move (row and column): \n";
    cout << "Row :: ";
    cin >> Row;
    cout << "Column :: ";
    cin >> Col;
    } else {
    cout << "Bot is making a move..." << endl;
    MakeBotMove();
            }
MakeMove(Row, Col, Symbol);

    if (CheckWin(Symbol)) {
    DisplayBoard();
    
    if (Player1Turn) {
        cout << "Player 1 is the winner!" << endl;
    } else {
        cout << "Player 2 is the winner!" << endl;
    }
    
    break;
}


            SwitchTurn();
        }
    }
};

int main() {
    srand(time(0));

    int BoardSize;
    cout << "Enter the board size (9 or 15): ";
    cin >> BoardSize;

    if (BoardSize != 9 && BoardSize != 15) {
        cout << "Invalid board size. Exiting the game." << endl;
        return 1;
    }

    GameBoard Game(BoardSize);
    Game.StartGame();

    return 0;
}

