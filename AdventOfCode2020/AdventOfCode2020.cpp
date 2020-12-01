// AdventOfCode2020.cpp : 
// - This file contains the 'main' function
// - Program execution begins and ends here
// - For running the solution of a specific puzzle from a specific day, you have to:
//      - Change the header file
//      - Change the function called from the 'main' function

#include <iostream>
#include "day1/day1puzzle1.h"

int main()
{
    vector<int> expenseArray;
    readInputs(expenseArray);

    int sol = solveDay1Task1(expenseArray);

    cout << sol;

    return 0;
}