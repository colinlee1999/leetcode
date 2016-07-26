#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int result = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			int minh = min(height[left], height[right]);
			if (height[left] == minh)
				while (left < right && height[left] <= minh)
				{
					result += minh - height[left];
					left++;
				}
			else
				while (left < right && height[right] <= minh)
				{
					result += minh - height[right];
					right--;
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
