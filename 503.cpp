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
typedef stack<int> SI;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		if (nums.empty()) return VI();
		nlen = nums.size();
		int max = INT_MIN;
		int pos = 0;
		for (int i = 0; i < nlen; ++i) {
			if (nums[i] > max) {
				max = nums[i];
				pos = i;
			}
		}
		SI s;
		s.push(max);
		VI result(nlen, -1);
		for (int i = prev(pos); i != pos; i = prev(i)) {
			while (!s.empty() && s.top() <= nums[i]) s.pop();
			if (!s.empty()) result[i] = s.top();
			s.push(nums[i]);
		}
		return result;
	}

private:
	int prev(int pos) {
		--pos;
		if (pos < 0) pos = nlen - 1;
		return pos;
	}

	int nlen;
};

int main()
{
	Solution s;
	cin.get();
}
