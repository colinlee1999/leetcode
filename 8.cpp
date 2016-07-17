#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int MAXINT = ~(1 << 31);
		int cur = 0;
		while (cur < str.length() && str[cur] == ' ')
			cur++;
		str = str.substr(cur);
		if (str.empty()) return 0;
		if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-' && str[0] != '+')
			return 0;
		int sign;
		if (str[0] == '-')
			sign = -1;
		else
			sign = 1;
		cur = 0;
		if (str[0] == '-' || str[0] == '+') cur++;
		if (!(str[cur] >= '0' && str[cur] <= '9'))
			return 0;
		int result = sign * (str[cur] - '0');
		while (++cur < str.length())
		{
			if (!(str[cur] >= '0' && str[cur] <= '9'))
				break;
			if (sign>0)
			{
				if (MAXINT / 10 < result)
					return MAXINT;
				else if (MAXINT / 10 == result)
				{
					if (str[cur]>'7') return MAXINT;
				}
			}
			else
			{
				if (((~MAXINT) / 10) > result)
					return ~MAXINT;
				else if (((~MAXINT) / 10) == result)
				{
					if (str[cur]>'8') return ~MAXINT;
				}
			}
			result = result * 10 + sign*(str[cur] - '0');
		}
		return result;
    }
};

int main()
{
	Solution s;
	cout << s.myAtoi("2147483648") << endl;
    cin.get();
}
