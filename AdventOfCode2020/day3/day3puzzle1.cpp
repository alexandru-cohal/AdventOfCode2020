#include "day3puzzle1.h"

void mainDay3Puzzle1()
{
	vector<string> map;
	readInputsDay3Puzzle1(map);

	cout << solveDay3Puzzle1(map);
}

void readInputsDay3Puzzle1(vector<string>& map)
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

int solveDay3Puzzle1(vector<string>& map)
{
	int numTreeEncount = 0;

	int column = 0;
	for (int row = 0; row < (int)map.size(); row++)
	{
		if (map[row][column] == '#')
		{
			numTreeEncount++;
		}

		column += 3;
		if (column >= (int)map[0].size())
		{
			column -= map[0].size();
		}
	}

	return numTreeEncount;
}