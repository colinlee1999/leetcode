#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		if (isBadVersion(1)) return 1;
		int left = 1;
		int right = n;
		int mid;
		while (left+1 < right)
		{
			mid = left + (right - left) / 2;
			if (isBadVersion(mid)) right = mid;
			else left = mid;
		}
		return left + 1;
    }
};

int main()
{
    Solution s;
    cin.get();
}
