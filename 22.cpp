#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		dfs(0, "", 0, 0, n, result);
		return result;
    }

private:
	void dfs(int depth, string cur_string, int left, int right, int n, vector<string> & result)
	{
		if (depth == n + n)
		{
			result.push_back(cur_string);
		}
		else
		{
			if (left < n)
				dfs(depth + 1, cur_string + "(", left + 1, right, n, result);
			if (left > right)
				dfs(depth + 1, cur_string + ")", left, right + 1, n, result);
		}
	}
};

int main()
{
	Solution s;
	for (auto it : s.generateParenthesis(3))
	{
		cout << it << endl;
	}
    cin.get();
}
