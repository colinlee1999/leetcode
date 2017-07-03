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

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		VI pos;
		for (auto vit : wall) {
			int cur = 0;
			for (int i = 0; i < vit.size() - 1; ++i) {
				cur += vit[i];
				pos.push_back(cur);
			}
		}
		sort(pos.begin(), pos.end());
		pos.push_back(-1);
		int result = 0;
		int last = -1;
		int count = 0;
		for (auto it : pos) {
			if (it == last) {
				++count;
			}
			else {
				if (count > result) result = count;
				last = it;
				count = 1;
			}
		}
		return wall.size() - result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
