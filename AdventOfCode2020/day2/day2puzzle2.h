#ifndef DAY2PUZZLE2_H
#define DAY2PUZZLE2_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void mainDay2Puzzle2();

void readInputsDay2Puzzle2(vector<int>& charIndex1Array,
							vector<int>& charIndex2Array,
							vector<string>& letterArray,
							vector<string>& passwordArray);

int solveDay2Puzzle2(vector<int>& charIndex1Array,
						vector<int>& charIndex2Array,
						vector<string>& letterArray,
						vector<string>& passwordArray);
#endif