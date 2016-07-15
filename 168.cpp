#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string str = "";
		while (n > 0)
		{
			int last = n % 26;
			if (last == 0) last = 26;
			str = (char)('A' + last - 1) + str;
			n -= last;
			n /= 26;
		}
		return str;
	}
};

int main()
{
    Solution s;
	cout << s.convertToTitle(288) << endl;
    cin.get();
}
