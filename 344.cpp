#include "iostream"
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string s2 = "";
        int l = s.length();
        while (l-->0)
            s2 += s[l];
        return s2;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseString("abcd")<<endl;
    cin.get();
}
