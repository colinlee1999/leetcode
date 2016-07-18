#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "cmath"
#define INT_MIN 1<<31
#define INT_MAX ~(INT_MIN)
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<bool> vertical(n, false);
		vector<bool> left_up(n + n -1, false);
		vector<bool> left_down(n + n - 1, false);
		vector<int> status(n, 0);
		dfs(0,
			n,
			vertical,
			left_up,
			left_down,
			status,
			result);
		return result;
	}

private:
	void dfs(
		int depth,
		int n,
		vector<bool> & vertical,
		vector<bool> & left_up,
		vector<bool> & left_down,
		vector<int> & status,
		vector<vector<string>> & result)
	{
		if (depth == n)
		{
			vector<string> temp_result;
			for (int i = 0;i < n;i++)
			{
				string temps = "";
				for (int j = 0;j < n;j++)
				{
					if (j == status[i]) temps += 'Q';
					else temps += '.';
				}
				temp_result.push_back(temps);
			}
			result.push_back(temp_result);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (!vertical[i] && !left_up[depth - i + (n - 1)] && !left_down[depth + i])
				{
					vertical[i] = true;
					left_up[depth - i + (n - 1)] = true;
					left_down[depth + i] = true;
					status[depth] = i;
					dfs(depth+1,
						n,
						vertical,
						left_up,
						left_down,
						status,
						result);
					vertical[i] = false;
					left_up[depth - i + (n - 1)] = false;
					left_down[depth + i] = false;
				}
			}
		}
	}
};

int main()
{
    Solution s;
    cin.get();
}
