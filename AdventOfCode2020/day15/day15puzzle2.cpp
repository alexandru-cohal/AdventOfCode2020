#include "day15puzzle2.h"

void mainDay15Puzzle2()
{
	vector<int> starting;
	readInputsDay15Puzzle2(starting);

	cout << solveDay15Puzzle2(starting);
}

void readInputsDay15Puzzle2(vector<int>& starting)
{
	string filename = "day15/day15Input.txt";
	ifstream inFile(filename);

	string line;
	inFile >> line;

	int posComma = line.find(',');
	while (posComma != string::npos)
	{
		starting.push_back(stoi(line.substr(0, posComma)));
		line.erase(line.begin(), line.begin() + posComma + 1);
		posComma = line.find(',');
	}
	starting.push_back(stoi(line));

	inFile.close();
}

int solveDay15Puzzle2(vector<int> starting)
{
	map<int, int> numberSpoken;

	for (int turn = 1; turn < (int)starting.size(); turn++)
	{
		numberSpoken[starting[turn - 1]] = turn;
	}

	int prevNumber;
	bool prevNumberFirstSpoken;

	prevNumber = starting[starting.size() - 1];
	if (numberSpoken.find(starting[starting.size() - 1]) != numberSpoken.end())
	{
		prevNumberFirstSpoken = true;
	}
	else
	{
		prevNumberFirstSpoken = false;
	}

	// Iterate over all the turns until the MAXTURN turn
	for (int turn = (int)starting.size() + 1; turn <= MAXTURN; turn++)
	{
		int currentNumber;
		bool currentNumberFirstSpoken;

		// Calculate the current number
		if (prevNumberFirstSpoken)
		{
			// The number was said before
			currentNumber = (turn - 1) - numberSpoken[prevNumber];
		}
		else
		{
			// The number was not said before
			currentNumber = 0;
		}

		// Add the previous number to the map
		numberSpoken[prevNumber] = turn - 1;

		// Determine the current number spoken flag 
		if (numberSpoken.find(currentNumber) != numberSpoken.end())
		{
			currentNumberFirstSpoken = true;
		}
		else
		{
			currentNumberFirstSpoken = false;
		}

		// Current -> Prev
		prevNumber = currentNumber;
		prevNumberFirstSpoken = currentNumberFirstSpoken;
	}

	return prevNumber;
}