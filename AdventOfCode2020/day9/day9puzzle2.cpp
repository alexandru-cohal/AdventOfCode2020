#include "day9puzzle2.h"

void mainDay9Puzzle2()
{
	vector<long long> numbers;
	readInputsDay9Puzzle2(numbers);

	cout << solveDay9Puzzle2(numbers);
}

void readInputsDay9Puzzle2(vector<long long>& numbers)
{
	string filename = "day9/day9Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		long long currentNumber;
		while (!inFile.eof())
		{
			inFile >> currentNumber;
			numbers.push_back(currentNumber);
		}
	}

	inFile.close();
}

long long solveDay9Puzzle2(vector<long long> numbers)
{
	vector<long long> partialSum;
	long long sumStartToEnd;

	for (int indexEnd = 0; indexEnd < (int)numbers.size(); indexEnd++)
	{
		// Calculate the new partialSum element (the one for index indexEnd)
		if (indexEnd == 0)
		{
			partialSum.push_back(numbers[0]);
		}
		else
		{
			partialSum.push_back(partialSum[indexEnd - 1] + numbers[indexEnd]);
		}

		// Iterate with the indexStart from 0 until indexEnd-1 and check if the sums between indexStart and indexEnd are equal with SOLUTIONPUZZLE1
		for (int indexStart = 0; indexStart < indexEnd; indexStart++)
		{
			if (indexStart == 0)
			{
				sumStartToEnd = partialSum[indexEnd];
			}
			else
			{
				sumStartToEnd = partialSum[indexEnd] - partialSum[indexStart - 1];
			}

			if (sumStartToEnd == SOLUTIONPUZZLE1)
			{
				// Contiguous sequence with sum equal with SOLUTIONPUZZLE1 found

				// Find out the minimum and maximum numbers of the contiguous sequence
				long long minNumber = numbers[indexStart];
				long long maxNumber = numbers[indexStart];

				for (int indexElem = indexStart + 1; indexElem <= indexEnd; indexElem++)
				{
					if (numbers[indexElem] < minNumber)
					{
						minNumber = numbers[indexElem];
					}
					else if (numbers[indexElem] > maxNumber)
					{
						maxNumber = numbers[indexElem];
					}
				}

				return minNumber + maxNumber;
			}
		}
	}

	return 0; // If a solution exists, this line shouldn't be executed
}