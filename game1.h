#ifndef GAME1_H
#define GAME1_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void generatePuzzle(std::vector<std::string>& puzzle);

void displayPuzzle(const std::vector<std::string>& puzzle);

bool checkPuzzle(const std::vector<std::string>& puzzle);

void moveBlock(std::vector<std::string>& puzzle, int x, int y, int dx, int dy);

void playgame1();

#endif
