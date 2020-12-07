#include "day7puzzle2.h"

void mainDay7Puzzle2()
{
	map<string, vector<element_T>> luggageRule;
	readInputsDay7Puzzle2(luggageRule);

	map<string, int> sumChildQuantity;
	cout << calculateContainedLuggagesPuzzle2(luggageRule, sumChildQuantity, "shiny gold") - 1; // -1 because the Shiny Gold bag is not considered in the total sum
}

void readInputsDay7Puzzle2(map<string, vector<element_T>>& luggageRule)
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

					element_T luggageChild{ luggageChildType, stoi(luggageChildQuantity) };

					// Add the parent - child relation to the luggage rule map
					luggageRule[luggageParentType].push_back(luggageChild);
				}
			}
		}
	}

	inFile.close();
}

int calculateContainedLuggagesPuzzle2(map<string, vector<element_T>>& luggageRule, 
									  map<string, int>& sumChildQuantity, 
									  string currentLuggageType)
{
	// Check if the value for "currentLuggageType" is already calculated and stored in "sumChildQuantity"
	if (sumChildQuantity.find(currentLuggageType) != sumChildQuantity.end())
	{
		// The value for "currentLuggageType" is already calculated => Return it
		return sumChildQuantity[currentLuggageType];
	}
	else
	{
		// The value for "currentLuggageType" is not already calculated => Calculate it
		// Check if "currentLuggageType" has any bags inside
		if (luggageRule.find(currentLuggageType) != luggageRule.end())
		{
			// "currentLuggageType" has bags inside => Calculate the sum of the bags from inside
			int sum = 1;
			for (int indexChild = 0; indexChild < (int)luggageRule[currentLuggageType].size(); indexChild++)
			{
				element_T child = luggageRule[currentLuggageType][indexChild];
				sum += calculateContainedLuggagesPuzzle2(luggageRule, sumChildQuantity, child.type) * child.quantity;
			}
			sumChildQuantity[currentLuggageType] = sum;
			return sum;
		}
		else
		{
			// "currentLuggageType" has no bags inside
			sumChildQuantity[currentLuggageType] = 1;
			return 1;
		}
	}
}