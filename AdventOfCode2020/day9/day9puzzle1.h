#ifndef DAY9PUZZLE1_H
#define DAY9PUZZLE1_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define PREAMBLESIZE 25

void mainDay9Puzzle1();
void readInputsDay9Puzzle1(vector<long long>& numbers);
long long solveDay9Puzzle1(vector<long long> numbers);
bool searchSumPuzzle1(unordered_set<long long> numbers, long long sum);

#endif