#include "day5puzzle2.h"

void mainDay5Puzzle2()
{
	vector<string> boardingPassArray;
	readInputsDay5Puzzle2(boardingPassArray);

	cout << solveDay5Puzzle2(boardingPassArray);
}

void readInputsDay5Puzzle2(vector<string>& boardingPassArray)
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

int solveDay5Puzzle2(vector<string> boardingPassArray)
{
	vector<int> idArray;

	for (int indexBoardingPass = 0; indexBoardingPass < (int)boardingPassArray.size(); indexBoardingPass++)
	{
		int row = calculatePositionPuzzle2(boardingPassArray[indexBoardingPass].substr(0, 7));
		int column = calculatePositionPuzzle2(boardingPassArray[indexBoardingPass].substr(7, 3));
		int id = row * 8 + column;

		idArray.push_back(id);
	}

	sort(idArray.begin(), idArray.end());

	for (int indexId = 1; indexId < (int)idArray.size(); indexId++)
	{
		if (idArray[indexId] == idArray[indexId - 1] + 2)
		{
			return idArray[indexId - 1] + 1;
		}
	}

	return -1;
}

int calculatePositionPuzzle2(string sequence)
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