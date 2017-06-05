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

#define MODULO 1000000007

typedef vector<long long> VLL;
typedef vector<VLL> VVLL;

class Solution {
public:
	Solution() {
		dx = vector<int>(4, 0);
		dy = vector<int>(4, 0);
		dx[2] = 1;
		dx[3] = -1;
		dy[0] = 1;
		dy[1] = -1;
	}

	int findPaths(int m, int n, int N, int i, int j) {
		VVLL f(m + 2, VLL(n + 2, 0));
		f[i + 1][j + 1] = 1;
		for (int iter = 0; iter < N; iter++) {
			VVLL nf(m + 2, VLL(n + 2, 0));
			// first row
			// last row
			for (int j = 1; j <= n; j++) {
				nf[0][j] = (f[0][j] + f[1][j]) % MODULO;
				nf[m + 1][j] = (f[m + 1][j] + f[m][j]) % MODULO;
			}
			// first column
			// last column
			for (int i = 1; i <= m; i++) {
				nf[i][0] = (f[i][0] + f[i][1]) % MODULO;
				nf[i][n + 1] = (f[i][n + 1] + f[i][n]) % MODULO;
			}
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					for (int ind = 0; ind < 4; ind++) {
							int ni = i + dx[ind];
							int nj = j + dy[ind];
							if (1 <= ni && ni <= m && 1 <= nj && nj <= n) {
								nf[i][j] += f[ni][nj];
							}
					}
					nf[i][j] %= MODULO;
				}
			}
			f.swap(nf);
			for (int i = 0; i <= m + 1; i++) {
				for (int j = 0; j <= n + 1; j++) {
					cout << f[i][j] << ' ';
				}
				cout << "\n";
			}
			cout << "\n";
		}
		long long result = 0;
		for (int j = 1; j <= n; j++) {
			result += f[0][j] + f[m + 1][j];
		}
		for (int i = 1; i <= m; i++) {
			result += f[i][0] + f[i][n + 1];
		}
		result %= MODULO;
		return result;
	}

private:
	vector<int> dx;
	vector<int> dy;
};

int main()
{
	Solution s;
	cin.get();
}
