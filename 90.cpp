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
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> cur_seq;
		unordered_map<int, int> m;
		for (auto it : nums)
		{
			auto temp = m.find(it);
			if (temp != m.end()) temp->second++;
			else m[it] = 1;
		}
		dfs(m.begin(), m, result, cur_seq);
		return result;
	}

private:
	void dfs(unordered_map<int,int>::iterator pos,
		unordered_map<int, int> & m,
		vector<vector<int>> & result,
		vector<int> & cur_seq)
	{
		if (pos == m.end())
			result.push_back(cur_seq);
		else
		{
			auto temp_pos = pos;
			dfs(++temp_pos, m, result, cur_seq);
			for (int i = 0; i < pos->second; i++)
			{
				temp_pos = pos;
				cur_seq.push_back(pos->first);
				dfs(++temp_pos, m, result, cur_seq);
			}
			for (int i = 0; i < pos->second; i++)
				cur_seq.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	s.subsetsWithDup(v);
    cin.get();
}
