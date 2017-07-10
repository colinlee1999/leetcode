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
typedef vector<VI> VVI;

typedef vector<bool> VB;

class Solution {
public:
	int countArrangement(int N) {
		int result = 0;
		VVI candidate(N + 1, VI());
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j < i; ++j) {
				if (i % j == 0) {
					candidate[i].push_back(j);
				}
			}
			for (int j = i; j <= N; j += i) {
				candidate[i].push_back(j);
			}
		}
		VB used(N + 1, false);
		dfs(1, N, candidate, used, result);
		return result;
	}

private:
	void dfs(int cur, int N, VVI& candidate, VB& used, int& result) {
		if (cur == N) {
			for (auto it : candidate[cur]) {
				if (!used[it]) ++result;
			}
		}
		else {
			for (auto it : candidate[cur]) {
				if (!used[it]) {
					used[it] = true;
					dfs(cur + 1, N, candidate, used, result);
					used[it] = false;
				}
			}
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
