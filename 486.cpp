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

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int nlen = nums.size();
		if (nlen < 2) return true;
		VVI f(nlen, VI(nlen, 0));
		VVI sum(f);
		for (int i = 0; i < nlen; ++i)
			f[i][i] = nums[i];
		for (int i = 0; i < nlen; ++i) {
			sum[i][i] = nums[i];
			for (int j = i + 1; j < nlen; ++j) {
				sum[i][j] = sum[i][j - 1] + nums[j];
			}
		}
		for (int j = 1; j < nlen; ++j) {
			for (int i = j - 1; i >= 0; --i) {
				f[i][j] = max(nums[i] + sum[i + 1][j] - f[i + 1][j], nums[j] + sum[i][j - 1] - f[i][j - 1]);
			}
		}
		return 2 * f[0][nlen - 1] >= sum[0][nlen - 1];
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
