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

typedef vector<bool> VB;

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int result = 0;
		int nlen = nums.size();
		VB vb(nlen, false);
		for (int i = 0; i < nlen; ++i) {
			if (vb[i]) continue;
			int cur = i;
			int count = 0;
			while (!vb[cur]) {
				vb[cur] = true;
				cur = nums[cur];
				++count;
			}
			if (count > result) result = count;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
