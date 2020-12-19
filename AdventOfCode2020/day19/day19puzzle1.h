#ifndef DAY19PUZZLE1_H
#define DAY19PUZZLE1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void mainDay19Puzzle1();
void readInputsDay19Puzzle1(map<int, string>& rule, vector<string>& receivedMsgs);
void solveRule(map<int, string>& rule, int indexQueryRule, map<int, vector<string>>& ruleMsgs);
int solveDay19Puzzle1(vector<string> rule0Msgs, vector<string> receivedMsgs);

#endif