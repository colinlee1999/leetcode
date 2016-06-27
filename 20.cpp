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
	bool isValid(string s) {
		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case '(':
			case '[':
			case '{':
				par.push(s[i]);
				break;
			case ')':
				if (par.empty()) return false;
				if (par.top() != '(') return false;
				par.pop();
				break;
			case ']':
				if (par.empty()) return false;
				if (par.top() != '[') return false;
				par.pop();
				break;
			case '}':
				if (par.empty()) return false;
				if (par.top() != '{') return false;
				par.pop();
				break;
			default:
				break;
			}
		}
		if (!par.empty()) return false;
		return true;
	}

private:
	stack<int> par;
};

int main()
{
	Solution s;
	cin.get();
}
