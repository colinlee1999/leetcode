#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int MAXINT = (1 << 30) - 1 + (1 << 30);
		if (x < 0)
		{
			int result = 0;
			while (x < 0)
			{
				if (MAXINT / 10 < result) return 0;
				result *= 10;
				result += (-(x % 10));
				x /= 10;
			}
			return -result;
		}
		else
		{
			int result = 0;
			while (x > 0)
			{
				if (MAXINT / 10 < result) return 0;
				result *= 10;
				result += x % 10;
				x /= 10;
			}
			return result;
		}
	}
};

int main()
{
	Solution s;
	cout<<s.reverse(-2147483412)<<endl;
	cin.get();
}
