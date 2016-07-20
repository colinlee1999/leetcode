#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		path += '/';
		stack<string> s;
		int nlen = path.length();
		for (int i = 0; i < nlen; i++)
		{
			while (i < nlen && path[i] == '/') i++;
			if (i >= nlen - 1) break;
			string temps = "";
			while (i < nlen && path[i] != '/')
			{
				temps += path[i];
				i++;
			}
			if (temps == ".") continue;
			if (temps == "..")
			{
				if (!s.empty()) s.pop();
				continue;
			}
			s.push(temps);
		}
		if (s.empty()) return "/";
		else
		{
			string result = "";
			while (!s.empty())
			{
				result = "/" + s.top() + result;
				s.pop();
			}
			return result;
		}		
	}
};

int main()
{
    Solution s;
    cin.get();
}
