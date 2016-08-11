#include "iostream"
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	Solution()
	{
		direction.push_back(pair<int, int>(1, 0));
		direction.push_back(pair<int, int>(-1, 0));
		direction.push_back(pair<int, int>(0, 1));
		direction.push_back(pair<int, int>(0, -1));
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		if (grid[0].empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<bool>> b(m, vector<bool>(n, false));
		int result = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (!b[i][j] && grid[i][j] == '1')
				{
					dfs(i, j, m, n, grid, b);
					result++;
				}
		return result;
	}

private:
	void dfs(int i, int j,
		const int & m, const int & n,
		vector<vector<char>> & grid,
		vector<vector<bool>> & b)
	{
		b[i][j] = true;
		for (auto it : direction)
		{
			int next_i = i + it.first;
			int next_j = j + it.second;
			if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && !b[next_i][next_j] && grid[next_i][next_j] == '1')
				dfs(next_i, next_j, m, n, grid, b);
		}
	}

	vector<pair<int, int>> direction;
};

int main()
{
	Solution s;
    cin.get();
}
