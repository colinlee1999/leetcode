#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double result = 1;
		double mul = x;
		int sign = 1;
		long long temp = n;
		if (temp < 0)
		{
			sign = -1;
			temp = -temp;
		}
		while (temp > 0)
		{
			if (temp & 1) result = result * mul;
			mul *= mul;
			temp >>= 1;
		}
		if (sign == 1)
			return result;
		else
			return 1 / result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
