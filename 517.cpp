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

class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int total = 0;
		int mlen = machines.size();
		vector<int> lcnt(mlen, 0);
		vector<int> rcnt(mlen, 0);
		for (int i = 0; i < mlen; i++) {
			total += machines[i];
		}
		if (total / mlen * mlen != total) {
			return -1;
		}
		int avg = total / mlen;
		int cur = 0;
		for (int i = 0; i < mlen; i++) {
			cur += machines[i];
			lcnt[i] = avg * (i + 1) - cur;
		}
		cur = 0;
		for (int i = mlen - 1; i >= 0; i--) {
			cur += machines[i];
			rcnt[i] = avg*(mlen - i) - cur;
		}
		int result = 0;
		for (int i = 0; i < mlen; i++) {
			if (lcnt[i] < 0 && rcnt[i] < 0) {
				result = max(-lcnt[i] - rcnt[i], result);
			}
			else {
				result = max(max(abs(lcnt[i]), abs(rcnt[i])), result);
			}
		}
		return result;
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
