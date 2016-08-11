#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		if (denominator == 0) return "";
		if (numerator == 0) return "0";
		ostringstream os;
		if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator>0))
			os << "-";
		long long abs_numerator = labs(numerator);
		long long abs_denominator = labs(denominator);
		long long g = gcd(abs_numerator, abs_denominator);
		abs_denominator /= g;
		abs_numerator /= g;
		int num_factor_2 = 0, num_factor_5 = 0;
		long long abs_denominator_backup = abs_denominator;
		while (abs_denominator % 2 == 0)
		{
			num_factor_2++;
			abs_denominator /= 2;
		}
		while (abs_denominator % 5 == 0)
		{
			num_factor_5++;
			abs_denominator /= 5;
		}
		int non_loop_bit = max(num_factor_2, num_factor_5);
		int loop_bit = 0;
		if (abs_denominator != 1)
		{
			loop_bit = 1;
			long long cur_remainder = 10 % abs_denominator;
			while (cur_remainder != 1)
			{
				cur_remainder *= 10;
				cur_remainder %= abs_denominator;
				loop_bit++;
			}
		}
		abs_denominator = abs_denominator_backup;
		os << abs_numerator / abs_denominator;
		abs_numerator %= abs_denominator;
		if (abs_numerator != 0)
		{
			os << ".";
			while (non_loop_bit--)
			{
				abs_numerator *= 10;
				os << abs_numerator / abs_denominator;
				abs_numerator %= abs_denominator;
			}
			if (loop_bit > 0)
			{
				os << "(";
				while (loop_bit--)
				{
					abs_numerator *= 10;
					os << abs_numerator / abs_denominator;
					abs_numerator %= abs_denominator;
				}				
				os << ")";
			}
		}
		return os.str();
    }

private:
	long long gcd(long long a, long long b)
	{
		return b == 0 ? a : gcd(b, a%b);
	}
};

int main()
{
	Solution s;
	cout << s.fractionToDecimal(1, 7) << endl;
    cin.get();
}
