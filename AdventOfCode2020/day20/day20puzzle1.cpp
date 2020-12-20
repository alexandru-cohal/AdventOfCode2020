#include "day20puzzle1.h"

void mainDay20Puzzle1()
{
	vector<tile_T> tileList;
	readInputsDay20Puzzle1(tileList);

	cout << solveDay20Puzzle1(tileList);
}

void readInputsDay20Puzzle1(vector<tile_T>& tileList)
{
	string filename = "day20/day20Input.txt";
	ifstream inFile(filename);

	string line;
	while (!inFile.eof())
	{
		// For each tile store in a tile_T variable: id, top edge, bottom edge, left edge and right edge
		getline(inFile, line);
		int indexSeparator = line.find(" ");
		string idString = line.substr(indexSeparator + 1, line.size() - 6);

		tile_T currentTile;
		currentTile.id = stoi(idString);

		getline(inFile, line);
		currentTile.top = line;
		while (line != "")
		{
			currentTile.left +=  line[0];
			currentTile.right += line[line.size() - 1];
			currentTile.bottom = line;

			if (inFile.eof())
			{
				break;
			}
			getline(inFile, line);
		}

		tileList.push_back(currentTile);
	}

	inFile.close();
}

long long solveDay20Puzzle1(vector<tile_T> tileList)
{
	// Create the edges' map based on the edges and their reverses of each tile
	map<string, int> edge;
	for (int indexTile = 0; indexTile < (int)tileList.size(); indexTile++)
	{
		string top = tileList[indexTile].top;
		edge[top]++;
		reverse(top.begin(), top.end());
		edge[top]++;
		
		string bottom = tileList[indexTile].bottom;
		edge[bottom]++;
		reverse(bottom.begin(), bottom.end());
		edge[bottom]++;

		string left = tileList[indexTile].left;
		edge[left]++;
		reverse(left.begin(), left.end());
		edge[left]++;

		string right = tileList[indexTile].right;
		edge[right]++;
		reverse(right.begin(), right.end());
		edge[right]++;
	}

	// Check each tile and count the number of occurence of its edges and of its reversed edges
	int numEdge;
	long long cornerIdProd = 1;
	for (int indexTile = 0; indexTile < (int)tileList.size(); indexTile++)
	{
		numEdge = 0;

		string top = tileList[indexTile].top;
		if (edge.find(top) != edge.end())
		{
			numEdge += edge[top];
		}
		reverse(top.begin(), top.end());		
		if (edge.find(top) != edge.end())
		{
			numEdge += edge[top];
		}

		string bottom = tileList[indexTile].bottom;
		if (edge.find(bottom) != edge.end())
		{
			numEdge += edge[bottom];
		}
		reverse(bottom.begin(), bottom.end());
		if (edge.find(bottom) != edge.end())
		{
			numEdge += edge[bottom];
		}

		string left = tileList[indexTile].left;
		if (edge.find(left) != edge.end())
		{
			numEdge += edge[left];
		}
		reverse(left.begin(), left.end());
		if (edge.find(left) != edge.end())
		{
			numEdge += edge[left];
		}

		string right = tileList[indexTile].right;
		if (edge.find(right) != edge.end())
		{
			numEdge += edge[right];
		}
		reverse(right.begin(), right.end());
		if (edge.find(right) != edge.end())
		{
			numEdge += edge[right];
		}

		// Multiply the IDs of the corner tiles
		// numEdge is 12 for corner tile, 14 for edge tile (but not corner) and 16 for inner tile
		if (numEdge == 12)
		{
			cornerIdProd *= tileList[indexTile].id;
		}
	}

	return cornerIdProd;
}