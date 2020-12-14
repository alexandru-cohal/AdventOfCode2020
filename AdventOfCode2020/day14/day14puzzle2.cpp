#include "day14puzzle2.h"

void mainDay14Puzzle2()
{
	map<long long, long long> memory;
	readInputsDay14Puzzle2(memory);

	cout << solveDay14Puzzle2(memory);
}

void readInputsDay14Puzzle2(map<long long, long long>& memory)
{
	string filename = "day14/day14Input.txt";
	ifstream inFile(filename);

	long long maskAND = 0;
	long long maskOR = 0;
	vector<int> xPos;

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
				// maskAND (X -> 0, 1 -> 1, 0 -> 1)
				// maskOR  (X -> 0, 1 -> 1, 0 -> 0)
				maskAND = 0;
				maskOR = 0;
				xPos.clear();
				for (int indexBit = 0; indexBit < 36; indexBit++)
				{
					long long power2 = (long long)pow(2, indexBit);
					switch (line[35 - indexBit])
					{
					case 'X':
						xPos.push_back(indexBit);
						break;
					case '0':
						maskAND += power2;
						break;
					case '1':
						maskOR += power2;
						maskAND += power2;
						break;
					}
				}
			}
			else
			{
				// The current line contains a Memory writing instruction

				int posOpenSqBracket = line.find('[');
				int posEqual = line.find(" = ");

				long long memAdr = (long long)stoi(line.substr(posOpenSqBracket + 1, posEqual - posOpenSqBracket - 2));
				int value = stoi(line.substr(posEqual + 3, line.size() - posEqual - 3));

				// Apply the mask to the memory address (
				// - the bits of the memory corresponding to the bits X of the mask are set to 0
				// - the bits of the memory corresponding to the bits 1 of the mask are set to 1
				// - the bits of the memory corresponding to the bits 0 of the mask are left unchanged
				memAdr = ((memAdr & maskAND) | maskOR);

				// Iterate over all the numbers between 0 and 2^numberOfXBitsInMask - 1. 
				// Each numbers represents a combinations of values of the X bits of the mask
				for (int combination = 0; combination < pow(2, xPos.size()); combination++)
				{
					long long memAdrCombination = memAdr;
					// Check which bits of the current combination are equal with 1 and add set the corresponding bits of the address to 1 (based on the location of the X bit in the mask)
					for (int indexXPos = 0; indexXPos < (int)xPos.size(); indexXPos++)
					{
						if ((long long)pow(2, indexXPos) & combination)
						{
							memAdrCombination += (long long)pow(2, xPos[indexXPos]);
						}
					}

					// Store in the current memory location the value
					memory[memAdrCombination] = value;
				}
			}
		}
	}

	inFile.close();
}

long long solveDay14Puzzle2(map<long long, long long> memory)
{
	long long sum = 0;
	for (auto indexMemory = memory.begin(); indexMemory != memory.end(); indexMemory++)
	{
		sum += indexMemory->second;
	}

	return sum;
}