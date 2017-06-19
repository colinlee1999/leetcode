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
#define MAXI ((ll)1<<62)

class Solution {
public:
	string smallestGoodBase(string n) {
		ll target = to_num(n);
		int best = 2;
		ll best_num = target - 1;
		ll cur = target - 1;
		ll base2 = 3;
		for (int i = 3; i <= 63; i++) {
			base2 = base2 * 2 + 1;
			if (base2 > target) {
				break;
			}
			cur = find(cur, i, target);
			if (get_series(cur, i) == target) {
				best = i;
				best_num = cur;
			}
		}
		return to_string(best_num);
	}

private:
	ll find(ll base, int p, ll target) {
		ll left = 2;
		ll right = base;
		ll mid, tmp;
		while (left + 1 < right) {
			mid = left + (right - left) / 2;
			tmp = get_series(mid, p);
			if (tmp == target) {
				return mid;
			}
			if (tmp == -1 || tmp > target) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		return left;
	}

	ll get_series(ll base, int p) {
		ll result = 1;
		ll cur = 1;
		for (int i = 1; i < p; i++) {
			if (MAXI / base < cur) {
				return -1;
			}
			cur *= base;
			if (MAXI - cur < result) {
				return -1;
			}
			result += cur;
		}
		return result;
	}

	ll to_num(string n) {
		ll result = 0;
		for (auto it : n) {
			result = 10 * result + it - '0';
		}
		return result;
	}

	string to_string(ll n) {
		string result = "";
		while (n > 9) {
			result.push_back(n % 10 + '0');
			n /= 10;
		}
		result.push_back(n % 10 + '0');
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
