#include "day4puzzle1.h"

void mainDay4Puzzle1()
{
	cout << readInputsDay4Puzzle1AndSolve();
}

int readInputsDay4Puzzle1AndSolve()
{
	string filename = "day4/day4Input.txt";
	ifstream inFile(filename);

	int numValidPassport = 0;

	bool byr = 0;
	bool iyr = 0;
	bool eyr = 0;
	bool hgt = 0;
	bool hcl = 0;
	bool ecl = 0;
	bool pid = 0;

	if (inFile.is_open())
	{
		string line;
		while (getline(inFile, line))
		{
			if (line == "")
			{
				if (byr == 1 && iyr == 1 && eyr == 1 &&
					hgt == 1 && hcl == 1 && ecl == 1 && pid == 1)
				{
					numValidPassport += 1;
				}

				byr = 0;
				iyr = 0;
				eyr = 0;
				hgt = 0;
				hcl = 0;
				ecl = 0;
				pid = 0;
			}
			else
			{
				if (line.find("byr:") != string::npos)
				{
					byr = 1;
				}
				if (line.find("iyr:") != string::npos)
				{
					iyr = 1;
				}
				if (line.find("eyr:") != string::npos)
				{
					eyr = 1;
				}
				if (line.find("hgt:") != string::npos)
				{
					hgt = 1;
				}
				if (line.find("hcl:") != string::npos)
				{
					hcl = 1;
				}
				if (line.find("ecl:") != string::npos)
				{
					ecl = 1;
				}
				if (line.find("pid:") != string::npos)
				{
					pid = 1;
				}
			}
		}

		if (byr == 1 && iyr == 1 && eyr == 1 &&
			hgt == 1 && hcl == 1 && ecl == 1 && pid == 1)
		{
			numValidPassport += 1;
		}
	}

	return numValidPassport;
}