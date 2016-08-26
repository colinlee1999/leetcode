#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty()) return;
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int live_num = get_live_num(board, i, j, m, n);
				if (live_num == 3)
					board[i][j] += 10;
				if (live_num == 2 && board[i][j]) board[i][j] += 10;
			}

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				board[i][j] /= 10;
	}

private:
	int get_live_num(vector<vector<int>> & board, int x, int y, const int & m, const int & n)
	{
		int result = 0;
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
				if (i >= 0 && i < m && j >= 0 && j < n && !(i == x && j == y) && (board[i][j] % 10))
					result++;
		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
