#include "day23puzzle1.h"

void mainDay23Puzzle1()
{
	vector<int> labels;
	readInputsDay23Puzzle1(labels);

	cout << solveDay23Puzzle1(labels);
}

void readInputsDay23Puzzle1(vector<int>& labels)
{
	string filename = "day23/day23Input.txt";
	ifstream inFile(filename);

	string line;
	getline(inFile, line);

	for (int indexLabel = 0; indexLabel < (int)line.size(); indexLabel++)
	{
		labels.push_back(line[indexLabel] - '0');
	}

	inFile.close();
}

string solveDay23Puzzle1(vector<int> labels)
{
	// The index of the current cup is always kept on 1
	// The indices of the picked-up cups are always 2, 3 and 4

	// Create a set with the labels within the destination cup is searched for
	set<int> labelsToSearch;
	for (auto itLabels = labels.begin() + 4; itLabels != labels.end(); itLabels++)
	{
		labelsToSearch.insert(*itLabels);
	}
	// Iterate over each move
	for (int indexMove = 1; indexMove <= NUMMOVES; indexMove++)
	{
		// Search for the destination cup and change its label is not found
		int labelToFind = labels[0] - 1;
		while (labelsToSearch.find(labelToFind) == labelsToSearch.end())
		{
			labelToFind--;
			if (labelToFind < *labelsToSearch.begin())
			{
				labelToFind = *(--labelsToSearch.end());
			}
		}

		// Update the set
		labelsToSearch.insert(labels[0]);
		labelsToSearch.insert(labels[1]);
		labelsToSearch.insert(labels[2]);
		labelsToSearch.insert(labels[3]);

		// Move the picked-up cups
		labels.insert(find(labels.begin() + 4, labels.end(), labelToFind) + 1, labels.begin() + 1, labels.begin() + 4);
		// Add the current label to the end 
		labels.push_back(labels[0]);
		// Remove the current label and the picked-up cups (they are duplicated now)
		labels.erase(labels.begin(), labels.begin() + 4);

		// Update the set
		labelsToSearch.erase(labels[0]);
		labelsToSearch.erase(labels[1]);
		labelsToSearch.erase(labels[2]);
		labelsToSearch.erase(labels[3]);
	}

	// Create the string from the current cups configuration such that to have cup 1 on the first position
	string finalLabels = "";

	for (auto itLabels = labels.begin(); itLabels != labels.end(); itLabels++)
	{
		finalLabels += to_string(*itLabels);
	}
	rotate(finalLabels.begin(), finalLabels.begin() + finalLabels.find("1"), finalLabels.end());

	return finalLabels.substr(1); // Return the string without the first cup (i.e. cup 1)
}