#ifndef DAY15PUZZLE2_H
#define DAY15PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define MAXTURN 30000000

void mainDay15Puzzle2();
void readInputsDay15Puzzle2(vector<int>& starting);
int solveDay15Puzzle2(vector<int> starting);

#endif