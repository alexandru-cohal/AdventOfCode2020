#include "day12puzzle2.h"

void mainDay12Puzzle2()
{
	vector<instruction_T> steps;
	readInputsDay12Puzzle2(steps);

	cout << solveDay12Puzzle2(steps);
}

void readInputsDay12Puzzle2(vector<instruction_T>& steps)
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

int solveDay12Puzzle2(vector<instruction_T> steps)
{
	int horizPosShip = 0; // North is positive, South is negative
	int vertPosShip = 0; // East is positive, West is negative 
	int horizPosWaypoint = 10; // North is positive, South is negative
	int vertPosWaypoint = 1; // East is positive, West is negative

	for (int indexStep = 0; indexStep < steps.size(); indexStep++)
	{
		if (steps[indexStep].direction == "N")
		{
			vertPosWaypoint += steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "S")
		{
			vertPosWaypoint -= steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "E")
		{
			horizPosWaypoint += steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "W")
		{
			horizPosWaypoint -= steps[indexStep].value;
		}
		else if (steps[indexStep].direction == "L")
		{
			int horizPosWaypointOld = horizPosWaypoint;
			int vertPosWaypointOld = vertPosWaypoint;
			switch (steps[indexStep].value)
			{
			case 90:
				vertPosWaypoint = horizPosWaypointOld;
				horizPosWaypoint = -vertPosWaypointOld;
				break;
			case 180:
				vertPosWaypoint = -vertPosWaypointOld;
				horizPosWaypoint = -horizPosWaypointOld;
				break;
			case 270:
				vertPosWaypoint = -horizPosWaypoint;
				horizPosWaypoint = vertPosWaypointOld;
				break;
			}
		}
		else if (steps[indexStep].direction == "R")
		{
			int horizPosWaypointOld = horizPosWaypoint;
			int vertPosWaypointOld = vertPosWaypoint;
			switch (steps[indexStep].value)
			{
			case 90:
				vertPosWaypoint = -horizPosWaypointOld;
				horizPosWaypoint = vertPosWaypointOld;
				break;
			case 180:
				vertPosWaypoint = -vertPosWaypointOld;
				horizPosWaypoint = -horizPosWaypointOld;
				break;
			case 270:
				vertPosWaypoint = horizPosWaypoint;
				horizPosWaypoint = -vertPosWaypointOld;
				break;
			}
		}
		else
		{
			vertPosShip += vertPosWaypoint * steps[indexStep].value;
			horizPosShip += horizPosWaypoint * steps[indexStep].value;
		}
	}

	return abs(vertPosShip) + abs(horizPosShip);
}