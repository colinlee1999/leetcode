#include "iostream"
#include "vector"
#include "set"
#include "map"
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		ratings.push_back(INT_MAX);
		int rlen = ratings.size();
		if (rlen == 1) return 0;
		if (rlen == 2) return 1;
		vector<int> f(rlen, 0);
		int total_candy = 0;
		int status = 0; // 0 means uphill, 1 means downhill;
		int last_extreme_pos = 0;
		if (ratings[1] < ratings[0])
		{
			status = 1;
			f[0] = 2;
			f[1] = 1;
		}
		else if (ratings[1] == ratings[0])
		{
			f[0] = 1;
			f[1] = 1;
			last_extreme_pos = 1;
		}
		else
		{
			f[0] = 1;
			f[1] = 2;
		}
		total_candy = f[0] + f[1];
		int cur = 2;
		while (cur < rlen)
		{
			switch (status)
			{
			case 0:
				if (ratings[cur] < ratings[cur - 1])
				{
					status = 1;
					last_extreme_pos = cur - 1;
					f[cur] = f[cur - 1] - 1;
				}
				else if (ratings[cur] == ratings[cur - 1])
				{
					f[cur] = 1;
					last_extreme_pos = cur;
				}
				else f[cur] = f[cur - 1] + 1;
				break;
			case 1:
				if (ratings[cur] >= ratings[cur - 1])
				{
					if (f[cur - 1] <= 0)
						total_candy += (1 - f[cur - 1]) * (cur - last_extreme_pos);
					else total_candy -= (f[cur - 1] - 1) * (cur - last_extreme_pos - 1);
					status = 0;
					if (ratings[cur] == ratings[cur - 1])
					{
						last_extreme_pos = cur;
						f[cur] = 1;
					}
					else
					{
						last_extreme_pos = cur - 1;
						f[cur] = 2;
					}
				}
				else f[cur] = f[cur - 1] - 1;
				break;
			default:
				break;
			}
			total_candy += f[cur];
			cur++;
		}
		ratings.pop_back();
		return total_candy - f[rlen - 1];
	}
};

int main()
{
    Solution s;
	vector<int> v;
	for (int i = 20000; i >= 1; i--)v.push_back(i);
	cout << s.candy(v) << endl;
    cin.get();
}
