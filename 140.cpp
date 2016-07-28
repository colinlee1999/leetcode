#include "iostream"
#include "vector"
#include "set"
#include "map"
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int slen = s.length();
		vector<vector<int>> from(slen, vector<int>());
		unordered_set<int> true_pos;
		true_pos.insert(0);
		int longest = 0;
		for (int i = 0; i < slen; i++)
		{
			for (auto it : true_pos)
				if (wordDict.count(s.substr(it, i - it + 1)))
				{
					from[i].push_back(it);
					longest = i + 1;
				}
			if (longest == i + 1)
				true_pos.insert(i + 1);
		}
		vector<string> result;
		if (longest == slen) dfs(result, from, slen - 1, "", s);
		return result;
	}

private:
	void dfs(vector<string> & result,
		vector<vector<int>> & from,
		int pos,
		string cur_str,
		string & s)
	{
		for (auto it : from[pos])
			if (it != 0)
				dfs(result, from, it - 1, " " + s.substr(it, pos - it + 1) + cur_str, s);
			else
				result.push_back(s.substr(0, pos + 1) + cur_str);
	}
};

int main()
{
    Solution s;
    cin.get();
}
