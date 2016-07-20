#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string cur_ip = "";
		int slen = s.length();
		dfs(result, cur_ip, s, 0, 0, slen);
		return result;
	}

private:
	void dfs(vector<string> & result,
		string cur_ip,
		const string & s,
		int pos,
		int k,
		const int & slen)
	{
		if (k == 4 && pos == slen)
			result.push_back(cur_ip);
		else
		{
			if (s[pos] == '0')
			{
				if (k == 0) dfs(result, "0", s, pos + 1, k + 1, slen);
				else dfs(result, cur_ip + ".0", s, pos + 1, k + 1, slen);
			}
			else
			{
				for (int i = 3; i >= 1; i--)
				{
					if (slen - i - pos > (3 - k) * 3) break;
					if (slen - i - pos < 3 - k) continue;
					string temps = s.substr(pos, i);
					istringstream is(temps);
					int try_fill;
					is >> try_fill;
					if (try_fill < 256)
					{
						if (k == 0) dfs(result, temps, s, pos + i, k + 1, slen);
						else dfs(result, cur_ip + "." + temps, s, pos + i, k + 1, slen);
					}
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
