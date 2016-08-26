#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> b(26, 0);
		for (auto sit : s)
			b[sit - 'a']++;
		for (int i = 0; i < s.length(); i++)
			if (b[s[i] - 'a'] == 1)
				return i;
		return -1;
	}
};

int main()
{
    cin.get();
}
