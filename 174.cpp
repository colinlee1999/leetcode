#include "iostream"
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty()) return -1;
		if (dungeon[0].empty()) return -1;
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>> f(m, vector<int>(n, 0));
		f[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : 1 - dungeon[m - 1][n - 1];
		for (int i = m - 2; i >= 0; i--)
		{
			f[i][n - 1] = f[i + 1][n - 1] - dungeon[i][n - 1];
			f[i][n - 1] = max(1, f[i][n - 1]);
		}
		for (int j = n - 2; j >= 0; j--)
		{
			f[m - 1][j] = f[m - 1][j + 1] - dungeon[m - 1][j];
			f[m - 1][j] = max(1, f[m - 1][j]);
		}
		for (int i = m - 2; i >= 0; i--)
			for (int j = n - 2; j >= 0; j--)
			{
				int v1 = f[i + 1][j] - dungeon[i][j];
				v1 = max(1, v1);
				int v2 = f[i][j + 1] - dungeon[i][j];
				v2 = max(1, v2);
				f[i][j] = min(v1, v2);
			}
		return f[0][0];
	}
};

int main()
{
    cin.get();
}
