#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
#include <unordered_set>
#define INT_MIN 1<<31
#define INT_MAX ~(INT_MIN)
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> cur_seq;
		vector<vector<int>> result;
		int nlen = nums.size();
		if (nlen == 0) return result;
		dfs(result, cur_seq, nums, 0, nlen);
		return result;
	}

private:
	void dfs(vector<vector<int>> & result,
		vector<int> & cur_seq,
		vector<int> & nums,
		int pos,
		int & nlen)
	{
		if (pos == nlen)
			result.push_back(cur_seq);
		else
		{
			dfs(result, cur_seq, nums, pos + 1, nlen);
			cur_seq.push_back(nums[pos]);
			dfs(result, cur_seq, nums, pos + 1, nlen);
			cur_seq.pop_back();
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
