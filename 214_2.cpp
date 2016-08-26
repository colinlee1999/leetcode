#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
	string shortestPalindrome(string s) {
		int slen = s.length();
		string r_s = s;
		reverse(r_s.begin(), r_s.end());
		string temps = s + '#' + r_s;
		vector<int> pi(slen + slen + 1, -1);
		int k = -1;
		for (int i = 1; i < slen + slen + 1; i++)
		{
			while (k >= 0 && temps[k + 1] != temps[i])
				k = pi[k];
			if (temps[k + 1] == temps[i])
				k++;
			pi[i] = k;
		}
		int to_fill = slen - pi.back() - 1;
		return r_s.substr(0, to_fill) + s;
	}
};

int main()
{
    Solution s;
	s.shortestPalindrome("1234321");
    cin.get();
}
