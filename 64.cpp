#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		if (grid[0].empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> f(m, vector<int>(n, 0));
		f[0][0] = grid[0][0];
		for (int i = 1; i < m; i++)
			f[i][0] = f[i - 1][0] + grid[i][0];
		for (int j = 1; j < n; j++)
			f[0][j] = f[0][j - 1] + grid[0][j];
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				f[i][j] = grid[i][j] + min(f[i - 1][j], f[i][j - 1]);
		return f[m - 1][n - 1];
	}
};

int main()
{
    Solution s;
    cin.get();
}
