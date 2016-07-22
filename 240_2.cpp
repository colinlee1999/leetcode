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
		pair<int, int> left_top(0, 0);
		pair<int, int> right_bottom(m - 1, n - 1);
		int left, right, mid, row, col;
		while (left_top.first < right_bottom.first || left_top.second < right_bottom.second)
		{
			// move top boundary
			left = left_top.first;
			right = right_bottom.first + 1;
			col = right_bottom.second;
			if (matrix[left][col] == target) return true;
			if (target > matrix[left][col])
			{
				while (left + 1 < right)
				{
					mid = left + (right - left) / 2;
					if (matrix[mid][col] == target) return true;
					if (matrix[mid][col] < target) left = mid;
					else right = mid;
				}
				left_top.first = left + 1;
			}
			if (left_top.first > right_bottom.first) return false;
			// move bottom boundary
			left = left_top.first-1;
			right = right_bottom.first;
			col = left_top.second;
			if (matrix[right][col] == target) return true;
			if (target < matrix[right][col])
			{
				while (left + 1 < right)
				{
					mid = left + (right - left) / 2;
					if (matrix[mid][col] == target) return true;
					if (matrix[mid][col] > target) right = mid;
					else left = mid;
				}
				right_bottom.first = right - 1;
			}
			if (left_top.first > right_bottom.first) return false;
			// move left boundary
			left = left_top.second;
			right = right_bottom.second+1;
			row = right_bottom.first;
			if (matrix[row][left] == target) return true;
			if (target > matrix[row][left])
			{
				while (left + 1 < right)
				{
					mid = left + (right - left) / 2;
					if (matrix[row][mid] == target) return true;
					if (matrix[row][mid] < target) left = mid;
					else right = mid;
				}
				left_top.second = left + 1;
			}
			if (left_top.second > right_bottom.second) return false;
			// move right boundary
			left = left_top.second - 1;
			right = right_bottom.second;
			row = left_top.first;
			if (matrix[row][right] == target) return true;
			if (target < matrix[row][right])
			{
				while (left + 1 < right)
				{
					mid = left + (right - left) / 2;
					if (matrix[row][mid] == target) return true;
					if (matrix[row][mid] > target) right = mid;
					else left = mid;
				}
				right_bottom.second = right - 1;
			}
			if (left_top.second > right_bottom.second) return false;
		}
		return matrix[left_top.first][left_top.second] == target;
	}
};

int main()
{
    Solution s;
	vector<vector<int>> v(1, vector<int>(2, 1));
	cout << s.searchMatrix(v, 2) << endl;
    cin.get();
}
