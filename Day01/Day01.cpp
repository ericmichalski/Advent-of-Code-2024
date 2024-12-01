// Parent Includes
#include "Day01.h"

// C++ Includes
#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	ifstream file("Day01/input.txt");

	if (!file)
	{
		cerr << "Failed to open file" << endl;
		return 0;
	}

	vector<int> vecLeft;
	vector<int> vecRight;

	// Read each line and retrieve each pair of integers
	string line;
	while (getline(file, line))
	{
		istringstream ss(line);

		int x, y;
		ss >> x >> y;

		vecLeft.push_back(x);
		vecRight.push_back(y);
	}

	if (vecLeft.size() <= 0 || vecRight.size() <= 0)
	{
		cerr << "File was empty or incomplete" << endl;
		return 0;
	}

	// Sort both
	sort(vecLeft.begin(), vecLeft.end());
	sort(vecRight.begin(), vecRight.end());

	Day01 obj;
	const int totalDist = obj.GetTotalDistance(vecLeft, vecRight);
	cout << "Total distance between the two lists is: " << totalDist << endl;

	const int totalSimilarity = obj.GetTotalSimilarity(vecLeft, vecRight);
	cout << "Total simularity : " << totalSimilarity << endl;

	file.close();
}

int Day01::GetTotalDistance(const vector<int>& vecLeft, const vector<int>& vecRight)
{
	int total = 0;

	// Assumption that both are equal sizes
	// Subtract each side from each other and add to total
	for (int i = 0; i < vecLeft.size(); ++i)
	{
		total += abs(vecLeft[i] - vecRight[i]);
	}

	return total;
}

int Day01::GetTotalSimilarity(const vector<int>& vecLeft, const vector<int>& vecRight)
{
	int totalSimilarity = 0;
	for (int i = 0; i < vecLeft.size(); ++i)
	{
		const int leftVal = vecLeft[i];

		int numInRight = 0;

		// Certainly not the fastest.
		// Could remove performing several loops based on the values since they're sorted by not doing it if it's too small
		// Also could stop searching vecRight once it was greater than the current value
		for (int j = 0; j < vecRight.size(); ++j)
		{
			if (leftVal == vecRight[j])
			{
				numInRight++;
			}
		}
		totalSimilarity += leftVal * numInRight;
	}

	return totalSimilarity;
}
