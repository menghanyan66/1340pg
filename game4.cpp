#include "game4.h"
#include <iostream>

using namespace std;

bool contains(const string &word, char letter) {
    return word.find(letter) != string::npos;
}

void displayHangman(int attempts) {
    cout << "  _______" << endl;
    cout << "  |/    |" << endl;

    if (attempts < 6) cout << "  |     O" << endl;
    else cout << "  |      " << endl;

    if (attempts < 5) {
        if (attempts < 4) {
            cout << "  |    /|\\" << endl;
        } else {
            cout << "  |    /|" << endl;
        }
    } else {
        cout << "  |      " << endl;
    }

    if (attempts < 3) {
        if (attempts < 2) {
            cout << "  |    / \\" << endl;
        } else {
            cout << "  |    /" << endl;
        }
    } else {
        cout << "  |      " << endl;
    }

    cout << "  |" << endl;
    cout << "__|__" << endl;
    cout << endl;
}

void playHangman() {
    vector<string> easy_words;
    easy_words.push_back("cat");
    easy_words.push_back("dog");
    easy_words.push_back("bat");

    vector<string> medium_words;
    medium_words.push_back("apple");
    medium_words.push_back("banana");
    medium_words.push_back("cherry");

    vector<string> hard_words;
    hard_words.push_back("pineapple");
    hard_words.push_back("strawberry");
    hard_words.push_back("grapefruit");

    vector<vector<string> > words;
    words.push_back(easy_words);
    words.push_back(medium_words);
    words.push_back(hard_words);

    cout << "Welcome to Hangman!" << endl;
    cout << "In this game, you need to guess the secret word one letter at a time." << endl;
    cout << "You have a limited number of attempts to guess the word, so choose your guesses wisely!" << endl << endl;

    int difficulty;
    cout << "Please choose a level of difficulty (1 - easy, 2 - medium, 3 - hard): ";
    cin >> difficulty;

    while (difficulty < 1 || difficulty > 3) {
        cout << "Invalid input. Please choose a valid level of difficulty (1 - easy, 2 - medium, 3 - hard): ";
        cin >> difficulty;
    }

    srand(time(0));
    string chosenWord = words[difficulty - 1][rand() % words[difficulty - 1].size()];

    string guessedWord(chosenWord.size(), '_');
    int attempts = 6;
    string guessedLetters;

    while (attempts > 0 && guessedWord != chosenWord) {
        char guess;
        displayHangman(attempts);
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Guessed word: " << guessedWord << endl;
        cout << "Guessed letters: " << guessedLetters << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        if (contains(guessedLetters, guess)) {
            cout << "You've already guessed that letter. Try again." << endl;
        } else if (contains(chosenWord, guess)) {
            for (size_t i = 0; i < chosenWord.size(); ++i) {
                if (chosenWord[i] == guess) {
                    guessedWord[i] = guess;
                }
            }
            guessedLetters += guess;
        } else {
            guessedLetters += guess;
            attempts--;
            cout << "Incorrect guess. Try again." << endl;
        }
    }

    displayHangman(attempts);

    if (guessedWord == chosenWord) {
        cout << "Congratulations! You've guessed the word: " << chosenWord << endl;
    } else {
        cout << "Sorry, you ran out of attempts. The word was: " << chosenWord << endl;
    }

}
