#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

class Anagram {
public:
	bool isAnagram(string s, string t) {
		int bucket[26] = { 0 };
		for (auto it : s)
			bucket[(int)(it - 'a')]++;
		for (auto it : t)
			bucket[(int)(it - 'a')]--;
		for (int i = 0; i < 26; i++)
			if (bucket[i]) return false;
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
		string ls1, ls2, rs1, rs2;
		for (int mid = 1; mid < n1; mid++)
		{
			ls1 = s1.substr(0, mid);
			rs1 = s1.substr(mid, n1 - mid);
			ls2 = s2.substr(0, mid);
			rs2 = s2.substr(mid, n2 - mid);
			if (!a.isAnagram(ls1, ls2))
			{
				ls2 = s2.substr(n2 - mid, mid);
				rs2 = s2.substr(0, n2 - mid);
			}
			if (!a.isAnagram(ls1, ls2)) continue;
			if (!a.isAnagram(rs1, rs2)) continue;
			if (isScramble(ls1, ls2) && isScramble(rs1, rs2)) return true;
		}
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
