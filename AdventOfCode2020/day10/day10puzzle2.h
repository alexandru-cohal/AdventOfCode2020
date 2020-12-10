#ifndef DAY10PUZZLE2_H
#define DAY10PUZZLE2_H

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void mainDay10Puzzle2();
void readInputsDay10Puzzle2(map<int, long long>& numSolForJoltRating, int& maxJoltRating);
long long solveDay10Puzzle2(map<int, long long> numSolForJoltRating, int maxJoltRating);

#endif