#include "day13puzzle2.h"

void mainDay13Puzzle2()
{
	int earliestTime;
	vector<busData> bus;
	readInputsDay13Puzzle2(earliestTime, bus);

	cout << solveDay13Puzzle2(earliestTime, bus);
}

void readInputsDay13Puzzle2(int& earliestTime, vector<busData>& bus)
{
	string filename = "day13/day13Input.txt";
	ifstream inFile(filename);

	string busIDString;
	int busIndex = 0;

	inFile >> earliestTime;
	inFile >> busIDString;

	// Check all the elements of the enumeration and store the integer values only
	int indexFind = busIDString.find(",");
	while (indexFind != string::npos)
	{
		string currentID = busIDString.substr(0, indexFind);
		if (currentID != "x")
		{
			bus.push_back(busData{ stoi(currentID), busIndex });
		}
		busIDString.erase(busIDString.begin(), busIDString.begin() + indexFind + 1);
		indexFind = busIDString.find(",");
		busIndex++;
	}

	// For the last element of the enumeration, which is not followed by ","
	if (busIDString != "x")
	{
		bus.push_back(busData{ stoi(busIDString), busIndex });
	}

	inFile.close();
}

// Calculates the modulo inverse of a with respect to m using the extended Euclid Algorithm
// Calculates x such that a*x mod m = 1 is true
// (Based on: https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/)
unsigned long long calcModularInv(unsigned long long a, unsigned long long m)
{
	unsigned long long m0 = m, t, q;
	unsigned long long x0 = 0, x1 = 1;

	if (m == 1)
	{
		return 0;
	}

	// Apply extended Euclid Algorithm 
	while (a > 1)
	{
		// q is quotient 
		q = a / m;
		t = m;

		// m is the remainder now, process same as Euclid algorithm 
		m = a % m;
		a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}

	// Make x1 positive 
	if (x1 < 0)
	{
		x1 += m0;
	}

	return x1;
}

unsigned long long solveDay13Puzzle2(int earliestTime, vector<busData> bus)
{
	// Apply the Chinese Remainder Theorem
	// (Based on: https://brilliant.org/wiki/chinese-remainder-theorem/)

	// Calculate N
	unsigned long long N = 1;
	for (int indexBus = 0; indexBus < (int)bus.size(); indexBus++)
	{
		N *= bus[indexBus].id;
	}

	// Calculate X
	// a_i = bus[indexBus].id - bus[indexBus].index
	// n_i = bus[indexBus].id
	// y_i = M / bus[indexBus].id
	// z_i mod n_i = calcModularInv(y_i, n_i) = calcModularInv((M / bus[indexBus].id), bus[indexBus].id)
	// X = product of (y_i, z_i, a_i)
	// (because a_0 = 0, the product which defines X starts from index 1)
	unsigned long long X = 0;
	for (int indexBus = 1; indexBus < (int)bus.size(); indexBus++)
	{
		X += (N / bus[indexBus].id) * 
			 calcModularInv((N / bus[indexBus].id), bus[indexBus].id) * 
			 ((unsigned long long)bus[indexBus].id - bus[indexBus].index);
	}

	X %= N;

	return X;
}