#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> cur_seq;
		dfs(k, 0, n, result, cur_seq);
		return result;
	}

private:
	void dfs(int k,
		int cur, int target,
		vector<vector<int>> & result,
		vector<int> & cur_seq)
	{
		if (target == 0 && k == 0)
			result.push_back(cur_seq);
		else
		{
			if (target < (cur + 1 + (cur + k)) * k / 2) return;
			for (int i = cur + 1; i <= 9; i++)
			{
				if (target - i >= 0)
				{
					cur_seq.push_back(i);
					dfs(k - 1, i, target - i, result, cur_seq);
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
