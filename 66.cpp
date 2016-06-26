#include "iostream"
#include "vector"
#include "map"
#include "cmath"
using namespace std;
 
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits.insert(digits.begin(), 0);
		digits.back() = digits.back() + 1;
		int carry = 0;
		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++)
		{
			*it += carry;
			carry = *it / 10;
			*it %= 10;
		}
		if (digits.front() == 0) digits.erase(digits.begin());
		return digits;
	}
};

int main()
{
    Solution s;
    cin.get();
}
