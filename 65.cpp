#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int left = 0;
		int right = s.length() - 1;
		while (left <= right && s[left] == ' ') left++;
		while (left <= right && s[right] == ' ') right--;
		if (left > right) return false;
		int status = 0, main_length = 0, decimal_length = 0, exp_length = 0;
		while (left <= right)
		{
			switch (status)
			{
			case 0: // accept '+' and '-' in main body
				if (s[left] == '+' || s[left] == '-') left++;
				status = 1;
				break;
			case 1: // accept 0..9 in main body
				if (s[left] >= '0' && s[left] <= '9')
				{
					left++;
					main_length++;
				}
				else status = 2;
				break;
			case 2: // accept '.'
				if (s[left] == '.') left++;
				status = 3;
				break;
			case 3: // accept 0..9 in decimal
				if (s[left] >= '0' && s[left] <= '9')
				{
					left++;
					decimal_length++;
				}
				else status = 4;
				break;
			case 4: // accept 'e'
				if (main_length + decimal_length == 0) return false;
				if (s[left] == 'e')
				{
					left++;
					status = 5;
				}
				else return false;
				break;
			case 5: // accept '+' and '-' in exp
				if (s[left] == '+' || s[left] == '-') left++;
				status = 6;
				break;
			case 6: // accept 0..9 in exp
				if (s[left] >= '0' && s[left] <= '9')
				{
					left++;
					exp_length++;
				}
				else status = 7;
				break;
			case 7: // end of detection
				return false;
				break;
			default:
				break;
			}
		}
		switch (status)
		{
		case 1:
			if (main_length == 0) return false;
			break;
		case 3:
			if (main_length + decimal_length == 0) return false;
			break;
		case 5:
		case 6:
			if (exp_length == 0) return false;
			break;
		default:
			break;
		}
		return true;
	}
};

int main()
{
	Solution s;
    cin.get();
}
