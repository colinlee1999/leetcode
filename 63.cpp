#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) return 0;
		if (obstacleGrid[0].empty()) return 0;
		if (obstacleGrid[0][0]) return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> f(m, vector<int>(n, 0));
		f[0][0] = 1;
		for (int i = 1; i < m; i++)
			f[i][0] = f[i - 1][0] && !obstacleGrid[i][0];
		for (int j = 1; j < n; j++)
			f[0][j] = f[0][j - 1] && !obstacleGrid[0][j];
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (obstacleGrid[i][j] == 0)
				{
					if (obstacleGrid[i - 1][j] == 0)  f[i][j] += f[i - 1][j];
					if (obstacleGrid[i][j - 1] == 0) f[i][j] += f[i][j - 1];
				}				
		return f[m - 1][n - 1];
	}
};

int main()
{
    Solution s;
    cin.get();
}
