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

typedef unordered_map<int, int> umap_i_i;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		umap_i_i umap;
		umap[0] = 1;
		int sum = 0;
		int result = 0;
		for (auto it : nums) {
			sum += it;
			if (umap.find(sum - k) != umap.end()) {
				result += umap[sum - k];
			}
			if (umap.find(sum) != umap.end()) {
				umap[sum]++;
			}
			else {
				umap[sum] = 1;
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
