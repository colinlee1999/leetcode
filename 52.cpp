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
	int totalNQueens(int n) {
		int result;
		vector<bool> vertical(n, false);
		vector<bool> left_up(n + n - 1, false);
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
		int & result)
	{
		if (depth == n)
			result++;
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
