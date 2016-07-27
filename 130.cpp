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
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		if (board[0].empty()) return;
		m = board.size();
		n = board[0].size();
		vector<vector<int>> v(m, vector<int>(n, 15)); // 1 means left, 2 means bottom, 4 means right, 8 means top
		vector<vector<bool>> b(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 'O' && !b[i][j])
				{
					if (check(board, v, b, i, j)) fill(board, i, j, 'O', 'X');
					else fill(board, i, j, 'O', '.');
					// for (int ii = 0; ii<m; ii++)
					// 	{
					// 		for (int jj= 0; jj<n; jj++)
					// 			cout<<board[ii][jj];
					// 		cout<<endl;
					// 	}
				}

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == '.')
					fill(board, i, j, '.', 'O');
	}

private:
	void fill(vector<vector<char>> & board, int i, int j, char target, char ch)
	{
		board[i][j] = ch;
		if (j - 1 >= 0 && board[i][j - 1] == target) fill(board, i, j - 1, target, ch);
		if (i + 1 < m && board[i + 1][j] == target) fill(board, i + 1, j, target, ch);
		if (j + 1 < n && board[i][j + 1] == target) fill(board, i, j + 1, target, ch);
		if (i - 1 >= 0 && board[i - 1][j] == target) fill(board, i - 1, j, target, ch);
	}

	bool check(vector<vector<char>> & board,
		vector<vector<int>> & v,
		vector<vector<bool>> & b,
		int i,
		int j)
	{
		// cout<<"i:\t"<<i<<"\tj:\t"<<j<<endl;
		b[i][j] = true;
		//check left
		if (j - 1 < 0) return false;
		if (!b[i][j - 1])
		{
			v[i][j] &= (~left);
			if (board[i][j - 1] == 'O')
				v[i][j - 1] &= (~right);
		}
		// check bottom
		if (i + 1 >= m) return false;
		if (!b[i + 1][j])
		{
			v[i][j] &= (~bottom);
			if (board[i + 1][j] == 'O')
				v[i + 1][j] &= (~top);
		}
		//check right
		if (j + 1 >= n) return false;
		if (!b[i][j + 1])
		{
			v[i][j] &= (~right);
			if (board[i][j + 1] == 'O')
				v[i][j + 1] &= (~left);
		}
		//check top
		if (i - 1 < 0) return false;
		if (!b[i - 1][j])
		{
			v[i][j] &= (~top);
			if (board[i - 1][j] == 'O')
				v[i - 1][j] &= (~bottom);
		}
		// cout<<v[i][j]<<endl;
		//traverse adjacent grids
		bool temp = true;
		//left
		if (!b[i][j - 1] && board[i][j - 1] == 'O') temp = check(board, v, b, i, j - 1);
		if (!temp) return false;
		//bottom
		if (!b[i + 1][j] && board[i + 1][j] == 'O') temp = check(board, v, b, i + 1, j);
		if (!temp) return false;
		//right
		if (!b[i][j + 1] && board[i][j + 1] == 'O') temp = check(board, v, b, i, j + 1);
		if (!temp) return false;
		//top
		if (!b[i - 1][j] && board[i - 1][j] == 'O') temp = check(board, v, b, i - 1, j);
		if (!temp) return false;
		if (v[i][j]) return false;
		return true;
	}

	int m, n;
	const int left = 1;
	const int bottom = 2;
	const int right = 4;
	const int top = 8;
};

int main()
{
    Solution s;
    cin.get();
}
