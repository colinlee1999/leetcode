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
#define MODULO 1000000007

class Solution {
public:
	int checkRecord(int n) {
		vector<ull> v(n + 1, 0);
		v[0] = 1;
		v[1] = 2;
		v[2] = 4;
		for (int i = 3; i <= n; i++) {
			v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % MODULO;
		}
		ull result = v[n];
		for (int i = 1; i <= n; i++) {
			result = (result + v[i - 1] * v[n - i]) % MODULO;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
