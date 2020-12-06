#include "day6puzzle1.h"

void mainDay6Puzzle1()
{
	cout << readInputsDay6Puzzle1AndSolve();
}

int readInputsDay6Puzzle1AndSolve()
{
	string filename = "day6/day6Input.txt";
	ifstream inFile(filename);

	set<char> answer;
	int sum = 0;

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			if (line == "")
			{
				sum += answer.size();
				answer.clear();
			}
			else
			{
				for (int indexAnswer = 0; indexAnswer < (int)line.size(); indexAnswer++)
				{
					answer.insert(line[indexAnswer]);
				}
			}
		}
	}

	sum += answer.size();

	inFile.close();

	return sum;
}
