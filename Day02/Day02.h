#pragma once

// C++ Includes
#include "sstream"
#include "vector"

using namespace std;

class Day02
{
public:
	int Main();

	bool IsSafe(const vector<int>& report);

	bool IsSafeWithOneRemoval(vector<int>& report);
};

