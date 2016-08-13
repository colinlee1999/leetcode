#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
    int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return max(0, nums[0]);
		int r1, r2;
		int backup = nums.back();
		nums.pop_back();
		{
			vector<int> result;
			result.push_back(0);
			result.push_back(nums[0]);
			for (int i = 1; i < nums.size(); i++)
			{
				result.push_back(result[i]);
				if (result[i - 1] + nums[i]>result[i + 1])
				{
					result[i + 1] = result[i - 1] + nums[i];
				}
			}
			r1 = result.back();
		}
		nums.push_back(backup);
		{
			vector<int> result;
			result.push_back(0);
			result.push_back(0);
			result.push_back(nums[1]);
			for (int i = 2; i < nums.size(); i++)
			{
				result.push_back(result[i]);
				if (result[i - 1] + nums[i]>result[i + 1])
				{
					result[i + 1] = result[i - 1] + nums[i];
				}
			}
			r2 = result.back();
		}
		return max(r1, r2);
    }
};

int main()
{
    Solution s;
    int myint[] = {2,1,3,4,5};
    vector<int> v(myint,myint+sizeof(myint)/sizeof(int));
    cout<<s.rob(v)<<endl;
    cin.get();
}
