#include "day14puzzle1.h"

void mainDay14Puzzle1()
{
	map<int, long long> memory;
	readInputsDay14Puzzle1(memory);

	cout << solveDay14Puzzle1(memory);
}

void readInputsDay14Puzzle1(map<int, long long>& memory)
{
	string filename = "day14/day14Input.txt";
	ifstream inFile(filename);

	long long maskAND = 0;
	long long maskOR = 0;

	string line;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			// The second character can be either 'a' from 'mask' or 'e' from 'mem'
			if (line[1] == 'a')
			{
				// The current line contains a Mask definition

				// Remove the beginning "mask = " and keep the actual mask
				line.erase(line.begin(), line.begin() + 7);

				// From the given mask, create 2 masks:
				// maskAND (X -> 1, 1 -> 1, 0 -> 0)
				// maskOR  (X -> 0, 1 -> 1, 0 -> 0)
				maskAND = 0;
				maskOR = 0;
				for (int indexBit = 0; indexBit < 36; indexBit++)
				{
					long long power2 = (long long)pow(2, indexBit);
					switch (line[35 - indexBit])
					{
					case 'X':
						maskAND += power2;
						break;
					case '0':
						break;
					case '1':
						maskAND += power2;
						maskOR += power2;
						break;
					}
				}
			}
			else
			{
				// The current line contains a Memory writing instruction

				int posOpenSqBracket = line.find('[');
				int posEqual = line.find(" = ");

				int memAdr = stoi(line.substr(posOpenSqBracket + 1, posEqual - posOpenSqBracket - 2));
				int value = stoi(line.substr(posEqual + 3, line.size() - posEqual - 3));

				memory[memAdr] = ((value & maskAND) | maskOR);
			}
		}
	}

	inFile.close();
}

long long solveDay14Puzzle1(map<int, long long> memory)
{
	long long sum = 0;
	for (auto indexMemory = memory.begin(); indexMemory != memory.end(); indexMemory++)
	{
		sum += indexMemory->second;
	}

	return sum;
}