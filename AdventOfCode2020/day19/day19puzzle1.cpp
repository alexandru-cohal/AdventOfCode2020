#include "day19puzzle1.h"

void mainDay19Puzzle1()
{
	map<int, string> rule;
	vector<string> receivedMsgs;
	readInputsDay19Puzzle1(rule, receivedMsgs);

	map<int, vector<string>> ruleMsgs;
	solveRuleDay19Puzzle1(rule, 0, ruleMsgs);

	cout << solveDay19Puzzle1(ruleMsgs[0], receivedMsgs);
}

void readInputsDay19Puzzle1(map<int, string>& rule, vector<string>& receivedMsgs)
{
	string filename = "day19/day19Input.txt";
	ifstream inFile(filename);

	string line;
	getline(inFile, line);
	line = line + " ";

	while (line[0] >= '0' && line[0] <= '9')
	{
		int indexSeparator = line.find(": ");
		int ruleNumber = stoi(line.substr(0, indexSeparator));
		line.erase(line.begin(), line.begin() + indexSeparator + 2);

		rule[ruleNumber] = line;

		getline(inFile, line);
		line = line + " ";
	}

	while (getline(inFile, line))
	{
		receivedMsgs.push_back(line);
	}

	inFile.close();
}

void solveRuleDay19Puzzle1(map<int, string>& rule, int indexQueryRule, map<int, vector<string>>& ruleMsgs)
{
	vector<string> queryRuleMsgsPart1;

	// If the indexQueryRule rule was not processed already
	if (rule[indexQueryRule].size() != 0)
	{
		// If the indexQueryRule rule matches a single character
		if (rule[indexQueryRule][0] == '\"')
		{
			ruleMsgs[indexQueryRule].push_back(rule[indexQueryRule].substr(1, size(rule[indexQueryRule]) - 3));
			rule[indexQueryRule] = "";
		}
		else
		{
			while (rule[indexQueryRule].size() > 0)
			{
				int indexSeparator = rule[indexQueryRule].find(" ");
				string term = rule[indexQueryRule].substr(0, indexSeparator);
				rule[indexQueryRule].erase(rule[indexQueryRule].begin(), rule[indexQueryRule].begin() + indexSeparator + 1);

				if (term[0] >= '0' && term[0] <= '9')
				{
					int indexSubrule = stoi(term);

					// Check if the indexSubrule wasn't already processed
					if (rule[indexSubrule].size() > 0)
					{
						solveRuleDay19Puzzle1(rule, indexSubrule, ruleMsgs);
					}

					if (queryRuleMsgsPart1.size() == 0)
					{
						queryRuleMsgsPart1 = ruleMsgs[indexSubrule];
					}
					else
					{
						vector<string> queryRuleMsgsPart1New;
						for (int indexQueryRuleMsgsPart1 = 0; indexQueryRuleMsgsPart1 < (int)queryRuleMsgsPart1.size(); indexQueryRuleMsgsPart1++)
						{
							for (int indexSubruleMsgs = 0; indexSubruleMsgs < (int)ruleMsgs[indexSubrule].size(); indexSubruleMsgs++)
							{
								queryRuleMsgsPart1New.push_back(queryRuleMsgsPart1[indexQueryRuleMsgsPart1] + ruleMsgs[indexSubrule][indexSubruleMsgs]);
							}
						}
						queryRuleMsgsPart1 = queryRuleMsgsPart1New;
					}
				}
				else if (term[0] == '|')
				{
					ruleMsgs[indexQueryRule] = queryRuleMsgsPart1;
					queryRuleMsgsPart1.clear();
				}
			}

			ruleMsgs[indexQueryRule].insert(ruleMsgs[indexQueryRule].end(), queryRuleMsgsPart1.begin(), queryRuleMsgsPart1.end());
		}
	}
}

int solveDay19Puzzle1(vector<string> rule0Msgs, vector<string> receivedMsgs)
{
	int numReceivedMsgsMatchRule0 = 0;
	set<string> rule0MsgsSet;

	// Create a set with the rule 0 valid messages
	for (int indexRule0Msgs = 0; indexRule0Msgs < (int)rule0Msgs.size(); indexRule0Msgs++)
	{
		rule0MsgsSet.insert(rule0Msgs[indexRule0Msgs]);
	}

	// Search in the set the received messages
	for (int indexReceivedMsgs = 0; indexReceivedMsgs < (int)receivedMsgs.size(); indexReceivedMsgs++)
	{
		if (rule0MsgsSet.find(receivedMsgs[indexReceivedMsgs]) != rule0MsgsSet.end())
		{
			numReceivedMsgsMatchRule0++;
		}
	}

	return numReceivedMsgsMatchRule0;
}