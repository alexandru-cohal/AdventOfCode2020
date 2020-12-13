#include "day13puzzle1.h"

void mainDay13Puzzle1()
{
	int earliestTime;
	vector<int> busID;
	readInputsDay13Puzzle1(earliestTime, busID);

	cout << solveDay13Puzzle1(earliestTime, busID);
}

void readInputsDay13Puzzle1(int& earliestTime, vector<int>& busID)
{
	string filename = "day13/day13Input.txt";
	ifstream inFile(filename);

	string busIDString;

	inFile >> earliestTime;
	inFile >> busIDString;

	// Check all the elements of the enumeration and store the integer values only
	int indexFind = busIDString.find(",");
	while (indexFind != string::npos)
	{
		string currentID = busIDString.substr(0, indexFind);
		if (currentID != "x")
		{
			busID.push_back(stoi(currentID));
		}
		busIDString.erase(busIDString.begin(), busIDString.begin() + indexFind + 1);
		indexFind = busIDString.find(",");
	}

	// For the last element of the enumeration, which is not followed by ","
	if (busIDString != "x")
	{
		busID.push_back(stoi(busIDString));
	}

	inFile.close();
}

int solveDay13Puzzle1(int earliestTime, vector<int>busID)
{
	int minWaitTime = INT_MAX;
	int busIDMinWaitTime = 0;

	for (int indexID = 0; indexID < (int)busID.size(); indexID++)
	{
		int currentWaitTime;
		if (earliestTime == (earliestTime / busID[indexID]) * busID[indexID])
		{
			currentWaitTime = 0;
		}
		else
		{
			currentWaitTime = (earliestTime / busID[indexID] + 1) * busID[indexID] - earliestTime;
		}

		if (currentWaitTime < minWaitTime)
		{
			minWaitTime = currentWaitTime;
			busIDMinWaitTime = busID[indexID];
		}
	}

	return minWaitTime * busIDMinWaitTime;
}