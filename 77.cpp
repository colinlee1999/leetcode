#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> cur_seq;
		dfs(result, cur_seq, n, k, 1);
		return result;
	}

private:
	void dfs(vector<vector<int>> & result,
		vector<int> & cur_seq,
		int n,
		int k,
		int pos)
	{
		if (k == 0)
			result.push_back(cur_seq);
		else
		{
			for (int i = pos; i <= n - k + 1; i++)
			{
				cur_seq.push_back(i);
				dfs(result, cur_seq, n, k - 1, i + 1);
				cur_seq.pop_back();
			}
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
