#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num<1) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        if (num==1) return true;
        else return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isUgly(16)<<endl;
    cin.get();
}
