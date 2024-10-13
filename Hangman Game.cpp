#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayHangman(int attemptsLeft) {
    switch (attemptsLeft) {
        case 6:
            cout << "\n Attempts left: 6" << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 5:
            cout << "\n Attempts left: 5" << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |     " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 4:
            cout << "\n Attempts left: 4" << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 3:
            cout << "\n Attempts left: 3" << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |    |" << endl;
            cout << " |" << endl;
            break;
        case 2:
            cout << "\n Attempts left: 2" << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|\\" << endl;
            cout << " |" << endl;
            break;
        case 1:
            cout << "\n Attempts left: 1" << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|\\" << endl;
            cout << " |   /" << endl;
            break;
        case 0:
            cout << "\n Attempts left: 0" << endl << endl;
            cout << "  ____" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   /|\\" << endl;
            cout << " |   / \\" << endl;
            break;
    }
}

int main() {
    string words[] = {"pakistan", "india", "canada", "america", "hungary"};
    srand(time(NULL));
    string word = words[rand() % 5];
    string displayWord(word.length(), '_');
    string guessedLetters = "";
    int attemptsLeft = 6;

    cout << "Welcome to Hangman! \n Rules are simple! Guess one character right and it reveals itself to you! If you guess wrong, you lose an attempt! \n GOOD LUCK" << endl;

    while (attemptsLeft > 0) {
        cout << "==> Current status: " << displayWord << endl;
        cout << "==> Guessed letters: " << guessedLetters << endl;

        displayHangman(attemptsLeft);

        char guess;
        cout << " -> Attempts left: " << attemptsLeft << endl;
        cout << " -> Guess a letter: ";
        cin >> guess;

        bool alreadyGuessed = false;
       for (size_t i = 0; i < guessedLetters.length(); ++i) {
    if (guessedLetters[i] == guess) {
        cout << "\n _______________ ERROR: _______________\n!! You already guessed that letter. !! \n Try Again: " << endl;
        alreadyGuessed = true;
        break;
    }
}


        if (alreadyGuessed) {
            continue;
        }

        guessedLetters += guess;
        bool found = false;

        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                displayWord[i] = guess;
                found = true;
            }
        }

        if (!found) {
            attemptsLeft--;
            cout << "\n ----- That letter is not in the word. ------ \n" << endl;
        }

        if (displayWord == word) {
            cout << "\n +++++++++++ Congratulations! You guessed the word: +++++++++++++ \n" << "::::::::: " << word << ":::::::::::"<< endl;
            return 0;
        }
    }

    cout << "\n !!!! Uh oh! You ran out of attempts. The word was: \n " << word << endl;
    return 0;
}

