#ifndef DAY8PUZZLE2_H
#define DAY8PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct line
{
	string instruction;
	int argument;
} line_T;

void mainDay8Puzzle2();
void readInputsDay8Puzzle2(vector<line_T>& program);
int solveDay8Puzzle2(vector<line_T> program);
bool executeProgramPuzzle2(vector<line_T> program, int& accValue);

#endif