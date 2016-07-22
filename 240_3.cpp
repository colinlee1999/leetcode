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
		while (col < n  && row >= 0)
		{
			if (matrix[row][col] > target) row--;
			else if (matrix[row][col] < target) col++;
			else return true;
		}
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
