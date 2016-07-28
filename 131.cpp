#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<int>> p_info = get_sub_palindrome_info(s);
		//for (int i = 0; i < p_info.size(); i++)
		//{
		//	for (int j = 0; j < p_info[i].size(); j++)
		//		cout << p_info[i][j] << ' ';
		//	cout << endl;
		//}
		vector<vector<string>> result;
		vector<string> cur_seq;
		dfs(result, cur_seq, p_info, s, s.length() - 1);
		// for (int i = 0; i < result.size(); i++)
		// {
		// 	for (int j = 0; j < result[i].size(); j++)
		// 		cout << result[i][j] << ' ';
		// 	cout << endl;
		// }
		return result;
	}

private:
	void dfs(vector<vector<string>> & result,
		vector<string> & cur_seq,
		vector<vector<int>> & p_info,
		string & s,
		int pos)
	{
		if (pos < 0)
		{
			result.push_back(cur_seq);
			reverse(result.back().begin(), result.back().end());
		}
		else
		{
			for (auto it : p_info[pos])
			{
				cur_seq.push_back(s.substr(pos - it + 1, it));
				dfs(result, cur_seq, p_info, s, pos - it);
				cur_seq.pop_back();
			}
		}
	}

    vector<vector<int>> get_sub_palindrome_info(string s) {
		string s2 = "#";
		for (auto it : s)
		{
			s2 += it;
			s2 += '#';
		}
		vector<int> f(s2.length(), 0);
		int c = 0;
		for (int pos = 1; pos < s2.length(); pos++)
		{
			if (c + c - pos >= 0 && pos + f[c + c - pos] < c + f[c])
				f[pos] = f[c + c - pos];
			else
			{
				int count = 0;
				if (c + c - pos >= 0) count = min(f[c + c - pos], c + f[c] - pos);
				while (pos - count - 1 >= 0 && pos + count + 1 <= s2.length() && s2[pos - count - 1] == s2[pos + count + 1])
					count++;
				f[pos] = count;
				c = pos;
			}
		}
		vector<vector<int>> result(s.length(), vector<int>(1, 1));
		for (int pos = 1; pos < s2.length(); pos++)
			if (f[pos] > 1)
			{
				int temp = f[pos];
				int s_pos = (pos + f[pos] - 2) / 2;
				while (temp > 1)
				{
					result[s_pos].push_back(temp);
					temp -= 2;
					s_pos--;
				}
			}
		return result;
    }
};

int main()
{
	Solution s;
	// s.partition("babcbabcbaccba");
	s.partition("aab");
    cin.get();
}
