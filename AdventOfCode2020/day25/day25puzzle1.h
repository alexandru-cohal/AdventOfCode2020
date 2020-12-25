#ifndef DAY25PUZZLE1_H
#define DAY25PUZZLE1_H

#include <iostream>
#include <fstream>

using namespace std;

#define INITIALSUBJECTNUMBER 7
#define DIVIDERNUMBER 20201227

void mainDay25Puzzle1();
void readInputsDay25Puzzle1(long long& cardPublicKey, long long& doorPublicKey);
int findLoopSizeDay25Puzzle1(long long key);
long long solveDay25Puzzle1(long long cardPublicKey, long long doorPublicKey);

#endif