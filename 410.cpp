#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> VI;

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		ll left, right, mid;
		left = right = 0;
		for (auto it : nums) {
			if (it > left) left = it;
			right += it;
		}
		--left;
		while (left + 1 < right) {
			mid = (right + left) / 2;
			if (check(nums, mid) < m) right = mid;
			else left = mid;
		}
		return right;
	}

	int check(VI& nums, ll target) {
		int result = 0;
		ll tmp = 0;
		for (auto it : nums) {
			if (tmp + it > target) {
				++result;
				tmp = 0;
			}
			tmp += it;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
