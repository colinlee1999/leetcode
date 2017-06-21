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
using namespace std;

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		for (auto it : words) {
			uset.insert(it);
		}
		vector<string> result;
		for (auto it : words) {
			if (!dfs(it, 0, 0)) {
				result.push_back(it);
			}
		}
		return result;
	}

private:
	unordered_set<string> uset;

	bool dfs(const string & s, int pos, int depth) {
		if (pos == s.length()){
			if (depth <= 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			for (int i = pos; i < s.length(); ++i) {
				if (uset.find(s.substr(pos, i - pos + 1)) != uset.end()) {
					bool tmp = dfs(s, i + 1, depth + 1);
					if (!tmp) {
						return false;
					}
				}
			}
			return true;
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
