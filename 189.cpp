#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int nlen = nums.size();
		k %= nlen;
		if (k == 0) return;
		int left = nlen - k;
		int g = gcd(nlen, left);
		for (int i = 0; i < g; i++)
		{
			int start = i;
			int start_number = nums[start];
			int last = start;
			int cur = start + left;
			cur %= nlen;
			while (cur != start)
			{
				nums[last] = nums[cur];
				last = cur;
				cur += left;
				cur %= nlen;
			}
			nums[last] = start_number;
		}
	}

private:
	int gcd(int a, int b)
	{
		return b ? gcd(b, a%b) : a;
	}
};

int main()
{
    Solution s;
	cout << s.convertToTitle(288) << endl;
    cin.get();
}
