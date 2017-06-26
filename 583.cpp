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
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int l1 = word1.length();
		int l2 = word2.length();
		VVI f(l1 + 1, VI(l2 + 1, 0));
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l2; j++) { 
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (word1[i - 1] == word2[j - 1]) {
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
				}
			}
		}
		return l1 + l2 - f.back().back() * 2;
	}

private:
	int max(int a, int b) {
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
