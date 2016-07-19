#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> & matrix) {
		vector<int> result;
		if (matrix.empty()) return result;
		if (matrix[0].empty()) return result;
		int left = 0;
		int right = matrix[0].size() - 1;
		int top = 0;
		int bottom = matrix.size() - 1;
		int total = (right + 1)*(bottom + 1);
		int row = 0, col = 0;
		int direction = 1; // 1 means to right, 2 means to bottom, 3 means to left, 4 means to top
		while (result.size() < total)
		{
			result.push_back(matrix[row][col]);
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
	vector<vector<int>> v(1,vector<int>());
	v[0].push_back(2);
	v[0].push_back(3);
	s.spiralOrder(v);
    cin.get();
}
