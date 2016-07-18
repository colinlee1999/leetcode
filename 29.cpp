#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "cmath"
#define INT_MIN 1<<31
#define INT_MAX ~(INT_MIN)
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
		if (dividend == 0) return 0;
		long long abs_dividend = labs(dividend);
		long long abs_divisor = labs(divisor);
		long long result = 0;
		long long try_divisor = abs_divisor;
		long long multiple = 1;
		while (abs_dividend >= (try_divisor << 1))
		{
			try_divisor <<= 1;
			multiple <<= 1;
		}
		while (abs_dividend >= abs_divisor)
		{
			if (abs_dividend >= try_divisor)
			{
				abs_dividend = abs_dividend - try_divisor;
				result += multiple;
			}
			multiple >>= 1;
			try_divisor >>= 1;
		}
		if ((divisor > 0) ^ (dividend > 0)) return -result;
		else return result;
	}
};

int main()
{
    Solution s;
	cout<<s.divide(-2147483648, 1)<<endl;
    cin.get();
}
