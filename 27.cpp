#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int left, right, temp;
		left = 0;
		right = nums.size() - 1;
		while (left<right)
		{
			while (left < right && nums[left] != val) left++;
			while (left < right && nums[right] == val) right--;
			if (left == right)break;
			temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
			right--;
		}
		while (0 <= right && nums[right] == val) right--;
		nums.resize(right+1);
		return nums.size();
    }
};

int main()
{
    Solution s;
    int myint[] = {2,2,3,3};
	vector<int> v(myint, myint + sizeof(myint) / sizeof(int));
	cout << s.removeElement(v, 3) << endl;
    cin.get();
}
