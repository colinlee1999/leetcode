#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int slen = s.length();
		int tlen = t.length();
		vector<vector<int>> f(slen + 1, vector<int>(tlen + 1, 0));
		for (int i = 0; i <= slen; i++)
			f[i][0] = 1;
		for (int i = 1; i <= slen; i++)
			for (int j = 1; j <= tlen; j++)
			{
				f[i][j] = f[i - 1][j];
				if (s[i - 1] == t[j - 1])
					f[i][j] += f[i - 1][j - 1];
			}
		return f[slen][tlen];
	}
};

int main()
{
    Solution s;
    cin.get();
}
