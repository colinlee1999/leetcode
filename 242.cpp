#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int bucket[26] = {0};
		for (string::iterator it = s.begin(); it != s.end(); ++it)
		{

			bucket[(int)(*it - 'a')]++;
		}
		for (string::iterator it = t.begin(); it != t.end(); ++it)
		{
			bucket[(int)(*it - 'a')]--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (bucket[i]) return false;
		}
		return true;
    }
};

int main()
{
    Solution s;
	cout << s.isAnagram("a", "b") << endl;
    cin.get();
}
