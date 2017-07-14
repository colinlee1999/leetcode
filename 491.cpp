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

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef unordered_set<string> USET_VI;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		VI cur;
		USET_VI uset;
		VVI result;
		dfs(0, nums, cur, uset, result);
		return result;
	}

private:
	void dfs(int depth, VI& nums, VI& cur, USET_VI& uset, VVI& result) {
		if (depth == nums.size()) {
			if (check(cur)) {
				string s = toString(cur);
				if (uset.find(s) == uset.end()) {
					uset.insert(s);
					result.push_back(cur);
				}
			}
		}
		else {
			dfs(depth + 1, nums, cur, uset, result);
			cur.push_back(nums[depth]);
			dfs(depth + 1, nums, cur, uset, result);
			cur.pop_back();
		}
	}

	bool check(VI& cur) {
		if (cur.size() < 2) return false;
		for (int i = 1; i < cur.size(); ++i) {
			if (cur[i] < cur[i - 1]) return false;
		}
		return true;
	}

	string toString(VI& cur) {
		string s = "";
		for (auto it : cur) {
			s += to_string(it) + ",";
		}
		return s;
	}
};

int main()
{
	Solution s;
	cin.get();
}
