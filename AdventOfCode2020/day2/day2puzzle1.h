#ifndef DAY2PUZZLE1_H
#define DAY2PUZZLE1_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readInputsDay2Puzzle1(vector<int> &minOccurenceArray,
							vector<int> &maxOccurenceArray,
							vector<string> &letterArray,
							vector<string> &passwordArray);

int solveDay2Puzzle1(vector<int> &minOccurenceArray,
						vector<int> &maxOccurenceArray,
						vector<string> &letterArray,
						vector<string> &passwordArray);
#endif