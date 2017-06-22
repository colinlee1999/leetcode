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

struct ele {
	ele() {}

	ele(int p, int c) {
		pos = p;
		count = c;
	}

	int pos;
	int count;
};

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		n = n + 1;
		vector<int> v(26, 0);
		for (auto it : tasks) {
			++v[it - 'A'];
		}
		priority_queue<int> pq;
		queue<ele> q;
		for (int i = 0; i < 26; i++) {
			if (v[i] != 0) {
				pq.push(v[i]);
			}
		}
		int result = 0;
		if (pq.size() <= n) {
			int num = 0;
			int last = pq.top();
			while (!pq.empty()) {
				if (pq.top() == last) {
					num++;
				}
				pq.pop();
			}
			result = (last - 1) * n + num;
		}
		else {
			while (!(pq.empty() && q.empty())) {
				if (!q.empty() && q.front().pos <= result) {
					pq.push(q.front().count);
					q.pop();
				}
				if (!pq.empty()) {
					int cur = pq.top() - 1;
					pq.pop();
					if (cur > 0) {
						q.emplace(result + n, cur);
					}
				}
				++result;
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
