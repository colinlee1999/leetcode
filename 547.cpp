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
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

VVI mul(VVI a, VVI b) {
	int m = a.size();
	int n = a[0].size();
	int p = b.size();
	VVI c(m, VI(p, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			if (c[i][j] > 0) c[i][j] = 1;
		}
	}
	return c;
}

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		VVI t(M);
		VVI s;
		for (int i = 0; i < 8; ++i) {
			s = mul(t, t);
			t = s;
		}
		
		int mlen = M.size();
		VB vb(mlen, false);
		int result = 0;
		for (int i = 0; i < mlen; ++i) {
			if (!vb[i]) {
				++result;
				for (int j = 0; j < mlen; ++j) {
					if (t[i][j] != 0) {
						vb[j] = true;
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
