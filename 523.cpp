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

typedef long long ll;
typedef unordered_map<ll, int> UMAP_LL_INT;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (nums.size() <= 1) return false;
		if (k == 0) {
			for (int i = 1; i < nums.size(); ++i) {
				if (nums[i - 1] + nums[i] == 0) {
					return true;
				}
			}
			return false;
		}
		UMAP_LL_INT umap;
		ll sum = 0;
		umap[0] = -1;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			sum %= k;
			if (umap.find(sum) != umap.end()) {
				if (i - umap[sum] >= 2) {
					return true;
				}
			}
			else {
				umap[sum] = i;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
