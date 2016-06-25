#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int carry = 1;
		int result = 0;
		for (string::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
		{
			result += (*it - 'A' + 1)*carry;
            carry *= 26;
		}
		return result;
    }
};

int main()
{
    Solution s;
	cout<<s.titleToNumber("ZZZ") << endl;
    cin.get();
}
