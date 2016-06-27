#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
		if (board.size() != 9) return false;
		for (int row = 0; row <= 8; row++)
		{
			if (board[row].size() != 9) return false;
			vector<bool> b(9, false);
			for (int col = 0; col <= 8; col++)
				if (board[row][col] != '.')
				{
					if (board[row][col] < '1' || board[row][col] > '9')
						return false;
					if (b[board[row][col] - '1']) return false;
					b[board[row][col] - '1'] = true;
				}
		}
		for (int col = 0; col <= 8; col++)
		{
			vector<bool> b(9, false);
			for (int row = 0; row <= 8; row++)
				if (board[row][col] != '.')
				{
					if (b[board[row][col] - '1']) return false;
					b[board[row][col] - '1'] = true;
				}
		}
		for (int row_block = 0; row_block < 3; row_block++)
			for (int col_block = 0; col_block < 3; col_block++)
			{
				vector<bool> b(9, false);
				for (int row = 0; row < 3;row++)
					for (int col = 0; col < 3; col++)
					{
						int i = row_block * 3 + row;
						int j = col_block * 3 + col;
						if (board[i][j] != '.')
						{
							if (b[board[i][j] - '1']) return false;
							b[board[i][j] - '1'] = true;
						}
					}
			}
		return true;
    }
};

int main()
{
	Solution s;
    cin.get();
}
