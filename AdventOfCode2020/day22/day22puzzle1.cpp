#include "day22puzzle1.h"

void mainDay22Puzzle1()
{
	deque<int> player1;
	deque<int> player2;
	readInputsDay22Puzzle1(player1, player2);

	cout << solveDay22Puzzle1(player1, player2);
}

void readInputsDay22Puzzle1(deque<int>& player1, deque<int>& player2)
{
	string filename = "day22/day22Input.txt";
	ifstream inFile(filename);

	string line;

	getline(inFile, line); // "Player 1:" line
	getline(inFile, line);
	while (line != "")
	{
		player1.push_back(stoi(line));
		getline(inFile, line);
	}

	getline(inFile, line); // "Player 2:" line
	while (getline(inFile, line))
	{
		player2.push_back(stoi(line));
	}

	inFile.close();
}

int solveDay22Puzzle1(deque<int> player1, deque<int> player2)
{
	// Play the game
	while (!player1.empty() && !player2.empty())
	{
		if (player1.front() > player2.front())
		{
			player1.push_back(player1.front());
			player1.push_back(player2.front());
			player1.pop_front();
			player2.pop_front();
		}
		else
		{
			player2.push_back(player2.front());
			player2.push_back(player1.front());
			player1.pop_front();
			player2.pop_front();
		}
	}

	// Count the winner's score
	deque<int> playerWinner;
	if (player1.empty())
	{
		playerWinner = player2;
	}
	else
	{
		playerWinner = player1;
	}

	long long playerWinnerScore = 0;
	int indexCard = playerWinner.size();
	for (auto itPlayerWinner = playerWinner.begin(); itPlayerWinner != playerWinner.end(); itPlayerWinner++)
	{
		playerWinnerScore += (long long)*itPlayerWinner * indexCard;
		indexCard--;
	}

	return playerWinnerScore;
}