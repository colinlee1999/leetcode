#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		int total_number = 0;
		vector<vector<bool>> horizontal(9, vector<bool>(9, false));
		vector<vector<bool>> vertical(horizontal);
		vector<vector<vector<bool>>> block(3, vector<vector<bool>>(3, vector<bool>(9, false)));
		for (int row = 0; row <= 8; row++)
			for (int col = 0; col <= 8; col++)
				if (board[row][col] != '.')
				{
					horizontal[row][board[row][col] - '1'] = true;
					total_number++;
				}
		total_number = 81 - total_number;
		for (int col = 0; col <= 8; col++)
			for (int row = 0; row <= 8; row++)
				if (board[row][col] != '.')
					vertical[col][board[row][col] - '1'] = true;
		for (int row_block = 0; row_block < 3; row_block++)
			for (int col_block = 0; col_block < 3; col_block++)
			{
				for (int row = 0; row < 3;row++)
					for (int col = 0; col < 3; col++)
					{
						int i = row_block * 3 + row;
						int j = col_block * 3 + col;
						if (board[i][j] != '.')
							block[row_block][col_block][board[i][j] - '1'] = true;
					}
			}
		dfs(total_number, 0, 0, board, horizontal, vertical, block);
    }

private:
	bool dfs(int total_number,
		int row,
		int col,
		vector<vector<char>> & board,
		vector<vector<bool>> & horizontal,
		vector<vector<bool>> & vertical,
		vector<vector<vector<bool>>> & block)
	{
		if (total_number == 0)
		{
			return true;
		}
		else
		{
			while (board[row][col] != '.')
			{
				col = col + 1;
				if (col == 9)
				{
					row = row + 1;
					col = 0;
				}
			}
			for (int try_fill = 1; try_fill <= 9; try_fill++)
			{
				if (!(block[row / 3][col / 3][try_fill - 1] || vertical[col][try_fill - 1] || horizontal[row][try_fill - 1]))
				{
					block[row / 3][col / 3][try_fill - 1] = true;
					vertical[col][try_fill - 1] = true;
					horizontal[row][try_fill - 1] = true;
					board[row][col] = (char)('0' + try_fill);
					if (dfs(total_number - 1, row, col, board, horizontal, vertical, block)) return true;
					block[row / 3][col / 3][try_fill - 1] = false;
					vertical[col][try_fill - 1] = false;
					horizontal[row][try_fill - 1] = false;
					board[row][col] = '.';
				}
			}
			return false;
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
