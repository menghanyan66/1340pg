#include "game1.h"
#include <iostream>


using namespace std;

void generatePuzzle(vector<string>& puzzle) {
    string chars = "123456789ABCDEF ";
    int size = chars.size();
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        int index = rand() % chars.size();
        puzzle.push_back(chars.substr(index, 1));
        chars.erase(index, 1);
    }
}

void displayPuzzle(const vector<string>& puzzle) {
    cout << "+----+----+----+----+" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "| ";
        for (int j = 0; j < 4; j++) {
            cout << puzzle[i * 4 + j] << " | ";
        }
        cout << endl << "+----+----+----+----+" << endl;
    }
}

bool checkPuzzle(const vector<string>& puzzle) {
    string target = "123456789ABCDEF ";
    return target == puzzle[0] + puzzle[1] + puzzle[2] + puzzle[3] +
                     puzzle[4] + puzzle[5] + puzzle[6] + puzzle[7] +
                     puzzle[8] + puzzle[9] + puzzle[10] + puzzle[11] +
                     puzzle[12] + puzzle[13] + puzzle[14] + puzzle[15];
}

void moveBlock(vector<string>& puzzle, int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
        return;
    }
    int index1 = y * 4 + x;
    int index2 = ny * 4 + nx;
    puzzle[index1].swap(puzzle[index2]);
}

void playgame1() {
    vector<string> puzzle;
    generatePuzzle(puzzle);
    displayPuzzle(puzzle);
    while (!checkPuzzle(puzzle)) {
        string input;
        cout << "Enter direction (up, down, left, right): ";
        cin >> input;
        int dx = 0;
        int dy = 0;
        if (input == "down") {
            dy = -1;
        } else if (input == "up") {
            dy = 1;
        } else if (input == "right") {
            dx = -1;
        } else if (input == "left") {
            dx = 1;
        } else {
            cout << "Invalid direction." << endl;
            continue;
        }
        int x = -1;
        int y = -1;
        for (int i = 0; i < 16; i++) {
            if (puzzle[i] == " ") {
                x = i % 4;
                y = i / 4;
                break;
            }
        }
        moveBlock(puzzle, x, y, dx, dy);
        displayPuzzle(puzzle);
    }
    cout << "Congratulations! You solved the puzzle." << endl;
}
