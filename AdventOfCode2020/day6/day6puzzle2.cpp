#include "day6puzzle2.h"

void mainDay6Puzzle2()
{
	cout << readInputsDay6Puzzle2AndSolve();
}

int readInputsDay6Puzzle2AndSolve()
{
	string filename = "day6/day6Input.txt";
	ifstream inFile(filename);

	unordered_map<char, int> answer;
	int sum = 0;
	int personsCount = 0;

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			if (line == "")
			{
				// The counting for the group which just finished
				for (auto answerElem = answer.begin(); answerElem != answer.end(); answerElem++)
				{
					if (answerElem->second == personsCount)
					{
						sum++;
					}
				}
				
				// Reset for a new group
				personsCount = 0;
				answer.clear();
			}
			else
			{
				// A new person
				personsCount++;

				for (int indexAnswer = 0; indexAnswer < (int)line.size(); indexAnswer++)
				{
					answer[line[indexAnswer]]++;
				}
			}
		}
	}

	// The counting for the last group because there is no empty line at the end of this group
	for (auto answerElem = answer.begin(); answerElem != answer.end(); answerElem++)
	{
		if (answerElem->second == personsCount)
		{
			sum++;
		}
	}

	inFile.close();

	return sum;
}
