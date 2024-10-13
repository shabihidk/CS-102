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
    GameBoard(int size) : Size(size), Player1Turn(true) {
    InitializeBoard();
    }

    void InitializeBoard() {
    for (int i = 0; i < Size; ++i) {
    for (int j = 0; j < Size; ++j) {
    Board[i][j] = ' ';}
}
}

   void DisplayBoard() {
    for (int i = 0; i < Size; ++i) {
    for (int j = 0; j < Size; ++j) {
            
		char currentSymbol = Board[i][j];

            if (currentSymbol == ' ') {
                cout << " ";
            } else if (currentSymbol == 'X' || currentSymbol == 'O') {
                cout << currentSymbol << " ";
        }
        }
        cout << endl;
    }
}

}

    bool IsValidMove(int row, int col) {
    if (row >= 0 && row < Size && col >= 0 && col < Size && Board[row][col] == ' ')
    {
	return true; //ensures that the values entered are in the parameters and that they are not repeated in one line
    }
}
    void MakeMove(int row, int col, char symbol) {
    if (IsValidMove(row, col)) {
    Board[row][col] = symbol;
        }
    }

    bool CheckWin(char symbol) {
    for (int i = 0; i < Size; ++i) {
    bool RowWin = true;
    bool ColWin = true;
    for (int j = 0; j < Size; ++j) {
    if (Board[i][j] != symbol) {
    RowWin = false;
    }
    if (Board[j][i] != symbol) {
    ColWin = false;
    }
    }
    if (RowWin || ColWin) {
    return true;
            }
        }

    bool Diag1Win = true;
    bool Diag2Win = true;
for (int i = 0; i < Size; ++i) {
    if (Board[i][i] != symbol) {
                Diag1Win = false;
            }
if (Board[i][Size - 1 - i] != symbol) {
        Diag2Win = false;
            }
        }
        if (Diag1Win || Diag2Win) {
            return true;
        }

        return false;
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
                cout << "Player " << ((Player1Turn) ? "1" : "2") << " wins!" << endl;
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

