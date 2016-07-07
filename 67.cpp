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
	string addBinary(string a, string b) {
		string result, addend;
		int lr, la;
		if (a.length() > b.length())
		{
			result = a;
			addend = b;
			lr = a.length();
			la = b.length();
		}
		else
		{
			result = b;
			addend = a;
			lr = b.length();
			la = a.length();
		}
		for (int i = lr - 1, j = la - 1; j >= 0; i--, j--)
			result[i] = result[i] + addend[j] - '0';
		int carry = 0;
		for (int i = lr - 1; i >= 0; i--)
		{
			int cur_digit = result[i] - '0' + carry;
			result[i] = cur_digit % 2 + '0';
			carry = cur_digit / 2;
		}
		if (carry) result = "1" + result;
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
