#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	Solution()
	{
		vowels.insert('a');
		vowels.insert('e');
		vowels.insert('i');
		vowels.insert('o');
		vowels.insert('u');
		vowels.insert('A');
		vowels.insert('E');
		vowels.insert('I');
		vowels.insert('O');
		vowels.insert('U');
	}

    string reverseVowels(string s) {
		int left, right;
		left = 0;
		right = s.size()-1;
		char temp;
		while (left<right)
		{
			while (left < right && vowels.find(s[left]) == vowels.end()) left++;
			while (left < right && vowels.find(s[right]) == vowels.end()) right--;
			if (left == right) break;
			temp = s[left];
			s[left] = s[right];
			s[right] = temp;
            left++;
            right--;
		}
		return s;
    }

private:
	set<char> vowels;
};

int main()
{
    Solution s;
	cout << s.reverseVowels("leetcode") << endl;
    cin.get();
}
