#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
//#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		istringstream in_string(str);
		vector<string> v;
		while (in_string)
		{
			string temp;
			in_string >> temp;
			if (temp.empty()) break;
			v.push_back(temp);
		}
		map<char, string> m1;
		map<char, string>::iterator iter1;
		map<string, char> m2;
		map<string, char>::iterator iter2;
		if (pattern.length() != v.size()) return false;
		for (int i = 0; i < pattern.length(); i++)
		{
			if ((iter1 = m1.find(pattern[i])) != m1.end())
			{
				if ((iter2 = m2.find(v[i])) == m2.end()) return false;
				if (iter1->second != v[i]) return false;
			}
			else
			{
				if ((iter2 = m2.find(v[i])) != m2.end()) return false;
				m1.insert(pair<char, string>(pattern[i], v[i]));
				m2.insert(pair<string, char>(v[i], pattern[i]));
			}
		}
		return true;
    }
};

int main()
{
	Solution s;
	string s1 = "abba";
	string s2 = "dog cat cat dog";
	cout << s.wordPattern(s1, s2) << endl;
	cin.get();
}
