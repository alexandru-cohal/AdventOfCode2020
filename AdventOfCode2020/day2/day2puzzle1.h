#ifndef DAY2PUZZLE1_H
#define DAY2PUZZLE1_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void mainDay2Puzzle1();

void readInputsDay2Puzzle1(vector<int> &minOccurenceArray,
							vector<int> &maxOccurenceArray,
							vector<string> &letterArray,
							vector<string> &passwordArray);

int solveDay2Puzzle1(vector<int> &minOccurenceArray,
						vector<int> &maxOccurenceArray,
						vector<string> &letterArray,
						vector<string> &passwordArray);
#endif