#include "day5puzzle1.h"

void mainDay5Puzzle1()
{
	vector<string> boardingPassArray;
	readInputsDay5Puzzle1(boardingPassArray);

	cout << solveDay5Puzzle1(boardingPassArray);
}

void readInputsDay5Puzzle1(vector<string>& boardingPassArray)
{
	string filename = "day5/day5Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			boardingPassArray.push_back(line);
		}
	}

	inFile.close();
}

int solveDay5Puzzle1(vector<string> boardingPassArray)
{
	int maxId = 0;

	for (int indexBoardingPass = 0; indexBoardingPass < (int)boardingPassArray.size(); indexBoardingPass++)
	{
		int row = calculatePosition(boardingPassArray[indexBoardingPass].substr(0, 7));
		int column = calculatePosition(boardingPassArray[indexBoardingPass].substr(7, 3));
		int id = row * 8 + column;

		maxId = max(maxId, id);
	}

	return maxId;
}

int calculatePosition(string sequence)
{
	int left = 0;
	int right;

	if (sequence.length() == 7)
	{
		right = 127;
	}
	else
	{
		right = 7;
	}

	for (int indexChar = 0; indexChar < (int)sequence.length(); indexChar++)
	{
		if (sequence[indexChar] == 'F' || sequence[indexChar] == 'L')
		{
			right = right - ((right - left) / 2 + 1);
		}
		else
		{
			left = left + ((right - left) / 2 + 1);
		}
	}

	return left;
}