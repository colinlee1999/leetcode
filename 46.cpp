#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <unordered_set>
#include <unordered_map>
#define	INT_MIN	1<<31
#define	INT_MAX	~(INT_MIN)
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> cur_per;
		vector<bool> cur_used(nums.size(), 0);
		dfs(result, cur_per, cur_used, nums);
		return result;
	}

private:
	void dfs(vector<vector<int>> & result,
		vector<int> & cur_per,
		vector<bool> & cur_used,
		vector<int> & nums)
	{
		if (cur_per.size() == nums.size())
			result.push_back(cur_per);
		else
		{
			for (int i = 0; i < nums.size(); i++)
				if (!cur_used[i])
				{
					cur_used[i] = true;
					cur_per.push_back(nums[i]);
					dfs(result, cur_per, cur_used, nums);
					cur_per.pop_back();
					cur_used[i] = false;
				}
		}
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	s.permute(v);
    cin.get();
}
