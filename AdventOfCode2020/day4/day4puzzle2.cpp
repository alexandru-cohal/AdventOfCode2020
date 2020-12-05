#include "day4puzzle2.h"

void mainDay4Puzzle2()
{
	cout << readInputsDay4Puzzle2AndSolve();
}

int readInputsDay4Puzzle2AndSolve()
{
	string filename = "day4/day4Input.txt";
	ifstream inFile(filename);

	int numValidPassport = 0;

	size_t found;
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
				int indexSpace = line.find(' '), indexColon;
				string pair, key, value;

				while (indexSpace != string::npos)
				{
					pair = line.substr(0, indexSpace);
					indexColon = pair.find(':');
					key = pair.substr(0, indexColon);
					value = pair.substr(indexColon + 1, pair.size());

					checkValidityKeyValue(key, value, byr, iyr, eyr, hgt, hcl, ecl, pid);

					line.erase(line.begin(), line.begin() + (indexSpace + 1));
					indexSpace = line.find(' ');
				}
				pair = line;

				indexColon = pair.find(':');
				key = pair.substr(0, indexColon);
				value = pair.substr(indexColon + 1, pair.size());

				checkValidityKeyValue(key, value, byr, iyr, eyr, hgt, hcl, ecl, pid);
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

void checkValidityKeyValue(string key, string value, bool &byr, bool &iyr, bool &eyr, bool &hgt, bool &hcl, bool &ecl, bool &pid)
{
	if (key == "byr")
	{
		int valueNumber = stoi(value);
		if (valueNumber >= 1920 && valueNumber <= 2002)
		{
			byr = 1;
		}
	}
	else if (key == "iyr")
	{
		int valueNumber = stoi(value);
		if (valueNumber >= 2010 && valueNumber <= 2020)
		{
			iyr = 1;
		}
	}
	else if (key == "eyr")
	{
		int valueNumber = stoi(value);
		if (valueNumber >= 2020 && valueNumber <= 2030)
		{
			eyr = 1;
		}
	}
	else if (key == "hgt")
	{
		if (value[value.size() - 2] == 'c' && value[value.size() - 1] == 'm')
		{
			value.erase(value.end() - 2, value.end());
			int valueNumber = stoi(value);
			if (valueNumber >= 150 && valueNumber <= 193)
			{
				hgt = 1;
			}
		}
		else if (value[value.size() - 2] == 'i' && value[value.size() - 1] == 'n')
		{
			value.erase(value.end() - 2, value.end());
			int valueNumber = stoi(value);
			if (valueNumber >= 59 && valueNumber <= 76)
			{
				hgt = 1;
			}
		}
	}
	else if (key == "hcl")
	{
		if (value[0] == '#' && value.size() == 7)
		{
			hcl = 1;
			for (int index = 1; index <= 6; index++)
			{
				if (!((value[index] >= '0' && value[index] <= '9') || (value[index] >= 'a' && value[index] <= 'f')))
				{
					hcl = 0;
					break;
				}
			}
		}
	}
	else if (key == "ecl")
	{
		if (value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth")
		{
			ecl = 1;
		}
	}
	else if (key == "pid")
	{
		if (value.size() == 9)
		{
			pid = 1;
			for (int index = 0; index < 9; index++)
			{
				if ((value[index] < '0' || value[index] > '9'))
				{
					pid = 0;
					break;
				}
			}
		}
	}
}