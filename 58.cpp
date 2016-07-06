#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "sstream"
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		while (s.back() == ' ')
		{
			s.pop_back();
		}
		if (s.length() == 0) return 0;
		size_t pos;
		if ((pos = s.rfind(' ')) == s.npos)
		{
			return s.length();
		}
		else
		{
			return s.length() - pos - 1;
		}
	}
};

int main()
{
    Solution s;
    cin.get();
}
