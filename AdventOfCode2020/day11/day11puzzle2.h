#ifndef DAY11PUZZLE2_H
#define DAY11PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct elem
{
	string neighbours;
	char type;
} elem_T;

void mainDay11Puzzle2();
void readInputsDay11Puzzle2(vector<vector<elem_T>>& layout);
int solveDay11Puzzle2(vector<vector<elem_T>> layout);
void updateNeighboursPuzzle2(vector<vector<elem_T>>& layout);
bool updateTypePuzzle2(vector<vector<elem_T>>& layout);

#endif