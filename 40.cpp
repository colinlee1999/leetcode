#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> cur_seq;
		unordered_map<int, int> m;
		for (auto it : candidates)
		{
			auto temp = m.find(it);
			if (temp != m.end())
				temp->second++;
			else
				m[it] = 1;
		}
		dfs(target, m, result, cur_seq, 0);
		return result;
	}

private:
	void dfs(int target,
		unordered_map<int, int> & m,
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
			auto it = m.begin();
			int i = pos;
			while (i--) it++;
			i = pos;
			for (; it != m.end(); it++, i++)
			{
				if ( it->second>0 && target >= it->first)
				{
					cur_seq.push_back(it->first);
					it->second--;
					dfs(target - it->first, m, result, cur_seq, i);
					it->second++;
					cur_seq.pop_back();
				}
			}
		}
	}
};

//class Solution {
//public:
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		vector<vector<int>> result;
//		vector<int> cur_seq;
//		sort(candidates.begin(), candidates.end());
//		dfs(target, candidates, result, cur_seq, 0);
//		return result;
//    }
//    
//private:
//	void dfs(int target,
//		vector<int> & candidates,
//		vector<vector<int>> & result,
//		vector<int> & cur_seq,
//		int pos)
//	{
//		if (target == 0)
//		{
//			result.push_back(cur_seq);
//		}
//		else
//		{
//			for (int i = pos; i < candidates.size(); i++)
//			{
//				if (i > 0 && candidates[i] == candidates[i - 1])
//				{
//					if (!cur_seq.empty() && cur_seq.back() != candidates[i]) continue;
//					if (cur_seq.empty()) continue;
//				}
//				if (target >= candidates[i])
//				{
//					cur_seq.push_back(candidates[i]);
//					dfs(target - candidates[i], candidates, result, cur_seq, i + 1);
//					cur_seq.pop_back();
//				}
//			}
//		}
//	}
//};

int main()
{
	Solution s;
    cin.get();
}
