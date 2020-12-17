#ifndef DAY17PUZZLE1_H
#define DAY17PUZZLE1_H

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

#define NUMCYCLES 6
#define MAXSIZE 24

void mainDay17Puzzle1();
void readInputsDay17Puzzle1(char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE]);
int countActiveNeighbDay17Puzzle1(int indexDim, int indexRow, int indexCol, char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE]);
void copyCubesSetDay17Puzzle1(char cubesSetNew[MAXSIZE][MAXSIZE][MAXSIZE], char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE]);
int solveDay17Puzzle1(char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE]);

#endif