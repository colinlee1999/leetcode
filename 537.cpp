#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int a1, a2;
		int b1, b2;
		sscanf(a.c_str(), "%d+%di", &a1, &a2);
		sscanf(b.c_str(), "%d+%di", &b1, &b2);
		ostringstream os;
		os << a1 * b1 - a2 * b2 << "+" << a1 * b2 + a2 * b1 << "i";
		return os.str();
	}
};

int main()
{
	Solution s;
	cin.get();
}
