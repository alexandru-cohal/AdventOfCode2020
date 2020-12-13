#ifndef DAY13PUZZLE2_H
#define DAY13PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct busData
{
	int id;
	int index;
} busData;

void mainDay13Puzzle2();
void readInputsDay13Puzzle2(int& earliestTime, vector<busData>& busID);
unsigned long long calcModularInv(unsigned long long a, unsigned long long m);
unsigned long long solveDay13Puzzle2(int earliestTime, vector<busData> busID);

#endif