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

typedef vector<int> VI;

class Solution {
public:
	int magicalString(int n) {
		if (n == 0) return 0;
		if (n <= 3) return 1;
		VI f(n + 1, 0);
		f[1] = 1;
		f[2] = f[3] = 2;
		int pos = 3;
		int num = 1;
		int occur = f[pos];
		int cur = 4;
		int result = 1;
		while (cur <= n) {
			if (occur > 0) {
				--occur;
				f[cur] = num;
				++cur;
				if (num == 1) ++result;
			}
			else {
				++pos;
				num = 3 - num;
				occur = f[pos];
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
