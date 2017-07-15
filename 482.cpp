#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result = "";
		int pos = 0;
		for (auto it = S.rbegin(); it != S.rend(); ++it) {
			if (*it == '-') continue;
			if (*it >= 'a' && *it <= 'z')
				*it += 'A' - 'a';
			if (pos > 0 && pos % K == 0) {
				result = "-" + result;
			}
			++pos;
			result = string(1, *it) + result;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
