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
	int numberOfArithmeticSlices(vector<int>& A) {
		int result = 0;
		int alen = A.size();
		vector<unordered_map<int, int> > f(alen);
		for (int i = 1; i < alen; i++) {
			for (int j = 0; j < i; j++) {
				ll tmp = (ll)A[i] - (ll)A[j];
				if (tmp < INT_MIN || tmp > INT_MAX) {
					continue;
				}
				int diff = (int)tmp;
				if (f[i].find(diff) == f[i].end()) { 
					f[i][diff] = 0;
				}
				f[i][diff]++;
				if (f[j].find(diff) != f[j].end()) {
					f[i][diff] += f[j][diff];
					result += f[j][diff];
				}
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
