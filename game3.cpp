#include "game3.h"
#include <iostream>

using namespace std;

void playgame3() {
    const int MAX_TRIES = 7;
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry", "fig"};
    string word = words[rand() % words.size()];
    int numTries = 0;
    string guessedLetters;
    string correctLetters(word.length(), '_');

    cout << "Welcome to Hangman! The word has " << word.length() << " letters." << endl;

    while (numTries < MAX_TRIES && correctLetters != word) {
        cout << endl << "Guessed letters: " << guessedLetters << endl;
        cout << "Incorrect guesses left: " << MAX_TRIES - numTries << endl;
        cout << "Current word: " << correctLetters << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed " << guess << "!" << endl;
            continue;
        }

        guessedLetters += guess;

        if (word.find(guess) != string::npos) {
            cout << "Correct!" << endl;
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == guess) {
                    correctLetters[i] = guess;
                }
            }
        } else {
            cout << "Incorrect." << endl;
            numTries++;
        }
    }

    if (correctLetters == word) {
        cout << "Congratulations, you guessed the word \"" << word << "\"!" << endl;
    } else {
        cout << "Sorry, you ran out of guesses. The word was \"" << word << "\"." << endl;
    }

}
