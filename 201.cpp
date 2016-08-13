#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int cur = 1;
		int result = 0;
		int gap = n - m;
		while (cur <= m)
		{
			if (m & cur)
			{
				long long already = ~(-cur) & m;
				if (already + gap < cur) result |= cur;
			}
			if (cur <= m / 2) cur <<= 1;
			else break;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout<<s.rangeBitwiseAnd(5,7);
    cin.get();
}
