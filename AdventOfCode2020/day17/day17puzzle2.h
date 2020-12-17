#ifndef DAY17PUZZLE2_H
#define DAY17PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

#define NUMCYCLES 6
#define MAXSIZE 24

void mainDay17Puzzle2();
void readInputsDay17Puzzle2(char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE]);
int countActiveNeighbDay17Puzzle2(int indexW, int indexDim, int indexRow, int indexCol, char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE]);
void copyCubesSetDay17Puzzle2(char cubesSetNew[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE], char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE]);
int solveDay17Puzzle2(char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE]);

#endif