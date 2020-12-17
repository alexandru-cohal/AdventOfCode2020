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

	// Generate the first configuration (i.e. [0, 1, 2, ... yourTicket.size() - 1])
	vector<int> config; // configurationField[i] = the field index (i.e. the rule index) for the i-th element of a ticket
	for (int indexConfigElem = 0; indexConfigElem < (int)yourTicket.values.size(); indexConfigElem++)
	{
		config.push_back(indexConfigElem);
	}

	// Find the valid configuration
	bool flagConfigOK = false;

	while (true)
	{
		if (testConfigDay16Puzzle2(config, ruleList, nearbyTicketList))
		{
			// Valid configuration
			break;
		}
		else
		{
			// Invalid confugration
			// Generate the next permutation
			if (!next_permutation(config.begin(), config.end()))
			{
				// If all permutations were checked and the initial one was reached => Return -1
				return -1;
			}
		}
	}

	// Get the final result
	long long multiplicationResult = 1;
	// Iterate over all the rules
	for (int indexRule = 0; indexRule < (int)ruleList.size(); indexRule++)
	{
		// If the rule field name starts with the word "departure"
		if (ruleList[indexRule].field.substr(0, 9) == "departure")
		{
			// Find the element in the configuration which has the associated field index equal with the current rule index
			int indexConfigElem;
			for (indexConfigElem = 0; indexConfigElem < (int)config.size(); indexConfigElem++)
			{
				if (config[indexConfigElem] == indexRule)
				{
					break;
				}
			}

			multiplicationResult *= yourTicket.values[indexConfigElem];
		}
	}

	return multiplicationResult;
}

bool testConfigDay16Puzzle2(vector<int> config,
				vector<rule_T> ruleList,
				vector<ticket_T> ticketList)
{
	// Iterate over all the tickets
	for (int indexTicket = 0; indexTicket < (int)ticketList.size(); indexTicket++)
	{
		// Iterate over all the ticket's values
		for (int indexValue = 0; indexValue < (int)ticketList[0].values.size(); indexValue++)
		{
			// Check if the value respects the rule chosen in the configuration for that value index
			if (!((ruleList[config[indexValue]].interv1.min <= ticketList[indexTicket].values[indexValue] &&
				   ruleList[config[indexValue]].interv1.max >= ticketList[indexTicket].values[indexValue]) ||
				  (ruleList[config[indexValue]].interv2.min <= ticketList[indexTicket].values[indexValue] &&
				   ruleList[config[indexValue]].interv2.max >= ticketList[indexTicket].values[indexValue])))
			{
				return false;
			}
		}
	}

	return true;
}