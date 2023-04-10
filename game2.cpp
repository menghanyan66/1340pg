#include "game2.h"
#include <iostream>

using namespace std;

struct Game {
    int numberToGuess;
    int triesLeft;
};

void playGame(Game* game) {
    // Generate a random number between 1 and 100
    srand(time(NULL));
    game->numberToGuess = rand() % 100 + 1;
    
    // Reset the number of tries
    game->triesLeft = 10;
    
    // Loop until the player runs out of tries or guesses the number correctly
    while (game->triesLeft > 0) {
        int guess;
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        
        // Check if the guess is correct
        if (guess == game->numberToGuess) {
            cout << "Congratulations, you guessed the number!" << endl;
            return;
        }
        // If the guess is incorrect, tell the player if their guess was too high or too low
        else if (guess > game->numberToGuess) {
            cout << "Your guess is too high." << endl;
        }
        else {
            cout << "Your guess is too low." << endl;
        }
        
        // Decrement the number of tries left
        game->triesLeft--;
        cout << "You have " << game->triesLeft << " tries left." << endl;
    }
    
    // If the player runs out of tries, they lose the game
    cout << "Sorry, you have run out of tries. The number was " << game->numberToGuess << "." << endl;
}

void playgame2() {
    // Allocate memory for the game struct
    Game* game = new Game;
    
    // Play the game
    playGame(game);
    
    // Free the memory allocated for the game struct
    delete game;
    
}
