#include "day1puzzle2.h"

void readInputsDay1Puzzle2(vector<int>& expenseArray)
{
	string filename = "day1/input.txt";
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

int solveDay1Puzzle2(vector<int>& expenseArray)
{
	for (int index1 = 0; index1 < (int)expenseArray.size() - 2; index1++)
	{
		for (int index2 = index1 + 1; index2 < (int)expenseArray.size() - 1; index2++)
		{
			for (int index3 = index2 + 1; index3 < (int)expenseArray.size(); index3++)
			{
				if (expenseArray[index1] + expenseArray[index2] + expenseArray[index3] == DESIRED_SUM_VALUE)
				{
					return expenseArray[index1] * expenseArray[index2] * expenseArray[index3];
				}
			}
		}
	}

	return -1;
}