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
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string result = "";
		int min_length = INT_MAX;
		for (vector<string>::iterator it = strs.begin(); it < strs.end(); it++)
			if ((*it).length() < min_length) min_length = (*it).length();
		for (int i = 0; i<min_length; i++)
		{
			char cur_char = strs.front()[i];
			for (vector<string>::iterator it = strs.begin()+1; it < strs.end(); it++)
				if ((*it)[i] != cur_char) return result;
			result += cur_char;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
