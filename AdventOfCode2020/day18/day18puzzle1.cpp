#include "day18puzzle1.h"

void mainDay18Puzzle1()
{
	cout << readInputsAndSolveDay18Puzzle1();
}

long long readInputsAndSolveDay18Puzzle1()
{
	string filename = "day18/day18Input.txt";
	ifstream inFile(filename);

	long long sumExpr = 0;

	string line;
	while (getline(inFile, line))
	{
		line += " ";
		sumExpr += solveExprDay18Puzzle1(line);
	}

	inFile.close();

	return sumExpr;
}

long long solveExprDay18Puzzle1(string& expr)
{
	long long term1;
	long long term2;
	int operation = 0; // 1 = addition, 2 = multiplication

	while (!expr.empty())
	{
		if (expr[0] == ' ')
		{
			expr.erase(expr.begin(), expr.begin() + 1);
		}
		else if (expr[0] == '(')
		{
			if (operation == 0)
			{
				// If it is the first term => Just store
				expr.erase(expr.begin(), expr.begin() + 1);
				term1 = solveExprDay18Puzzle1(expr);
			}
			else
			{
				// If it is the second term => Store and Evaluate the last operation
				expr.erase(expr.begin(), expr.begin() + 1);
				term2 = solveExprDay18Puzzle1(expr);

				// Get the result of the last operation
				if (operation == 1)
				{
					term1 = term1 + term2;
				}
				else
				{
					term1 = term1 * term2;
				}
				operation = 0;
			}
		}
		else if (expr[0] == ')')
		{
			expr.erase(expr.begin(), expr.begin() + 1);
			return term1;
		}
		else if (expr[0] >= '0' && expr[0] <= '9')
		{
			int indexSpace = expr.find(' ');
			int indexCloseBracket = expr.find(')');
			int indexEnd;
			if (indexCloseBracket != string::npos && indexCloseBracket < indexSpace)
			{
				indexEnd = indexCloseBracket;
			}
			else
			{
				indexEnd = indexSpace;
			}

			if (operation == 0)
			{
				// If it is the first term => Just store
				term1 = stoi(expr.substr(0, indexEnd));
			}
			else
			{
				// If it is the second term => Store and Evaluate the last operation
				term2 = stoi(expr.substr(0, indexEnd));

				// Get the result of the last operation
				if (operation == 1)
				{
					term1 = term1 + term2;
				}
				else
				{
					term1 = term1 * term2;
				}
				operation = 0;
			}
			expr.erase(expr.begin(), expr.begin() + indexEnd);
		}
		else
		{
			switch (expr[0])
			{
			case '+':
				operation = 1;
				break;
			case '*':
				operation = 2;
				break;
			}
			expr.erase(expr.begin(), expr.begin() + 1);
		}
	}

	return term1;
}
