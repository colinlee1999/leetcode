#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return -1;
		if (x <= 1) return x;
		int left = 1;
		int cur = 1;
		while (cur <= (x >> 2))
		{
			cur <<= 2;
			left <<= 1;
		}
		int right = left << 1;
		int mid, temp;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			temp = x / mid;
			if (temp == mid) return mid;
			else if (temp < mid) right = mid;
			else left = mid;
		}
		return left;
	}
};

int main()
{
    Solution s;
    cin.get();
}
