#ifndef DAY7PUZZLE1_H
#define DAY7PUZZLE1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef struct element
{
	string type;
	int quantity;
} element_T;

void mainDay7Puzzle1();
void readInputsDay7Puzzle1(map<string, vector<element_T>>& luggageRule);
int solveDay7Puzzle1(map<string, vector<element_T>>& luggageRule);

#endif