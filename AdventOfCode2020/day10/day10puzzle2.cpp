#include "day10puzzle2.h"

void mainDay10Puzzle2()
{
	map<int, long long> numSolForJoltRating;
	int maxJoltRating = 0;
	readInputsDay10Puzzle2(numSolForJoltRating, maxJoltRating);
	numSolForJoltRating[0] = 1;

	cout << solveDay10Puzzle2(numSolForJoltRating, maxJoltRating);
}

void readInputsDay10Puzzle2(map<int, long long>& numSolForJoltRating, int& maxJoltRating)
{
	string filename = "day10/day10Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		int currentJoltage;
		while (!inFile.eof())
		{
			inFile >> currentJoltage;
			numSolForJoltRating[currentJoltage] = 0;

			if (currentJoltage > maxJoltRating)
			{
				maxJoltRating = currentJoltage;
			}
		}
	}

	inFile.close();
}

long long solveDay10Puzzle2(map<int, long long> numSolForJoltRating, int maxJoltRating)
{
	// Calculate the number of solutions for each joltage rating of an existent adapter
	for (int joltage = 1; joltage <= maxJoltRating; joltage++)
	{
		// Check if an adapter with the chosed joltage exists
		if (numSolForJoltRating.find(joltage) != numSolForJoltRating.end())
		{
			// Calculate the number of solutions for the chosen joltage
			if (numSolForJoltRating.find(joltage - 1) != numSolForJoltRating.end())
			{
				numSolForJoltRating[joltage] += numSolForJoltRating[joltage - 1];
			}

			if (numSolForJoltRating.find(joltage - 2) != numSolForJoltRating.end())
			{
				numSolForJoltRating[joltage] += numSolForJoltRating[joltage - 2];
			}

			if (numSolForJoltRating.find(joltage - 3) != numSolForJoltRating.end())
			{
				numSolForJoltRating[joltage] += numSolForJoltRating[joltage - 3];
			}
		}
	}

	return numSolForJoltRating[maxJoltRating];
}