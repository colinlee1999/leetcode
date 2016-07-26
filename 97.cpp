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
	bool isInterleave(string s1, string s2, string s3) {
		int s1len = s1.length();
		int s2len = s2.length();
		int s3len = s3.length();
		if (s3len != s2len + s1len) return false;
		vector<vector<bool>> f(s1len + 1, vector<bool>(s2len + 1, false));
		f[0][0] = true;
		for (int i = 1; i <= s1len; i++)
			f[i][0] = f[i - 1][0] && s3[i - 1] == s1[i - 1];
		for (int j = 1; j <= s2len; j++)
			f[0][j] = f[0][j - 1] && s3[j - 1] == s2[j - 1];
		for (int i = 1; i <= s1len; i++)
			for (int j = 1; j <= s2len; j++)
				f[i][j] = (f[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (f[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
		return f[s1len][s2len];
	}
};

int main()
{
	Solution s;
	s.isInterleave("aabcc", "dbbca", "aadbbbaccc");
    cin.get();
}
