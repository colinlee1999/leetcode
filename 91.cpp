#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int nlen = s.length();
		if (nlen == 0) return 0;
		vector<int> f(nlen + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= nlen; i++)
		{
			if (s[i - 1] != '0') f[i] += f[i - 1];
			if (i > 1 && s[i - 2] != '0')
			{
				int temp = s[i - 2] - '0';
				temp = temp * 10 + s[i - 1] - '0';
				if (temp <= 26)
					f[i] += f[i - 2];
			}
		}
		return f.back();
	}
};

int main()
{
    Solution s;
    cin.get();
}
