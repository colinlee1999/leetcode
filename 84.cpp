#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
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
