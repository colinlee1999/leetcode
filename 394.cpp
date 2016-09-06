#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	string decodeString(string s) {
		int slen = s.length();
		if (slen == 0) return "";
		string result;
		for (int i = 0; i < slen;)
		{
			// cout << s[i] << endl;
			if (s[i] >= '0' && s[i] <= '9')
			{
				int temp = 0;
				while (s[i] >= '0' && s[i] <= '9')
					temp = temp * 10 + s[i++] - '0';
				i++;
				string sub = "";
				int num_bracket=1;
				while (num_bracket > 0)
				{
					if (s[i] == '[') num_bracket++;
					if (s[i] == ']') num_bracket--;
					if (num_bracket == 0) break;
					sub += s[i++];
				}
				string gen_sub = decodeString(sub);
				while (temp--) result += gen_sub;
			}
			else
				result += s[i];
			i++;
		}
		return result;
	}
};

int main()
{
	Solution s;
	string st = "3[a]2[bc]";
	cout << s.decodeString(st) << endl;
    cin.get();
}
