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
typedef pair<ll, ll> pll;
typedef map<pll, int> mplli;

class Solution {
public:
	int smallestFactorization(int a) {
		if (a == 1) {
			return 1;
		}
		vector<int> v;
		for (int i = 9; i >= 2; i--) {
			while (a % i == 0) {
				v.push_back(i);
				a /= i;
			}
		}
		if (a > 1) {
			return 0;
		}
		else {
			long long result = 0;
			for (auto it = v.rbegin(); it != v.rend(); it++) {
				result = 10 * result + *it;
			}
			if ((int)result != result) {
				return 0;
			}
			else {
				return (int)result;
			}
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
