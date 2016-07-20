#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result;
		if (n < 1) return result;
		result = vector<vector<int>>(n, vector<int>(n, 0));
		int left = 0;
		int right = n - 1;
		int top = 0;
		int bottom = n - 1;
		int total = n*n;
		int row = 0, col = 0;
		int direction = 1; // 1 means to right, 2 means to bottom, 3 means to left, 4 means to top
		int count = 0;
		while (count < total)
		{
			count++;
			result[row][col] = count;
			switch (direction)
			{
			case 1:
				if (col != right) col++;
				else
				{
					direction = 2;
					row++;
					top++;
				}
				break;
			case 2:
				if (row != bottom) row++;
				else
				{
					direction = 3;
					col--;
					right--;
				}
				break;
			case 3:
				if (col != left) col--;
				else
				{
					direction = 4;
					row--;
					bottom--;
				}
				break;
			case 4:
				if (row != top) row--;
				else
				{
					direction = 1;
					col++;
					left++;
				}
				break;
			default:
				break;
			}
		}
		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
