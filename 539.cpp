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

typedef vector<int> VI;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		VI v;
		for (auto s : timePoints) {
			v.push_back(getMinute(s));
		}
		sort(v.begin(), v.end());
		int result = 1440 - (v.back() - v.front());
		for (int i = 1; i < v.size(); ++i) {
			if (v[i] - v[i - 1] < result) {
				result = v[i] - v[i - 1];
			}
		}
		return result;
	}
}

private:
	int getMinute(string& s) {
		int h, m;
		sscanf(s.c_str(), "%d:%d", &h, &m);
		return h * 60 + m;
	}
};

int main()
{
	Solution s;
	cin.get();
}
