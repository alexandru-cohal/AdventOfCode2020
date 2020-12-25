#include "day25puzzle1.h"

void mainDay25Puzzle1()
{
	long long cardPublicKey;
	long long doorPublicKey;

	readInputsDay25Puzzle1(cardPublicKey, doorPublicKey);

	cout << solveDay25Puzzle1(cardPublicKey, doorPublicKey);
}

void readInputsDay25Puzzle1(long long& cardPublicKey, long long& doorPublicKey)
{
	string filename = "day25/day25Input.txt";
	ifstream inFile(filename);

	inFile >> cardPublicKey;

	inFile >> doorPublicKey;

	inFile.close();
}

int findLoopSizeDay25Puzzle1(long long key)
{
	int loopSize = 0;
	long long currentValue = 1;

	while (currentValue != key)
	{
		loopSize++;
		currentValue *= INITIALSUBJECTNUMBER;
		currentValue %= DIVIDERNUMBER;
	}

	return loopSize;
}

long long findEncryptionKey(int loopSize, long long publicKey)
{
	long long currentValue = 1;

	for (int indexLoop = 1; indexLoop <= loopSize; indexLoop++)
	{
		currentValue *= publicKey;
		currentValue %= DIVIDERNUMBER;
	}

	return currentValue;
}

long long solveDay25Puzzle1(long long cardPublicKey, long long doorPublicKey)
{
	int cardLoopSize = findLoopSizeDay25Puzzle1(cardPublicKey);
	long long encryptionKey = findEncryptionKey(cardLoopSize, doorPublicKey);

	return encryptionKey;
}