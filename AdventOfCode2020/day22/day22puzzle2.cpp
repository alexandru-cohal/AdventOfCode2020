#include "day22puzzle2.h"

void mainDay22Puzzle2()
{
	deque<int> player1;
	deque<int> player2;
	readInputsDay22Puzzle2(player1, player2);

	cout << solveDay22Puzzle2(player1, player2);
}

void readInputsDay22Puzzle2(deque<int>& player1, deque<int>& player2)
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

long long solveDay22Puzzle2(deque<int> player1, deque<int> player2)
{
	deque<int> playerWinner;

	// Play the game and store the winner's deck
	if (playGameDay22Puzzle2(player1, player2) == 0)
	{
		playerWinner = player1;
	}
	else
	{
		playerWinner = player2;
	}

	// Count the winner's score
	long long playerWinnerScore = 0;
	int indexCard = playerWinner.size();
	for (auto itPlayerWinner = playerWinner.begin(); itPlayerWinner != playerWinner.end(); itPlayerWinner++)
	{
		playerWinnerScore += (long long)*itPlayerWinner * indexCard;
		indexCard--;
	}

	return playerWinnerScore;
}

bool playGameDay22Puzzle2(deque<int>& player1, deque<int>& player2) // Returns 0 if Player 1 wins, 1 if Player 2 wins
{
	set<vector<int>> playedConfig;

	// Play the game
	while (!player1.empty() && !player2.empty())
	{
		// Create the configuration "code"
		vector<int> config;
		config.push_back(player1.size());
		config.push_back(player2.size());
		config.insert(config.end(), player1.begin(), player1.end());
		config.insert(config.end(), player2.begin(), player2.end());

		if (playedConfig.find(config) != playedConfig.end())
		{
			// The same configuration was found => Player 1 wins
			return 0;
		}
		else
		{
			// Add the current configuration
			playedConfig.insert(config);

			if (player1.front() <= (int)player1.size() - 1 && player2.front() <= (int)player2.size() - 1)
			{
				// Prepare the copied deck for Player 1
				deque<int> copyPlayer1 = player1;
				while ((int)copyPlayer1.size() - 1 > copyPlayer1.front())
				{
					copyPlayer1.pop_back();
				}
				copyPlayer1.pop_front();

				// Prepare the copied deck for Player 2
				deque<int> copyPlayer2 = player2;
				while ((int)copyPlayer2.size() - 1 > copyPlayer2.front())
				{
					copyPlayer2.pop_back();
				}
				copyPlayer2.pop_front();

				// Play the sub-game
				if (playGameDay22Puzzle2(copyPlayer1, copyPlayer2) == 0)
				{
					// Player 1 won the sub-game
					player1.push_back(player1.front());
					player1.push_back(player2.front());
					player1.pop_front();
					player2.pop_front();
				}
				else
				{
					// Player 2 won the sub-game
					player2.push_back(player2.front());
					player2.push_back(player1.front());
					player1.pop_front();
					player2.pop_front();
				}
			}
			else if (player1.front() > player2.front())
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
	}

	if (player1.empty())
	{
		// Player 2 won
		return 1;
	}
	else
	{
		// Player 1 won
		return 0;
	}
}