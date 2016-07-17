#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		string s2 = "#";
		int max_count = 0;
		int max_count_pos;
		for (auto it : s)
		{
			s2 += it;
			s2 += '#';
		}
		vector<int> f(s2.length(), 0);
		int c = 0;
		for (int pos = 1; pos < s2.length(); pos++)
		{
			if (c + c - pos >= 0 && pos + f[c + c - pos] < c + f[c])
				f[pos] = f[c + c - pos];
			else
			{
				int count = 0;
				if (c + c - pos >= 0) count = min(f[c + c - pos], c + f[c] - pos);
				while (pos - count - 1 >= 0 && pos + count + 1 <= s2.length() && s2[pos - count - 1] == s2[pos + count + 1])
					count++;
				f[pos] = count;
				if (f[pos] > max_count)
				{
					max_count = f[pos];
					max_count_pos = pos;
				}
				c = pos;
			}
		}
		string s3 = "";
		int cur_pos = max_count_pos - max_count + 1;
		while (cur_pos < max_count_pos + max_count)
		{
			s3 += s2[cur_pos];
			cur_pos += 2;
		}
		return s3;
    }
};

int main()
{
	//int myint[] = { 3,4 };
	//vector<int> v1(myint, myint + sizeof(myint) / sizeof(int));
	//int myint2[] = {  };
	//vector<int> v2(myint2, myint2 + sizeof(myint2) / sizeof(int));
	// for (auto it : v1)
	// 	cout<<it<<' ';
	// cout<<endl;
	Solution s;
	cout << s.longestPalindrome("babcbabcbaccba") << endl;
    cin.get();
}
