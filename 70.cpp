#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int c;
        while (n-->1)
        {
			c = a + b;
			a = b;
			b = c;
        }
		return b;
    }
};

int main()
{
    Solution s;
	cout << s.climbStairs(0) << endl;
	cout << s.climbStairs(1) << endl;
	cout << s.climbStairs(2) << endl;
	cout << s.climbStairs(3) << endl;
	cout << s.climbStairs(4) << endl;
	cout << s.climbStairs(5) << endl;
	cout << s.climbStairs(6) << endl;
	cout << s.climbStairs(7) << endl;
    cin.get();
}
