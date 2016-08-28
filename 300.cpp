#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> last;
		for (auto nit : nums)
		{
			int pos = find_pos(last, nit);
			if (pos == -1)
				last.push_back(nit);
			else if (last[pos] < nit)
			{
				if (pos + 1 == last.size())
					last.push_back(nit);
				else last[pos + 1] = nit;
			}
			else last[pos] = nit;
		}
		return last.size();
	}

private:
	int find_pos(const vector<int> & last, int nit)
	{
		if (last.empty()) return -1;
		int left = 0;
		int right = last.size();
		while (left + 1 < right)
		{
			int mid = left + (right - left) / 2;
			if (last[mid] <= nit) left = mid;
			else right = mid;
		}
		return left;
	}
};

int main()
{
	Solution s;
    cin.get();
}
