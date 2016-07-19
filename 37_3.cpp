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
		cout << total_number << endl;
		vector<vector<unordered_set<int>>> ready(9, vector<unordered_set<int>>(9,unordered_set<int>()));
		for (int row_block = 0; row_block < 3; row_block++)
			for (int col_block = 0; col_block < 3; col_block++)
			{
				for (int row = 0; row < 3; row++)
					for (int col = 0; col < 3; col++)
					{
						int i = row_block * 3 + row;
						int j = col_block * 3 + col;
						if (board[i][j] == '.')
						{
							for (int try_fill = 1; try_fill <= 9; try_fill++)
								if (!(block[row][col][try_fill - 1] || vertical[j][try_fill - 1] || horizontal[i][try_fill - 1]))
									ready[i][j].insert(try_fill);
						}
					}
			}
		dfs(total_number, 0, 0, board, horizontal, vertical, block, ready);
    }

private:
	bool dfs(int total_number,
		int row,
		int col,
		vector<vector<char>> & board,
		vector<vector<bool>> & horizontal,
		vector<vector<bool>> & vertical,
		vector<vector<vector<bool>>> & block,
		vector<vector<unordered_set<int>>> & ready)
	{
		if (total_number == 0)
		{
			return true;
		}
		else
		{
			for (int min_row = 0; min_row <= 8; min_row++)
				for (int min_col = 0; min_col <= 8; min_col++)
					if (board[min_row][min_col] == '.')
				{
					unordered_set<int> temp(ready[min_row][min_col]);
					vector<bool> horizontal_mask(9, false);
					vector<bool> vertical_mask(horizontal_mask);
					vector<vector<bool>> block_mask(3, vector<bool>(3, false));
					//cout << "min_row:\t" << min_row << "\tmin_col:\t" << min_col << endl;
					for (auto it : temp)
					{
						ready[min_row][min_col].erase(it);
						board[min_row][min_col] = '0' + it;
						horizontal[min_row][it] = true;
						vertical[min_col][it] = true;
						block[min_row / 3][min_col / 3][it] = true;
						for (int row = 0; row <= 8; row++)
							if (row != min_row && ready[row][min_col].find(it) != ready[row][min_col].end())
							{
								vertical_mask[row] = true;
								ready[row][min_col].erase(it);
							}
						for (int col = 0; col <= 8; col++)
							if (col != min_col && ready[min_row][col].find(it) != ready[min_row][col].end())
							{
								horizontal_mask[col] = true;
								ready[min_row][col].erase(it);
							}
						for (int i = 0; i < 3; i++)
							for (int j = 0; j < 3; j++)
							{
								int row = min_row / 3 + i;
								int col = min_col / 3 + i;
								if (row != min_row && col != min_col && ready[row][col].find(it) != ready[row][col].end())
								{
									block_mask[i][j] = true;
									ready[row][col].erase(it);
								}
							}
						if (dfs(total_number - 1, board, horizontal, vertical, block, ready)) return true;
						for (int row = 0; row <= 8; row++)
							if (row != min_row && vertical_mask[row])
							{
								vertical_mask[row] = false;
								ready[row][min_col].insert(it);
							}
						for (int col = 0; col <= 8; col++)
							if (col != min_col && horizontal_mask[col])
							{
								horizontal_mask[col] = false;
								ready[min_row][col].insert(it);
							}
						for (int i = 0; i < 3; i++)
							for (int j = 0; j < 3; j++)
							{
								int row = min_row / 3 + i;
								int col = min_col / 3 + i;
								if (row != min_row && col != min_col && block_mask[i][j])
								{
									block_mask[i][j] = false;
									ready[row][col].insert(it);
								}
							}
						ready[min_row][min_col].insert(it);
						board[min_row][min_col] = '.';
						horizontal[min_row][it] = false;
						vertical[min_col][it] = false;
						block[min_row / 3][min_col / 3][it] = false;
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
