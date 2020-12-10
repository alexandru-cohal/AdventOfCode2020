#include "day10puzzle1.h"

void mainDay10Puzzle1()
{
	set<int> joltageRatings;
	readInputsDay10Puzzle1(joltageRatings);

	cout << solveDay10Puzzle1(joltageRatings);
}

void readInputsDay10Puzzle1(set<int>& joltageRatings)
{
	string filename = "day10/day10Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		int currentJoltage;
		while (!inFile.eof())
		{
			inFile >> currentJoltage;
			joltageRatings.insert(currentJoltage);
		}
	}

	inFile.close();
}

int solveDay10Puzzle1(set<int> joltageRatings)
{
	int currentJoltage = 0;
	bool findAdapter = true;
	int diffJoltage1 = 0, diffJoltage2 = 0, diffJoltage3 = 1; 
	// diffJoltage3 is initialized with 1 because the device has a joltage adapter rated for 3 jolts higher than the highest-rated adapter

	// Find the best adapter until there is no possible adapter to connect
	while (findAdapter)
	{
		if (joltageRatings.find(currentJoltage + 1) != joltageRatings.end())
		{
			currentJoltage = currentJoltage + 1;
			diffJoltage1++;
		}
		else if (joltageRatings.find(currentJoltage + 2) != joltageRatings.end())
		{
			currentJoltage = currentJoltage + 2;
			diffJoltage2++;
		}
		else if (joltageRatings.find(currentJoltage + 3) != joltageRatings.end())
		{
			currentJoltage = currentJoltage + 3;
			diffJoltage3++;
		}
		else
		{
			findAdapter = false;
		}
	}

	return diffJoltage1 * diffJoltage3;
}