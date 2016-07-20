#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
	int minDistance(string word1, string word2) {
		int nlen1 = word1.length();
		int nlen2 = word2.length();
		if (nlen1 == 0) return nlen2;
		if (nlen2 == 0) return nlen1;
		vector<vector<int>> f(nlen1 + 1, vector<int>(nlen2 + 1, 0));
		for (int i = 1; i <= nlen1; i++)
			f[i][0] = i;
		for (int j = 1; j <= nlen2; j++)
			f[0][j] = j;
		for (int i = 1; i <= nlen1; i++)
			for (int j = 1; j <= nlen2; j++)
			{
				f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), f[i - 1][j - 1] + 1);
				if (word1[i - 1] == word2[j - 1])
					f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
		return f[nlen1][nlen2];
	}
};

int main()
{
    Solution s;
    cin.get();
}
