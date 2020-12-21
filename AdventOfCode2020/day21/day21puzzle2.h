#ifndef DAY21PUZZLE2_H
#define DAY21PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef struct food
{
	set<string> ingredients;
	set<string> allergens;
} food_T;

void mainDay21Puzzle2();
void readInputsDay21Puzzle2(vector<food_T>& foodList, set<string>& allergensSet);
string solveDay21Puzzle2(vector<food_T> foodList, set<string> allergensSet);

#endif