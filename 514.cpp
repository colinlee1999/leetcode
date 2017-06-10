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

typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
	int findRotateSteps(string ring, string key) {
		int rlen = ring.length();
		int klen = key.length();
		VVI f(klen + 1, VI(rlen, rlen * klen));
		fill(f[0].begin(), f[0].end(), 0);
		for (int i = 1; i < klen; i++) {
			for (int j = 0; j < rlen; j++) {
				if (key[i - 1] == ring[j]) {
					for (int k = 0; k < rlen; k++) {
						f[i][j] = min(f[i][j], f[i - 1][k] + min(abs(j - k), rlen - abs(j - k)));
					}
				}
			}
		}
		int result = rlen * klen;
		for (int j = 0; j < rlen; j++) {
			if (f[klen][j] < result) {
				result = f[klen][j];
			}
		}
		return result + klen;
	}

private:
	int min(int a, int b) {
		if (a < b) return a;
		else return b;
	}
};

int main()
{
	Solution s;
	cin.get();
}
