#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		if (n < 1) return 0;
		return (int)sqrt(n);
	}
};

int main()
{
    Solution s;
    cin.get();
}
