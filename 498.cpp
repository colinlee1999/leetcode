#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_m	ap>
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
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return VI();
		M = matrix.size();
		N = matrix[0].size();
		int cx, cy;
		cx = cy = 0;
		flag = false;
		VI result;
		result.push_back(matrix[cx][cy]);
		while (next(cx, cy)) {
			result.push_back(matrix[cx][cy]);
		}
		return result;
	}

private:
	bool next(int& cx, int& cy) {
		if (cx == M - 1 && cy == N - 1)
			return false;
		if (!flag) {
			if (cx == 0 || cy == N - 1) {
				if (cy == N - 1) {
					++cx;
				}
				else {
					++cy;
				}
				flag = !flag;
			}
			else {
				--cx;
				++cy;
			}
		}
		else {
			if (cy == 0 || cx == M - 1) {
				if (cx == M - 1) {
					++cy;
				}
				else {
					++cx;
				}
				flag = !flag;
			}
			else {
				++cx;
				--cy;
			}
		}
		return true;
	}

	int M, N;
	bool flag;
};

int main()
{
	Solution s;
	cin.get();
}
