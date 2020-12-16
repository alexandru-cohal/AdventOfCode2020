#include "day16puzzle1.h"

void mainDay16Puzzle1()
{
	vector<rule_T> ruleList;
	ticket_T yourTicket;
	vector<ticket_T> nearbyTicketList;
	readInputsDay16Puzzle1(ruleList, yourTicket, nearbyTicketList);

	cout << solveDay16Puzzle1(ruleList, nearbyTicketList);
}

void readInputsDay16Puzzle1(vector<rule_T>& ruleList,
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

int solveDay16Puzzle1(vector<rule_T> ruleList,
					  vector<ticket_T> nearbyTicketList)
{
	int scanningError = 0;

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

			// If no rule was found for the selected value, update the scanning error rate
			if (!flagValueValid)
			{
				scanningError += nearbyTicketList[indexNearbyTicket].values[indexValue];
			}
		}
	}

	return scanningError;
}