#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;
		if (matrix[0].empty()) return;
		int m = matrix.size();
		int n = matrix[0].size();
		bool top_line_found_zero = false;
		for (int j = 0; j < n; j++)
			if (!matrix[0][j])
			{
				top_line_found_zero = true;
				break;
			}
		for (int i = 1; i < m; i++)
		{
			bool found_zero = false;
			for (int j = 0; j < n; j++)
				if (!matrix[i][j])
				{
					if (!found_zero)
					{
						for (int k = 0; k < j; k++) matrix[i][k] = 0;
						found_zero = true;
					}
					matrix[0][j] = 0;
				}
				else if (found_zero)
					matrix[i][j] = 0;
		}
		for (int j = 0; j < n; j++)
			if (!matrix[0][j])
				for (int i = 1; i < m; i++) matrix[i][j] = 0;
		if (top_line_found_zero)
			for (int j = 0; j < n; j++)
				matrix[0][j] = 0;
	}
};

int main()
{
	Solution s;
	cin.get();
}
