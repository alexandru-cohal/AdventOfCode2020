#include "day21puzzle1.h"

void mainDay21Puzzle1()
{
	vector<food_T> foodList;
	set<string> allergensSet;
	readInputsDay21Puzzle1(foodList, allergensSet);

	cout << solveDay21Puzzle1(foodList, allergensSet);
}

void readInputsDay21Puzzle1(vector<food_T>& foodList, set<string>& allergensSet)
{
	string filename = "day21/day21Input.txt";
	ifstream inFile(filename);

	string line;
	while (getline(inFile, line))
	{
		// Process the food description stored in the string "line"
		food_T currentFood;
		
		// Ingredients
		int indexContains = line.find(" (contains ");
		string ingredients = line.substr(0, indexContains);

		while (ingredients != "")
		{
			int indexSpace = ingredients.find(" ");
			string currentIngredient;
			if (indexSpace != string::npos)
			{
				currentIngredient = ingredients.substr(0, indexSpace);
				ingredients.erase(ingredients.begin(), ingredients.begin() + indexSpace + 1);
			}
			else
			{
				currentIngredient = ingredients;
				ingredients = "";
			}
			currentFood.ingredients.insert(currentIngredient);
		}

		// Allergens
		line.erase(line.begin(), line.begin() + indexContains + 11);
		string allergens = line.substr(0, line.size() - 1);
		
		while (allergens != "")
		{
			int indexComma = allergens.find(", ");
			string currentAllergen;
			if (indexComma != string::npos)
			{
				currentAllergen = allergens.substr(0, indexComma);
				allergens.erase(allergens.begin(), allergens.begin() + indexComma + 2);
			}
			else
			{
				currentAllergen = allergens;
				allergens = "";
			}
			currentFood.allergens.insert(currentAllergen);
			allergensSet.insert(currentAllergen);
		}

		foodList.push_back(currentFood);
	}

	inFile.close();
}

long long solveDay21Puzzle1(vector<food_T> foodList, set<string> allergensSet)
{
	// Create the "allergen2Ingredients" set which contains for each allergen all the possible ingredients which can contain it
	map<string, set<string>> allergen2Ingredients;

	for (auto itAllergensSet = allergensSet.begin(); itAllergensSet != allergensSet.end(); itAllergensSet++)
	{
		string currentAllergen = (*itAllergensSet);
		set<string> intersecIngred;

		for (int indexFood = 0; indexFood < (int)foodList.size(); indexFood++)
		{
			if (foodList[indexFood].allergens.find(currentAllergen) != foodList[indexFood].allergens.end())
			{
				// currentAllergen was found in the current food (i.e. foodList[indexFood])
				if (intersecIngred.empty())
				{
					intersecIngred = foodList[indexFood].ingredients;
				}
				else
				{
					set<string> intersecIngredNew;
					set_intersection(intersecIngred.begin(), intersecIngred.end(),
						foodList[indexFood].ingredients.begin(), foodList[indexFood].ingredients.end(),
						inserter(intersecIngredNew, intersecIngredNew.begin()));
					intersecIngred = intersecIngredNew;
				}
			}
		}

		for (auto itIntersecIngred = intersecIngred.begin(); itIntersecIngred != intersecIngred.end(); itIntersecIngred++)
		{
			allergen2Ingredients[currentAllergen].insert(*itIntersecIngred);
		}
	}

	// Choose one ingredient for each allergen
	set<string> checkedAllergen;
	for (int indexCycle = 0; indexCycle < (int)allergen2Ingredients.size(); indexCycle++)
	{
		// Search for the allergen with only one element in the ingredients list
		for (auto itAllergen = allergen2Ingredients.begin(); itAllergen != allergen2Ingredients.end(); itAllergen++)
		{
			string currentAllergen = itAllergen->first;
			if (itAllergen->second.size() == 1 && checkedAllergen.find(currentAllergen) == checkedAllergen.end())
			{
				checkedAllergen.insert(currentAllergen);
				string currentIngredient = *itAllergen->second.begin();

				for (auto itAllergenUpdate = allergen2Ingredients.begin(); itAllergenUpdate != allergen2Ingredients.end(); itAllergenUpdate++)
				{
					if (itAllergenUpdate != itAllergen)
					{
						if (itAllergenUpdate->second.find(currentIngredient) != itAllergenUpdate->second.end())
						{
							itAllergenUpdate->second.erase(currentIngredient);
						}
					}
				}

				break;
			}
		}
	}

	// Create a set with the ingredients which contain allergens
	set<string> ingredientsWithAllergens;
	for (auto itAllergen = allergen2Ingredients.begin(); itAllergen != allergen2Ingredients.end(); itAllergen++)
	{
		ingredientsWithAllergens.insert(*itAllergen->second.begin());
	}

	// Count the number of ingredients from all the foods which don't have any allergen
	int numOccurenceIngredWithoutAllergens = 0;
	for (int indexFood = 0; indexFood < (int)foodList.size(); indexFood++)
	{
		set<string> intersecIngredWithAllergens;
		set_intersection(foodList[indexFood].ingredients.begin(), foodList[indexFood].ingredients.end(),
			ingredientsWithAllergens.begin(), ingredientsWithAllergens.end(),
			inserter(intersecIngredWithAllergens, intersecIngredWithAllergens.begin()));

		numOccurenceIngredWithoutAllergens += foodList[indexFood].ingredients.size() - intersecIngredWithAllergens.size();
	}

	return numOccurenceIngredWithoutAllergens;
}