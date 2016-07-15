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
    bool isPalindrome(string s) {
		int left = 0;
		int right = s.length() - 1;
		while (left < right)
		{
			while (left < right && !is_alphanumeric(s[left])) left++;
			while (left < right && !is_alphanumeric(s[right])) right--;
			if (left == right) break;
			if (s[left] >= 'a') s[left] -= 32;
			if (s[right] >= 'a') s[right] -= 32;
			if (s[left] != s[right]) return false;
			left++;
			right--;
		}		
		return true;
    }

private:
	bool is_alphanumeric(char ch)
	{
		if (ch >= '0' && ch <= '9') return true;
		if (ch >= 'a' && ch <= 'z') return true;
		if (ch >= 'A' && ch <= 'Z') return true;
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
