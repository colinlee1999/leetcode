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
		vector<int> heights(n + 1, 0);
		heights[n] = -1;
		int result = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == '0') heights[j] = 0;
				else heights[j] += 1;
			int temp = largestRectangleArea(heights);
			result = max(result, temp);
		}
		return result;
	}

private:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) return 0;
		stack<int> s;
		stack<int> t;
		int result = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			if (s.empty() || s.top() <= heights[i])
			{
				s.push(heights[i]);
				t.push(i);
			}				
			else
			{
				int last_t_pop;
				while (!s.empty() && s.top()>heights[i])
				{
					result = max(result, (int)s.top() * (i - (int)t.top()));
					s.pop();
					last_t_pop = t.top();
					t.pop();
				}
				s.push(heights[i]);
				t.push(last_t_pop);
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
