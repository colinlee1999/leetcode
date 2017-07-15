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

typedef long long ll;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		ll result = 0;
		ll cur = 1;
		int nlen = nums.size();
		ll ones = nlen;
		int found = true;
		while (found) {
			ones = 0;
			found = false;
			for (auto it : nums) {
				if (it & cur) ++ones;
				if (it >= cur) found = true;
			}
			if (!found) break;
			result += (nlen - ones) * ones;
			cur <<= 1;
		}
		return int(result);
	}
};

int main()
{
	Solution s;
	cin.get();
}
