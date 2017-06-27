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
using namespace std;

typedef vector<int> VI;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int s1len = s1.length();
		int s2len = s2.length();
		if (s2len < s1len) {
			return false;
		}
		VI stat = getStatistics(s1);
		auto tmpString = s2.substr(0, s1len);
		VI cur = getStatistics(tmpString);
		if (comp(stat, cur)) {
			return true;
		}
		for (int i = s1len; i < s2len; i++) {
			cur[s2[i] - 'a']++;
			cur[s2[i - s1len] - 'a']--;
			if (comp(stat, cur)) {
				return true;
			}
		}
		return false;
	}

private:
	bool comp(VI& a, VI& b) {
		for (int i = 0; i < 26; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
	VI getStatistics(string & s) {
		VI re(26, 0);
		for (auto it : s) {
			re[it - 'a']++;
		}
		return re;
	}
};

int main()
{
	Solution s;
	cin.get();
}
