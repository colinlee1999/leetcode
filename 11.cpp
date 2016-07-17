#include "iostream"
#include "vector"
#include "set"
#include <map>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int max_area = 0;
		int cur_area;
		int left = 0, right = height.size() - 1;
		while (left != right)
		{
			cur_area = (right - left)*min(height[left], height[right]);
			max_area = max(cur_area, max_area);
			if (height[left] < height[right]) left++;
			else right--;
		}
		return max_area;
    }
};

int main()
{
	Solution s;
    cin.get();
}
