#ifndef DAY5PUZZLE1_H
#define DAY5PUZZLE1_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void mainDay5Puzzle1();
void readInputsDay5Puzzle1(vector<string>& boardingPassArray);
int solveDay5Puzzle1(vector<string> boardingPassArray);
int calculatePositionPuzzle1(string sequence);

#endif