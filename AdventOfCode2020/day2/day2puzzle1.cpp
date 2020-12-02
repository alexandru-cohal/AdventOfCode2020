#include "day2puzzle1.h"

void readInputsDay2Puzzle1(vector<int>& minOccurenceArray,
							vector<int>& maxOccurenceArray,
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
			minOccurenceArray.push_back(stoi(line.substr(0, indexFound)));
			line.erase(line.begin(), line.begin() + (indexFound + 1));

			indexFound = line.find(' ');
			maxOccurenceArray.push_back(stoi(line.substr(0, indexFound)));
			line.erase(line.begin(), line.begin() + (indexFound + 1));

			indexFound = line.find(':');
			letterArray.push_back(line.substr(0, indexFound));
			line.erase(line.begin(), line.begin() + (indexFound + 2));

			passwordArray.push_back(line);
		}
	}

	inFile.close();
}

int solveDay2Puzzle1(vector<int>& minOccurenceArray,
						vector<int>& maxOccurenceArray,
						vector<string>& letterArray,
						vector<string>& passwordArray)
{
	int correctPasswords = 0;

	for (int indexPolicy = 0; indexPolicy < passwordArray.size(); indexPolicy++)
	{
		int letterCounter = 0;
		for (int indexCharacter = 0; indexCharacter < passwordArray[indexPolicy].size(); indexCharacter++)
		{
			if (letterArray[indexPolicy][0] == passwordArray[indexPolicy][indexCharacter])
			{
				letterCounter++;
			}
		}

		if (minOccurenceArray[indexPolicy] <= letterCounter && letterCounter <= maxOccurenceArray[indexPolicy])
		{
			correctPasswords++;
		}
	}

	return correctPasswords;
}