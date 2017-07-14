#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_m	ap>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

typedef long long ll;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty()) return 0;
		ll result = duration;
		for (int i = 1; i < timeSeries.size(); ++i) {
			if (timeSeries[i] - timeSeries[i - 1] < duration) {
				result += timeSeries[i] - timeSeries[i - 1];
			}
			else {
				result += duration;
			}
		}
		return int(result);
	}
};

int main()
{
	Solution s;
	cin.get();
}
