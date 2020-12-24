#include "day24puzzle1.h"

void mainDay24Puzzle1()
{
	cout << readInputsAndSolveDay24Puzzle1();
}

int readInputsAndSolveDay24Puzzle1()
{
	string filename = "day24/day24Input.txt";
	ifstream inFile(filename);

	// Keep the black tiles in the set "blackTiles"
	set<pair<int, int>> blackTiles;

	string line;
	// For each line from the input
	while (getline(inFile, line))
	{
		// Use a 2D plane with movement only along the 2 axis (i.e. X axis and Y axis)
		// Start from position (0, 0)
		// Steps: W = (-1, 0), NW = (0, -1), NE = (1, -1), E = (1, 0), SE = (0, 1), SW = (-1, 1)

		int currentX = 0;
		int currentY = 0;

		for (int indexChar = 0; indexChar < (int)line.size(); indexChar++)
		{
			switch (line[indexChar])
			{
			case 'e':
				// E
				currentX++;
				break;
			case 's':
				indexChar++;
				if (line[indexChar] == 'e')
				{
					// SE
					currentY++;
				}
				else
				{
					// SW
					currentX--;
					currentY++;
				}
				break;
			case 'w':
				// W
				currentX--;
				break;
			case 'n':
				indexChar++;
				if (line[indexChar] == 'w')
				{
					currentY--;
				}
				else
				{
					// NE
					currentX++;
					currentY--;
				}
				break;
			}
		}

		// Update the "blackTiles" set
		pair<int, int> currentTile{ currentX, currentY };
		if (blackTiles.find(currentTile) != blackTiles.end())
		{
			blackTiles.erase(currentTile);
		}
		else
		{
			blackTiles.insert(currentTile);
		}
	}

	inFile.close();

	return (int)blackTiles.size();
}