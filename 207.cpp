#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		sort(prerequisites.begin(), prerequisites.end(), my_comp_func);
		vector<int> pre_index(numCourses, -1);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int cur = prerequisites[i].first;
			if (pre_index[cur] == -1)
				pre_index[cur] = i;
		}
		vector<int> mark(numCourses, 0); //0 unmarked, 1 temp marked, 2, final marked
		for (int i = 0; i < numCourses; i++)
		{
			if (mark[i] == 0)
				if (!dfs(i, prerequisites, pre_index, mark)) return false;
		}
		return true;
	}

private:
	bool dfs(int cur_pos,
		vector<pair<int, int>> & prerequisites,
		vector<int> & pre_index,
		vector<int> & mark)
	{
		if (mark[cur_pos] == 1) return false;
		mark[cur_pos] = 1;
		if (pre_index[cur_pos] != -1)
		{
			for (int i = pre_index[cur_pos]; i < prerequisites.size(); i++)
			{
				if (prerequisites[i].first != prerequisites[pre_index[cur_pos]].first) break;
				if (!dfs(prerequisites[i].second,
					prerequisites,
					pre_index,
					mark))
					return false;
			}
		}
		mark[cur_pos] = 2;
		return true;
	}

	struct 
	{
		bool operator()(const pair<int, int> & a, const pair<int, int> & b)
		{
			return a.first < b.first;
		}
	} my_comp_func;
};

int main()
{
	Solution s;
    cin.get();
}
