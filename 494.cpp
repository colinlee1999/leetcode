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

typedef vector<int> VI;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		result = 0;
		dfs(0, nums, 0, S);
		return result;
	}

private:
	void dfs(int depth, VI& nums, int cur, int S) {
		if (depth == nums.size()) {
			if (cur == S) ++result;
		}
		else {
			dfs(depth + 1, nums, cur + nums[depth], S);
			dfs(depth + 1, nums, cur - nums[depth], S);
		}
	}

	int result;
};

int main()
{
	Solution s;
	cin.get();
}
