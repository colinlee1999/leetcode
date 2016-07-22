#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

class Anagram {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> m;
		for (auto it : s)
		{
			auto mit = m.find(it);
			if (mit == m.end())
				m[it] = 1;
			else mit->second++;
		}
		for (auto it : t)
		{
			auto mit = m.find(it);
			if (mit == m.end())
				return false;
			else mit->second--;
		}
		for (auto mit : m)
			if (mit.second != 0)
				return false;
		return true;
	}
};

class Solution {
public:
	bool isScramble(string s1, string s2) {
		int n1 = s1.length();
		int n2 = s2.length();
		if (n1 != n2) return false;
		if (n1 == 0) return true;
		if (n1 == 1)
		{
			if (s1[0] == s2[0])
				return true;
			else return false;
		}			
		Anagram a;
		if (!a.isAnagram(s1, s2)) return false;
		string ls1, rs1;
		for (int mid = 1; mid < n1; mid++)
		{
			ls1 = s1.substr(0, mid);
			rs1 = s1.substr(mid, n1 - mid);
			if (isScramble(ls1, s2.substr(0, mid)) && isScramble(rs1, s2.substr(mid, n2 - mid))) return true;
			if (isScramble(ls1, s2.substr(n2 - mid, mid)) && isScramble(rs1, s2.substr(0, n2 - mid))) return true;
		}
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
