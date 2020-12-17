#include "day16puzzle2.h"

void mainDay16Puzzle2()
{
	vector<rule_T> ruleList;
	ticket_T yourTicket;
	vector<ticket_T> nearbyTicketList;
	readInputsDay16Puzzle2(ruleList, yourTicket, nearbyTicketList);

	cout << solveDay16Puzzle2(ruleList, yourTicket, nearbyTicketList);
}

void readInputsDay16Puzzle2(vector<rule_T>& ruleList,
							ticket_T& yourTicket,
							vector<ticket_T>& nearbyTicketList)
{
	string filename = "day16/day16Input.txt";
	ifstream inFile(filename);

	string line;

	// Read and store the rules
	getline(inFile, line);
	while (line != "")
	{
		// Get the field name
		int posFind = line.find(":");
		string field = line.substr(0, posFind);
		line.erase(line.begin(), line.begin() + posFind + 2);

		// Get the first interval
		interval_T interv1;
		posFind = line.find("-");
		interv1.min = stoi(line.substr(0, posFind));
		line.erase(line.begin(), line.begin() + posFind + 1);

		posFind = line.find(" or ");
		interv1.max = stoi(line.substr(0, posFind));
		line.erase(line.begin(), line.begin() + posFind + 4);

		// Get the second interval
		interval_T interv2;
		posFind = line.find("-");
		interv2.min = stoi(line.substr(0, posFind));
		line.erase(line.begin(), line.begin() + posFind + 1);

		interv2.max = stoi(line);

		// Create and store the rule
		rule_T currentRule{ field, interv1, interv2 };
		ruleList.push_back(currentRule);

		getline(inFile, line);
	}

	getline(inFile, line); // "your ticket:" line
	getline(inFile, line);

	// Read and store your ticket
	int findPos = line.find(",");
	while (findPos != string::npos)
	{
		yourTicket.values.push_back(stoi(line.substr(0, findPos)));
		line.erase(line.begin(), line.begin() + findPos + 1);

		findPos = line.find(",");
	}
	yourTicket.values.push_back(stoi(line));

	getline(inFile, line); // empty line
	getline(inFile, line); // "nearby tickets:" line

	// Read and store the nearby tickets
	int indexNearbyTicket = -1;
	while (getline(inFile, line))
	{
		indexNearbyTicket++;
		nearbyTicketList.push_back(ticket_T{});

		int findPos = line.find(",");
		while (findPos != string::npos)
		{
			nearbyTicketList[indexNearbyTicket].values.push_back(stoi(line.substr(0, findPos)));
			line.erase(line.begin(), line.begin() + findPos + 1);

			findPos = line.find(",");
		}
		nearbyTicketList[indexNearbyTicket].values.push_back(stoi(line));
	}


	inFile.close();
}

void eliminateInvalidTicketsPuzzle2(vector<rule_T> ruleList,
									vector<ticket_T>& nearbyTicketList)
{
	// Iterate over all the nearby tickets
	for (int indexNearbyTicket = 0; indexNearbyTicket < (int)nearbyTicketList.size(); indexNearbyTicket++)
	{
		// Iterate over all the nearby ticket's values
		for (int indexValue = 0; indexValue < (int)nearbyTicketList[indexNearbyTicket].values.size(); indexValue++)
		{
			bool flagValueValid = false;
			// Iterate over all the rules
			for (int indexRule = 0; indexRule < (int)ruleList.size(); indexRule++)
			{
				// Check if the value respects the rule
				if ((ruleList[indexRule].interv1.min <= nearbyTicketList[indexNearbyTicket].values[indexValue] &&
					ruleList[indexRule].interv1.max >= nearbyTicketList[indexNearbyTicket].values[indexValue]) ||
					(ruleList[indexRule].interv2.min <= nearbyTicketList[indexNearbyTicket].values[indexValue] &&
						ruleList[indexRule].interv2.max >= nearbyTicketList[indexNearbyTicket].values[indexValue]))
				{
					flagValueValid = true;
					break;
				}
			}

			// If no rule was found for the selected value, delete the invalid ticket
			if (!flagValueValid)
			{
				nearbyTicketList.erase(nearbyTicketList.begin() + indexNearbyTicket);
				indexNearbyTicket--;
				break;
			}
		}
	}
}

long long solveDay16Puzzle2(vector<rule_T> ruleList,
				 			ticket_T yourTicket,
							vector<ticket_T> nearbyTicketList)
{
	// Eliminate the invalid nearby tickets
	eliminateInvalidTicketsPuzzle2(ruleList, nearbyTicketList);

	// Add to the nearby ticket list your ticket for simplicity later on
	nearbyTicketList.push_back(yourTicket);

	// Determine all the fields options for each value based on the rules
	vector<valueOption_T> optionsValues;
	// Iterate over all the tickets' values
	for (int indexValue = 0; indexValue < (int)yourTicket.values.size(); indexValue++)
	{
		optionsValues.push_back(valueOption_T{});
		optionsValues[indexValue].index = indexValue;

		// Iterate over all the rules
		for (int indexRule = 0; indexRule < (int)ruleList.size(); indexRule++)
		{
			bool flagRuleOK = true;

			// Iterate over all the tickets
			for (int indexTicket = 0; indexTicket < (int)nearbyTicketList.size(); indexTicket++)
			{
				if (!((ruleList[indexRule].interv1.min <= nearbyTicketList[indexTicket].values[indexValue] &&
					ruleList[indexRule].interv1.max >= nearbyTicketList[indexTicket].values[indexValue]) ||
					(ruleList[indexRule].interv2.min <= nearbyTicketList[indexTicket].values[indexValue] &&
					ruleList[indexRule].interv2.max >= nearbyTicketList[indexTicket].values[indexValue])))
				{
					flagRuleOK = false;
					break;
				}
			}

			if (flagRuleOK)
			{
				optionsValues[indexValue].optionList.push_back(indexRule);
			}
		}
	}

	// Sort the values based on the number of options
	sort(optionsValues.begin(), optionsValues.end(), compareValueOptionT);

	// Choose an option for each value
	set<int> usedOption;
	vector<int> fieldIndexToValueIndex(ruleList.size(), 0);
	for (int indexValue = 0; indexValue < (int)yourTicket.values.size(); indexValue++)
	{
		for (int indexOption = 0; indexOption < (int)optionsValues[indexValue].optionList.size(); indexOption++)
		{
			auto findOption = usedOption.find(optionsValues[indexValue].optionList[indexOption]);
			if (findOption != usedOption.end())
			{
				optionsValues[indexValue].optionList.erase(optionsValues[indexValue].optionList.begin() + indexOption);
				indexOption--;
			}
		}

		if (optionsValues[indexValue].optionList.size() == 1)
		{
			usedOption.insert(optionsValues[indexValue].optionList[0]);
			fieldIndexToValueIndex[optionsValues[indexValue].optionList[0]] = optionsValues[indexValue].index;
		}
		else
		{
			int t = 0;
		}
	}

	// Calculate the solution
	long long multiplSol = 1;
	for (int indexRule = 0; indexRule < (int)ruleList.size(); indexRule++)
	{
		if (ruleList[indexRule].field.substr(0, 9) == "departure")
		{
			multiplSol *= yourTicket.values[fieldIndexToValueIndex[indexRule]];
		}
	}

	return multiplSol;
}

bool compareValueOptionT(valueOption_T vp1, valueOption_T vp2)
{
	return vp1.optionList.size() < vp2.optionList.size();
}