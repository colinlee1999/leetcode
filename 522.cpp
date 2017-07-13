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
	int findLUSlength(vector<string>& strs) {
		int result = -1;
		int slen = strs.size();
		bool found;
		for (int i = 0; i < slen; ++i) {
			found = false;
			for (int j = 0; j < slen; ++j) {
				if (i == j) {
					continue;
				}
				if (contains(strs[j], strs[i])) {
					found = true;
					break;
				}
			}
			if (!found) {
				result = max(result, strs[i].length());
			}
		}
		return result;
	}

private:
	int max(int a, int b) {
		if (a > b) return a;
		else return b;
	}

	bool contains(string& a, string& b) {
		int i, j;
		i = 0;
		j = 0;
		int alen = a.length();
		int blen = b.length();
		while (i < alen) {
			if (a[i] == b[j]) {
				++j;
				if (j == blen) return true;
			}
			++i;
		}
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
