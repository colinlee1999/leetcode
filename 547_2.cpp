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

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int mlen = M.size();
		VB vb(mlen, false);
		int result = 0;
		for (int i = 0; i < mlen; ++i) {
			if (!vb[i]) {
				dfs(i, M, vb);
				++result;
			}
		}
		return result;
	}

private:
	void dfs(int cur, const VVI& vvi, VB& vb) {
		vb[cur] = true;
		for (int i = 0; i < vvi.size(); ++i) {
			if (!vb[i] && vvi[cur][i]) {
				dfs(i, vvi, vb);
			}
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
