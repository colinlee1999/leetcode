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
	vector<int> grayCode(int n) {
		vector<int> result;
		int cur = 0;
		dfs(n, cur, result);
		return result;
	}

	void dfs(int n, int & cur, vector<int> & result)
	{
		if (n == 0)
			result.push_back(cur);
		else
		{
			dfs(n - 1, cur, result);
			cur ^= 1 << (n - 1);
			dfs(n - 1, cur, result);
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
