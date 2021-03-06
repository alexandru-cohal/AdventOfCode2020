#include "day1puzzle1.h"

void mainDay1Puzzle1()
{
	vector<int> expenseArray;
	readInputsDay1Puzzle1(expenseArray);

	cout << solveDay1Puzzle1(expenseArray);
}

void readInputsDay1Puzzle1(vector<int> &expenseArray)
{
	string filename = "day1/day1Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			int currentExpense;

			inFile >> currentExpense;
			expenseArray.push_back(currentExpense);
		}
	}

	inFile.close();
}

int solveDay1Puzzle1(vector<int> &expenseArray)
{
	for (int index1 = 0; index1 < (int)expenseArray.size() - 1; index1++)
	{
		for (int index2 = index1 + 1; index2 < (int)expenseArray.size(); index2++)
		{
			if (expenseArray[index1] + expenseArray[index2] == DESIRED_SUM_VALUE)
			{
				return expenseArray[index1] * expenseArray[index2];
			}
		}
	}

	return -1;
}