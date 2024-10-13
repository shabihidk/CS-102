#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

void clearScreen() {
    // ANSI escape code to clear the screen
    cout << "\033[2J\033[1;1H";
}

void moveCursorTo(int x, int y) {
    // ANSI escape code to move the cursor
    cout << "\033[" << y << ";" << x << "H";
}

int main() {
    int x = 1;
    int y = 1;

    clearScreen();
    moveCursorTo(x, y);
    cout << "<3";

    while (x >= 0 && y >= 0) {
        if (_kbhit()) {
            char ch = _getch();

            if (ch == 'd') {
                x++;
            } else if (ch == 'a') {
                x--;
            } else if (ch == 'w') {
                y--;
            } else if (ch == 's') {
                y++;
            }

            clearScreen();
            moveCursorTo(x, y);

            if (ch == 'd') {
                cout << "-->"; // Right
            } else if (ch == 'a') {
                cout << "<--";
            } else if (ch == 'w') {
                cout << "^"; // Up
                moveCursorTo(x, y + 1);
                cout<< "|";
            } else if (ch == 's') {
            	cout<< "|";
            	moveCursorTo(x, y + 1);
                cout << "v"; // Down
            }
        }
    }

    return 0;
}

