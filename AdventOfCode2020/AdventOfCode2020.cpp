// AdventOfCode2020.cpp : 
// - This file contains the 'main' function
// - Program execution begins and ends here
// - For running the solution of a specific puzzle from a specific day, you have to:
//      - Change the header file
//      - Change the function called from the 'main' function
//      - Create the data structures needed to be provided as input to the functions called

#include <iostream>
#include "day2/day2puzzle1.h"

int main()
{
    vector<int> minOccurenceArray;
    vector<int> maxOccurenceArray;
    vector<string> letterArray;
    vector<string> passwordArray;
    readInputsDay2Puzzle1(minOccurenceArray, maxOccurenceArray, letterArray, passwordArray);

    int sol = solveDay2Puzzle1(minOccurenceArray, maxOccurenceArray, letterArray, passwordArray);

    cout << sol;

    return 0;
}