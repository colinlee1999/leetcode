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
#include <list>
#include <utility>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

struct ele {
	ele() {}

	ele(int x, int y, int c) {
		this->x = x;
		this->y = y;
		this->c = c;
	}

	int x, y, c;
};

typedef queue<ele> QE;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		VVB b(m, VB(n, false));
		QE q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					b[i][j] = true;
					q.emplace(i, j, 0);
				}
			}
		}

		int dx[] = { 0,0,1,-1 };
		int dy[] = { 1,-1,0,0 };

		VVI result(m, VI(n, 0));
		while (!q.empty()) {
			ele e = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = e.x + dx[i];
				int ny = e.y + dy[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
					if (!b[nx][ny]) {
						b[nx][ny] = true;
						result[nx][ny] = e.c + 1;
						q.emplace(nx, ny, e.c + 1);
					}
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
