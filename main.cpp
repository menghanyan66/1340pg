#include "game1.h"
#include "game2.h"
#include "game3.h"
#include "game4.h"
#include "game5.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Define a function to read a single character of input without waiting for the user to press enter
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) {
        perror("tcsetattr()");
    }
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) {
        perror("tcsetattr ICANON");
    }
    if (read(0, &buf, 1) < 0) {
        perror("read()");
    }
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror("tcsetattr ~ICANON");
    }
    return buf;
}


int main()
{
    // Define the maze as a 2D character array
    char maze[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', '4', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', '1', ' ', '#', ' ', ' ', '2', '#', '#'},
        {'#', '#', '#', ' ', '#', '#', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#'},
        {'#', '3', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '5', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', 'F', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
    };

    // Set the starting position
    int x = 1;
    int y = 1;

    // Draw the initial maze
    system("clear");
    cout << "Welcome to the maze game!" << endl;
    cout << "the maze will shown below and useing asdw to change the direction you are @" << endl;
    cout << "S is start position, and your destination is F" << endl;
    cout << "the number on the road are some puzzle you need to solve, best wishes!" << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    // Loop until the user reaches the end of the maze
    while (maze[x][y] != '#') {
        // Read a key from the user
        char key = getch();

        // Move the player in the corresponding direction
        switch (key) {
            case 'w':
                if (maze[x - 1][y] != '#') {
                    x--;
                }
                break;
            case 's':
                if (maze[x + 1][y] != '#') {
                    x++;
                }
                break;
            case 'a':
                if (maze[x][y - 1] != '#') {
                    y--;
                }
                break;
            case 'd':
                if (maze[x][y + 1] != '#') {
                    y++;
                }
                break;
        }

        if (maze[x][y] == '1'){
            playgame1();
        }
        else if (maze[x][y] == '2'){
            playgame2();
        }
        else if (maze[x][y] == '3'){
            playgame3();
        }
        else if (maze[x][y] == '4'){
            playHangman();
        }
        else if (maze[x][y] == '5'){
            playgame5();
        }
        else if (maze[x][y] == 'F') {
            break;
        }
        // Redraw the maze with the player in the new position
        system("cls");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == x && j == y) {
                    cout << '@';
                } else {
                    cout << maze[i][j];
                }
            }
            cout << endl;
        }
    }

    // Print a message when the user reaches the end of the maze
    cout << "Congratulations, you made it to the end!" << endl;

    return 0;
}
