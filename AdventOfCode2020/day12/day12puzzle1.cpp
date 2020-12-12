#include "day12puzzle1.h"

void mainDay12Puzzle1()
{
	vector<instruction_T> steps;
	readInputsDay12Puzzle1(steps);

	cout << solveDay12Puzzle1(steps);
}

void readInputsDay12Puzzle1(vector<instruction_T>& steps)
{
	string filename = "day12/day12Input.txt";
	ifstream inFile(filename);

	string line;
	instruction_T currentInstruction;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			currentInstruction.direction = line[0];
			currentInstruction.value = stoi(line.substr(1, line.size()));

			steps.push_back(currentInstruction);
		};
	}

	inFile.close();
}

int solveDay12Puzzle1(vector<instruction_T> steps)
{
	int horizPos = 0; // North is positive, South is negative
	int vertPos = 0; // East is positive, West is negative
	int orientation = 90; // North = 0, East = 90, South = 180; West = 270 

	for (int indexStep = 0; indexStep < steps.size(); indexStep++)
	{
		if (steps[indexStep].direction == "N")
		{
			vertPos += steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "S")
		{
			vertPos -= steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "E")
		{
			horizPos += steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "W")
		{
			horizPos -= steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "L")
		{
			orientation -= steps[indexStep].value;
			if (orientation < 0)
			{
				orientation += 360;
			}
		}
		else if (steps[indexStep].direction == "R")
		{
			orientation += steps[indexStep].value;
			if (orientation >= 360)
			{
				orientation -= 360;
			}
		}
		else
		{
			switch (orientation)
			{
			case 0:
				vertPos += steps[indexStep].value;
				break;
			case 90:
				horizPos += steps[indexStep].value;
				break;
			case 180:
				vertPos -= steps[indexStep].value;
				break;
			case 270:
				horizPos -= steps[indexStep].value;
				break;
			}
		}
	}

	return abs(vertPos) + abs(horizPos);
}