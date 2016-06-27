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
	bool isIsomorphic(string s, string t) {
		vector<char> mapping(256, -1);
		vector<char> reverse_mapping(256, -1);
		for (int i = 0; i < s.length(); i++)
		{
			if (mapping[s[i]] != -1)
			{
				if (reverse_mapping[t[i]] == -1) return false;
				if (mapping[s[i]] != t[i]) return false;
			}
			else
			{
				if (reverse_mapping[t[i]] != -1) return false;
				mapping[s[i]] = t[i];
				reverse_mapping[t[i]] = s[i];
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	cin.get();
}
