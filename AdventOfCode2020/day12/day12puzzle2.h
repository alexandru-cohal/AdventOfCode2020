#ifndef DAY12PUZZLE2_H
#define DAY12PUZZLE2H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct instruction
{
	string direction;
	int value;
} instruction_T;

void mainDay12Puzzle2();
void readInputsDay12Puzzle2(vector<instruction_T>& steps);
int solveDay12Puzzle2(vector<instruction_T> steps);

#endif