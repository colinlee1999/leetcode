#include "iostream"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		int len = s.length();
		unordered_map<string, int> m;
		vector<string> result;
		for (int i = 0; i < len - 9; i++)
		{
			string temps = s.substr(i, 10);
			if (m.count(temps))
			{
				if (m[temps] == 1) result.push_back(temps);
				m[temps]++;
			}
			else
				m[temps] = 1;
		}
		return result;
	}
};

int main()
{
    cin.get();
}
