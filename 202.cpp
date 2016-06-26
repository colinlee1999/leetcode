#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0) return false;
		int magic = 4;
		while (1)
		{
			if (n == 1) return true;
			if (n == magic) return false;
			int next = 0;
			while (n)
			{
				next += (n % 10)*(n % 10);
				n /= 10;
			}
            n = next;
		}
	}
};

int main()
{
    Solution s;
    cout<<s.isHappy(16)<<endl;
    cin.get();
}
