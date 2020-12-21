#ifndef DAY21PUZZLE1_H
#define DAY21PUZZLE1_H

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

void mainDay21Puzzle1();
void readInputsDay21Puzzle1(vector<food_T>& foodList, set<string>& allergensSet);
int solveDay21Puzzle1(vector<food_T> foodList, set<string> allergensSet);

#endif