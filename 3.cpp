#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<bool> b(256, false);
		int max_len = 0;
		int head, tail;
		head = tail = 0;
		while (head < s.length())
		{
			while (head<s.length() && (!b[s[head]]))
			{
				b[s[head]] = true;
				head++;				
			}				
			if (head - tail>max_len)  max_len = head - tail;
			if (head < s.length())
			{
				while (b[s[head]])
					b[s[tail++]] = false;
			}
		}
		return max_len;
    }
};

int main()
{
    Solution s;
    cin.get();
}
