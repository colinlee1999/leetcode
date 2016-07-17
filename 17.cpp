#include "iostream"
#include "vector"
#include "set"
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty()) return result;
		if (digits.length() == 1)
		{
			for (auto ch : digit_string[digits[0] - '0'])
				result.push_back(string(1, ch));
			return result;
		}
		vector<string> last_result = letterCombinations(digits.substr(1));
		for (auto ch : digit_string[digits[0] - '0'])
		{
			for (auto it : last_result)
			{
				cout << string(1, ch) + it << endl;
				result.push_back(string(1, ch) + it);
			}
		}
		return result;
    }
	
private:
	string digit_string[10] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
};

int main()
{
	Solution s;
	s.letterCombinations("2345");
    cin.get();
}
