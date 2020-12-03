#include "day3puzzle2.h"

void mainDay3Puzzle2()
{
	vector<string> map;
	readInputsDay3Puzzle2(map);

	cout << solveDay3Puzzle2(map, 1, 1) * 
			solveDay3Puzzle2(map, 3, 1) *
			solveDay3Puzzle2(map, 5, 1) *
			solveDay3Puzzle2(map, 7, 1) *
			solveDay3Puzzle2(map, 1, 2);
}

void readInputsDay3Puzzle2(vector<string>& map)
{
	string filename = "day3/day3Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			map.push_back(line);
		}
	}

	inFile.close();
}

int solveDay3Puzzle2(vector<string>& map, int stepCol, int stepRow)
{
	int numTreeEncount = 0;

	int column = 0;
	for (int row = 0; row < (int)map.size(); row += stepRow)
	{
		if (map[row][column] == '#')
		{
			numTreeEncount++;
		}

		column += stepCol;
		if (column >= (int)map[0].size())
		{
			column -= map[0].size();
		}
	}

	return numTreeEncount;
}