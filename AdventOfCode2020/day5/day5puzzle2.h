#ifndef DAY5PUZZLE2_H
#define DAY5PUZZLE2_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void mainDay5Puzzle2();
void readInputsDay5Puzzle2(vector<string>& boardingPassArray);
int solveDay5Puzzle2(vector<string> boardingPassArray);
int calculatePositionPuzzle2(string sequence);

#endif