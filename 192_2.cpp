#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    int hammingWeight(int32_t n) 
    {
        int NumberOfOne = 0;

        while(n) {
            NumberOfOne ++;
            n = n&(n-1);
        }
        return NumberOfOne;
    }
};

int main()
{
    Solution s;
    cout<<s.hammingWeight(16)<<endl;
    cin.get();
}
