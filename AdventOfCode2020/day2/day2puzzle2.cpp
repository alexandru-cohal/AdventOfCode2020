#include "day2puzzle2.h"

void readInputsDay2Puzzle2(vector<int>& charIndex1Array,
							vector<int>& charIndex2Array,
							vector<string>& letterArray,
							vector<string>& passwordArray)
{
	string filename = "day2/day2Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			int indexFound;

			indexFound = line.find('-');
			charIndex1Array.push_back(stoi(line.substr(0, indexFound)));
			line.erase(line.begin(), line.begin() + (indexFound + 1));

			indexFound = line.find(' ');
			charIndex2Array.push_back(stoi(line.substr(0, indexFound)));
			line.erase(line.begin(), line.begin() + (indexFound + 1));

			indexFound = line.find(':');
			letterArray.push_back(line.substr(0, indexFound));
			line.erase(line.begin(), line.begin() + (indexFound + 2));

			passwordArray.push_back(line);
		}
	}

	inFile.close();
}

int solveDay2Puzzle2(vector<int>& charIndex1Array,
						vector<int>& charIndex2Array,
						vector<string>& letterArray,
						vector<string>& passwordArray)
{
	int correctPasswords = 0;

	for (int indexPolicy = 0; indexPolicy < passwordArray.size(); indexPolicy++)
	{
		int letterCounter = 0;
		
		if ((letterArray[indexPolicy][0] == passwordArray[indexPolicy][charIndex1Array[indexPolicy] - 1]) ^
			(letterArray[indexPolicy][0] == passwordArray[indexPolicy][charIndex2Array[indexPolicy] - 1]))
		{
			correctPasswords++;
		}
	}

	return correctPasswords;
}