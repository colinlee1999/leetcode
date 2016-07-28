#include "iostream"
#include "vector"
#include "set"
#include "map"
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.size() == 0) return -1;
		if (gas.size() != cost.size()) return -1;
		int glen = gas.size();
		vector<int> v(glen, 0);
		vector<int> next(glen, -1);
		for (int i = 0; i < glen; i++)
			v[i] = gas[i] - cost[i];
		int start_pos = 0, highest_start_pos = 0;
		int cur_pos = start_pos;
		int next_pos;
		int tank = 0;
		while (next[start_pos] != start_pos)
		{
			tank += v[cur_pos];
			if (tank >= 0)
			{
				if (next[cur_pos] == -1) next_pos = (cur_pos + 1) % glen;
				else next_pos = (next[cur_pos] + 1) % glen;
				v[start_pos] += v[next_pos];
				next[start_pos] = next_pos;
				cur_pos = next_pos;
			}
			else
			{
				cur_pos = (cur_pos + 1) % glen;
				tank = 0;
				start_pos = cur_pos;
				if (start_pos <= highest_start_pos) return -1;
				highest_start_pos = max(start_pos, highest_start_pos);
			}
		}
		return start_pos;
	}
};

int main()
{
    Solution s;
    cin.get();
}
