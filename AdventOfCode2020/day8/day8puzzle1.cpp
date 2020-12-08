#include "day8puzzle1.h"

void mainDay8Puzzle1()
{
	vector<line_T> program;
	readInputsDay8Puzzle1(program);

	cout << solveDay8Puzzle1(program);
}

void readInputsDay8Puzzle1(vector<line_T>& program)
{
	string filename = "day8/day8Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			// Get the luggage parent type
			int indexDelimiter = line.find(" ");
			string instruction = line.substr(0, indexDelimiter);
			line.erase(line.begin(), line.begin() + indexDelimiter + 1); // +1 is used for erasing the space after
			int argument = stoi(line);

			program.push_back(line_T{ instruction, argument });
		}
	}

	inFile.close();
}

int solveDay8Puzzle1(vector<line_T> program)
{
	const int numProgramLine = program.size();
	vector<bool> visitedLine(program.size(), false);

	int accValue = 0;
	int currentLine = 0;
	while (!visitedLine[currentLine])
	{
		visitedLine[currentLine] = true;
		
		if (program[currentLine].instruction == "nop")
		{
			currentLine++;
		}
		else if (program[currentLine].instruction == "acc")
		{
			accValue += program[currentLine].argument;
			currentLine++;
		}
		else
		{
			currentLine += program[currentLine].argument;
		}
	}

	return accValue;
}