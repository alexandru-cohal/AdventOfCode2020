#include "day9puzzle1.h"

void mainDay9Puzzle1()
{
	vector<long long> numbers;
	readInputsDay9Puzzle1(numbers);

	cout << solveDay9Puzzle1(numbers);
}

void readInputsDay9Puzzle1(vector<long long>& numbers)
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

long long solveDay9Puzzle1(vector<long long> numbers)
{
	// Create the initial queue and unordered set with the numbers from preamble
	queue<long long> previousNumbersQueue;
	unordered_set<long long> previousNumbersSet;
	for (int indexNumber = 0; indexNumber < PREAMBLESIZE; indexNumber++)
	{
		previousNumbersQueue.push(numbers[indexNumber]);
		previousNumbersSet.insert(numbers[indexNumber]);
	}

	// Iterate over the numbers after preamble one by one
	for (int indexNumber = PREAMBLESIZE; indexNumber < (int)numbers.size(); indexNumber++)
	{
		// Search for the sum of 2 numbers equal with the current number
		if (!searchSumPuzzle1(previousNumbersSet, numbers[indexNumber]))
		{
			return numbers[indexNumber];
		}

		// Remove the oldest element
		previousNumbersSet.erase(previousNumbersQueue.front());
		previousNumbersQueue.pop();

		// Insert a new element
		previousNumbersQueue.push(numbers[indexNumber]);
		previousNumbersSet.insert(numbers[indexNumber]);
	}

	return 0; // If a solution exists, this line shouldn't be executed
}

bool searchSumPuzzle1(unordered_set<long long> numbers, long long sum)
{
	for (auto itNumber = numbers.begin(); itNumber != numbers.end(); itNumber++)
	{
		auto itFind = numbers.find(sum - *itNumber);
		if (itFind != numbers.end() && itFind != itNumber)
		{
			return true;
		}
	}

	return false;
}