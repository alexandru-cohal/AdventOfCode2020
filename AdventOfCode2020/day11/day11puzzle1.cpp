#include "day11puzzle1.h"

void mainDay11Puzzle1()
{
	vector<string> layout;
	readInputsDay11Puzzle1(layout);

	cout << solveDay11Puzzle1(layout);
}

void readInputsDay11Puzzle1(vector<string>& layout)
{
	string filename = "day11/day11Input.txt";
	ifstream inFile(filename);

	bool firstLine = true;
	string line;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			if (firstLine)
			{
				// Add the first line having only '.' characters
				string firstLastLine(line.size() + 2, '.');
				layout.push_back(firstLastLine);

				firstLine = false;
			}

			// Add at the beginning and at the end of each line one '.' character
			line.insert(line.begin(), '.');
			line.insert(line.end(), '.');
			layout.push_back(line);
		}
	}
	// Add the last line having only '.' characters
	string firstLastLine(line.size() + 2, '.');
	layout.push_back(firstLastLine);

	inFile.close();
}

int solveDay11Puzzle1(vector<string> layout)
{
	vector<string> layoutNew = layout;
	vector<int> rowStep{1, 0, -1, -1, -1, 0, 1, 1};
	vector<int> colStep{ -1, -1, -1, 0, 1, 1, 1, 0 };
	bool flagChange = true;
	int numOccupied;

	while (flagChange)
	{
		flagChange = false;

		// Check all the positions one by one
		for (int indexRow = 1; indexRow < layout.size() - 1; indexRow++)
		{
			for (int indexCol = 1; indexCol < layout[0].size() - 1; indexCol++)
			{
				numOccupied = 0;

				// Check all the 8 neighbours and count how many are occupied seats and how many are unoccupied seats
				for (int indexStep = 0; indexStep < 8; indexStep++)
				{
					if (layout[indexRow + rowStep[indexStep]][indexCol + colStep[indexStep]] == '#')
					{
						numOccupied++;
					}
				}

				// Change the seat if the conditions are fulfilled or keep its state otherwise
				if (layout[indexRow][indexCol] == 'L' && numOccupied == 0)
				{
					layoutNew[indexRow][indexCol] = '#';
					flagChange = true;
				}
				else if (layout[indexRow][indexCol] == '#' && numOccupied >= 4)
				{
					layoutNew[indexRow][indexCol] = 'L';
					flagChange = true;
				}
				else
				{
					layoutNew[indexRow][indexCol] = layout[indexRow][indexCol];
				}
			}
		}

		layout = layoutNew;
	}

	// Count how many occupied seats are in the last layout
	numOccupied = 0;
	for (int indexRow = 1; indexRow < layout.size() - 1; indexRow++)
	{
		for (int indexCol = 1; indexCol < layout[0].size() - 1; indexCol++)
		{
			if (layout[indexRow][indexCol] == '#')
			{
				numOccupied++;
			}
		}
	}

	return numOccupied;
}