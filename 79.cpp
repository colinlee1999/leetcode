#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
#include <unordered_set>
#define INT_MIN 1<<31
#define INT_MAX ~(INT_MIN)
using namespace std;

class Solution {
public:
	Solution()
	{
		pair<int, int> d1(1, 0);
		pair<int, int> d2(-1, 0);
		pair<int, int> d3(0, 1);
		pair<int, int> d4(0, -1);
		direction.push_back(d1);
		direction.push_back(d2);
		direction.push_back(d3);
		direction.push_back(d4);
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		if (board.empty()) return false;
		if (board[0].empty()) return false;
		int m = board.size();
		int n = board[0].size();
		int wlen = word.length();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == word[0])
				{
					board[i][j] = 0;
					if (dfs(i, j, m, n, board, 1, word, wlen)) return true;
					board[i][j] = word[0];
				}					
		return false;
	}

private:
	bool dfs(int row, int col,
		const int & m, const int & n,
		vector<vector<char>> & board,
		int pos,
		const string & word, const int & wlen)
	{
		if (pos == wlen)
			return true;
		for (auto dir : direction)
		{
			int new_row = row + dir.first;
			int new_col = col + dir.second;
			if (is_in(new_row, new_col, m, n) && board[new_row][new_col] == word[pos])
			{
				board[new_row][new_col] = 0;
				if (dfs(new_row, new_col, m, n, board, pos + 1, word, wlen)) return true;
				board[new_row][new_col] = word[pos];
			}
		}
		return false;
	}

	bool is_in(const int & row, const int & col, const int & m, const int & n)
	{
		return row >= 0 && row < m && col >= 0 && col < n;
	}

	vector<pair<int, int>> direction;
};

int main()
{
	Solution s;
	cin.get();
}
