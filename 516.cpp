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

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int slen = s.length();
		VVI f(slen + 1, VI(slen + 1, 0));
		for (int i = 1; i <= slen; ++i) {
			for (int j = 1; j <= slen; ++j) {
				if (s[i - 1] == s[slen - j]) {
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
				}
				f[i][j] = max(f[i][j], f[i - 1][j]);
				f[i][j] = max(f[i][j], f[i][j - 1]);
			}
		}
		return f[slen][slen];
	}

private:
	int max(int a, int b) {
		if (a > b) return a;
		else return b;
	}
};

int main()
{
	Solution s;
	cin.get();
}
