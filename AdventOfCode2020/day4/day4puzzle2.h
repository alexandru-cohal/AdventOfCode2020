#ifndef DAY4PUZZLE2_H
#define DAY4PUZZLE2_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void mainDay4Puzzle2();
int readInputsDay4Puzzle2AndSolve();
void checkValidityKeyValue(string key, string value, bool& byr, bool& iyr, bool& eyr, bool& hgt, bool& hcl, bool& ecl, bool& pid);

#endif