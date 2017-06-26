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

typedef long long ll;

class Solution {
public:
	string fractionAddition(string expression) {
		string & ex = expression;
		if (ex.front() != '-') {
			ex = "+" + ex;
		}
		ll deno = 1;
		ll nume = 0;
		int i = 0;
		while (i < ex.length()) {
			int sign = 1;
			if (ex[i] == '-') {
				sign = -1;
			}
			++i;
			ll tnume = sign * parse(i, ex);
			++i;
			ll tdeno = parse(i, ex);
			add(nume, deno, tnume, tdeno);
		}
		ostringstream oss;
		oss << nume << '/' << deno;
		return oss.str();
	}

private:
	void add(ll & a, ll & b, ll & c, ll & d) {
		ll deno, nume;
		deno = b * d;
		nume = a * d + c * b;
		ll g = gcd(abs(deno), abs(nume));
		a = nume / g;
		b = deno / g;
	}

	ll abs(ll a) {
		if (a < 0) return -a;
		else return a;
	}

	ll gcd(ll a, ll b) {
		if (b == 0) return a;
		else return gcd(b, a % b);
	}

	ll parse(int & i, string & ex) {
		ll r = 0;
		while (i < ex.length() && isDigit(ex[i])) {
			r = 10 * r + ex[i] - '0';
			++i;
		}
		return r;
	}
	
	bool isDigit(char & ch) {
		return ch >= '0' && ch <= '9';
	}
};

int main()
{
	Solution s;
	cin.get();
}
