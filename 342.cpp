#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
    bool isPowerOfFour(int num) {
		if (num < 1) return false;
		int square_root = (int)sqrt(num);
		if (square_root*square_root != num) return false;
		if ((square_root & (square_root - 1)) != 0) return false;
		return true;
    }
};

int main()
{
    Solution s;
    cin.get();
}
