#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		vector<vector<int>> p_info = get_sub_palindrome_info(s);
		vector<int> f(s.length() + 1, INT_MAX);
		f[0] = -1;
		for (int i = 1; i <= s.length(); i++)
		{
			for (auto it : p_info[i - 1])
				f[i] = min(f[i - it] + 1, f[i]);
		}
		return f.back();
	}

private:
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
