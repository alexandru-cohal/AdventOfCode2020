#ifndef DAY8PUZZLE1_H
#define DAY8PUZZLE1_H

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

void mainDay8Puzzle1();
void readInputsDay8Puzzle1(vector<line_T>& program);
int solveDay8Puzzle1(vector<line_T> program);

#endif