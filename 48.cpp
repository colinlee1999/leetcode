#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int row = 0;
		int n = matrix.size();
		while (row < n / 2)
		{
			int cur_row = row;
			for (int cur_col = row; cur_col < n - row - 1; cur_col++)
			{
				int temp = matrix[cur_row][cur_col];
				matrix[cur_row][cur_col] = matrix[n - cur_col - 1][cur_row];
				matrix[n - cur_col - 1][cur_row] = matrix[n - cur_row - 1][n - cur_col - 1];
				matrix[n - cur_row - 1][n - cur_col - 1] =matrix[cur_col][n - cur_row - 1];
				matrix[cur_col][n - cur_row - 1] = temp;
			}
			row++;
		}
    }
};

int main()
{
	Solution s;
    cin.get();
}
