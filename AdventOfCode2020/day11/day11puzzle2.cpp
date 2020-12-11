#include "day11puzzle2.h"

void mainDay11Puzzle2()
{
	vector<vector<elem_T>> layout;
	readInputsDay11Puzzle2(layout);

	cout << solveDay11Puzzle2(layout);
}

void readInputsDay11Puzzle2(vector<vector<elem_T>>& layout)
{
	string filename = "day11/day11Input.txt";
	ifstream inFile(filename);

	string line;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			vector<elem_T> lineElem;
			for (int index = 0; index < (int)line.size(); index++)
			{
				elem_T elem;
				elem.type = line[index];
				elem.neighbours = "........";
				lineElem.push_back(elem);
			}

			layout.push_back(lineElem);
		}
	}

	inFile.close();
}

int solveDay11Puzzle2(vector<vector<elem_T>> layout)
{
	updateNeighboursPuzzle2(layout);
	while (updateTypePuzzle2(layout))
	{
		updateNeighboursPuzzle2(layout);
	}

	// Count how many occupied seats are in the last layout
	int numOccupied = 0;
	for (int indexRow = 0; indexRow < (int)layout.size(); indexRow++)
	{
		for (int indexCol = 0; indexCol < (int)layout[0].size(); indexCol++)
		{
			if (layout[indexRow][indexCol].type == '#')
			{
				numOccupied++;
			}
		}
	}

	return numOccupied;
}

void countEmptyAndOccupiedPuzzle2(vector<vector<elem_T>> layout, int row, int col, int& numEmpty, int& numOccupied)
{
	for (int indexNeighbour = 0; indexNeighbour < 8; indexNeighbour++)
	{
		if (layout[row][col].neighbours[indexNeighbour] == 'L')
		{
			numEmpty++;
		}
		else if (layout[row][col].neighbours[indexNeighbour] == '#')
		{
			numOccupied++;
		}
	}
}

void updateNeighboursPuzzle2(vector<vector<elem_T>>& layout)
{
	vector<int> rowStep{ 0, -1, -1, -1, 0, 1, 1, 1};
	vector<int> colStep{ -1, -1, 0, 1, 1, 1, 0, -1};

	// From left to right and top to bottom
	for (int indexRow = 0; indexRow < (int)layout.size(); indexRow++)
	{
		for (int indexCol = 0; indexCol < (int)layout[0].size(); indexCol++)
		{
			// Consider only the left, top-left, top and top-right directions
			for (int indexStep = 0; indexStep < 4; indexStep++)
			{
				int indexRowStep = indexRow + rowStep[indexStep];
				int indexColStep = indexCol + colStep[indexStep];

				if (indexRowStep >= 0 && indexRowStep < (int)layout.size() &&
					indexColStep >= 0 && indexColStep < (int)layout[0].size())
				{
					// The position in the stepping direction exists

					if (layout[indexRowStep][indexColStep].type == 'L' || layout[indexRowStep][indexColStep].type == '#')
					{
						layout[indexRow][indexCol].neighbours[indexStep] = layout[indexRowStep][indexColStep].type;
					}
					else
					{
						layout[indexRow][indexCol].neighbours[indexStep] = layout[indexRowStep][indexColStep].neighbours[indexStep];
					}
				}
				else
				{
					// The position in the stepping direction doesn't exist

					layout[indexRow][indexCol].neighbours[indexStep] = '.';
				}
			}
		}
	}

	// From right to left and bottom to top
	for (int indexRow = (int)layout.size() - 1; indexRow >= 0; indexRow--)
	{
		for (int indexCol = (int)layout[0].size() - 1; indexCol >= 0; indexCol--)
		{
			// Consider only the right, bottom-right, bottom and bottom-left directions
			for (int indexStep = 4; indexStep < 8; indexStep++)
			{
				int indexRowStep = indexRow + rowStep[indexStep];
				int indexColStep = indexCol + colStep[indexStep];

				if (indexRowStep >= 0 && indexRowStep < (int)layout.size() &&
					indexColStep >= 0 && indexColStep < (int)layout[0].size())
				{
					// The position in the stepping direction exists

					if (layout[indexRowStep][indexColStep].type == 'L' || layout[indexRowStep][indexColStep].type == '#')
					{
						layout[indexRow][indexCol].neighbours[indexStep] = layout[indexRowStep][indexColStep].type;
					}
					else
					{
						layout[indexRow][indexCol].neighbours[indexStep] = layout[indexRowStep][indexColStep].neighbours[indexStep];
					}
				}
				else
				{
					// The position in the stepping direction doesn't exist

					layout[indexRow][indexCol].neighbours[indexStep] = '.';
				}
			}
		}
	}
}

bool updateTypePuzzle2(vector<vector<elem_T>>& layout)
{
	bool flagChange = false;
	int numEmpty, numOccupied;

	for (int indexRow = 0; indexRow < (int)layout.size(); indexRow++)
	{
		for (int indexCol = 0; indexCol < (int)layout[0].size(); indexCol++)
		{
			numEmpty = 0;
			numOccupied = 0;
			countEmptyAndOccupiedPuzzle2(layout, indexRow, indexCol, numEmpty, numOccupied);

			if (layout[indexRow][indexCol].type == 'L' && numOccupied == 0)
			{
				layout[indexRow][indexCol].type = '#';
				flagChange = true;
			}
			else if (layout[indexRow][indexCol].type == '#' && numOccupied >= 5)
			{
				layout[indexRow][indexCol].type = 'L';
				flagChange = true;
			}
		}
	}

	return flagChange;
}