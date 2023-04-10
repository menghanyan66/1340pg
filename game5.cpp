#include "game5.h"
#include <iostream>

using namespace std;

const int BOARD_SIZE = 5;
const int NUM_MINES = 5;

class Minesweeper {
public:
  Minesweeper() {
    board = new char*[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
      board[i] = new char[BOARD_SIZE];
      for (int j = 0; j < BOARD_SIZE; j++) {
        board[i][j] = '-';
      }
    }

    srand(time(NULL));
    int count = 0;
    while (count < NUM_MINES) {
      int row = rand() % BOARD_SIZE;
      int col = rand() % BOARD_SIZE;
      if (board[row][col] != '*') {
        board[row][col] = '*';
        count++;
      }
    }
  }

  ~Minesweeper() {
    for (int i = 0; i < BOARD_SIZE; i++) {
      delete[] board[i];
    }
    delete[] board;
  }

  void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  void play() {
    while (true) {
      printBoard();

      int row, col;
      cout << "Enter row and column (1-5): ";
      cin >> row >> col;

      if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
        cout << "Invalid input. Try again." << endl;
        continue;
      }

      if (board[row - 1][col - 1] == '*') {
        cout << "Game over! You hit a mine." << endl;
        board[row - 1][col - 1] = 'X';
        printBoard();
        break;
      } else {
        int count = countMines(row - 1, col - 1);
        board[row - 1][col - 1] = '0' + count;

        if (count == 0) {
          revealAdjacentCells(row - 1, col - 1);
        }

        bool win = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
          for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-' && !(i == row - 1 && j == col - 1)) {
              win = false;
              break;
            }
          }
          if (!win) {
            break;
          }
        }

        if (win) {
          cout << "Congratulations! You win!" << endl;
          printBoard();
          break;
        }
      }
    }
  }

private:
  char** board;

  int countMines(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
      for (int j = col - 1; j <= col + 1; j++) {
        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
          if (board[i][j] == '*') {
            count++;
          }
        }
      }
    }
    return count;
  }

  void revealAdjacentCells(int row, int col) {
    for (int i = row - 1; i <= row + 1; i++) {
      for (int j = col - 1; j <= col + 1; j++) {
        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
          if (board[i][j] == '-') {
            int count = countMines(i, j);
            board[i][j] = '0' + count;
            if (count == 0) {
              revealAdjacentCells(i, j);
            }
          }
        }
      }
    }
  }
};

void playgame5() {
  Minesweeper game;
  game.play();
}