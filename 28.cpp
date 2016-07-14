#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int lh = haystack.length();
		int ln = needle.length();
		int next[ln];
		compute_prefix_function(needle, next);
		int k = -1;
		for (int i = 0;i < lh;i++)
		{
			while (k >= 0 && needle[k + 1] != haystack[i])
				k = next[k];
			if (haystack[i] == needle[k + 1])
				k++;
			if (k == ln - 1)
				return i - ln + 1;
		}
		return -1;
	}
private:
	void compute_prefix_function(string needle, int * next)
	{
		int ln = needle.length();
		next[0] = -1;
		int k = -1;
		for (int i = 1;i < ln;i++)
		{
			while (k >= 0 && needle[i] != needle[k + 1])
				k = next[k];
			if (needle[k + 1] == needle[i])
				k++;
			next[i] = k;
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
