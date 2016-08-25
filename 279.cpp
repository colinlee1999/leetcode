#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> f(n + 1, 0);
		f[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			f[i] = f[i - 1] + 1;
			for (int j = 2; j <= n; j++)
				if (i - j*j >= 0)
					f[i] = min(f[i], f[i - j*j] + 1);
				else
					break;
		}
		return f[n];
	}
};

int main()
{
    Solution s;
    cin.get();
}
