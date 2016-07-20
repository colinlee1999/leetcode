#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <stack>
using namespace std;
 
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		if (matrix[0].empty()) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> top(m, vector<int>(n, 0));
		for (int j = 0; j < n; j++)
		{
			int last = 0;
			if (matrix[0][j] == '0') last = 1;
			for (int i = 1; i < m; i++)
				if (matrix[i][j] == '1') top[i][j] = last;
				else last = i + 1;
		}
		int result = 0;
		for (int i = 0; i < m; i++)
		{
			int j = 0;
			while (j < n)
			{
				while (j < n && matrix[i][j] == '0')
					j++;
				if (j == n) break;
				vector<int> heights;
				while (j < n && matrix[i][j] == '1')
				{
					heights.push_back(i + 1 - top[i][j]);
					j++;
				}
				int temp = largestRectangleArea(heights);
				result = max(result, temp);
			}
		}
		return result;
	}

private:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) return 0;
		heights.push_back(-1);
		stack<int> s;
		s.push(heights[0]);
		int result = 0;
		int hlen = heights.size();
		for (int i = 1; i < hlen; i++)
		{
			if (heights[i] >= s.top())
				s.push(heights[i]);
			else
			{
				int count = 0;
				while (!s.empty() && s.top()> heights[i])
				{
					count++;
					result = max(result, s.top() * count);
					s.pop();
				}
				s.push(heights[i]);
				while (count--)
					s.push(heights[i]);
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
