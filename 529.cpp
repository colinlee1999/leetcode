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

#include <cstdio>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

struct ele {
	ele(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int x, y;
};

typedef queue<ele> Q_ELE;

class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int r = click[0];
		int c = click[1];
		if (board[r][c] == 'M') {
			board[r][c] = 'X';
			return board;
		}
		rlen = board.size();
		clen = board[0].size();
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		Q_ELE q;
		VVB vvb(rlen, VB(clen, false));
		q.emplace(r, c);
		vvb[r][c] = true;
		int nx, ny;
		while (!q.empty()) {
			ele e = q.front();
			q.pop();
			int numMines = getAdjacentMines(board, e);
			if (numMines == 0) {
				board[e.x][e.y] = 'B';
				for (int i = -1; i <= 1; ++i) {
					for (int j = -1; j <= 1; ++j) {
						if (i == 0 && j == 0) continue;
						nx = e.x + i;
						ny = e.y + j;
						if (isIn(nx, ny) && board[nx][ny] == 'E' && !vvb[nx][ny]) {
							q.emplace(nx, ny);
							vvb[nx][ny] = true;
						}
					}
				}
			}
			else {
				board[e.x][e.y] = '0' + numMines;
			}
		}
		return board;
	}

private:
	int getAdjacentMines(VVC& board, ele e) {
		int result = 0;
		int nx, ny;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i == 0 && j == 0) continue;
				nx = e.x + i;
				ny = e.y + j;
				if (isIn(nx, ny)) {
					if (board[nx][ny] == 'M') {
						++result;
					}
				}
			}
		}
		return result;
	}

	bool isIn(int nx, int ny) {
		return nx >= 0 && nx < rlen && ny >= 0 && ny < clen;
	}

	int rlen, clen;
};

int main()
{
	Solution s;
	cin.get();
}
