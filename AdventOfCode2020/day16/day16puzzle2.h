#ifndef DAY16PUZZLE2_H
#define DAY16PUZZLE2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct interval
{
	int min;
	int max;
} interval_T;

typedef struct rule
{
	string field;
	interval_T interv1;
	interval_T interv2;
} rule_T;

typedef struct ticket
{
	vector<int> values;
} ticket_T;

void mainDay16Puzzle2();
void readInputsDay16Puzzle2(vector<rule_T>& ruleList,
							ticket_T& yourTicket,
							vector<ticket_T>& nearbyTicketList);
void eliminateInvalidTicketsPuzzle2(vector<rule_T> ruleList,
									vector<ticket_T>& nearbyTicketList);
long long solveDay16Puzzle2(vector<rule_T> ruleList,
							ticket_T yourTicket,
							vector<ticket_T> nearbyTicketList);
bool testConfigDay16Puzzle2(vector<int> config,
							vector<rule_T> ruleList,
							vector<ticket_T> ticketList);

#endif