#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

typedef long long ll;

class Solution {
public:
	int numDecodings(string s) {
		cout << endl;
		cout << endl;
		if (!valid(s)) return 0;
		const ll MODULO = 1000000007;
		ll first, second, current;
		first = 1;
		second = 1;
		for (int i = 0; i < s.length(); ++i) {
			//cout << first << '\t' << second << "\t\t\t";
			if (i + 1 < s.length() && s[i + 1] == '0') {
				if (s[i] == '*') {
					current = 2 * second % MODULO;
				}
				else {
					current = second;
				}
				first = 1;
				second = current;
				++i;
			}
			else {
				if (s[i] == '*') {
					current = second * 9 % MODULO;
					if (s[i - 1] == '1') {
						current += first * 9;
					}
					else if (s[i - 1] == '2') {
						current += first * 6;
					}
					else if (s[i - 1] == '*') {
						current += first * 15;
					}
					current %= MODULO;
				}
				else if (s[i] != '0') {
					current = second;
					if (s[i - 1] == '1') {
						current += first;
					}
					else if (s[i - 1] == '2' && s[i] <= '6') {
						current += first;
					}
					else if (s[i - 1] == '*') {
						if (s[i] <= '6') {
							current += 2 * first;
						}
						else {
							current += first;
						}
					}
					current %= MODULO;
				}
				first = second;
				second = current;
			}
			//cout << first << '\t' << second << endl;
		}
		return int(second);
	}

	bool valid(string& s) {
		if (s.empty()) return false;
		if (s[0] == '0') return false;
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] == '0') {
				if (!(s[i - 1] == '1' || s[i - 1] == '2' || s[i - 1] == '*'))
					return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	cin.get();
}
