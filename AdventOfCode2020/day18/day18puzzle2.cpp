#include "day18puzzle2.h"

void mainDay18Puzzle2()
{
	cout << readInputsAndSolveDay18Puzzle2();
}

long long readInputsAndSolveDay18Puzzle2()
{
	string filename = "day18/day18Input.txt";
	ifstream inFile(filename);

	long long sumExpr = 0;

	string line;
	while (getline(inFile, line))
	{
		line += " ";
		sumExpr += evaluateExpressionDay18Puzzle2(line);
		// Based on the solution from https://stackoverflow.com/questions/9329406/evaluating-arithmetic-expressions-from-string-in-c
	}

	inFile.close();

	return sumExpr;
}

long long evaluateExpressionDay18Puzzle2(string& expr)
{
	long long result = evaluateTermDay18Puzzle2(expr);

	while (expr[0] == '*')
	{
		expr.erase(expr.begin(), expr.begin() + 2); // remove the sign and the space after
		result *= evaluateTermDay18Puzzle2(expr);
	}

	return result;
}

long long evaluateTermDay18Puzzle2(string& expr)
{
	long long result = evaluateFactorDay18Puzzle2(expr);

	while (expr[0] == '+')
	{
		expr.erase(expr.begin(), expr.begin() + 2); // remove the sign and the space after
		result += evaluateFactorDay18Puzzle2(expr);
	}

	return result;
}

long long evaluateFactorDay18Puzzle2(string& expr)
{
	if (expr[0] >= '0' && expr[0] <= '9')
	{
		return evaluateNumberDay18Puzzle2(expr);
	}
	else if (expr[0] == '(')
	{
		expr.erase(expr.begin(), expr.begin() + 1); // remove the open bracket
		long long result = evaluateExpressionDay18Puzzle2(expr);
		expr.erase(expr.begin(), expr.begin() + 1); // remove the closed bracket and the space after

		if (expr[0] == ' ')
		{
			expr.erase(expr.begin(), expr.begin() + 1); // remove the space after the closed bracket (if exists)
		}

		return result;
	}
}

long long evaluateNumberDay18Puzzle2(string& expr)
{
	long long number = 0;
	while (expr[0] >= '0' && expr[0] <= '9')
	{
		number = number * 10 + (expr[0] - '0');
		expr.erase(expr.begin(), expr.begin() + 1); // remove the digit
	}

	if (expr[0] == ' ')
	{
		expr.erase(expr.begin(), expr.begin() + 1); // remove the space after the number (if exists)
	}

	return number;
}
