#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		if (matrix[0].empty()) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int col, row;
		col = 0;
		row = m - 1;
		while (col <= n - 1 && row > 0)
		{
			if (matrix[row][col] == target) return true;
			else if (matrix[row][col] > target) row--;
			else col++;
		}
		if (col == n - 1)
		{
			for (int i = 0; i <= row; i++)
				if (matrix[i][n - 1] == target)
					return true;
		}
		if (row == 0)
		{
			for (int j = col; j <= n - 1; j++)
				if (matrix[0][j] == target)
					return true;
		}
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
