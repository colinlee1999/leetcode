#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int slen = s.length();
		int tlen = t.length();
		int spos = 0;
		int tpos = 0;
		while (spos < slen)
		{
			if (tpos == tlen) return false;
			if (t[tpos] == s[spos])
				spos++;
			tpos++;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string s1 = "axc";
	string s2 = "ahbgdc";
	cout << s.isSubsequence(s1, s2) << endl;
    cin.get();
}
