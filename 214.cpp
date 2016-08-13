#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
	string shortestPalindrome(string s) {
		vector<int> v = get_sub_palindrome_info(s);
		int slen = s.length();
		int pos;
		for (int i = slen - 1; i >= 0; i--)
			if (i+1-v[i] ==0)
			{
				pos = i;
				break;
			};
		string result = s;
		while (++pos < slen)
			result = s[pos] + result;
		return result;
	}

private:
	vector<int> get_sub_palindrome_info(string s) {
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
		vector<int> result(s.length(), 1);
		for (int pos = 1; pos < s2.length(); pos++)
			if (f[pos] > 1)
			{
				int temp = f[pos];
				int s_pos = (pos + f[pos] - 2) / 2;
				result[s_pos] = max(result[s_pos], temp);
			}
		return result;
	}
};

int main()
{
    Solution s;
	s.shortestPalindrome("1234321");
    cin.get();
}
