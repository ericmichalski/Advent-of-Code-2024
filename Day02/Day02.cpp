// Parent Includes
#include "Day02.h"

// C++ Includes
#include "iostream"
#include "fstream"
#include "string"
#include "sstream"

using namespace std;

int Day02::Main()
{
	ifstream file("Day02/input.txt");

	if (!file)
	{
		cerr << "Failed to open file" << endl;
		return 0;
	}

	Day02 obj;

	string line;
	int numSafe = 0;

	// Read each line
	while (getline(file, line))
	{
		stringstream ss(line);

		vector<int> report;
		int num;

		while (ss >> num)
		{
			report.push_back(num);
		}

		// Check if safe or if safe with removing a number
		if (obj.IsSafe(report))
		{
			numSafe++;
		}
		else if (obj.IsSafeWithOneRemoval(report))
		{
			numSafe++;
		}
	}

	cout << "Num safe: " << numSafe << endl;

	file.close();

	return 1;
}

bool Day02::IsSafe(const vector<int>& report)
{
	bool bIsAscending = true, bIsDescending = true;

	for (int i = 1; i < report.size(); ++i)
	{
		int diff = report[i] - report[i - 1];

		// Ensure difference is between 1 and 3
		if (abs(diff) < 1 || abs(diff) > 3)
		{
			return false;
		}

		// Check if it is increasing or decreasing
		if (diff < 0)
		{
			bIsAscending = false;
		}
		if (diff > 0)
		{
			bIsDescending = false;
		}
	}

	return bIsAscending || bIsDescending;
}

bool Day02::IsSafeWithOneRemoval(vector<int>& report)
{
	// Try removing each num and check if it becomes safe
	for (int i = 0; i < report.size(); ++i)
	{
		vector<int> adjustedReport = report;
		adjustedReport.erase(adjustedReport.begin() + i);

		if (IsSafe(adjustedReport))
		{
			return true;
		}
	}

	return false;
}