#ifndef DAY12PUZZLE1_H
#define DAY12PUZZLE1_H

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

void mainDay12Puzzle1();
void readInputsDay12Puzzle1(vector<instruction_T>& steps);
int solveDay12Puzzle1(vector<instruction_T> steps);

#endif