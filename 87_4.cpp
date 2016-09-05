#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		int n1 = s1.length();
		int n2 = s2.length();
		if (n1 != n2) return false;
		if (n1 == 0) return true;
		vector<vector<vector<bool>>> f(n1 + 1, vector<vector<bool>>(n1, vector<bool>(n2, false)));
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < n2; j++)
				f[1][i][j] = (s1[i] == s2[j]);
		for (int k = 2; k <= n1; k++)
			for (int i = 0; i <= n1 - k; i++)
				for (int j = 0; j <= n2 - k; j++)
					for (int mid = 1; mid < k && !f[k][i][j]; mid++)
						f[k][i][j] = (f[mid][i][j] && f[k - mid][i + mid][j + mid]) || (f[mid][i + k - mid][j] && f[k - mid][i][j + mid]);
		return f[n1][0][0];
	}
};

int main()
{
    Solution s;
    cin.get();
}
