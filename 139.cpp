#include "iostream"
#include "vector"
#include "set"
#include "map"
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		unordered_set<int> true_pos;
		true_pos.insert(0);
		int longest = 0;
		for (int i = 0; i < s.length(); i++)
		{
			for (auto it : true_pos)
				if (wordDict.count(s.substr(it, i - it + 1)))
				{
					longest = i + 1;
					break;
				}
			if (longest == i+1)
				true_pos.insert(i + 1);
		}
		return (longest == s.length());
	}
};

int main()
{
    Solution s;
    cin.get();
}
