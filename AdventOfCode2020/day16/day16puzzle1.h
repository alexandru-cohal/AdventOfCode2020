#ifndef DAY16PUZZLE1_H
#define DAY16PUZZLE1_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

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

void mainDay16Puzzle1();
void readInputsDay16Puzzle1(vector<rule_T>& ruleList,
							ticket_T& yourTicket,
							vector<ticket_T>& nearbyTicketList);
int solveDay16Puzzle1(vector<rule_T> ruleList,
					  vector<ticket_T> nearbyTicketList);

#endif