#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> cur_seq;
		dfs(target, candidates, result, cur_seq, 0);
		return result;
	}

private:
	void dfs(int target,
		vector<int> & candidates,
		vector<vector<int>> & result,
		vector<int> & cur_seq,
		int pos)
	{
		if (target == 0)
		{
			result.push_back(cur_seq);
		}
		else
		{
			for (int i = pos; i < candidates.size(); i++)
			{
				if (target >= candidates[i])
				{
					cur_seq.push_back(candidates[i]);
					dfs(target - candidates[i], candidates, result, cur_seq, i);
					cur_seq.pop_back();
				}
			}
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
