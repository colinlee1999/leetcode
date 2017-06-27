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

typedef vector<int> VI;

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		if (test(p1, p2, p3, p4)) return true;
		if (test(p1, p3, p2, p4)) return true;
		return false;
	}

private:
	bool test(VI& a, VI& b, VI& c, VI& d) {
		int ax = a[0];
		int ay = a[1];
		int bx = b[0];
		int by = b[1];
		if (ax == bx && ay == by) {
			return false;
		}
		int diffx = bx - ax;
		int diffy = by - ay;
		int tx = -diffy;
		int ty = diffx;
		int pcx = ax + tx;
		int pcy = ay + ty;
		int pdx = bx + tx;
		int pdy = by + ty;
		if ((pcx == c[0] && pcy == c[1] && pdx == d[0] && pdy == d[1]) ||
			(pcx == d[0] && pcy == d[1] && pdx == c[0] && pdy == c[1])) {
			return true;
		}
		tx = -tx;
		ty = -ty;
		pcx = ax + tx;
		pcy = ay + ty;
		pdx = bx + tx;
		pdy = by + ty;
		if ((pcx == c[0] && pcy == c[1] && pdx == d[0] && pdy == d[1]) ||
			(pcx == d[0] && pcy == d[1] && pdx == c[0] && pdy == c[1])) {
			return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
