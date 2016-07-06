#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "sstream"
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		int count;
		char current_char;
		while (--n)
		{
			ostringstream next_s;
			current_char = s[0];
			count = 1;
			s += (char)0;
			for (int i = 1; i < s.length(); i++)
			{
				if (s[i] != current_char)
				{
					next_s << count << current_char;
					current_char = s[i];
					count = 1;
				}
				else
				{
					count++;
				}
			}
			s = next_s.str();
		}
		return s;
	}
};

int main()
{
    Solution s;
    cout<<s.countAndSay(1)<<endl;
    cout<<s.countAndSay(2)<<endl;
    cout<<s.countAndSay(3)<<endl;
    cout<<s.countAndSay(4)<<endl;
    cout<<s.countAndSay(5)<<endl;
    cout<<s.countAndSay(6)<<endl;
    cout<<s.countAndSay(20)<<endl;
    cin.get();
}
