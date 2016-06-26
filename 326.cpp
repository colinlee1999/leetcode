#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
    	return ((n>0) && (1162261467 % n == 0));
    }
};


int main()
{
    Solution s;
    cout<<s.isPowerOfThree(9)<<endl;
    cout<<s.isPowerOfThree(80)<<endl;
    cin.get();
}
