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

typedef vector<short> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		int blen = boxes.size();
		VVVI f(blen, VVI(blen, VI(blen, 0)));
		for (int i = 0; i < blen; i++) {
			for (int k = 0; k < blen; k++) {
				f[i][i][k] = (k + 1) * (k + 1);
			}
		}
		for (int j = 1; j < blen; j++) {
			for (int i = j - 1; i >= 0; i--) {
				for (int k = blen - 1; k >= 0; k--) {
					f[i][j][k] = f[i][j - 1][0] + (k + 1) * (k + 1);
					for (int pos = i; pos < j; pos++) {
						if (boxes[pos] == boxes[j]) {
							f[i][j][k] = max(f[i][j][k], f[i][pos][k + 1] + f[pos + 1][j - 1][0]);
						}
					}
				}
			}
		}
		return f[0][blen - 1][0];
	}

private:
	int max(int a, int b) {
		if (a > b) return a;
		else return b;
	}
};

int main()
{
	Solution s;
	cin.get();
}
