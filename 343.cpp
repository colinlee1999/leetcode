#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		if (n == 2) return 1;
		if (n == 3) return 2;
		int result = 1;
		while (n > 4)
		{
			n -= 3;
			result *= 3;
		}
		return result * n;
	}
};

int main()
{
    Solution s;
    cin.get();
}
