#ifndef DAY20PUZZLE1_H
#define DAY20PUZZLE1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct tile
{
	int id;
	string top;
	string bottom;
	string left;
	string right;
}tile_T;

void mainDay20Puzzle1();
void readInputsDay20Puzzle1(vector<tile_T>& tileList);
long long solveDay20Puzzle1(vector<tile_T> tileList);

#endif