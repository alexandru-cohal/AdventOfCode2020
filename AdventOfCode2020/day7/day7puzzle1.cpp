#include "day7puzzle1.h"

void mainDay7Puzzle1()
{
	map<string, vector<element_T>> luggageRule;
	readInputsDay7Puzzle1(luggageRule);

	cout << solveDay7Puzzle1(luggageRule);
}

void readInputsDay7Puzzle1(map<string, vector<element_T>>& luggageRule)
{
	string filename = "day7/day7Input.txt";
	ifstream inFile(filename);

	if (inFile.is_open())
	{
		string line;
		int indexDelimiter;
		while (getline(inFile, line))
		{
			// Get the luggage parent type
			indexDelimiter = line.find(" bags contain");
			string luggageParentType = line.substr(0, indexDelimiter);
			line.erase(line.begin(), line.begin() + (indexDelimiter + (strlen(" bags contain") + 1))); // +1 is used for erasing the space after

			// Get the content of the current luggage, one child luggage after another one
			while (line.size() > 0)
			{
				// Get the luggage child type and quantity 
				string luggageParentContent;
				indexDelimiter = line.find(",");
				if (indexDelimiter == string::npos)
				{
					luggageParentContent = line.substr(0, line.size() - 1); // -1 is used for not getting the dot 
					line.erase();
				}
				else
				{
					luggageParentContent = line.substr(0, indexDelimiter);
					line.erase(line.begin(), line.begin() + (indexDelimiter + 2)); // -2 is used for erasing the comma and the space after
				}

				// Separate the type of child luggage and its quantity
				if (luggageParentContent != "no other bags")
				{
					indexDelimiter = luggageParentContent.find(" ");
					string luggageChildQuantity = luggageParentContent.substr(0, indexDelimiter);
					luggageParentContent.erase(luggageParentContent.begin(), luggageParentContent.begin() + (indexDelimiter + 1)); // +1 for removing the space after 

					indexDelimiter = luggageParentContent.find(" bag");
					string luggageChildType = luggageParentContent.substr(0, indexDelimiter);

					element_T luggageChild{ luggageParentType, stoi(luggageChildQuantity) };

					// Add the child - parent relation to the luggage rule map
					luggageRule[luggageChildType].push_back(luggageChild);
				}
			}
		}
	}

	inFile.close();
}

int solveDay7Puzzle1(map<string, vector<element_T>>& luggageRule)
{
	set<string> outermostLuggage;
	queue<string> parentLuggageQueue;

	parentLuggageQueue.push("shiny gold");
	while (!parentLuggageQueue.empty())
	{
		string currentLuggageType = parentLuggageQueue.front();
		parentLuggageQueue.pop();

		for (int indexParent = 0; indexParent < (int)luggageRule[currentLuggageType].size(); indexParent++)
		{
			parentLuggageQueue.push(luggageRule[currentLuggageType][indexParent].type);
			outermostLuggage.insert(luggageRule[currentLuggageType][indexParent].type);
		}
	}

	return outermostLuggage.size();
}