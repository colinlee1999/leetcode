#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> m;
		for (auto it : magazine)
		{
			if (m.count(it))
				m[it]++;
			else
				m[it] = 1;
		}
		for (auto it : ransomNote)
		{
			if (m.count(it))
			{ 
				m[it]--;
				if (m[it] < 0) return false;
			}
			else return false;
		}
		return true;
	}
};

int main()
{
    Solution s;
	cout << s.calculate("2-1+2") << endl;
    cin.get();
}
