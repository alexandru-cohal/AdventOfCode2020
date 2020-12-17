#include "day17puzzle2.h"

void mainDay17Puzzle2()
{
	char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE];
	for (int indexW = 0; indexW < MAXSIZE; indexW++)
	{
		for (int indexDim = 0; indexDim < MAXSIZE; indexDim++)
		{
			for (int indexRow = 0; indexRow < MAXSIZE; indexRow++)
			{
				for (int indexCol = 0; indexCol < MAXSIZE; indexCol++)
				{
					cubesSet[indexW][indexDim][indexRow][indexCol] = '.';
				}
			}
		}
	}
	readInputsDay17Puzzle2(cubesSet);

	cout << solveDay17Puzzle2(cubesSet);
}

void readInputsDay17Puzzle2(char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE])
{
	string filename = "day17/day17Input.txt";
	ifstream inFile(filename);

	int indexRow = -1;
	string line;
	while (getline(inFile, line))
	{
		indexRow++;
		for (int indexCol = 0; indexCol < (int)line.size(); indexCol++)
		{
			// Place the initial layer in the middle of the 4D space of MAXSIZE on each dimension
			cubesSet[11][11][indexRow + ((MAXSIZE - line.size()) / 2 + 1)][indexCol + ((MAXSIZE - line.size()) / 2 + 1)] = line[indexCol];
		}
	}

	inFile.close();
}

int countActiveNeighbDay17Puzzle2(int indexW, int indexDim, int indexRow, int indexCol, char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE])
{
	int activeNeighb = 0;

	for (int stepW = -1; stepW <= 1; stepW++)
	{
		for (int stepDim = -1; stepDim <= 1; stepDim++)
		{
			for (int stepRow = -1; stepRow <= 1; stepRow++)
			{
				for (int stepCol = -1; stepCol <= 1; stepCol++)
				{
					if (!(stepW == 0 && stepDim == 0 && stepRow == 0 && stepCol == 0))
					{
						if (cubesSet[indexW + stepW][indexDim + stepDim][indexRow + stepRow][indexCol + stepCol] == '#')
						{
							activeNeighb++;
						}
					}
				}
			}
		}
	}

	return activeNeighb;
}

void copyCubesSetDay17Puzzle2(char cubesSetNew[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE], char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE])
{
	for (int indexW = 0; indexW < MAXSIZE; indexW++)
	{
		for (int indexDim = 1; indexDim < MAXSIZE - 1; indexDim++)
		{
			for (int indexRow = 1; indexRow < MAXSIZE - 1; indexRow++)
			{
				for (int indexCol = 1; indexCol < MAXSIZE - 1; indexCol++)
				{
					cubesSet[indexW][indexDim][indexRow][indexCol] = cubesSetNew[indexW][indexDim][indexRow][indexCol];
				}
			}
		}
	}
}

int solveDay17Puzzle2(char cubesSet[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE])
{
	int activeCubes;

	for (int indexCycle = 1; indexCycle <= NUMCYCLES; indexCycle++)
	{
		// Initialize the new cubes set with inactive cubes
		char cubesSetNew[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE];
		for (int indexW = 0; indexW < MAXSIZE; indexW++)
		{
			for (int indexDim = 0; indexDim < MAXSIZE; indexDim++)
			{
				for (int indexRow = 0; indexRow < MAXSIZE; indexRow++)
				{
					for (int indexCol = 0; indexCol < MAXSIZE; indexCol++)
					{
						cubesSetNew[indexW][indexDim][indexRow][indexCol] = '.';
					}
				}
			}
		}

		activeCubes = 0;

		// Iterate over each cube and check if the state is kept or changed
		for (int indexW = 1; indexW < MAXSIZE - 1; indexW++)
		{
			for (int indexDim = 1; indexDim < MAXSIZE - 1; indexDim++)
			{
				for (int indexRow = 1; indexRow < MAXSIZE - 1; indexRow++)
				{
					for (int indexCol = 1; indexCol < MAXSIZE - 1; indexCol++)
					{
						int activeNeighb = countActiveNeighbDay17Puzzle2(indexW, indexDim, indexRow, indexCol, cubesSet);
						if (cubesSet[indexW][indexDim][indexRow][indexCol] == '#')
						{
							if (activeNeighb == 2 || activeNeighb == 3)
							{
								cubesSetNew[indexW][indexDim][indexRow][indexCol] = '#';
								activeCubes++;
							}
							else
							{
								cubesSetNew[indexW][indexDim][indexRow][indexCol] = '.';
							}
						}
						else if (cubesSet[indexW][indexDim][indexRow][indexCol] == '.')
						{
							if (activeNeighb == 3)
							{
								cubesSetNew[indexW][indexDim][indexRow][indexCol] = '#';
								activeCubes++;
							}
							else
							{
								cubesSetNew[indexW][indexDim][indexRow][indexCol] = '.';
							}
						}
					}
				}
			}
		}

		// Copy in the cubesSet variable the new configuration of the cubes at the end of the current cycle
		copyCubesSetDay17Puzzle2(cubesSetNew, cubesSet);
	}

	return activeCubes;
}
