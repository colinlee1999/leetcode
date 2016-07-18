#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <hash_map>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
		int carry, result;
		while (b)
		{
			int result = a ^ b;
			int carry = (a & b) << 1;
			a = result;
			b = carry;
		}
		return a;
    }
};

int main()
{
	Solution s;
    cin.get();
}
