#ifndef DAY22PUZZLE2_H
#define DAY22PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <set>
#include <vector>

using namespace std;

void mainDay22Puzzle2();
void readInputsDay22Puzzle2(deque<int>& player1, deque<int>& player2);
bool playGameDay22Puzzle2(deque<int>& player1, deque<int>& player2);
long long solveDay22Puzzle2(deque<int> player1, deque<int> player2);

#endif