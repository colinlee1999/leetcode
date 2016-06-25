#include "iostream"
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num==0) return 0;
        int result = num%9;
        if (result==0) result = 9;
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.addDigits(400) <<endl;
    cin.get();
}
