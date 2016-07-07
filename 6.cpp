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
    string convert(string s, int numRows) {
    	if (numRows==1) return s;
		string next_s = "";
		for (int row = 0; row < numRows; row++)
		{
			int gap1 = (numRows - row - 1) * 2;
			int gap2 = (numRows - 1) * 2 - gap1;
			int pos = row;
			while (pos < s.length())
			{
				next_s += s[pos];
				pos += gap1;
				if (gap1 != 0 && gap2!= 0 && pos < s.length()) next_s += s[pos];
				pos += gap2;
			}
		}
		return next_s;
    }
};

int main()
{
	Solution s;
	cout<<s.convert("ABC",1)<<endl;
	cin.get();
}
