#include "day8puzzle2.h"

void mainDay8Puzzle2()
{
	vector<line_T> program;
	readInputsDay8Puzzle2(program);

	cout << solveDay8Puzzle2(program);
}

void readInputsDay8Puzzle2(vector<line_T>& program)
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

int solveDay8Puzzle2(vector<line_T> program)
{
	// Generate a new version of the program by inverting the "nop" and "jmp" instructions one by one
	for (int indexLine = 0; indexLine < (int)program.size(); indexLine++)
	{
		int accValue = 0;
		if (program[indexLine].instruction == "nop")
		{
			program[indexLine].instruction = "jmp";

			// Test the new program
			if (executeProgramPuzzle2(program, accValue))
			{
				return accValue;
			}

			program[indexLine].instruction = "nop";
		}
		else if (program[indexLine].instruction == "jmp")
		{
			program[indexLine].instruction = "nop";

			// Test the new program
			if (executeProgramPuzzle2(program, accValue))
			{
				return accValue;
			}

			program[indexLine].instruction = "jmp";
		}
	}

	return 0; // If a solution exists, this line shouldn't be executed
}

bool executeProgramPuzzle2(vector<line_T> program, int& accValue)
{
	vector<bool> visitedLine(program.size(), false);

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

		if (currentLine >= program.size())
		{
			return true;
		}
	}

	return false;
}