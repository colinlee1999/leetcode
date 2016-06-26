#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x<=9) return true;
		int len = 10;
		while (x / len >= 10) len *= 10;
		int right = 1;
		while (len > right)
		{
			if ((x / right % 10) != (x / len % 10)) return false;
			len /= 10;
			right *= 10;
		}
		return true;
    }
};

int main()
{
	Solution s;
	cout<<s.isPalindrome(1)<<endl;
    cin.get();
}
