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
using namespace std;

typedef unsigned long long ull;

class Solution {
public:
	string nearestPalindromic(string s) {
		if (s.size() == 1) {
			s[0] = s[0] - 1;
			return s;
		}
		if (toNumber(s) == 10 || toNumber(s) == 11) {
			return toString(9);
		}
		if (allNine(s)) {
			return toString(toNumber(s) + 2);
		}
		auto v = getDigits(toNumber(s));
		int len = v.size();
		bool odd = len & 1;
		auto hv = getHalf(v);
		//cout << toNumber(hv) << endl;
		ull min, max, medium;
		medium = genPalindrome(hv, odd);
		
		auto minhv = getDigits(toNumber(hv) - 1);
		if (minhv.size() < hv.size()) {
			min = replicateNine(len - 1);
		}
		else {
			min = genPalindrome(minhv, odd);
		}

		auto maxhv = getDigits(toNumber(hv) + 1);
		if (maxhv.size() > hv.size()) {
			max = replicateNine(len);
		}
		else {
			max = genPalindrome(maxhv, odd);
		}
		ull result = getClosest(toNumber(s), min, max, medium);
		return toString(result);
	}

private:
	bool allNine(string s) {
		for (auto it : s) {
			if (it != '9') {
				return false;
			}
		}
		return true;
	}

	ull genPalindrome(vector<int> & hv, bool odd) {
		vector<int> tv(hv);
		reverse(tv.begin(), tv.end());
		if (odd) {
			tv.pop_back();
		}
		ull result = toNumber(hv);
		for (int i = 0; i < tv.size(); i++) {
			result *= 10;
		}
		return result + toNumber(tv);
	}

	ull getClosest(ull target, ull a, ull b, ull c) {
		ull minAbs = 0;
		ull result = 0;
		minAbs = ~minAbs;
		tryA(minAbs, result, target, a);
		tryA(minAbs, result, target, b);
		tryA(minAbs, result, target, c);
		return result;
	}

	void tryA(ull & minAbs, ull & result, ull target, ull a) {
		ull tmp = getAbs(target, a);
		if (tmp != 0 && (tmp < minAbs || tmp == minAbs && a < result)) {
			result = a;
			minAbs = tmp;
		}
	}

	ull getAbs(ull a, ull b) {
		if (a > b) {
			return a - b;
		}
		else {
			return b - a;
		}
	}

	ull replicateNine(int l) {
		ull result = 0;
		while (l--) {
			result = result * 10 + 9;;
		}
		return result;
	}

	vector<int> getHalf(vector<int> & v) {
		vector<int> result;
		int t = (v.size() + 1) / 2;
		for (int i = t - 1; i >= 0; i--) {
			result.push_back(*(v.rbegin() + i));
		}
		return result;
	}

	vector<int> getDigits(ull n) {
		vector<int> v;
		while (n > 9) {
			v.push_back(n % 10);
			n /= 10;
		}
		v.push_back(n);
		return v;
	}

	ull toNumber(string s) {
		ull result = 0;
		for (auto it : s) {
			result = 10 * result + it - '0';
		}
		return result;
	}

	ull toNumber(vector<int> & v) {
		ull result = 0;
		for (auto it = v.rbegin(); it < v.rend(); it++) {
			result = 10 * result + *it;
		}
		return result;
	}

	string toString(ull n) {
		auto v = getDigits(n);
		string result = "";
		for (auto it : v) {
			result = string(1, it + '0') + result;
		}
		return result;
	}

	string toString(vector<int> & v) {
		string result = "";
		for (auto it : v) {
			result = string(1, it + '0') + result;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.nearestPalindromic("829123257743") << endl;
	cin.get();
}
