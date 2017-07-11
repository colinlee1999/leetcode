#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		sort(d.begin(), d.end(), [] (const string& a, const string& b) {
			if (a.length() == b.length()) {
				return a < b;
			}
			else {
				return a.length() > b.length();
			}
		});
		for (auto it : d) {
			if (contains(s, it)) {
				return it;
			}
		}
		return "";
	}

private:
	bool contains(string& a, string& b) {
		int i, j;
		i = 0;
		j = 0;
		int alen = a.length();
		int blen = b.length();
		while (i < alen) {
			if (a[i] == b[j]) {
				++j;
				if (j == blen) return true;
			}
			++i;
		}
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
