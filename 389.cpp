#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> v(26, 0);
		for (auto it : t)
			v[it - 'a']++;
		for (auto it : s)
			v[it - 'a']--;
		for (int i = 0; i < 26; i++)
			if (v[i]) return (char)(i + 'a');
		return 0;
	}
};

int main()
{
    Solution s;
	cout<<s.findTheDifference("abcd", "abcde")<<endl;
    cin.get();
}
