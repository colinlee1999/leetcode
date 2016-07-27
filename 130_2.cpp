#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~(INT_MIN))
using namespace std;

class Solution {
public:
	Solution()
	{
		direction.push_back(pair<int, int>(0, 1));
		direction.push_back(pair<int, int>(0, -1));
		direction.push_back(pair<int, int>(1, 0));
		direction.push_back(pair<int, int>(-1, 0));
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		if (board[0].empty()) return;
		m = board.size();
		n = board[0].size();
		vector<pair<int, int>> v;
		vector<vector<bool>> b(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 'O' && !b[i][j])
					check_and_fill(board, v, b, i, j);
	}

private:
	void check_and_fill(vector<vector<char>> & board,
		vector<pair<int, int>> & v,
		vector<vector<bool>> & b,
		int i,
		int j)
	{
		v.clear();
		v.push_back(pair<int, int>(i, j));
		int start = 0;
		bool edge = false;
		if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
			edge = true;
		while (start < v.size())
		{
			pair<int, int> cur = v[start];
			for (auto dir : direction)
			{
				pair<int, int> next(cur.first + dir.first, cur.second + dir.second);
				if (is_in(next) && board[next.first][next.second] == 'O' && !b[next.first][next.second])
				{
					v.push_back(next);
					b[next.first][next.second] = true;
					if (next.first == 0 || next.first == m - 1 || next.second == 0 || next.second == n - 1)
						edge = true;
				}
			}
			start++;
		}
		if (!edge)
			for (auto p : v)
				board[p.first][p.second] = 'X';
	}

	bool is_in(pair<int, int> p)
	{
		if (p.first < 0 || p.second < 0) return false;
		if (p.first >= m || p.second >= n) return false;
		return true;
	}

	vector<pair<int, int>> direction;
	int m, n;
};

int main()
{
    Solution s;
    cin.get();
}
