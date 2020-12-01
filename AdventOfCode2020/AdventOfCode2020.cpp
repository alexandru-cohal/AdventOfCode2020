// AdventOfCode2020.cpp : 
// - This file contains the 'main' function
// - Program execution begins and ends here
// - For running the solution of a specific puzzle from a specific day, you have to:
//      - Change the header file
//      - Change the function called from the 'main' function
//      - Create the data structures needed to be provided as input to the functions called

#include <iostream>
#include "day1/day1puzzle2.h"

int main()
{
    vector<int> expenseArray;
    readInputsDay1Puzzle2(expenseArray);

    int sol = solveDay1Puzzle2(expenseArray);

    cout << sol;

    return 0;
}