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

typedef vector<string> VS;
typedef unordered_set<string> USET_STRING;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		USET_STRING result;
		minDeleted = s.length();
		result.insert("");
		int lPraR, rPraR;
		lPraR = rPraR = 0;
		for (auto it : s) {
			if (it == '(') ++lPraR;
			else if (it == ')') ++rPraR;
		}
		dfs(result, s, 0, "", 0, 0, 0, lPraR, rPraR);
		VS realResult;
		for (auto it : result) {
			realResult.push_back(it);
		}
		return realResult;
	}

private:
	void dfs(USET_STRING& result, string& s, int pos, string curS, int curDeleted, int lPraL, int rPraL, int lPraR, int rPraR) {
		if (curDeleted > minDeleted) return;
		if (pos == s.length()) {
			if (curDeleted < minDeleted) {
				result.clear();
				minDeleted = curDeleted;
			}
			result.insert(curS);
		}
		else {
			if (s[pos] == '(') {
				if (rPraR > lPraL - rPraL) {
					dfs(result, s, pos + 1, curS + s[pos], curDeleted, lPraL + 1, rPraL, lPraR - 1, rPraR);
				}
				dfs(result, s, pos + 1, curS, curDeleted + 1, lPraL, rPraL, lPraR - 1, rPraR);
			}
			else if (s[pos] == ')') {
				if (0 < lPraL - rPraL) {
					dfs(result, s, pos + 1, curS + s[pos], curDeleted, lPraL, rPraL + 1, lPraR, rPraR - 1);
				} 
				dfs(result, s, pos + 1, curS, curDeleted + 1, lPraL, rPraL, lPraR, rPraR - 1);
			}
			else {
				dfs(result, s, pos + 1, curS + s[pos], curDeleted, lPraL, rPraL, lPraR, rPraR);
			}
		}
	}

	int minDeleted;
};

int main()
{
	Solution s;
	cin.get();
}
