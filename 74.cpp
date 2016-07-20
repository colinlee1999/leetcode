#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		if (matrix[0].empty()) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int left = 0, right = m, mid;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			if (matrix[mid][0] <= target) left = mid;
			else right = mid;
		}
		int row = left;
		left = 0;
		right = n;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			if (matrix[row][mid] <= target) left = mid;
			else right = mid;
		}
		return matrix[row][left] == target;
	}
};

int main()
{
	Solution s;
	cin.get();
}
