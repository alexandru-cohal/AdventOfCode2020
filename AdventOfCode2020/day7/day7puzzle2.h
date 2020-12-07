#ifndef DAY7PUZZLE2_H
#define DAY7PUZZLE2_H

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

void mainDay7Puzzle2();
void readInputsDay7Puzzle2(map<string, vector<element_T>>& luggageRule);
int calculateContainedLuggagesPuzzle2(map<string, vector<element_T>>& luggageRule,
									  map<string, int>& sumChildQuantity,
									  string currentLuggageType);

#endif